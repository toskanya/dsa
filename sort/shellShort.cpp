// TODO: Write your code here

static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total)
{
    // TODO

    int size = end - start;
    for (int i = segment_idx; i < size; i += cur_segment_total)
    {
        T key = start[i];
        int j = i - cur_segment_total;
        while (j >= 0 && start[j] > key)
        {
            start[j + cur_segment_total] = start[j];
            j -= cur_segment_total;
        }
        start[j + cur_segment_total] = key;
    }
}

static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases)
{

    for (int k = num_phases - 1; k >= 0; --k)
    {
        int cur_segment_total = num_segment_list[k];
        for (int segment_idx = 0; segment_idx < cur_segment_total; ++segment_idx)
        {
            sortSegment(start, end, segment_idx, cur_segment_total);
        }
        cout << cur_segment_total << " segments: "; // In ra số lượng đoạn sau khi sắp xếp từng pha
        printArray(start, end);                     // In ra mảng sau khi sắp xếp từng pha
    }
}