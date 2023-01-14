#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {

        // Your code here
        int curr_sum = 0;
        int res = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            if (curr_sum < 0)
            {
                res = max(res, arr[i]);
                curr_sum = arr[i];
            }
            else
            {
                curr_sum += arr[i];
                res = max(res, curr_sum);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends