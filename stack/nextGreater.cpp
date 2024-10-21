// iostream, stack and vector are included

vector<int> nextGreater(vector<int> &arr)
{
    vector<int> retur(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        int j = i + 1;
        for (j; j < arr.size(); j++)
        {
            if (arr[i] < arr[j])
            {
                retur[i] = arr[j];
                break;
            }
        }
        if (j == arr.size())
            retur[i] = -1;
    }
    return retur;
}