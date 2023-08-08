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