import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class MorethanNineHomophones {

	public static void main(String[] args) {
		UALDictionary<String, Pronunciation> PDict = new UALDictionary<String, Pronunciation>();
	
		
		ArrayList<String> valueList = new ArrayList<String>();
		ArrayList<String> words = new ArrayList<String>();

		long startTime = System.nanoTime();

		File file = new File("cmudict.0.7a.txt");

		//File file = new File("shuffledDictionary.txt");


		try {
			Scanner scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				if (line.substring(0, 3).equals(";;;"))
					continue; // skip comment lines
				Pronunciation p = new Pronunciation(line);
				PDict.insert(p.getWord(), p);

			}
			scanner.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		int count = 0;
	

		int countNineHom = 0;

		for (Pronunciation pr : PDict.values()) {

			valueList.add(pr.getPhonemes());

		}
		
		Collections.sort(valueList);

		ArrayList<String> listOf9HomWord = new ArrayList<String>();

		for (int i = 0; i < valueList.size() - 1; i++) {

			String first = valueList.get(i);
			String second = valueList.get(i + 1);

			if (first.equals(second)) {
				count++;
				if (count >= 9 && !listOf9HomWord.contains(first)) { // comment if statement if you want the normal program
					countNineHom++; //number of phonemes that have more than 9 homophones
					listOf9HomWord.add(first);
				}
			}

			else
				count = 0;

		}
		
		for (Pronunciation pr2 : PDict.values()) {

			if (listOf9HomWord.contains(pr2.getPhonemes())) {
				words.add(pr2.getWord());
			}

		}
		
		
		

		long endTime = System.nanoTime();

		System.out.println("there are: " + words.size() + " words that have 9 or more homophones in the dictionary");

		System.out.println("Total execution time: " + (endTime - startTime));

	}

}
