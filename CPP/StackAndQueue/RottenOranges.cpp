#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        // Start rotting the nearrest oranges level wise like BFS
        // Traverse the grid once and populate the first level in que
        // Will do it till the level exhaust and there is nothing to traverse

        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> que;

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (grid[row][col] == 2)
                    que.push({row, col});
            }
        }

        int queSize, res = 0;
        pair<int, int> temp;
        while (!que.empty())
        {
            queSize = que.size();
            res++;
            while (queSize--)
            {
                temp = que.front();
                que.pop();
                // cout<< temp.first << " " << temp.second << endl;
                // If left is not rotten
                if (temp.second > 0 and grid[temp.first][temp.second - 1] == 1)
                {
                    grid[temp.first][temp.second - 1] = 2;
                    que.push({temp.first, temp.second - 1});
                }
                // If right is not rotten
                if (temp.second != cols - 1 and grid[temp.first][temp.second + 1] == 1)
                {
                    grid[temp.first][temp.second + 1] = 2;
                    que.push({temp.first, temp.second + 1});
                }
                // If upper is not rotten
                if (temp.first > 0 and grid[temp.first - 1][temp.second] == 1)
                {
                    grid[temp.first - 1][temp.second] = 2;
                    que.push({temp.first - 1, temp.second});
                }
                // If down is not rotten
                if (temp.first != rows - 1 and grid[temp.first + 1][temp.second] == 1)
                {
                    grid[temp.first + 1][temp.second] = 2;
                    que.push({temp.first + 1, temp.second});
                }
            }
        }

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (grid[row][col] == 1)
                    return -1;
            }
        }

        return (res == 0 ? 0 : res - 1);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends