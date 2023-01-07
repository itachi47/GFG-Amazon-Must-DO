#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        vector<long long> res(n, -1);
        stack<int> stk;

        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() and arr[stk.top()] < arr[i])
            {
                res[stk.top()] = arr[i];
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};

int main()
{
    int test = 1;
    cin >> test;
    string a;
    while (test--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}