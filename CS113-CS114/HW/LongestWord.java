import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

/**
 * Find length of longest word in the first n lines of words.txt.
 */

public class LongestWord {

	public static void main(String[] args) {
		//List<NewWordPair> wordList;
		//wordList = new ArrayList<NewWordPair>();
		File file = new File("words.txt"); // for your local machine
		 //File file = new File("../resource/asnlib/public/words.txt");

		int maxWordLength = 0;
            
		Scanner inp = new Scanner(System.in);

		int numLines = inp.nextInt();
      
      String [] list = new String [numLines];
      
		int n = 0;
		try {
			Scanner scanner = new Scanner(file);
			while (scanner.hasNext()) {
				String line = scanner.next();
            list[n] = line;
				++n;
				if (line.length() > maxWordLength)
					maxWordLength = line.length();
				if (n >= numLines)
					break;
			}
			scanner.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		System.out.println("Longest word length: " + maxWordLength);
      
      for (String x : list)
      {
         System.out.println(x);
      }
      
      
	}

}
