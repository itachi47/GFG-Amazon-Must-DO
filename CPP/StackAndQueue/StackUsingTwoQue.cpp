#include <bits/stdc++.h>
using namespace std;

// The structure of the class is
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    // Your Code
    q1.push(x);
    return;
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    // Your Code
    if (q1.empty())
        return -1;

    int res = q1.back();
    while (q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    return res;
}

int main()
{
    int test = 1;
    cin >> test;
    while (test--)
    {
        QueueStack *qs = new QueueStack();
        int Q;
        cin >> Q;
        while (Q--)
        {
            int queryType = 0;
            cin >> queryType;
            if (queryType == 1)
            {
                int a;
                cin >> a;
                qs->push(a);
            }
            else if (queryType == 2)
            {
                cout << qs->pop() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}