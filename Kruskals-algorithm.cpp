// C++ program for Kruskal's algorithm to find Minimum 
// Spanning Tree of a given connected, undirected and 
// weighted graph 
#include<bits/stdc++.h> 
using namespace std; 

// Creating shortcut for an integer pair 
typedef pair<int, int> iPair; 

// Utility function to add an edge 
void addEdge(vector< pair<int, iPair> > &edges,int u, int v, int w) 
{ 
		edges.push_back({w, {u, v}}); 
} 



// Find the parent of a node 'u' 
// Path Compression 
int find(int u,vector<int> &parent) 
{ 
		/* Make the parent of the nodes in the path 
		from u--> parent[u] point to parent[u] */
		if (u != parent[u]) 
			parent[u] = find(parent[u],parent); 
		return parent[u]; 
} 

	// Union by rank 
void merge(int x, int y,vector<int> &rnk,vector<int> &parent) 
{ 
		
		/* Make tree with smaller height 
		a subtree of the other tree */
		if (rnk[x] > rnk[y]) 
			parent[y] = x; 
		else // If rnk[x] <= rnk[y] 
			parent[x] = y; 

		if (rnk[x] == rnk[y]) 
			rnk[y]++; 
} 


/* Functions returns weight of the MST*/

int kruskalMST(vector< pair<int, iPair> > &edges,int V,int E) 
{ 
	int mst_wt = 0; // Initialize result 

	// Sort edges in increasing order on basis of cost 
	sort(edges.begin(), edges.end()); 
    
    // Create disjoint sets
    vector<int> parent(V+1);
    vector<int> rnk(V+1,0);
    for(int i=0;i<V;i++)
        parent[i]=i;
    
	
	// Iterate through all sorted edges 
	 
	for (auto it=edges.begin(); it!=edges.end(); it++) 
	{ 
		int u = it->second.first; 
		int v = it->second.second; 

		int set_u = find(u,parent); 
		int set_v = find(v,parent); 

		// Check if the selected edge is creating 
		// a cycle or not (Cycle is created if u 
		// and v belong to same set) 
		if (set_u != set_v) 
		{ 
			// Current edge will be in the MST 
			// so print it 
			cout << u << " - " << v << endl; 

			// Update MST weight 
			mst_wt += it->first; 

			// Merge two sets 
			merge(set_u, set_v,rnk,parent); 
		} 
	} 

	return mst_wt; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us create above shown weighted 
	and unidrected graph */
	int V = 9, E = 14; 
	vector< pair<int, iPair> > edges; 
	

	// making above shown graph 
	addEdge(edges,0, 1, 4); 
	addEdge(edges,0, 7, 8); 
	addEdge(edges,1, 2, 8); 
	addEdge(edges,1, 7, 11); 
	addEdge(edges,2, 3, 7);
	addEdge(edges,2, 8, 2); 
	addEdge(edges,2, 5, 4); 
	addEdge(edges,3, 4, 9); 
	addEdge(edges,3, 5, 14); 
	addEdge(edges,4, 5, 10); 
	addEdge(edges,5, 6, 2); 
	addEdge(edges,6, 7, 1); 
	addEdge(edges,6, 8, 6); 
	addEdge(edges,7, 8, 7); 

	cout << "Edges of MST are \n"; 
	int mst_wt = kruskalMST(edges,V,E); 

	cout << "\nWeight of MST is " << mst_wt; 

	return 0; 
} 
