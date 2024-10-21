class QueueS
{
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    void enqueue(int value)
    {
        inStack.push(value);
    }

    int dequeue()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        if (outStack.empty())
        {
            throw out_of_range("Empty queue");
        }
        int value = outStack.top();
        outStack.pop();
        return value;
    }

    int front()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        if (outStack.empty())
        {
            throw out_of_range("Empty queue");
        }
        return outStack.top();
    }

    int rear()
    {
        if (!inStack.empty())
        {
            return inStack.top();
        }
        else if (!outStack.empty())
        {
            stack<int> temp = outStack;
            while (temp.size() > 1)
            {
                temp.pop();
            }
            return temp.top();
        }
        else
        {
            throw out_of_range("Empty queue");
        }
    }

    string toString()
    {
        stack<int> tempIn = inStack;
        stack<int> tempOut = outStack;
        string result = "FRONT|";

        while (!tempOut.empty())
        {
            result += " " + to_string(tempOut.top());
            tempOut.pop();
        }

        stack<int> reverseIn;
        while (!tempIn.empty())
        {
            reverseIn.push(tempIn.top());
            tempIn.pop();
        }
        while (!reverseIn.empty())
        {
            result += " " + to_string(reverseIn.top());
            reverseIn.pop();
        }

        result += "|REAR";
        return result;
    }
};