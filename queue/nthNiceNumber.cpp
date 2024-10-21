// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n)
{
    queue<long long> q;

    // Start by enqueuing the base numbers 2 and 5
    q.push(2);
    q.push(5);

    long long currentNiceNumber;

    // We need to find the Nth nice number
    for (int i = 0; i < n; ++i)
    {
        // Get the next nice number from the queue
        currentNiceNumber = q.front();
        q.pop();

        // Append 2 and 5 to the current number and enqueue them
        q.push(currentNiceNumber * 10 + 2);
        q.push(currentNiceNumber * 10 + 5);
    }

    return currentNiceNumber;
}