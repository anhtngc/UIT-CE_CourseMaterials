CREATE DATABASE QUANLYCASI

USE QUANLYCASI

CREATE TABLE CASI
(
	MACS CHAR(5) PRIMARY KEY,
	HOTEN VARCHAR(30),
	NGAYSINH SMALLDATETIME,
	SODT VARCHAR(15),
)

CREATE TABLE TACGIA
(
	MATG CHAR(5) PRIMARY KEY,
	HOTEN VARCHAR(20),
	NGSINH SMALLDATETIME,
	SODT INT,
)

CREATE TABLE BAIHAT
(
	MABH CHAR(5) PRIMARY KEY,
	TENBH VARCHAR(25),
	NGAYST SMALLDATETIME,
	MATG CHAR(5) FOREIGN KEY REFERENCES TACGIA(MATG)
)

CREATE TABLE LICHDIEN
(
	NGAYDIEN SMALLDATETIME,
	MACS CHAR(5) FOREIGN KEY REFERENCES CASI(MACS),
	MABH CHAR(5) FOREIGN KEY REFERENCES BAIHAT(MABH),
	DIADIEM VARCHAR(15),
	TENSK VARCHAR(20),
	CONSTRAINT PK_LD PRIMARY KEY(NGAYDIEN, MACS, MABH)
)

-- 2a. Trong cùng một ngày diễn, mỗi ca sĩ phải hát ít nhất 2 bài trở lên.
CREATE TRIGGER TRG_LD ON LICHDIEN FOR INSERT, UPDATE
AS
BEGIN
	DECLARE @MACS CHAR(5), @NGAYDIEN SMALLDATETIME, @COUNT_MABH INT
	SELECT @MABH = MABH FROM INSERTED
	SELECT @COUNT_MABH = COUNT(MABH) FROM INSERTED WHERE MACS = @MACS AND NGAYDIEN = @NGAYDIEN

	IF (@COUNT_MABH >= 2)
		PRINT N'Thêm mới một lịch diễn thành công.'
	ELSE
	BEGIN
		PRINT N'Lỗi: Trong cùng ngày diễn, mỗi ca sĩ hát ít nhất 2 bài.'
		ROLLBACK TRANSACTION
	END
END

-- 2b. Ngày diễn của một ca sĩ phải lớn hơn ngày sinh của ca sĩ đó.
CREATE TRIGGER TRG_LD_CS ON LICHDIEN FOR INSERT
AS
BEGIN
	DECLARE @NGAYDIEN SMALLDATETIME, @NGAYSINH SMALLDATETIME, @MACS CHAR(5)
	SELECT @NGAYDIEN = NGAYDIEN, @MACS = MACS FROM INSERTED
	SELECT	@NGAYSINH = NGAYSINH FROM CASI WHERE MACS = @MACS

	IF (@NGAYDIEN >= @NGAYSINH)
		PRINT N'Thêm mới một lịch diễn thành công.'
	ELSE
	BEGIN
		PRINT N'Lỗi: Ngày diễn của ca sĩ phải lớn hơn ngày sinh.'
		ROLLBACK TRANSACTION
	END
END

-- 3a. Liệt kê các bài hát do nhạc sĩ Trịnh Công Sơn sáng tác được biển diễn ngày 26/09/2021, xuất theo thứ tự tăng dần.
SELECT MABH, TENBH
FROM LICHDIEN LD, CASI CS, TACGIA TG, BAIHAT BH
WHERE LD.MACS = CS.MACS AND
	  LD.MABH = BH.MABH AND
	  BH.MATG = TG.MATG AND
	  TG.HOTEN = 'Trịnh Công Sơn' AND
	  LD.NGAYDIEN = '26/09/2021'
ORDER BY MABH

-- 3b. Tìm tác giả đã sáng tác bài hát 'Nối vòng tay lớn' được ca sĩ 'Tạ Minh Tâm' trình bày trong đêm nhạc ngày 26/09/2021.
SELECT TG.MATG, TG.HOTEN 
FROM LICHDIEN LD, CASI CS, TACGIA TG, BAIHAT BH
WHERE LD.MACS = CS.MACS AND
	  LD.MABH = BH.MABH AND
	  BH.MATG = TG.MATG AND
	  BH.TENBH = 'Nối vòng tay lớn' AND
	  TG.HOTEN = 'Tạ Minh Tâm' AND
	  LD.NGAYDIEN = '26/09/2021'

-- 3c. Thống kê số lượng bài hát trình bày của từng ca sĩ trong đêm nhạc ngày '26/01/2021'
SELECT CS.MACS, CS.HOTEN, LD.COUNT(DISTINCT MABH) 
FROM LICHDIEN LD, CASI CS
WHERE LD.MACS = CS.MaCS AND
	  LD.NgayDien = '26/09/2021'

-- 3d. Liệt kê ca sĩ trong đêm nhạc ngày '22/12/2023' tại 'SVĐ Mỹ Đình Hà Nội' đã trình diễn bài hát của nhạc sĩ 'Văn Cao' nhưng không trình diễn bài hát của nhạc sĩ 'Hoàng Quý'
SELECT CS.HOTEN 
FROM LICHDIEN LD, CASI CS, TACGIA TG, BAIHAT BH
WHERE LD.MaCS = CS.MaCS AND
	  LD.MaBH = BH.MaBH AND
	  BH.MaTG = TG.MaTG AND
	  LD.NgayDien = '22/12/2023' AND
	  LD.TENSK = 'sân vận động Mỹ Đình Hà Nội' AND
	  TG.HOTEN = 'Văn Cao' AND
	  TG.HOTEN NOT IN (
						SELECT TG.HOTEN 
						FROM TACGIA 
						WHERE HOTEN = 'Hoàng Quý'
					  )

-- 3e. Tìm ca sĩ đã hát tất cả các bài hát do nhạc sĩ 'Trịnh Công Sơn' sáng tác sau năm 1990.
SELECT CS.HOTEN 
FROM LICHDIEN LD, CASI CS, TACGIA TG, BAIHAT BH
WHERE LD.MACS = CS.MACS AND
	  LD.MABH = BH.MABH AND
	  BH.MATG = TG.MATG AND
	  YEAR(BH.NGAYST) >= '1990' AND
	  TG.HOTEN = 'Trịnh Công Sơn' AND
GROUP BY CS.HOTEN
HAVING COUNT(DISTINCT LD.MABH) = (
									SELECT COUNT(BH.MABH) 
									FROM BAIHAT BH, TACGIA TG
									WHERE YEAR(BH.NGAYST) >= '1990' AND 
									      BH.MATG = TG.MATG AND 
										  TG.HOTEN = 'Trịnh Công Sơn'
							     )

-- 3f. Tìm ca sĩ đã hát nhiều bài hát nhất của nhạc sĩ 'Trịnh Công Sơn'
SELECT TENBH, CS.MACS, CS.HOTEN, COUNT(MABH) AS SOLUONGBH
FROM CASI CS, LICHDIEN LD, TACGIA TG, BAIHAT BH1
WHERE CS.MACS = LD.MACS AND
      LD.MABH = BH1.MABH AND
	  BH1.MATG = TG.MATG AND
	  TG.HOTEN = 'Trịnh Công Sơn'
GROUP BY CS.MACS, CS.HOTEN, TENBH
HAVING COUNT(MABH) >= ALL (
							SELECT COUNT(MABH) AS SOLUONGBH
							FROM CASI CS, LICHDIEN LD, TACGIA TG, BAIHAT BH2
							WHERE CS.MACS = LD.MACS AND
								  LD.MABH = BH2.MABH AND
								  BH2.MATG = TG.MATG AND
								  TG.HOTEN = 'Trịnh Công Sơn'
							GROUP BY CS.MACS, TENBH
							HAVING BH1.TENBH = BH2.TENBH
						   )

