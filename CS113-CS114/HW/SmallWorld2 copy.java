
import java.util.*; //Collab with Haseeb

public class SmallWorld2 {
	public static void main(String[] args) throws Exception {

		ArrayList<ActorRecord> act = new ArrayList<ActorRecord>();
		BST<String, Integer> tree = new BST<String, Integer>();

		Scanner scan = new Scanner(System.in);

		String content;
		String content2;
		String temp;
		String temp2;
		String[] tkn;
		String[] tkn2;

		int count = 0;

		// String fname = "shortestActors.list.gz";
		String fname2 = "actors.list.gz";
		String fname = "actresses.list.gz";

		RetrieveActors ra = new RetrieveActors(fname);
		RetrieveActors ra2 = new RetrieveActors(fname2);

		long start1 = System.currentTimeMillis();
		System.out.println("reading...");
		while ((content = ra.getNext()) != null) {
			tkn = content.split("@@@");
			ActorRecord ar = new ActorRecord(tkn[0]);
			for (int i = 1; i < tkn.length; i++) {
				temp = tkn[i];
				if (!(temp.substring(0, 2).equals("FM")))
					continue;
				tree.insert(temp, count);
				ar.addMovie(temp);

			}
			act.add(ar);

			count++;
		}

		while ((content2 = ra2.getNext()) != null) {
			tkn2 = content2.split("@@@");
			ActorRecord ar1 = new ActorRecord(tkn2[0]);
			for (int j = 1; j < tkn2.length; j++) {
				temp2 = tkn2[j];
				if (!(temp2.substring(0, 2).equals("FM")))
					continue;

				tree.insert(temp2, count);
				ar1.addMovie(temp2);
			}
			act.add(ar1);

			count++;
		}

		long end1 = System.currentTimeMillis();
		System.out.println("Finish reading files");

		ArrayList<String> allMovies = tree.keyValues();
		ArrayList<String> allMovies2 = new ArrayList<String>();
		Collections.sort(allMovies);

		Graphl alGraph = new Graphl(count);

		long start2 = System.currentTimeMillis();
		String tempSad = "";
		for (String sad : allMovies) {
			if (sad.equals(tempSad)) {
				continue;
			} else {
				allMovies2.add(sad);
				ArrayList<Integer> currentArray = tree.findAll(sad);
				int currentSize = currentArray.size();
				for (int number = 0; number < currentSize - 1; number++) {
					for (int number2 = number + 1; number2 < currentSize; number2++) {
						int n1 = currentArray.get(number);
						int n2 = currentArray.get(number2);
						alGraph.setEdge(n1, n2, 0);
						alGraph.setEdge(n2, n1, 0);

					}

				}
			}
			tempSad = sad;
		}

		long end2 = System.currentTimeMillis();
		System.out.println("time reading files: " + (end1 - start1) + " msec.");
		System.out.println("time setting edges: " + (end2 - start2) + " msec.");

		long start4 = System.currentTimeMillis();
		int firstActor;
		int secondActor;

		do {
			System.out.println("Enter Values");
			firstActor = scan.nextInt();
			secondActor = scan.nextInt();

			System.out.println("Start BFS");
			BFS(alGraph, firstActor, secondActor, act, allMovies);

		} while (firstActor > 0 || secondActor > 0);

		// BFS(alGraph, 3, 7, act, allMovies2);

		long end4 = System.currentTimeMillis();

		System.out.println("time of BFS: " + (end4 - start4) + " msec.");
		scan.close();

	}

	static void BFS(Graphl G, int start, int end, ArrayList<ActorRecord> act, ArrayList<String> allMovies) {
		LinkedList<Integer> Q = new LinkedList<Integer>();
		int[] checkSeen = new int[G.n()];
		ArrayList<ActorRecord> correctOrder = new ArrayList<ActorRecord>();

		for (int x = 0; x < G.n(); x++)
			checkSeen[x] = -1;

		Q.addLast(start);

		while (Q.size() > 0) { // Process each vertex on Q

			int v = Q.removeFirst();
			// checkSeen.add(v);

			if ((v == end) || (v <= 0 || end <= 0))
				break;

			if (G.isEdge(v, end)) {
				act.get(end).pred = act.get(v);
				break;
			} else {
				for (int w : G.neighbors(v)) {
					if (!(checkSeen[w] == w)) { // Put neighbors on Q if not seen
						checkSeen[w] = w;
						Q.addLast(w);
						act.get(w).pred = act.get(v);
					}
				}
			}
		}

		System.out.println("Starting backtracking");

		int counting = 0;

		if (start <= 0 || end <= 0)
			System.out.println("terminated.");

		else {
			System.out.println("Shortest path between " + act.get(start).name + " and " + act.get(end).name);

			for (ActorRecord currentAcR = act.get(end); counting < G.n()
					&& currentAcR != null; currentAcR = currentAcR.pred) {

				correctOrder.add(currentAcR);
				counting++;
				if ((currentAcR.name).equals(act.get(start).name))
					break;
			}

			System.out.println("finish assigning predecessors");

			if (!(correctOrder.get(correctOrder.size() - 1).name).equals(act.get(start).name)) // check if there is a
																								// path
				System.out.println("No path");

			else {
				System.out.println("Distance: " + (correctOrder.size() - 1) + " the chain is:");
				for (int tempVar = correctOrder.size() - 1; tempVar > 0; tempVar--) {
					ActorRecord temp1 = correctOrder.get(tempVar);
					ActorRecord temp2 = correctOrder.get(tempVar - 1);
					String commonMovie = "no movie";
					for (String s2 : allMovies)
						if (temp1.appearedIn(s2) && temp2.appearedIn(s2)) {
							commonMovie = s2;
							break;
						}
					System.out.print(temp1.name + " appeared with " + temp2.name + " in  " + commonMovie.substring(2));
					System.out.println();

				}

			}

		}
	}
}
