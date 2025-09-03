import java.util.*;

class Dijkstra {

    // Pair class to store neighbor and weight
    static class Pair {
        int node, weight;
        Pair(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    static int[] dijkstra(int V, int[][] edges, int src) {
        // Build adjacency list
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj.get(u).add(new Pair(v, w));
            adj.get(v).add(new Pair(u, w)); // undirected
        }

        // Distance array
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Min-heap: [distance, node]
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.weight));
        pq.offer(new Pair(src, 0));

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int u = curr.node;
            int d = curr.weight;

            // Skip stale entries
            if (d > dist[u]) continue;

            for (Pair nei : adj.get(u)) {
                int v = nei.node, w = nei.weight;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.offer(new Pair(v, dist[v]));
                }
            }
        }

        return dist;
    }

    // Driver code
    public static void main(String[] args) {
        int V = 5, src = 0;
        int[][] edges = {
            {0, 1, 4}, {0, 2, 8}, {1, 4, 6},
            {2, 3, 2}, {3, 4, 10}
        };

        int[] result = dijkstra(V, edges, src);
        System.out.println("Shortest distances: " + Arrays.toString(result));
    }
}
