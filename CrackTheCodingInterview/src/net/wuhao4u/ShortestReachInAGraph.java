import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class ShortestReachInAGraph {
    public static class Graph {
        private final int V;
        private int E;
        private LinkedList<Integer>[] adj;

        public Graph(int size) {
            this.V = size;
            this.E = 0;
            adj = (LinkedList<Integer>[]) new LinkedList[size];
            for (int i = 0; i < V; ++i) {
                adj[i] = new LinkedList<Integer>();
            }
        }

        public void addEdge(int first, int second) {
            ++E;

            for (int v = 0; v < V; ++v) {
                if (v == first) {
                    adj[v].add(second);
                } else if (v == second) {
                    adj[v].add(first);
                }
            }
        }

        public int[] shortestReach(int s) { // 0 indexed
            if (s < 0 || s > V-1) {
                return null;
            }

            int[] hops = new int[V];
            for (int i = 0; i < hops.length; ++i) {
                hops[i] = -1;
            }

            // bfs starting from startID
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(s);

            int curV = -1;
            int hopCount = 0;

            while (!q.isEmpty()) {
                curV = q.poll();
                hopCount += 6;

                LinkedList<Integer> neighbors = adj[curV];

                for (Integer nei : neighbors) {
                    if (hops[nei] != -1 || nei == s) {
                        continue;
                    }
                    hops[nei] = hopCount;
                    q.add(nei);
                }
            }

            return hops;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int queries = scanner.nextInt();

        for (int t = 0; t < queries; t++) {

            // Create a graph of size n where each edge weight is 6:
            Graph graph = new Graph(scanner.nextInt());
            int m = scanner.nextInt();

            // read and set edges
            for (int i = 0; i < m; i++) {
                int u = scanner.nextInt() - 1;
                int v = scanner.nextInt() - 1;

                // add each edge to the graph
                graph.addEdge(u, v);
            }

            // Find shortest reach from node s
            int startId = scanner.nextInt() - 1;
            int[] distances = graph.shortestReach(startId);

            for (int i = 0; i < distances.length; i++) {
                if (i != startId) {
                    System.out.print(distances[i]);
                    System.out.print(" ");
                }
            }
            System.out.println();
        }

        scanner.close();
    }
}
