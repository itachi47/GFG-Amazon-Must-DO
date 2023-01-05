//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

/*You are required to complete this method*/
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Your code here
        int start = 0, end = 1;
        int currPetrol = p[start].petrol - p[start].distance;

        // Loop runs till both of the pointer will not meet or we have negative petrol.
        // As soons we have a condition where both the pointer are at the same place
        // and petrol >= 0 i.e. we have made the circular tour
        while (start != end or currPetrol < 0)
        {

            while (currPetrol < 0 and start != end)
            {
                currPetrol -= p[start].petrol - p[start].distance;
                start = (start + 1) % n;
                if (start == 0)
                    return -1;
            }
            currPetrol += p[end].petrol - p[end].distance;
            end = (end + 1) % n;
        }
        return start;
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
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}

// } Driver Code Ends