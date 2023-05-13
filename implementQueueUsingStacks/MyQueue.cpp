class MyQueue
{
public:
    MyQueue()
    {

    }

    void push(int x)
    {
        in_stack.push(x);
    }

    int pop()
    {
        if (out_stack.empty())
        {
            in2out();
        }

        int x = out_stack.top();
        out_stack.pop();

        return x;
    }

    int peek()
    {
        if (out_stack.empty())
        {
            in2out();
        }

        return out_stack.top();
    }

    bool empty()
    {
        return in_stack.empty() && out_stack.empty();
    }

private:
    std::stack<int> in_stack, out_stack;

    void in2out()
    {
        while (!in_stack.empty())
        {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }
};
