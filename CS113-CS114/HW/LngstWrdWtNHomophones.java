
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class LngstWrdWtNHomophones {

	public static void main(String[] args) {
		UALDictionary<String, Pronunciation> PDict = new UALDictionary<String, Pronunciation>();
		UALDictionary<String, String> PDict2 = new UALDictionary<String, String>();
		ArrayList<String> valueList = new ArrayList<String>();
		ArrayList<String> words = new ArrayList<String>();

		long startTime = System.nanoTime();

		File file = new File("cmudict.0.7a.txt");

		// File file = new File("shuffledDictionary.txt");

		try {
			Scanner scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				if (line.substring(0, 3).equals(";;;"))
					continue; // skip comment lines
				Pronunciation p = new Pronunciation(line);
				PDict.insert(p.getWord(), p);
				PDict2.insert(p.getPhonemes(), p.getWord());

			}
			scanner.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		int count = 0;

		for (Pronunciation pr : PDict.values()) {

			valueList.add(pr.getPhonemes());

		}

		Collections.sort(valueList);

		System.out.println("Start block one");
		ArrayList<String> listOfNoHomoph = new ArrayList<String>();

		for (int i = 0; i < valueList.size() - 1; i++) {

			String first = valueList.get(i);
			String second = valueList.get(i + 1);

			if (first.equals(second)) {
				count++;
			}

			else {
				if (count == 0)
					listOfNoHomoph.add(first);
				count = 0;
			}

		}

		int maxlength = 0;
		String maxlengthWord = "";
		System.out.println("Start block two");
		for (String current : listOfNoHomoph) {
			String curr2 = PDict2.find(current);
				int currLen = curr2.length();
				if (currLen > maxlength) {
					maxlength = currLen;
					maxlengthWord = curr2;
				}
				
			}
		



		long endTime = System.nanoTime();

		System.out.println(
				"The longest word with no homophones is: " + maxlengthWord + " and it is " + maxlength + " long");

		System.out.println("Total execution time: " + (endTime - startTime));

	}

}
