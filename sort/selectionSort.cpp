template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int n = end - start; // Kích thước mảng
    for (int i = 0; i < n - 1; i++)
    {
        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (start[j] < start[min_idx])
            {
                min_idx = j;
            }
        }
        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của mảng chưa sắp xếp
        if (min_idx != i)
        {
            std::swap(start[i], start[min_idx]);
        }
        // In ra mảng sau mỗi lần chọn
        printArray(start, end);
    }
}