#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        for (auto c : x)
        {
            if (c == '}' or c == ')' or c == ']')
            {
                if (stk.empty())
                    return false;
                if (abs(c - stk.top()) > 2)
                    return false;
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};

int main()
{
    int test = 1;
    cin >> test;
    string a;
    while (test--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}