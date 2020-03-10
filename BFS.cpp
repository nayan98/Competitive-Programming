// A Quick implementation of BFS using 
// vectors and queue 
#include <bits/stdc++.h> 
#define pb push_back 

using namespace std; 

void addedge(vector<vector<int>> &g,int a, int b) 
{ 
	g[a].pb(b); 

	// for undirected graph add this line 
	// g[b].pb(a); 
} 

void bfs(vector<vector<int>>g,vector<bool> &v,int u) 
{ 
	queue<int> q; 

	q.push(u); 
	v[u] = true; 

	while (!q.empty()) { 

		int f = q.front(); 
		q.pop(); 

		cout << f << " "; 

		// Enqueue all adjacent of f and mark them visited 
		for (auto i = g[f].begin(); i != g[f].end(); i++) { 
			if (!v[*i]) { 
				q.push(*i); 
				v[*i] = true; 
			} 
		} 
	} 
} 

// Driver code 
int main() 
{ 
    
	int n, e; 
	cin >> n >> e; 
    vector<bool> v(n,false); 
    vector<vector<int> > g; 
	
	g.assign(n, vector<int>()); 

	int a, b; 
	for (int i = 0; i < e; i++) { 
		cin >> a >> b; 
		addedge(g,a, b); 
	} 
	//Printing the adjacency list
	for(int i=0;i<g.size();i++)
	{
	    cout<<i<<"-> ";
	    for(int j=0;j<g[i].size();j++)
	        cout<<g[i][j]<<" ";
	    cout<<endl;
	}

	for (int i = 0; i < n; i++) { 
		if (!v[i]) 
			bfs(g,v,i); 
	} 

	return 0; 
} 
