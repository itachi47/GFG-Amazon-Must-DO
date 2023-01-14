#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int curr_sum = 0;
        int p = 0;
        for (int i = 0; i < n; ++i)
        {
            while (curr_sum + arr[i] > s and p < i)
            {
                curr_sum -= arr[p++];
            }
            if (curr_sum + arr[i] == s)
            {
                vector<int> res{p + 1, i + 1};
                return res;
            }
            curr_sum += arr[i];
        }
        vector<int> res{-1};
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends