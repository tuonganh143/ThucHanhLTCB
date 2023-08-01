#include <iostream>
using namespace std;
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
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth = getDaysInMonth(month, year);
    return day <= daysInMonth;
}

void getNextDate(int &day, int &month, int &year)
{
    int daysInMonth = getDaysInMonth(month, year);

    if (day < daysInMonth)
    {
        day++;
    }
    else
    {
        day = 1;

        if (month < 12)
        {
            month++;
        }
        else
        {
            month = 1;
            year++;
        }
    }
}

void getPreviousDate(int &day, int &month, int &year)
{
    if (day > 1)
    {
        day--;
    }
    else
    {
        if (month > 1)
        {
            month--;
        }
        else
        {
            month = 12;
            year--;
        }
    }
    int daysInMonth = getDaysInMonth(month, year);
    day = daysInMonth;
}
void printSportsEvents(int startYear)
{
    for (int year = startYear; year <= 2023; year++)
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            cout << "Nam " << year << ": Olympic va Euro" << endl;
        }
        if ((year - 1990) % 4 == 0 && year >= 1990)
        {
            cout << "Nam " << year << ": World Cup" << endl;
        }
        if ((year - 1995) % 2 == 0 && year >= 1995)
        {
            cout << "Nam " << year << ": SeaGame" << endl;
        }
        if ((year - 1996) % 2 == 0 && year >= 1996)
        {
            cout << "Nam " << year << ": Tiger Cup" << endl;
        }
    }
}
void printNumberString(int digit)
{
    switch (digit)
    {
    case 0:
        cout << "Khong" << endl;
        break;
    case 1:
        cout << "Mot" << endl;
        break;
    case 2:
        cout << "Hai" << endl;
        break;
    case 3:
        cout << "Ba" << endl;
        break;
    case 4:
        cout << "Bon" << endl;
        break;
    case 5:
        cout << "Nam" << endl;
        break;
    case 6:
        cout << "Sau" << endl;
        break;
    case 7:
        cout << "Bay" << endl;
        break;
    case 8:
        cout << "Tam" << endl;
        break;
    case 9:
        cout << "Chin" << endl;
        break;
    default:
        cout << "So nhap khong dung!";
    }
}
string docSo(int n)
{
    string units[] = {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    string tens[] = {"", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "ssu muoi", "bay muoi", "tam muoi", "chin muoi"};
    string hundreds[] = {"", "mot tram", "hai tram", "ba tram", "bon tram", "nam tram", "sau tram", "bay tram", "tam tram", "chin tram"};

    string result;
    int unit = n % 10;
    int ten = (n / 10) % 10;
    int hundred = n / 100;

    if (hundred > 0)
    {
        result += hundreds[hundred] + " ";
    }

    if (ten > 1)
    {
        result += tens[ten] + " ";
        if (unit > 0)
        {
            result += units[unit];
        }
    }
    else if (ten == 1)
    {
        result += "mười ";
        if (unit > 0)
        {
            result += units[unit];
        }
    }
    else
    {
        if (unit > 0)
        {
            result += units[unit];
        }
    }

    return result;
}
string readNumber(int num)
{
    string result;

    // Mảng lưu các chữ số từ 0 đến 19
    string ones[] = {"", "mot ", "hai ", "ba ", "bon ", "nam ", "sau ", "bay ", "tam ", "chin ", "muoi ",
                     "muoi mot ", "muoi hai ", "muoi ba ", "muoi bon ", "muoi nam ", "muoi sau ",
                     "muoi bay ", "muoi tam ", "muoi chin "};

    // Mảng lưu các chữ số hàng chục
    string tens[] = {"", "", "hai muoi ", "ba muoi ", "bon muoi ", "nam muoi ", "sau muoi ",
                     "bay muoi ", "tam muoi ", "chin muoi "};

    // Mảng lưu các chữ số hàng trăm
    string hundreds[] = {"", "một tram ", "hai tram ", "ba tram ", "bon tram ", "nam tram ",
                         "sau tram ", "bay tram ", "tam tram ", "chin tram "};

    if (num == 0)
    {
        result = "khong";
    }
    else if (num < 20)
    {
        result = ones[num];
    }
    else if (num < 100)
    {
        result = tens[num / 10] + ones[num % 10];
    }
    else if (num < 1000)
    {
        result = hundreds[num / 100] + readNumber(num % 100);
    }
    else if (num < 1000000)
    {
        result = readNumber(num / 1000) + "nghin " + readNumber(num % 1000);
    }
    else
    {
        result = "So vuot qua gioi han";
    }

    return result;
}
int timGiaTriLonNhat(int arr[], int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
int timViTriGiaTriLonNhat(int arr[], int n)
{
    int maxVal = arr[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}
void chenGiaTriTruocGiaTriLonNhat(int arr[], int &n, int m)
{
    // lấy vị trí của max trước
    int maxIndex = timViTriGiaTriLonNhat(arr, n);

    for (int i = n - 1; i >= maxIndex; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[maxIndex] = m;
    n++;
}
void sapXepPhanTuAmVeDauDay(int arr[], int &n)
{
    int left = 0;      // Con trỏ trỏ tới phần tử đầu tiên của dãy
    int right = n - 1; // Con trỏ trỏ tới phần tử cuối cùng của dãy

    while (left < right)
    {
        // Di chuyển con trỏ left sang phải cho đến khi gặp phần tử dương hoặc bằng 0
        while (left < right && arr[left] < 0)
        {
            left++;
        }

        // Di chuyển con trỏ right sang trái cho đến khi gặp phần tử âm
        while (left < right && arr[right] >= 0)
        {
            right--;
        }

        // Nếu left < right, tức là tìm thấy cặp phần tử cần đổi chỗ
        if (left < right)
        {
            // Đổi chỗ hai phần tử
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
}
// Function to standardize a phone number
string kichthuocsophone(const string &input)
{
    string result;

    // Remove all non-digit characters from the input string
    for (char c : input)
    {
        if (isdigit(c))
        {
            result += c;
        }
    }

    return result;
}
string s;
int main()
{
    cout << "Bai Tap Ung dung" << endl;
    cout << "Hay chon menu sau:" << endl;
    cout << "Nhap 1: De xem bai 1" << endl;
    cout << "Nhap 2: De xem bai 2" << endl;
    cout << "Nhap 3: De xem bai 3" << endl;
    cout << "Nhap 4: De xem bai 4" << endl;
    cout << "Nhap 5: De xem bai 5" << endl;
    cout << "Nhap 6: De xem bai 6" << endl;
    cout << "Nhap 7: De xem bai 7" << endl;
    cout << "Nhap 0: de thoat khoi ung dung" << endl;

    int control;
    cin >> control;

    switch (control)
    {
    case 1:

        break;
    case 2:
        int n;
        int arr[100];
        int maxVal;
        cout << "Nhap so luong phan tu cua day: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "So luong phan tu khong hop le!" << endl;
            return 1;
        }

        cout << "Nhap cac phan tu cua day: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Day vua nhap : ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        maxVal = timGiaTriLonNhat(arr, n);
        cout << "Gia tri lon nhat cua day la: " << maxVal << endl;
        int m;
        cout << "Nhap gia tri m muon chen: ";
        cin >> m;
        chenGiaTriTruocGiaTriLonNhat(arr, n, m);
        cout << "Day sau khi chen gia tri m la: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        sapXepPhanTuAmVeDauDay(arr, n);
        cout << "Day sau khi sap xep phan tu am ra dau day : ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        break;
    case 3:

        break;
    case 4:
        int T;
        cout << "nhap t(so bo test)" << endl;
        cin >> T;
        cin.ignore(); // Ignore the newline character after reading T

        while (T--)
        {
            string sdt;
            getline(cin, sdt);

            // Standardize the phone number
            string kichthuoc = kichthuocsophone(sdt);

            // Output the standardized phone number
            cout << kichthuoc << endl;
        }
        break;
    case 5:
        int digit;

        cout << "Nhap mot so don vi: " << endl;
        cin >> digit;

        printNumberString(digit);
        int number;
        cout << "Nhap vao mot so nguyen co 3 chu so: ";
        cin >> number;

        if (number >= 100 && number <= 999)
        {
            string result = docSo(number);
            cout << "Chuoi doc so cua " << number << " la: " << result << endl;
        }
        else
        {
            cout << "Vui long nhap mot so nguyen co 3 chu so!" << endl;
        }
        cout << "Nhap so nguyen nho hon 1000000: ";
        cin >> n;

        s = readNumber(n);
        cout << "Chuoi " << n << " la: " << s << endl;

        break;
    case 6:
        int startYear;

        cout << "Nhap nam bat dau: ";
        cin >> startYear;

        if (startYear >= 1975 && startYear <= 2023)
        {
            printSportsEvents(startYear);
        }
        else
        {
            cout << "Nam khong hop le!" << endl;
        }

        break;
    case 7:
        int day, month, year;

        cout << "Nhap ngay: ";
        cin >> day;

        cout << "Nhap thang: ";
        cin >> month;

        cout << "Nhap nam: ";
        cin >> year;

        if (isValidDate(day, month, year))
        {
            cout << "Ngay thang nhap hop le.\n";

            int daysInMonth = getDaysInMonth(month, year);
            cout << "Thang " << month << " co " << daysInMonth << " ngay.\n";

            cout << "Ngay hom sau la: ";
            getNextDate(day, month, year);
            cout << day << "/" << month << "/" << year << "\n";

            cout << "Ngay hom truoc la: ";
            getPreviousDate(day, month, year);
            cout << day << "/" << month << "/" << year << "\n";
        }
        else
        {
            cout << "Ngay thang nhap khong hop le.\n";
        }

        break;
    default:
        cout << "Ban chon thoat khoi chuong trinh" << endl;
    }

    return 1;
}