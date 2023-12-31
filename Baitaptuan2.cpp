#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

// Hàm tính tiền thưởng dựa trên số ngày công
double tinhTienThuong(int soNgayCong, double luongCoBan)
{
    if (soNgayCong >= 25)
    {
        return 0.2 * luongCoBan;
    }
    else if (soNgayCong >= 22 && soNgayCong < 25)
    {
        return 0.1 * luongCoBan;
    }
    else
    {
        return 0.0;
    }
}

// Hàm tính tổng thu nhập của nhân viên
double tinhTongThuNhap(double luongCoBan, int soNgayCong, string chucVu)
{
    double tongThuNhap = luongCoBan * soNgayCong;

    // Tính phụ cấp theo chức vụ
    if (chucVu == "GD")
    {
        tongThuNhap += 250000;
    }
    else if (chucVu == "PGD")
    {
        tongThuNhap += 200000;
    }
    else if (chucVu == "TP")
    {
        tongThuNhap += 180000;
    }
    else if (chucVu == "NV")
    {
        tongThuNhap += 150000;
    }

    // Tính tiền thưởng
    double tienThuong = tinhTienThuong(soNgayCong, luongCoBan);
    tongThuNhap += tienThuong;

    return tongThuNhap;
}

int Nhap()
{
    int x;
    do
    {
        cin >> x;
        if (x < 0)
            cout << "Nhap sai, yeu cau nhap lai!";
    } while (x < 0);
    return x;
}

double Tinh(int n)
{
    float s = 0, t = 0;
    long p = 1;
    for (int i = 1; i <= n; i++)
    {
        t = t + i;
        p = p * i;
        s = s + (double)t / p;
    }
    return s;
}

bool kiemTraSoNguyenTo(int number)
{
    if (number <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}
void printASCII(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << static_cast<char>(i) << "\t" << i << endl;
    }
}
double Diemtrungbinh(double a, double b, double c)
{
    double dtb;
    dtb = (a + b + c) / 3;
    if (dtb >= 9.0)
    {
        cout << "Xuat Sac";
    }
    if (9.0 > dtb >= 8.0)
    {
        cout << "Gioi";
    }
    if (8.0 > dtb >= 6.5)
    {
        cout << "Kha";
    }
    if (6.5 > dtb >= 5.0)
    {
        cout << "Trung Binh";
    }
    if (5.0 > dtb >= 3.0)
    {
        cout << "Yeu";
    }
    if (3.5 > dtb)
    {
        cout << "Kem";
    }
}
long tinhTienPhong(int &ngaythue, char loaiPhong)
{
    int giaA, giaB, giaC;
    long tongTienPhong, giamgia;
    giaA = 250000;
    giaB = 200000;
    giaC = 150000;

    if (loaiPhong == 'A')
    {
        if (ngaythue > 12)
        {
            tongTienPhong = giaA * ngaythue;
            giamgia = tongTienPhong * 0.1;
            tongTienPhong = tongTienPhong - giamgia;
        }
        else
        {
            tongTienPhong = giaA * ngaythue;
        }
    }
    if (loaiPhong == 'B')
    {
        if (ngaythue > 12)
        {
            tongTienPhong = giaB * ngaythue;
            giamgia = tongTienPhong * 0.08;
            tongTienPhong = tongTienPhong - giamgia;
        }
        else
        {
            tongTienPhong = giaB * ngaythue;
        }
    }
    if (loaiPhong == 'C')
    {
        if (ngaythue > 12)
        {
            tongTienPhong = giaC * ngaythue;
            giamgia = tongTienPhong * 0.08;
            tongTienPhong = tongTienPhong - giamgia;
        }
        else
        {
            tongTienPhong = giaC * ngaythue;
        }
    }
    return tongTienPhong;
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year)
{
    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

bool isValidDate(int day, int month, int year)
{
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int maxDay = getDaysInMonth(month, year);
    return day <= maxDay;
}

void getNextDate(int &day, int &month, int &year)
{
    int maxDay = getDaysInMonth(month, year);

    if (day == maxDay)
    {
        day = 1;

        if (month == 12)
        {
            month = 1;
            year++;
        }
        else
        {
            month++;
        }
    }
    else
    {
        day++;
    }
}

void getPreviousDate(int &day, int &month, int &year)
{
    if (day == 1)
    {
        if (month == 1)
        {
            month = 12;
            year--;
        }
        else
        {
            month--;
        }

        int maxDay = getDaysInMonth(month, year);
        day = maxDay;
    }
    else
    {
        day--;
    }
}

void Rutien(int amount)
{
    int count100000 = 0, count50000 = 0, count20000 = 0, count10000 = 0;

    if (amount % 10000 != 0)
    {
        cout << "So tien rut khong chia het cho 10.000 vui long nhap lai.\n";
        return;
    }

    while (amount >= 100000)
    {
        amount -= 100000;
        count100000++;
    }

    while (amount >= 50000)
    {
        amount -= 50000;
        count50000++;
    }

    while (amount >= 20000)
    {
        amount -= 20000;
        count20000++;
    }

    while (amount >= 10000)
    {
        amount -= 10000;
        count10000++;
    }

    cout << "So to tien can rut:\n";
    cout << "Menh gia 100,000: " << count100000 << " to\n";
    cout << "Menh gia 50,000: " << count50000 << " to\n";
    cout << "Menh gia 20,000: " << count20000 << " to\n";
    cout << "Menh gia 10,000: " << count10000 << " to\n";
}

int pageSize = 10; // Số lượng ký tự trên mỗi trang
int currentPage = 1;
int totalPages = 8; // Tổng số trang
int soDaoNguoc = 0;
int count = 0; // Biến đếm số lượng chữ số
int sum = 0;   // Biến tổng các chữ số
const int gia_km_dau = 15000;
const int gia_km_2_5 = 13500;
const int gia_km_tu_6 = 11000;
const int giam_gia_km_lon = 120;
const double phan_tram_giam_gia = 0.1;
int tong_tien = 0;
string maNhanVien, hoTen, chucVu;
double luongCoBan;
int soNgayCong;
double tongThuNhap;
int main()
{
    cout << "-------------BAI TAP CO BAN-------------" << endl;
    cout << "Hay chon menu sau:" << endl;
    cout << "Nhap 1: Bai 1" << endl;
    cout << "Nhap 2: Bai 2" << endl;
    cout << "Nhap 3: Bai 3" << endl;
    cout << "Nhap 4: Bai 4" << endl;
    cout << "Nhap 5: Bai 5" << endl;
    cout << "Nhap 6: Bai 6" << endl;
    cout << "Nhap 7: Bai 7" << endl;
    cout << "Nhap 8: Bai 8" << endl;
    cout << "Nhap 9: Bai 9" << endl;
    cout << "Nhap 10: Bai 10" << endl;
    cout << "-------------BAI TAP UNG DUNG-------------" << endl;
    cout << "Nhap 11: Bai 1" << endl;
    cout << "Nhap 12: Bai 2" << endl;
    cout << "Nhap 13: Bai 3" << endl;
    cout << "Nhap 14: Bai 4" << endl;
    cout << "Nhap 15: Bai 5" << endl;
    cout << "Nhap 16: Bai 6" << endl;
    cout << "Nhap 0: de thoat khoi ung dung" << endl;

    int control;
    cin >> control;

    switch (control)
    {
    case 1:
        int number;
        cout << "Nhap so tu 10 den 99: ";
        cin >> number;

        // Kiểm tra điều kiện số nhập vào
        if (number >= 10 && number <= 99)
        {
            int soDau = number / 10;  // Chữ số hàng chục
            int soCuoi = number % 10; // Chữ số hàng đơn vị

            // Kiểm tra điều kiện tích của hai chữ số bằng 2 lần tổng của hai chữ số
            if (soDau * soCuoi == 2 * (soDau + soCuoi))
            {
                cout << "So hop le!" << endl;
            }
            else
            {
                cout << "So khong hop le!" << endl;
            }
        }
        else
        {
            cout << "So khong hop le!" << endl;
        }
        return 0;
        break;
    case 2:
        int n;
        cout << "Nhap so nguyen n: ";
        cin >> n;
        cout << "Cac so nguyen to nho hon " << n << " la: ";
        for (int i = 2; i < n; i++)
        {
            if (kiemTraSoNguyenTo(i))
            {
                cout << i << " ";
            }
        }
        cout << endl;
        break;
    case 3:
        while (currentPage <= totalPages)
        {
            system("cls"); // Xóa màn hình (cho Windows)

            cout << "Bang ma ASCII - Trang" << currentPage << endl;
            cout << "-------------------------" << endl;
            cout << "Ky tu   Ma" << endl;
            int start = (currentPage - 1) * pageSize;
            int end = currentPage * pageSize - 1;
            printASCII(start, end);

            cout << endl;
            cout << "Nhan Enter de xem trang tiep theo...";
            cin.ignore(); // Đợi người dùng nhấn Enter để chuyển trang
            currentPage++;
        }
        return 0;
        break;
    case 4:

        cout << "Nhap mot so nguyen duong: ";
        cin >> n;

        while (n > 0)
        {
            int digit = n % 10;
            soDaoNguoc = soDaoNguoc * 10 + digit;
            n /= 10;
        }

        cout << "So dao nguoc  " << n << " la: " << soDaoNguoc << endl;
        return 0;
        break;
    case 5:
        cout << "Nhap mot so nguyen duong: ";
        cin >> n;

        // Lặp qua từng chữ số của số nguyên dương n
        while (n > 0)
        {
            int digit = n % 10; // Lấy chữ số cuối cùng
            count++;            // Tăng biến đếm
            sum += digit;       // Cộng chữ số vào tổng

            n /= 10; // Loại bỏ chữ số cuối cùng
        }

        cout << "So luong cac chu so: " << count << endl;
        cout << "Tong cac chu so: " << sum << endl;

        return 0;
        break;
    case 6:
        int giatu0_7, giatu7_17, giatu17_24, thoigian;
        float tongTien;
        float giam;
        giatu0_7 = 18000;
        giatu7_17 = 24000;
        giatu17_24 = 21000;
        tongTien = 0;
        int gioBd, gioKt;
        cout << "Nhap vao gio bat dau: ";
        cin >> gioBd;
        cout << "Nhap vao gio ke thuc: ";
        cin >> gioKt;
        thoigian = gioKt - gioBd;
        cout << " Thoi gian ban truy cap la : " << thoigian << endl;
        if (gioBd >= 7 && gioKt <= 17)
        {
            if (thoigian > 6)
            {
                tongTien = giatu7_17 * thoigian;
                giam = tongTien * 0.1;
                tongTien = tongTien - giam;
            }
            else
            {
                tongTien = giatu7_17 * thoigian;
            }
        }
        if (gioBd >= 17 && gioKt <= 24)
        {
            if (thoigian > 4)
            {
                tongTien = giatu17_24 * thoigian;
                giam = tongTien * 0.12;
                tongTien = tongTien - giam;
            }
            else
            {
                tongTien = giatu17_24 * thoigian;
            }
        }
        if (gioBd >= 0 && gioKt <= 7)
        {
            if (thoigian > 7)
            {
                tongTien = giatu0_7 * thoigian;
                giam = tongTien * 0.15;
                tongTien = tongTien - giam;
            }
            else
            {
                tongTien = giatu0_7 * thoigian;
            }
        }
        cout << "Tong tien truy cap Internet : " << tongTien;

        break;
    case 7:
        int ngaythue;
        char loaiphong;
        long tongtienphong;
        cout << "Nhap ngay thue" << endl;
        cin >> ngaythue;
        cout << "chon loai phong A B C" << endl;
        cin >> loaiphong;
        tongtienphong = tinhTienPhong(ngaythue, loaiphong);
        cout << "Tong tien phong:" << tongtienphong << endl;
        break;
    case 8:
        int day, month, year;

        cout << "Nhap vao ngay: ";
        cin >> day;

        cout << "Nhap vao thang: ";
        cin >> month;

        cout << "Nhap vao nam: ";
        cin >> year;

        if (isValidDate(day, month, year))
        {
            cout << "Ngay thang hop le!" << endl;

            int daysInMonth = getDaysInMonth(month, year);
            cout << "Thang " << month << " nam " << year << " co " << daysInMonth << " ngay." << endl;

            int nextDay = day;
            int nextMonth = month;
            int nextYear = year;
            getNextDate(nextDay, nextMonth, nextYear);
            cout << "Ngay tiep theo: " << nextDay << "/" << nextMonth << "/" << nextYear << endl;

            int previousDay = day;
            int previousMonth = month;
            int previousYear = year;
            getPreviousDate(previousDay, previousMonth, previousYear);
            cout << "Ngay truoc do: " << previousDay << "/" << previousMonth << "/" << previousYear << endl;
        }
        else
        {
            cout << "Ngay thang khong hop le!" << endl;
        }

        return 0;
        break;
    case 9:
        int so_km;
        cout << "Nhap vao so km: ";
        cin >> so_km;

        if (so_km <= 0)
        {
            cout << "So km khong hop le!";
        }
        else if (so_km == 1)
        {
            tong_tien = gia_km_dau;
        }
        else if (so_km >= 2 && so_km <= 5)
        {
            tong_tien = gia_km_dau + (so_km - 1) * gia_km_2_5;
        }
        else if (so_km >= 6)
        {
            tong_tien = gia_km_dau + 4 * gia_km_2_5 + (so_km - 5) * gia_km_tu_6;
        }

        if (so_km > giam_gia_km_lon)
        {
            double giam_gia = tong_tien * phan_tram_giam_gia;
            tong_tien -= giam_gia;
        }

        cout << "Tong tien la: " << tong_tien << " VND";

        return 0;
        break;
    case 10:
        char ten[100];
        double toan, ly, hoa;
        cout << "Nhap ten hoc sinh" << endl;
        cin >> ten;
        cout << "Nhap diem toan, ly, hoa" << endl;
        cin >> toan >> ly >> hoa;
        cout << "Hoc luc cua hoc sinh " << ten << endl;
        Diemtrungbinh(toan, ly, hoa);
        break;
    case 11:
        while (currentPage <= totalPages)
        {
            system("cls"); // Xóa màn hình (cho Windows)

            cout << "Bang ma ASCII - Trang" << currentPage << endl;
            cout << "-------------------------" << endl;
            cout << "Ky tu   Ma" << endl;
            int start = (currentPage - 1) * pageSize;
            int end = currentPage * pageSize - 1;
            printASCII(start, end);

            cout << endl;
            cout << "Nhan Enter de xem trang tiep theo...";
            cin.ignore(); // Đợi người dùng nhấn Enter để chuyển trang
            currentPage++;
        }
        return 0;
        break;
    case 12:

        cout << "Nhap so nguyen n: ";
        n = Nhap();
        cout << "Ket qua la: " << Tinh(n) << endl;

        return 0;
        break;
    case 13:
        int amount;
        cout << "Nhap so tien can rut(chia het cho 10.000): ";
        cin >> amount;

        Rutien(amount);

        return 0;
        break;
    case 14:
        // Nhập thông tin nhân viên
        cout << "Nhap ma nhan vien: ";
        cin >> maNhanVien;

        cout << "Nhap ho va ten: ";
        cin.ignore();
        getline(cin, hoTen);

        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;

        cout << "Nhap so ngay cong: ";
        cin >> soNgayCong;

        cout << "Nhap chuc vu (GD/PGD/TP/NV): ";
        cin >> chucVu;

        // Tính toán thu nhập
        tongThuNhap = tinhTongThuNhap(luongCoBan, soNgayCong, chucVu);

        // Hiển thị thông tin và thu nhập của nhân viên
        cout << "\nThong tin nhan vien:\n";
        cout << maNhanVien << " ";
        cout << hoTen << " ";
        cout << luongCoBan << " ";
        cout << soNgayCong << " ";
        cout << chucVu << " ";
        cout << tongThuNhap << " ";

        return 0;
        break;
    case 15:
        break;
    case 16:
        break;
    default:
        cout << "Ban chon thoat khoi chuong trinh" << endl;
    }

    return 1;
}
