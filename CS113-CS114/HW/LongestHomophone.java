import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class LongestHomophone {

	public static void main(String[] args) {
		UALDictionary<String, Pronunciation> PDict = new UALDictionary<String, Pronunciation>();
		ArrayList<String> valueList = new ArrayList<String>();

		ArrayList<String> homophonesList = new ArrayList<String>();
		ArrayList<String> words = new ArrayList<String>();

		long startTime = System.nanoTime();

		// File file = new File("cmudict.0.7a.txt");

		File file = new File("shuffledDictionary.txt");

		try {
			Scanner scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				if (line.substring(0, 3).equals(";;;"))
					continue; // skip comment lines
				Pronunciation p = new Pronunciation(line);
				PDict.insert(p.getWord(), p);
				valueList.add(p.getPhonemes());
				words.add(p.getWord());

			}
			scanner.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		

		Collections.sort(valueList);

		for (int i = 0; i < valueList.size() - 1; i++) {

			String first = valueList.get(i);
			String second = valueList.get(i + 1);

			if (first.equals(second) && !(homophonesList.contains(first))) {
				homophonesList.add(first);
			}

		}
		
		int maxSize = 0;
		
		for (Pronunciation pr2 : PDict.values()) {
			for (String hom : homophonesList) {
				if (pr2.getPhonemes().equals(hom) && pr2.getWord().length()>maxSize) {
					maxSize = pr2.getWord().length();
				}

			}

		}
		
		System.out.println(maxSize);
		long endTime = System.nanoTime();

		System.out.println("Total execution time: " + (endTime - startTime)/1000000000);

	}

}
