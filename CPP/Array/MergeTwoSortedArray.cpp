#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // code here
        int h = ceil((float)(n + m) / 2);
        int p, q;
        while (h > 0)
        {
            p = 0;
            q = h;
            while (q - n < m)
            {
                if (q < n and arr1[p] > arr1[q])
                {
                    swap(arr1[p], arr1[q]);
                }
                else if (p < n and q >= n and arr1[p] > arr2[q - n])
                {
                    swap(arr1[p], arr2[q - n]);
                }
                else if (p >= n and arr2[p - n] > arr2[q - n])
                {
                    swap(arr2[p - n], arr2[q - n]);
                }
                p++;
                q++;
            }
            h = h == 1 ? 0 : ceil((float)h / 2);
        }
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends