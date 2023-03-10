#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k - 1; ++i)
        {
            while (!dq.empty() and arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
        }

        for (int i = k - 1; i < n; ++i)
        {
            while (!dq.empty() and dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() and arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
            res.push_back(arr[dq.front()]);
        }
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

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends