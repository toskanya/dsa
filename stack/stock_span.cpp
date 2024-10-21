vector<int> stock_span(const vector<int> &ns)
{
    // STUDENT ANSWER
    int n = ns.size();
    vector<int> span(n, 1);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && ns[s.top()] < ns[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
            span[i] = i - s.top();
        s.push(i);
    }
    return span;
}