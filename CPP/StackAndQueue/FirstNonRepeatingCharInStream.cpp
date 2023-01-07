#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Needs to track which char comes first
    // Also their frequency to check if they are potential answer or not
    string FirstNonRepeating(string A)
    {
        // Code here
        queue<char> q;
        vector<int> freq(26, 0);
        string res = "";

        for (auto ch : A)
        {
            q.push(ch);
            freq[ch - 'a']++;
            while (!q.empty() and freq[q.front() - 'a'] > 1)
                q.pop();
            if (q.empty())
                res += '#';
            else
                res += q.front();
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends