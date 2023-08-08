#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void sortByAscending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void performTask()
{
    int n;
    cout << "Nhap so phan tu cua mang (n <= 100): ";
    cin >> n;
    int arr[n];

    // Nhap mang
    cout << "Nhap cac phan tu cua mang:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    // Tinh trung binh cong cua so duong va so am
    int sumPositive = 0;
    int countPositive = 0;
    int sumNegative = 0;
    int countNegative = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            sumPositive += arr[i];
            countPositive++;
        }
        else if (arr[i] < 0)
        {
            sumNegative += arr[i];
            countNegative++;
        }
    }

    float averagePositive = (countPositive != 0) ? (float)sumPositive / countPositive : 0;
    float averageNegative = (countNegative != 0) ? (float)sumNegative / countNegative : 0;

    cout << "Trung binh cong cua cac so duong: " << averagePositive << endl;
    cout << "Trung binh cong cua cac so am: " << averageNegative << endl;

    // In ra cac so nguyen to trong mang
    cout << "Cac so nguyen to trong mang: ";
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    // Sap xep cac so chan trong mang theo thu tu tang dan
    sortByAscending(arr, n);
    cout << "Mang sau khi sap xep cac so chan tang dan: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void findAndDelete(vector<int> &arr, int x)
{
    bool found = false;
    int count = 0;

    // Tìm kiếm và đếm số lần x xuất hiện trong mảng
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            count++;
            found = true;
        }
    }

    // Xóa toàn bộ các phần tử x khỏi mảng
    if (found)
    {
        arr.erase(remove(arr.begin(), arr.end(), x), arr.end());
    }

    // Hiển thị thông báo và số lần x xuất hiện
    if (found)
    {
        cout << "Phan tu " << x << " co ton tai trong mang." << endl;
        cout << "So lan xuat hien cua " << x << " la " << count << endl;
    }
    else
    {
        cout << "Phan tu " << x << " khong ton tai trong mang." << endl;
    }
}

vector<int> arr;
int n, x;

void sapXepTangDan(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sapXepGiamDan(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                // Hoán đổi giá trị của hai phần tử
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void chenPhanTu(int arr[], int &n, int x)
{
    int i = n - 1;
    while (i >= 0 && arr[i] < x)
    {
        arr[i + 1] = arr[i]; // Dịch phần tử sang phải
        i--;
    }
    arr[i + 1] = x; // Chèn phần tử x vào đúng vị trí
    n++;
}

void inMang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void nhapMang(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> A[i];
    }
}

void xuatMang(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void huyPhanTu(int A[], int &size, int p, int n)
{
    // Hủy n phần tử trong mảng A bắt đầu từ vị trí p
    if (p >= 0 && p < size)
    {
        for (int i = p; i < size - n; i++)
        {
            A[i] = A[i + n];
        }
        size -= n;
    }
}
const int N = 100; // Kích thước của mảng A

// Hàm chèn mảng B vào mảng A tại vị trí p
void chenMang(int mangA[], int mangB[], int p, int n)
{
    for (int i = 0; i < n; i++)
    {
        mangA[p + i] = mangB[i];
    }
}

int B[N];

void inputArray(vector<float> &mang)
{
    int n;
    cout << "Nhap so luong phan tu mang: ";
    cin >> n;

    cout << "Nhap cac phan tu mang:\n";
    for (int i = 0; i < n; i++)
    {
        float element;
        cin >> element;
        mang.push_back(element);
    }
}

void sortArray(vector<float> &mang)
{
    sort(mang.begin(), mang.end());
}

void printMostFrequentElement(const vector<float> &mang)
{
    vector<int> count(mang.size(), 0);

    for (int i = 0; i < mang.size(); i++)
    {
        for (int j = i + 1; j < mang.size(); j++)
        {
            if (mang[i] == mang[j])
            {
                count[i]++;
            }
        }
    }

    int maxCount = *max_element(count.begin(), count.end());
    cout << "Phan tu xuat hien nhieu nhat: ";
    for (int i = 0; i < mang.size(); i++)
    {
        if (count[i] == maxCount)
        {
            cout << mang[i] << " ";
        }
    }
    cout << endl;
}

void searchOrInsert(vector<float> &mang, float x)
{
    int pos = -1;
    for (int i = 0; i < mang.size(); i++)
    {
        if (mang[i] == x)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        cout << "Phan tu " << x << " xuat hien tai vi tri " << pos << endl;
    }
    else
    {
        int insertPos = 0;
        while (insertPos < mang.size() && mang[insertPos] < x)
        {
            insertPos++;
        }
        mang.insert(mang.begin() + insertPos, x);
        cout << "Da chen " << x << " vao mang sao cho mang van tang." << endl;
    }
}

vector<float> mang;

int main()
{
    cout << "BAI TAP CO BAN" << endl;
    cout << "Hay chon menu sau:" << endl;
    cout << "Nhap 1: de xem bai 1" << endl;
    cout << "Nhap 2: de xem bai 2" << endl;
    cout << "Nhap 3: de xem bai 3" << endl;
    cout << "Nhap 4: de xem bai 4" << endl;
    cout << "Nhap 5: de xem bai 5" << endl;
    cout << "Nhap 6: de xem bai 6" << endl;
    cout << "Nhap 7: de xem bai 7" << endl;
    cout << "Nhap 8: de xem bai 8" << endl;
    cout << "Nhap 9: de xem bai 9" << endl;
    cout << "Nhap 10: de xem bai 10" << endl;
    cout << "Nhap 0: de thoat khoi ung dung" << endl;

    int control;
    cin >> control;

    switch (control)
    {
    case 1:
        performTask();
        break;
    case 2:

        // Nhập kích thước và các phần tử của mảng
        cout << "Nhap vao so phan tu cua mang: ";
        cin >> n;

        cout << "Nhap vao cac phan tu cua mang: ";
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        // Nhập giá trị cần tìm và xóa
        cout << "Nhap vao so can tim va xoa: ";
        cin >> x;

        // Gọi hàm để tìm và xóa
        findAndDelete(arr, x);

        // Hiển thị mảng sau khi xóa
        cout << "Mang sau khi xoa: ";
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }

        break;
    case 3:
        cout << "Nhap so phan tu cua mang: ";
        cin >> n;

        int arr[100];
        cout << "Nhap cac phan tu cua mang: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Mang ban dau: ";
        inMang(arr, n);

        sapXepGiamDan(arr, n);

        cout << "Mang sau khi sap xep giam dan: ";
        inMang(arr, n);

        cout << "Nhap so nguyen x: ";
        cin >> x;

        chenPhanTu(arr, n, x);

        cout << "Mang sau khi chen phan tu " << x << ": ";
        inMang(arr, n);

        break;
    case 4:
        cout << "Nhap so nguyen duong n : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 100 + 1;
        }
        cout << " Mang ngau nhien n phan tu " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        sapXepTangDan(arr, n);
        cout << " Mang ngau nhien sau khi sap xep tang dan " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        break;
    case 5:

        int A[N], size;

        cout << "Nhap kich thuoc mang A (1 <= size <= " << N << "): ";
        cin >> size;

        nhapMang(A, size);

        int p;
        cout << "Nhap vi tri p: ";
        cin >> p;
        cout << "Nhap so phan tu can huy n: ";
        cin >> n;

        huyPhanTu(A, size, p, n);

        cout << "Mang A sau khi huy phan tu: ";
        xuatMang(A, size);

        break;
    case 6:

        cout << "Nhap so phan tu cua mang A: ";
        cin >> n;
        cout << "Nhap mang A:" << endl;
        nhapMang(A, n);

        cout << "Nhap so phan tu cua mang B: ";
        cin >> n;
        cout << "Nhap mang B:" << endl;
        nhapMang(B, n);

        cout << "Nhap vi tri p de chen mang B vao mang A: ";
        cin >> p;

        chenMang(A, B, p, n);

        cout << "Mang A sau khi chen mang B:" << endl;
        xuatMang(A, n + p);

        break;
    case 7:

        inputArray(mang);

        sortArray(mang);

        printMostFrequentElement(mang);

        float x;
        cout << "Nhap vao so thuc x: ";
        cin >> x;

        searchOrInsert(mang, x);
        break;
    case 8:

        break;
    case 9:

        break;
    case 10:

        break;
    default:
        cout << "Ban chon thoat khoi chuong trinh" << endl;
    }

    return 1;
}