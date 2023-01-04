#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    int cap;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    list<int> dll;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        this->cap = cap;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        moveToFront(key);
        return mp[key].second;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        if (mp.find(key) != mp.end())
        {
            mp[key].second = value;
            moveToFront(key);
        }
        else
        {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            cap--;
        }
        if (cap < 0)
        {
            mp.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }

    // Helper function to move the node to intial to make it as the Most Recently used
    void moveToFront(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends