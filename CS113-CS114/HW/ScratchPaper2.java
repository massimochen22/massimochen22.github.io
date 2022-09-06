import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class ScratchPaper2 {

	public static char[] WordArrPair(String word) // convert all words to a char list
	{
		char[] charArr = word.toCharArray();
		Arrays.sort(charArr); // time complexity of O(nlog(n))
		return charArr;

	}

	public static boolean isAnagram(char[] wordArrPair, char[] charArr) // check if anagrams
	{
		return Arrays.equals(charArr, wordArrPair); // time complexity of O(n)
	}

	public static void main(String[] args) throws Exception {

		ArrayList<String> lineList = new ArrayList<String>();
		File file = new File("words.txt");
		int variable = 5;
		
		int n = 0;
		try {
			Scanner scanner = new Scanner(file);
			
			 //the lenghth of the desired length word
			
			while (scanner.hasNext()) {
				String line = scanner.next(); // O(n)
				if (line.length() == variable) 
					lineList.add(line);

				++n;

			}
			scanner.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		ArrayList<String> newList = new ArrayList<String>();
		ArrayList<String> noAnagList = new ArrayList<String>();
		int listSize = lineList.size();

		for (int x = 0; x < listSize -1; x++) {
			int count = 0;
			for (int y = x + 1; y < listSize; y++) {
				if (isAnagram(WordArrPair(lineList.get(x)), WordArrPair(lineList.get(y)))) {
					count++;
					if (!newList.contains(lineList.get(y)))
						newList.add(lineList.get(y));
					
				}
			}

			if (count > 0) 
				if (!newList.contains(lineList.get(x)))
					newList.add(lineList.get(x));
			
			if (count == 0)
				noAnagList.add(lineList.get(x));
				
		}
		
		

		System.out.println("words that dont have any anagrams: " + noAnagList.size());
		System.out.println("there are "+ newList.size() + " anagrams of length "+ variable);
		System.out.println("there are "+listSize+" words that are made of "+ variable+ " characters");
		System.out.println("there are a total of "+ n+ " words in the file");

	}

}