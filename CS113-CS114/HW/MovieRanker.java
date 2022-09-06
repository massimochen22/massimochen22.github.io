
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Collections;

/* Starter code for PS8.
 */

public class MovieRanker {

	public static void main(String[] args) {
                File file = new File("ratings.tsv");

		ArrayList<MovieRating> rl = new ArrayList<MovieRating>();
		int count = 0;

		try {
			Scanner scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
                String[] tkns = line.split("\\t"); // tabs separate tokens
                MovieRating nr = new MovieRating(tkns[0], tkns[1], tkns[2]);

                //if (nr.getRating() == 9.6 || nr.getRating() > 9.6) {  // only add the movie that has more than or equal to 9.6 
                
                if (nr.getVotes()>=10000 && nr.getRating() <= 10.0) { //use only when it asks for a tot of at least votes
                	rl.add(nr);
                	count++;
                }
			}
			scanner.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
 
		
		
		int minVotes = 1;
		int numRecords = 1;
		Scanner input = new Scanner(System.in);
		while (true) {
			System.out.println();
			System.out.println("Enter minimum vote threshold and number of records:");
			minVotes = input.nextInt();
			numRecords = input.nextInt();
			if (minVotes * numRecords == 0)
				break;
			long startTime = System.currentTimeMillis();

/* Fill in code to determine the top numRecords movies that have at least
 * minVotes votes. For each record mr, in decreaseing order of average rating,
 * execute a System.out.println(mr).
 * Do not sort the movie list!
 * 
 */
			MaxHeap heap = new MaxHeap(); //use for question like at least 9.6  or normal
			for (int i = 0; i<rl.size();i++) {
				if (rl.get(i).getVotes() >= minVotes)
					heap.insert(rl.get(i));
			}
			

			
			for (int y = 0; y<numRecords;y++) {
				System.out.println(heap.removemax());
			}
			
			
//			System.out.println(heap.heapsize());  //use for question like at least 9.6 
//			int count2 = 0;
//			for (int y = 0; y<heap.heapsize() ;y++) {
//	
//				System.out.println(heap.removemax());
//				count2++;
//
//			}
//			System.out.println(count2);
			

		
//			MinHeap heap = new MinHeap();
//			for (int i = 0; i<rl.size();i++) {
//				if (rl.get(i).getVotes() >= minVotes)
//					heap.insert(rl.get(i));
//			}
//			
//
//			
//			for (int y = 0; y<numRecords;y++) {
//				System.out.println(heap.removemin());
//			}
			
			
			
			
			System.out.println("number of movies that have more than 9.6 as rating "+ count);
			System.out.println();
			long readTime = System.currentTimeMillis();
			System.out.println("Time: "+(System.currentTimeMillis()-startTime)+" ms");
		}
	}
}
