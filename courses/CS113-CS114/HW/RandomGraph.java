import java.util.LinkedList;
import java.util.Random;

public class RandomGraph {

	public static void main(String[] args) {

		int n = 5; // number of vertices
		// enter the seed as a single command line argument
		long seed = 0; // pseudo-random number generator seed
		if (args.length != 1) {
			System.out.println("Must supply a random number seed.");
			System.exit(0);
		} else
			seed = Long.parseLong(args[0]);
		Random rng = new Random(seed);
		Graphm graph = new Graphm(n);

		// create a random graph; each edge present with probability 0.3
		for (int i = 0; i < n; ++i) {
			graph.setMark(i, 0);
			for (int j = i + 1; j < n; ++j) {
				double u = rng.nextDouble();
				if (u < 0.3) {
					graph.setEdge(i, j, 1);
					graph.setEdge(j, i, 1);
				}
			}
		}

		System.out.println("Adjacency matrix:");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (graph.isEdge(i, j))
					System.out.print("1 ");
				else
					System.out.print("0 ");
			}
			System.out.println();
		}

		// To do 1: use BFS or DFS to identify connected components
		BFS(graph, 0);
		// To do 2: Compute matrix of distances between pairs of vertices.
	}

	/** Depth first search */
	static void DFS(Graph G, int v) {
		PreVisit(G, v); // Take appropriate action
		G.setMark(v, 1);
		for (int w = G.first(v); w < G.n(); w = G.next(v, w))
			if (G.getMark(w) == 0)
				DFS(G, w);
		PostVisit(G, v); // Take appropriate action
	}

	/** Breadth first (queue-based) search */
	static void BFS(Graph G, int start) {
		LinkedList<Integer> Q = new LinkedList<Integer>();
		Q.addLast(start);
		G.setMark(start, 1);
		int d = 0;
		while (Q.size() > 0) { // Process each vertex on Q
			++d;
			int v = Q.removeFirst();
			PreVisit(G, v); // Take appropriate action
			for (int w = G.first(v); w < G.n(); w = G.next(v, w))
				if (G.getMark(w) == 0) { // Put neighbors on Q
					G.setMark(w, G.getMark(v) + 1);
					Q.addLast(w);
				}
			PostVisit(G, v); // Take appropriate action
		}
//		System.out.println("Adjacency matrix222:");
//		for (int i = 0; i < G.n(); ++i) {
//			for (int j = 0; j < G.n(); ++j) {
//				System.out.print(G.getMark(j)+" ");
//			}
//			System.out.println();
//		}
		
	}

	static void PreVisit(Graph G, int v) {
		// System.out.println("");
	}

	static void PostVisit(Graph G, int v) {
		// System.out.println("");
//		System.out.println("Adjacency matrix222:");
//		for (int i = 0; i < G.n(); ++i) {
//			for (int j = 0; j < G.n(); ++j) {
//				System.out.print(G.getMark(j)+" ");
//			}
//			System.out.println();
//		}
	}
}
