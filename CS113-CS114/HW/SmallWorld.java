import java.util.*;

public class SmallWorld {
	public static void main(String[] args) throws Exception {
		ArrayList<ActorRecord> act = new ArrayList<ActorRecord>();
		ArrayList<String> allMovies = new ArrayList<String>();
		Scanner scan = new Scanner(System.in);

		String content;
		String[] tkn;
		int count = 0;

		String fname = "shortestActors.list.gz";
		RetrieveActors ra = new RetrieveActors(fname);
		while ((content = ra.getNext()) != null) { // create ActorRecord objects (actors) and assign all the movies that
													// they acted
			++count; // it counts how many actors are there
			tkn = content.split("@@@");
			ActorRecord ar = new ActorRecord(tkn[0]);

			for (int i = 1; i < tkn.length; ++i) {
				if (tkn[i].substring(0, 2).equals("FM")) {
					ar.addMovie(tkn[i].substring(2));
					if (!(allMovies.contains((tkn[i].substring(2))))) { // put all the movie names in the array
																		// allMovies
						allMovies.add((tkn[i].substring(2)));
					}
				}
			}
			act.add(ar);
		}

		Graphl alGraph = new Graphl(count);

		for (int n = 0; n < act.size(); ++n) {
			alGraph.setMark(n, n); // set the vertices as the indexes of the actors
		}

		for (String s : allMovies) {
			for (int x = 0; x < act.size(); x++) {
				for (int y = x + 1; y < act.size(); y++) {

					if ((act.get(x).appearedIn(s)) && (act.get(y).appearedIn(s))) {
						if (!(alGraph.isEdge(x, y)) && x != y)
							alGraph.setEdge(x, y, 0);
						if (!(alGraph.isEdge(y, x)) && x != y)
							alGraph.setEdge(y, x, 0);
					}
				}
			}
		}

		System.out.println("Enter source and destination indices: ");

		int firstActor;
		int secondActor;
		do {
			firstActor = scan.nextInt() - 1;
			secondActor = scan.nextInt() - 1;

			BFS(alGraph, firstActor, secondActor, act, allMovies);

		} while (firstActor >=0 || secondActor >= 0);

	}

	static void BFS(Graphl G, int start, int end, ArrayList<ActorRecord> act, ArrayList<String> allMovies) {
		LinkedList<Integer> Q = new LinkedList<Integer>();
		ArrayList<Integer> checkSeen = new ArrayList<Integer>();
		ArrayList<ActorRecord> correctOrder = new ArrayList<ActorRecord>();
		Q.addLast(start);
		int d = 0;
		while (Q.size() > 0) { // Process each vertex on Q
			++d;

			int v = Q.removeFirst();
			checkSeen.add(v);
			if ((v == end)||(v<0 || end<0))
				break;

			if (G.isEdge(v, end)) {
				act.get(end).pred = act.get(v);
				break;
			} else {
				for (int w = G.first(v); w < G.n(); w = G.next(v, w))
					if (!checkSeen.contains(G.getMark(w))) { // Put neighbors on Q if its not the end value
						// G.setMark(w, G.getMark(v) + 1);
						Q.addLast(w);
						act.get(w).pred = act.get(v);
					}
			}
		}

		// "Starting backtracking"

		int counting = 0;
		

		if (start < 0 || end < 0)
			System.out.println("terminated.");

		else {
			System.out.println("Shortest path between " + act.get(start).name + " and " + act.get(end).name);
			for (ActorRecord currentAcR = act.get(end); currentAcR != null; currentAcR = currentAcR.pred) {
				correctOrder.add(currentAcR);
				counting++;
			}

			System.out.println("Distance: " + (counting - 1) + " the chain is:");

			for (int tempVar = correctOrder.size() - 1; tempVar > 0; tempVar--) {
				ActorRecord temp1 = correctOrder.get(tempVar);
				ActorRecord temp2 = correctOrder.get(tempVar - 1);
				String commonMovie = "no movie";
				for (String s2 : allMovies)
					if (temp1.appearedIn(s2) && temp2.appearedIn(s2)) {
						commonMovie = s2;
						break;
					}
				System.out.print(temp1.name + " appeared with " + temp2.name + " in  " + commonMovie);
				System.out.println();

			}
		}
	}
}
