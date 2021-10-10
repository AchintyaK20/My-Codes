// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// design the class:

class LRUCache
{
	list<pair<int ,int>> dq;
	unordered_map<int, list<pair<int, int>>::iterator> ma;
	int csize;

public:
	LRUCache(int cap)
	{
		csize = cap;
		dq.clear();
		ma.clear();
	}

	int get(int key)
	{
		if(ma.find(key) == ma.end())
		{
			return -1;
		}
		auto it = ma[key];
		int d = it->second;
		dq.erase(it);
		dq.push_front({key, d});
		ma[key] = dq.begin();
		return d;

	}

	void set(int key, int value)
	{
		if (ma.find(key) == ma.end())
		{
			if(dq.size() == csize)
			{
				int Lx = dq.back().first;
				int Ly = dq.back().second;
				dq.pop_back();
				dq.push_front({key, value});
				ma.erase(Lx);
				ma[key] = dq.begin();
			}
			else
			{
				dq.push_front({key, value});
				ma[key] = dq.begin(); 
			}
		}
		else
		{
			auto it = ma[key];
			dq.erase(it);
			dq.push_front({key, value});
			ma[key] = dq.begin();
		}
	}
};

// { Driver Code Starts.

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
				cache->set(key, value);
			}
			else
			{
				int key;
				cin >> key;
				cout << cache->get(key) << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends