void interleaveQueue(queue<int> &q)
{
    int n = q.size();
    if (n % 2 != 0)
    {
        return; // The problem specifies that the queue has an even length
    }

    queue<int> temp;
    int halfSize = n / 2;

    // Step 1: Move the first half of the queue into the temp queue
    for (int i = 0; i < halfSize; ++i)
    {
        temp.push(q.front());
        q.pop();
    }

    // Step 2: Interleave the elements from the temp queue and the remaining queue
    while (!temp.empty())
    {
        q.push(temp.front()); // Add element from the first half
        temp.pop();

        q.push(q.front()); // Add element from the second half
        q.pop();
    }
}