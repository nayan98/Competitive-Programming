// Program to find Dijkstra's shortest path using STL set 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
typedef pair<int,int> ipair;
 

// function to add an edge to graph 
void addEdge(vector<vector<ipair >> &adj,int u, int v, int w)
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

// Prints shortest paths from src to all other vertices 
void DijiktrasShortestPath(vector<vector<ipair >> &adj,vector<int> &dist,int V,int src) 
{ 
	// Create a set to store vertices that are being 
	// prerocessed 
	set< pair<int, int> > setds; 

	// Insert source itself in Set and initialize its 
	// distance as 0. 
	setds.insert(make_pair(0, src)); 
	dist[src] = 0; 

	/* Looping till all shortest distance are finalized 
	then setds will become empty */
	while (!setds.empty()) 
	{ 
		// The first vertex in Set is the minimum distance 
		// vertex, extract it from set. 
		pair<int, int> tmp = *(setds.begin()); 
		setds.erase(setds.begin()); 

		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		int u = tmp.second; 

		// 'i' is used to get all adjacent vertices of a vertex 
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).first; 
			int weight = (*i).second; 

			// If there is shorter path to v through u. 
			if (dist[v] > dist[u] + weight) 
			{ 
				/* If distance of v is not INF then it must be in 
					our set, so removing it and inserting again 
					with updated less distance. 
					Note : We extract only those vertices from Set 
					for which distance is finalized. So for them, 
					we would never reach here. */
				if (dist[v] != INF) 
					setds.erase(setds.find(make_pair(dist[v], v))); 

				// Updating distance of v 
				dist[v] = dist[u] + weight; 
				setds.insert(make_pair(dist[v], v)); 
			} 
		} 
	} 
	
}
void printShortesPaths(vector<int> dist,int V)
{
	// Print shortest distances stored in dist[] 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < V; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

 
int main() 
{ 
	 
	int V = 9; 
	vector<vector<ipair >> adj(V);
	
	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 
	vector<int> dist(V,INF);


	addEdge(adj,0, 1, 4); 
	addEdge(adj,0, 7, 8); 
	addEdge(adj,1, 2, 8); 
	addEdge(adj,1, 7, 11); 
	addEdge(adj,2, 3, 7); 
	addEdge(adj,2, 8, 2); 
	addEdge(adj,2, 5, 4); 
	addEdge(adj,3, 4, 9); 
	addEdge(adj,3, 5, 14); 
	addEdge(adj,4, 5, 10); 
	addEdge(adj,5, 6, 2); 
	addEdge(adj,6, 7, 1); 
	addEdge(adj,6, 8, 6); 
	addEdge(adj,7, 8, 7); 
    
    int src =0;
	DijiktrasShortestPath(adj,dist,V,src); 
	printShortesPaths(dist,V);

	return 0; 
} 
