// STL implementation of Prim's algorithm for MST 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> Integer Pair 
typedef pair<int, int> ipair; 

// To add an edge 
void addEdge(vector<vector <ipair>> &adj, int u, int v, int wt) 
{ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
} 

// Prints shortest paths from src to all other vertices 
void primMST(vector<vector<ipair >> &adj, vector<int> &parent ,int V) 
{ 
	// Create a Set to store vertices that 
	// are being preinMST. 
	
	set< pair<int, int> > setds; 
  

	int src = 0; // Taking vertex 0 as source 

	// Create a vector for keys and initialize all 
	// keys as infinite (INF) 
	vector<int> key(V, INF); 

	// To store parent array which in turn store MST 
	 

	// To keep track of vertices included in MST 
	vector<bool> inMST(V, false); 

	// Insert source itself in Set and initialize 
	// its key as 0. 
	setds.insert(make_pair(0, src)); 
	key[src] = 0; 

	/* Looping till Set becomes empty */
	while (!setds.empty()) 
	{ 
		// The first vertex in pair is the minimum key 
		// vertex, extract it from Set. 
		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted key (key must be first item 
		// in pair) 
		pair<int, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin());
		int u = tmp.second; 
		 

		inMST[u] = true; // Include vertex in MST 

		// Traverse all adjacent of u 
		for (auto x : adj[u]) 
		{ 
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = x.first; 
			int weight = x.second; 

			// If v is not in MST and weight of (u,v) is smaller 
			// than current key of v 
			if (inMST[v] == false && key[v] > weight) 
			{ 
				// Updating key of v 
				if(key[v]!=INF)
				setds.erase(setds.find(make_pair(key[v], v))); 
				key[v] = weight; 
				 
				 setds.insert(make_pair(key[v], v));
				parent[v] = u; 
			} 
		} 
	} 
}

void printMST(vector<int> parent,int V)
{
	// Print edges of MST using parent array 
	for (int i = 1; i < V; ++i) 
		printf("%d - %d\n", parent[i], i); 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	int V = 9; 
	vector<vector<ipair >> adj(V); 
	vector<int> parent(V, -1);

	// making above shown graph 
	addEdge(adj, 0, 1, 4); 
	addEdge(adj, 0, 7, 8); 
	addEdge(adj, 1, 2, 8); 
	addEdge(adj, 1, 7, 11); 
	addEdge(adj, 2, 3, 7); 
	addEdge(adj, 2, 8, 2); 
	addEdge(adj, 2, 5, 4); 
	addEdge(adj, 3, 4, 9); 
	addEdge(adj, 3, 5, 14); 
	addEdge(adj, 4, 5, 10); 
	addEdge(adj, 5, 6, 2); 
	addEdge(adj, 6, 7, 1); 
	addEdge(adj, 6, 8, 6); 
	addEdge(adj, 7, 8, 7); 

//Printing The Adjacency List
/*
for(int i=0;i<V;i++)
{
    for(int j=0;j<adj[i].size();j++)
    {
        cout<<adj[i][j].first<<"-"<<adj[i][j].second<<"  ";
    }
    cout<<endl;
}
*/
	        

	primMST(adj,parent, V);
	printMST(parent,V);

	return 0; 
} 
