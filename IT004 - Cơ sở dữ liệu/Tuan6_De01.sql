-- 1. Tạo các quan hệ 

CREATE DATABASE QLS

USE QLS

CREATE TABLE SACH
(
	MASACH CHAR(5) PRIMARY KEY,
	TENSACH VARCHAR(25),
	THELOAI VARCHAR(25)
)

CREATE TABLE TACGIA
(
	MATG CHAR(5) PRIMARY KEY,
	HOTEN VARCHAR(20),
	DIACHI VARCHAR(50),
	NGSINH SMALLDATETIME,
	SODT VARCHAR(15)
)

CREATE TABLE TACGIA_SACH
(
	MATG CHAR(5) FOREIGN KEY REFERENCES TACGIA(MATG),
	MASACH CHAR(5) FOREIGN KEY REFERENCES SACH(MASACH),
	PRIMARY KEY(MATG, MASACH)
)

CREATE TABLE PHATHANH
(
	MAPH CHAR(5) PRIMARY KEY,
	MASACH CHAR(5) FOREIGN KEY REFERENCES SACH(MASACH),
	NGAYPH SMALLDATETIME,
	SOLUONG INT,
	NHAXUATBAN VARCHAR(20)
)

-- 2.1. Ngày phát hành sách phải lớn hơn ngày sinh của tác giả
CREATE TRIGGER TRG_PH_TG ON PHATHANH AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM INSERTED I
		INNER JOIN TACGIA_SACH TGS ON I.MASACH = TGS.MASACH
        INNER JOIN TACGIA TG ON TG.MATG = TGS.MATG 
        WHERE TG.NGSINH >= I.NGAYPH 
    )
    BEGIN
        RAISERROR('Lỗi: Ngày phát hành sách phải lớn hơn ngày sinh của tác giả', 16, 1);
        ROLLBACK TRANSACTION;
    END
	ELSE
	BEGIN
		PRINT('Thêm mới một phát hành thành công')
	END
END

-- 2.2. Sách thuộc thể loại “Giáo khoa” chỉ do nhà xuất bản “Giáo dục” phát hành.
CREATE TRIGGER TRG_SACH_PH ON SACH AFTER INSERT, UPDATE  --Thêm và sửa bảng sách
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM INSERTED I, PHATHANH PH
        WHERE I.THELOAI = 'Giáo khoa' AND I.MASACH = PH.MASACH AND PH.NHAXUATBAN NOT IN ('Giáo Dục')
    )
    BEGIN
        RAISERROR('Lỗi: Sách thuộc thể loại “Giáo khoa” chỉ do nhà xuất bản “Giáo dục” phát hành.', 16, 1);
        ROLLBACK TRANSACTION;
    END
	ELSE
	BEGIN
		PRINT('Thêm mới một sách thành công')
	END
END

CREATE TRIGGER TRG_UPD_PH ON PHATHANH AFTER UPDATE  --Sửa bảng phát hành
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM INSERTED I, SACH S
        WHERE S.THELOAI = 'Giáo khoa' AND I.MASACH = S.MASACH AND I.NHAXUATBAN NOT IN ('Giáo Dục')
    )
    BEGIN
        RAISERROR('Lỗi: Sách thuộc thể loại “Giáo khoa” chỉ do nhà xuất bản “Giáo dục” phát hành.', 16, 1);
        ROLLBACK TRANSACTION;
    END
	ELSE
	BEGIN
		PRINT('Cập nhật phát hành thành công')
	END
END

-- 3.1. Tìm tác giả (MaTG,HoTen,SoDT) của những quyển sách thuộc thể loại “Văn học” do nhà xuất bản Trẻ phát hành
SELECT TG.MATG, TG.HOTEN, TG.SODT
FROM PHATHANH PH, SACH S, TACGIA TG, TACGIA_SACH TGS
WHERE TGS.MASACH = S.MASACH AND
	  TGS.MATG = TG.MATG AND
	  S.MASACH = PH.MASACH AND
	  S.THELOAI = 'Văn học' AND
	  PH.NHAXUATBAN = 'Trẻ'

-- 3.2. Tìm nhà xuất bản phát hành nhiều thể loại sách nhất.
SELECT A.NXB FROM (
	SELECT PH.NHAXUATBAN AS NXB, RANK() OVER (ORDER BY COUNT(DISTINCT S.THELOAI) DESC) RANK_SLTHELOAI
	FROM PHATHANH PH, SACH S
	WHERE PH.MASACH = S.MASACH
	GROUP BY PH.NHAXUATBAN) A
WHERE RANK_SLTHELOAI = 1

-- 3.3. Trong mỗi nhà xuất bản, tìm tác giả (MaTG,HoTen) có số lần phát hành nhiều sách nhất. 
SELECT A.NHAXUATBAN, A.MATG, A.HOTEN, A.MAX(SL) FROM (
	SELECT PH.NHAXUATBAN, TG.MATG, TG.HOTEN, COUNT(DISTINCT MAPH) AS SL
	FROM TACGIA TG, PHATHANH PH, TACGIA_SACH TGS
	WHERE PH.MASACH = TGS.MASACH AND TGS.MATG = TG.MATG
	GROUP BY PH.NHAXUATBAN, TG.MATG, TG.HOTEN) A



