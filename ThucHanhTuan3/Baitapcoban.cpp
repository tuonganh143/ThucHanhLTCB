#include <iostream>
#include <string>
using namespace std;
int timsonhonhat2so(int num1, int num2)
{
    if (num1 < num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

int timsonhonhat3so(int num1, int num2, int num3)
{
    int smallerNum = timsonhonhat2so(num1, num2);
    return timsonhonhat2so(smallerNum, num3);
}

// Hàm tính ước chung lớn nhất (GCD) của a và b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Hàm tính bội số chung nhỏ nhất (LCM) của a và b
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

double power(double x, int n)
{
    double result = 1.0;

    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result *= x;
        }

        x *= x;
        n /= 2;
    }

    return result;
}

// Hàm tính chu vi hình chữ nhật
double tinhChuVi(double chieuDai, double chieuRong)
{
    return 2 * (chieuDai + chieuRong);
}

// Hàm tính diện tích hình chữ nhật
double tinhDienTich(double chieuDai, double chieuRong)
{
    return chieuDai * chieuRong;
}

// Hàm vẽ hình chữ nhật bằng dấu *
void veHinhChuNhat(int chieuDai, int chieuRong)
{
    for (int i = 0; i < chieuRong; i++)
    {
        for (int j = 0; j < chieuDai; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
// Hàm kiểm tra số hoàn thiện
bool isPerfectNumber(int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum == number;
}

// Hàm in ra tất cả các số hoàn thiện nhỏ hơn số n
void printPerfectNumbers(int n)
{
    cout << "Cac so hoan thien nho hon " << n << " la: ";
    for (int i = 1; i < n; i++)
    {
        if (isPerfectNumber(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void DaoKiSo(int &n)
{
    int reversedNum = 0;
    while (n > 0)
    {
        int remainder = n % 10;                     // Lấy phần dư của n khi chia cho 10
        reversedNum = reversedNum * 10 + remainder; // Xây dựng số đảo ngược
        n /= 10;                                    // Loại bỏ chữ số cuối cùng của n
    }
    n = reversedNum; // Gán lại giá trị đã đảo vào n
}
int giaiThua(int n)
{
    if (n == 1)
        return 1;
    return n * giaiThua(n - 1);
}

int tinhC(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    else
    {
        int giaithuatu = giaiThua(n);
        int giaithuamau = giaiThua(k) * giaiThua(n - k);
        return giaithuatu / giaithuamau;
    }
}
void printOptimalSolution(int amount, int notes[], int numNotes)
{
    int count[numNotes] = {0};
    for (int i = 0; i < numNotes; i++)
    {
        if (amount >= notes[i])
        {
            count[i] = amount / notes[i];
            amount %= notes[i];
        }
    }

    cout << "So to cua tung loai tien: " << endl;
    for (int i = 0; i < numNotes; i++)
    {
        if (count[i] > 0)
        {
            cout << notes[i] << " VND: " << count[i] << " to" << endl;
        }
    }
}
int notes[] = {50000, 20000, 10000, 5000, 2000, 1000};
int main()
{
    cout << "BAI TAP CO BAN" << endl;
    cout << "Hay chon menu sau:" << endl;
    cout << "Nhap 1: De chon bai 1" << endl;
    cout << "Nhap 2: De chon bai 2" << endl;
    cout << "Nhap 3: De chon bai 3" << endl;
    cout << "Nhap 4: De chon bai 4" << endl;
    cout << "Nhap 5: De chon bai 5" << endl;
    cout << "Nhap 6: De chon bai 6" << endl;
    cout << "Nhap 7: De chon bai 7" << endl;
    cout << "Nhap 8: De chon bai 8" << endl;
    cout << "Nhap 9: De chon bai 9" << endl;
    cout << "Nhap 0: de thoat khoi ung dung" << endl;

    int control;
    cin >> control;

    switch (control)
    {
    case 1:
        int number1, number2, number3, snn;
        cout << "Nhap so dau tien: ";
        cin >> number1;
        cout << "Nhap so thu hai: ";
        cin >> number2;
        cout << "Nhap so thu ba: ";
        cin >> number3;
        snn = timsonhonhat3so(number1, number2, number3);
        cout << "So nho nhat trong 3 so: " << snn << endl;
        break;
    case 2:
        int a, b;

        // Nhập hai số nguyên dương a và b từ người dùng
        cout << "Nhap vao hai so nguyen duong a va b: ";
        cin >> a >> b;

        // Tính và hiển thị GCD và LCM của a và b
        cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << gcd(a, b) << endl;
        cout << "Boi so chung nho nhat cua " << a << " va " << b << " la: " << lcm(a, b) << endl;
        break;
    case 3:
        int n;
        cout << "Nhap n" << endl;
        cin >> n;
        cout << "Giai thua cua " << n << " la: " << giaiThua(n);
        return 0;
        break;
    case 4:
        double x, result;

        cout << "Nhap (x): " << endl;
        cin >> x;

        cout << "Nhap (n): " << endl;
        cin >> n;

        result = power(x, n);

        cout << "Ket qua: " << result << endl;
        break;
    case 5:
        int k;
        double C;
        cout << "Nhap n,k" << endl;
        cin >> n >> k;
        C = tinhC(n, k);
        cout << "Ket qua"
             << " = " << C << endl;
        break;
    case 6:
        double chieuDai, chieuRong, chuVi, dienTich;

        cout << "Nhap chieu dai hinh chu nhat: ";
        cin >> chieuDai;
        cout << "Nhap chieu rong hinh chu nhat: ";
        cin >> chieuRong;

        // Tính và hiển thị chu vi và diện tích hình chữ nhật
        chuVi = tinhChuVi(chieuDai, chieuRong);
        dienTich = tinhDienTich(chieuDai, chieuRong);

        cout << "Chu vi hinh chu nhat la: " << chuVi << endl;
        cout << "Dien tich hinh chu nhat la: " << dienTich << endl;

        // Vẽ hình chữ nhật bằng dấu *
        cout << "Ve hinh chu nhat:" << endl;
        veHinhChuNhat(chieuDai, chieuRong);
        break;
    case 7:
        cout << "Nhap mot so nguyen duong n: ";
        cin >> n;
        printPerfectNumbers(n);
        break;
    case 8:
        int amount, numNotes;
        cout << "Nhap so tien can doi: ";
        cin >> amount;

                numNotes = sizeof(notes) / sizeof(notes[0]);

        printOptimalSolution(amount, notes, numNotes);

        break;
    case 9:
        cout << "Nhap n: ";
        cin >> n;

        DaoKiSo(n);

        cout << "Sau khi dao gia tri cua n la: " << n << endl;
        break;
    default:
        cout << "Ban chon thoat khoi chuong trinh" << endl;
    }

    return 1;
}