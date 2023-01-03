#include <bits/stdc++.h>
using namespace std;

// The structure of the class is
class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    int pop();
};

// Function to push an element in queue by using 2 stacks.
void StackQueue ::push(int x)
{
    // Your Code
    s1.push(x);
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    // Your Code
    if (s1.empty())
        return -1;
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int res = s2.top();
    s2.pop();

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return res;
}

int main()
{
    int test = 1;
    cin >> test;
    while (test--)
    {
        StackQueue *sq = new StackQueue();
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
                sq->push(a);
            }
            else if (queryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}