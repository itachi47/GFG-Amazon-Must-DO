#include <bits/stdc++.h>
using namespace std;

/* APPROACH
 * Sort the array (ascending order).
 * Pick an element from the back.
 * Check for that element how many pair exists that adds up to the picked element.
 * Time complexity: nlog(n) (sortring) + n (for finding pairs) * n (array traversal) => O(n^2)
 * Space Complexity: O(1)
 */

class Solution
{
public:
    int foundTriplet(int arr[], int left, int right, int sm)
    {
        int res = 0;
        while (left < right)
        {
            if (arr[left] + arr[right] == sm)
            {
                res++;
                left++;
                right--;
            }
            else if (arr[left] + arr[right] > sm)
                right--;
            else
                left++;
        }
        return res;
    }

    int countTriplet(int arr[], int n)
    {
        // Your code goes here
        sort(arr, arr + n);
        int res = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            res += foundTriplet(arr, 0, i, arr[i + 1]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";
    }

    return 0;
}
// } Driver Code Ends