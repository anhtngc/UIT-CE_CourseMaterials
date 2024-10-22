#include "Mang1Chieu.h"

//Thiết lập không tham số
Mang1Chieu::Mang1Chieu()
{
	size = 0;
	arr = NULL;
}

//Thiết lập truyền tham số n
Mang1Chieu::Mang1Chieu(int size)
{
	cout << "Nhap so phan tu cua mang: ";
	cin >> size;
	if (size <= 0)
	{
		do
		{
			cout << "Nhap lai so phan tu (> 0) cua mang: ";
			cin >> size;
		} while (size <= 0);
	}
	this->size = size;
	arr = new int[this->size];
	for (int i = 0; i < this->size; i++) {
		arr[i] = 0;
	}
}

//Thiết lập sao chép
Mang1Chieu::Mang1Chieu(const Mang1Chieu& M1C)
{
	size = M1C.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = M1C.arr[i];
	}
}

//Hàm hủy
Mang1Chieu::~Mang1Chieu()
{
	if (arr != NULL)
	{
		size = 0;
		delete[]arr;
		arr = NULL;
		cout << "Da huy mang 1 chieu\n";
	}
}

int Mang1Chieu::GetSize()
{
	return size;
}

int* Mang1Chieu::GetArray()
{
	return arr;
}

//Phương thức nạp chồng toán tử gán
Mang1Chieu& Mang1Chieu::operator=(const Mang1Chieu& M1C)
{
	if (arr != NULL) {
		this->~Mang1Chieu();
	}
	size = M1C.size;
	arr = new int[size];
	for (int i = 0; i < size; i++){
		arr[i] = M1C.arr[i];
	}
	return *this;
}

//Nhập các giá trị phần tử mảng
istream& operator>>(istream& in, Mang1Chieu& M1C)
{
	if (M1C.arr != NULL) {
		M1C.~Mang1Chieu();
	}
	cout << "Nhap so phan tu cua mang: ";
	in >> M1C.size;
	if (M1C.size <= 0)
	{
		do
		{
			cout << "Nhap lai so phan tu (> 0) cua mang: ";
			in >> M1C.size;
		} while (M1C.size);
	}
	M1C.arr = new int[M1C.size];
	for (int i = 0; i < M1C.size; i++)
	{
		cout << "a[" << i << "] = ";
		in >> M1C.arr[i];
	}
	return in;
}

//Xuất giá trị các phần tử mảng
ostream& operator<<(ostream& out, Mang1Chieu& M1C)
{
	if (M1C.arr == NULL) {
		out << "Mang rong\n";
	}
	else
	{
		for (int i = 0; i < M1C.size; i++)
		{
			out << M1C.arr[i] << "  ";
		}
		out << endl;
	}
	return out;
}

//Liệt kê số nguyên tố trong mảng
bool Mang1Chieu::KiemTraSoNguyenTo(int n)
{
	if (n < 2)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return false;
		}
	}
	return true;
}

void Mang1Chieu::LietKeSoNguyenTo()
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (KiemTraSoNguyenTo(arr[i]) == false)
			count++;
	}
	if (count == size) {
		cout << "Khong ton tai so nguyen to trong mang.";
	}
	else
	{
		cout << "Cac so nguyen to trong mang la: ";
		for (int i = 0; i < size; i++)
		{
			if (KiemTraSoNguyenTo(arr[i]) == true)
				cout << arr[i] << "  ";
		}
	}
	cout << endl;
}

//Đếm số lượng số chính phương trong mảng
void Mang1Chieu::DemSoChinhPhuong()
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (sqrt(arr[i]) == floor(sqrt(arr[i])) && arr[i] > 0)
			count++;
	}
	cout << "Mang da nhap co " << count << " so chinh phuong." << endl;
}

//Tính tổng giá trị các phần tử là số hoàn thiện trong mảng
bool Mang1Chieu::KiemTraSoHoanThien(int n)
{
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0 && n != i)
			sum += i;
	}
	if (sum == n)
		return true;
	return false;
}

void Mang1Chieu::TinhTongSoHoanThien()
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (KiemTraSoHoanThien(arr[i]) == false)
			count++;
	}
	if (count == size) {
		cout << "Khong ton tai so hoan thien trong mang.";
	}
	else
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (KiemTraSoHoanThien(arr[i]) == true)
				sum += arr[i];
		}
		cout << "Tong cac phan tu hoan thien trong mang la: " << sum;
	}
	cout << endl;
}

//Tính tổng trung bình cộng các phần tử đối xứng trong mảng
bool Mang1Chieu::KiemTraDoiXung(int n)
{
	if (n < 0) {
		return false;
	}
	int sodaonguoc = 0;
	int sobandau = n;
	while (sobandau > 0)
	{
		sodaonguoc = sodaonguoc * 10 + sobandau % 10;
		sobandau /= 10;
	}
	return n == sodaonguoc;
}

void Mang1Chieu::TinhTrungBinhSoDoiXung()
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (KiemTraDoiXung(arr[i]) == true)
		{
			sum += arr[i];
			count++;
		}
	}
	if (count == 0) {
		cout << "Khong ton tai so doi xung trong mang." << endl;
	}
	else {
		cout << "Trung binh cong cac phan tu doi xung trong mang la: " << static_cast<double>(sum) / count << endl;
	}
}

//Kiểm tra mảng có toàn phần tử lẻ hay không?
void Mang1Chieu::KiemTraChanLe()
{
	int even = 0;
	int odd = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0) {
			even++;
		}
		else odd++;
	}
	if (even == size) {
		cout << "Cac phan tu trong mang deu la so chan." << endl;
	}
	else if (odd == size) {
		cout << "Cac phan tu trong mang deu la so le." << endl;
	}
	else {
		cout << "Mang da nhap khong chan cung khong le." << endl;
	}
}

//Tìm giá trị phần tử chẵn nhỏ nhất trong mảng
void Mang1Chieu::TimPhanTuChanNhoNhat()
{
	int minEven = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] % 2 == 0 && arr[i] < minEven) {
			minEven = arr[i];
		}
	}
	if (minEven % 2 == 0) {
		cout << "So chan nho nhat trong mang la: " << minEven << endl;
	}
	else {
		cout << "Khong ton tai so chan trong mang." << endl;
	}
}

//Sắp xếp mảng tăng dần
void Mang1Chieu::Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Mang1Chieu::SapXepTangDan()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j]) {
				Swap(arr[i], arr[j]);
			}
		}
	}
}

//Sắp xếp mảng giảm dần
void Mang1Chieu::SapXepGiamDan()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] < arr[j]) {
				Swap(arr[i], arr[j]);
			}
		}
	}
}

//Xóa phần tử tại vị trí bất kì
void Mang1Chieu::XoaPhanTu(int x)
{
	if (x < 0 || x >= size) {
		cout << "Khong tim thay vi tri can xoa." << endl;
		return;
	}
	for (int i = x; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
	cout << "Da xoa phan tu tai vi tri " << x << " trong mang." << endl;
}

//Thêm phần tử tại vị trí bất kì
void Mang1Chieu::ThemPhanTu(int x, int vitri)
{
	int i;
	for (i = size - 1; i > vitri; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[vitri] = x;
	cout << "Phan tu " << x << " da duoc them vao vi tri " << vitri << " cua mang." << endl;
}

//Tìm kiếm phần tử có giá trị bất kì
bool Mang1Chieu::TimPhanTuX(int x)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == x)
		{
			return true;
		}
	}
	return false;
}

void Mang1Chieu::DemViTriXXuatHien(int x)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Khong tim thay phan tu " << x << " trong mang.";
	}
	else
	{
		cout << "Da tim thay phan tu " << x << " o vi tri: ";
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == x) {
				cout << "a[" << i << "]" << "   ";
			}
		}
	}
	cout << endl;
}

//Tạo mảng ngẫu nhiên
void Mang1Chieu::TaoMangNgauNhien()
{
	cout << "Nhap so phan tu cua mang: ";
	cin >> size;
	if (size <= 0)
	{
		do
		{
			cout << "Nhap lai so phan tu (> 0) cua mang: ";
			cin >> size;
		} while (size <= 0);
	}
	this->size = size;
	arr = new int[this->size];
	srand((unsigned)time(NULL));
	for (int i = 0; i < this->size; i++) {
		arr[i] = rand() % 100 - rand() % 100;
	}
	cout << "Da tao mot mang ngau nhien gom " << size << " phan tu, hay chon lenh xuat mang de xem." << endl;
}