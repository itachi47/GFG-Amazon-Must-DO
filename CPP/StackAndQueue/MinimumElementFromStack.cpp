#include <bits/stdc++.h>
using namespace std;

// The structure of the class is as follows
class _stack
{
    stack<int> s;
    int minEle;

public:
    int getMin();
    int pop();
    void push(int);
};

class Solution
{
    int minEle;
    stack<int> s;

public:
    /*returns min element from stack*/
    int getMin()
    {

        // Write your code here
        if (s.empty())
            return -1;
        return minEle;
    }

    /*returns poped element from stack*/
    int pop()
    {

        // Write your code here
        if (s.empty())
            return -1;
        int res;
        if (s.top() < minEle)
        {
            res = minEle;
            minEle = 2 * minEle - s.top();
            s.pop();
            return res;
        }
        res = s.top();
        s.pop();
        return res;
    }

    /*push element x into the stack*/
    void push(int x)
    {

        // Write your code here
        if (s.empty())
        {
            s.push(x);
            minEle = x;
        }
        else if (minEle <= x)
        {
            s.push(x);
        }
        else
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
        return;
    }
};

int main()
{
    int test = 1;
    cin >> test;
    while (test--)
    {
        int q;
        cin >> q;
        Solution obj;
        while (q--)
        {
            int qt;
            cin >> qt;
            if (qt == 1)
            {
                // push
                int att;
                cin >> att;
                obj.push(att);
            }
            else if (qt == 2)
            {
                // pop
                cout << obj.pop() << " ";
            }
            else if (qt == 3)
            {
                cout << obj.getMin() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}