-- 1. Tạo các quan hệ 
CREATE DATABASE QLKH

USE QLKH

CREATE TABLE KAHCHHANG
(
	MAKH CHAR(5) PRIMARY KEY,
	HOTEN VARCHAR(30),
	DIACHI VARCHAR(30),
	SODT VARCHAR(15),
	LOAIKH VARCHAR(10)
)

CREATE TABLE BANG_DIA
(
	MABD CHAR(5) PRIMARY KEY,
	TENBD VARCHAR(25),
	THELOAI VARCHAR(25)
)

CREATE TABLE PHIEUTHUE
	MAPT CHAR(5) PRIMARY KEY,
	MAKH CHAR(5) FOREIGN KEY REFERENCES KHACHHANG(MAKH),
	NGAYTHUE SMALLDATETIME,
	NGAYTRA SMALLDATETIME,
	SOLUONGTHUE INT
)

CREATE TABLE CHITIET_PT
(
	MAPT CHAR(5) FOREIGN KEY REFERENCES PHIEUTHUE(MAPT),
	MABD CHAR(5) FOREIGN KEY REFERENCES BANG_DIA(MABD),
	PRIMARY KEY(MAPT, MABD)
)

-- 2.1. Thể loại băng đĩa chỉ thuộc các thể loại sau “ca nhạc”, “phim hành động”, “phim tình cảm”, “phim hoạt hình”.
CREATE TRIGGER TRG_BD ON BANGDIA AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM INSERTED I
        WHERE I.THELOAI NOT IN ('ca nhạc', 'phim hành động', 'phim hoạt hình')
    )
    BEGIN
        RAISERROR('Lỗi: Thể loại băng đĩa chỉ thuộc các thể loại sau “ca nhạc”, “phim hành động”, “phim tình cảm”, “phim hoạt hình”.', 16, 1);
        ROLLBACK TRANSACTION;
    END
	ELSE
	BEGIN
		PRINT('Thêm mới một phiếu xe thành công')
	END
END

-- 2.2. Chỉ những khách hàng thuộc loại VIP mới được thuê với số lượng băng đĩa trên 5. 
CREATE TRIGGER TRG_KH ON KHACHHANG AFTER INSERT, UPDATE 
AS
BEGIN
    IF EXISTS (
        SELECT *
        FROM INSERTED I, PHIEUTHUE PT
        WHERE I.MAKH = PT.MAKH AND PT.SOLUONGTHUE >= 5 AND I.LOAIKH NOT IN ('VIP')
    )
    BEGIN
        RAISERROR('Lỗi: Chỉ những khách hàng thuộc loại VIP mới được thuê với số lượng băng đĩa trên 5.', 16, 1);
        ROLLBACK TRANSACTION;
    END
	ELSE
	BEGIN
		PRINT('Thêm mới khách hàng thành công')
	END
END

-- 3.1. Tìm các khách hàng (MaKH,HoTen) đã thuê băng đĩa thuộc thể loại phim “Tình cảm” có số lượng thuê lớn hơn 3
SELECT KH.MAKH, KH.HOTEN
FROM KHACHHANG KH, BANG_DIA BD, PHIEUTHUE PT, CHITIET_PT CT
WHERE KH.MAKH = PT.MAKH AND PT.MAPT = CT.MAPT AND CT.MABD = BD.MABD AND BD.THELOAI = 'Tình cảm' AND PT.SOLUONGTHUE > 3

-- 3.2. Tìm các khách hàng(MaDG,HoTen) thuộc loại VIP đã thuê nhiều băng đĩa nhất
SELECT A.MAKH, A.HOTEN FROM (
	SELECT KH.MAKH, KH.HOTEN, RANK() OVER (ORDER BY SUM(PT.SOLUONGTHUE) DESC) RANK_SLBD
	FROM KHACHHANG KH, BANG_DIA BD, PHIEUTHUE PT, CHITIET_PT CT
	WHERE KH.MAKH = PT.MAKH AND PT.MAPT = CT.MAPT AND CT.MABD = BD.MABD AND KH.LOAIKH = 'VIP'
	GROUP BY KH.MAKH, KH.HOTEN) A
WHERE RANK_SLBD = 1

-- 3.3. Trong mỗi thể loại băng đĩa, cho biết tên khách hàng nào đã thuê nhiều băng đĩa nhất.
SELECT A.THELOAI, A.MAKH, A.HOTEN, A.MAX(SL) FROM (
	SELECT BD.THELOAI, KH.MAKH, KH.HOTEN, SUM(PT.SOLUONGTHUE) AS SL
	FROM BANG_DIA BD, KHACHHANG KH, PHIEUTHUE PT, CHITIET_PT CT
	WHERE KH.MAKH = PT.MAKH AND PT.MAPT = CT.MAPT AND CT.MABD = BD.MABD 
	GROUP BY BD.THELOAI, KH.MAKH, KH.HOTEN) A

