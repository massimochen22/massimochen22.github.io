import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class MostHomophones {

	public static void main(String[] args) {
		UALDictionary<String, Pronunciation> PDict = new UALDictionary<String, Pronunciation>();
		ArrayList<String> valueList = new ArrayList<String>();


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
				if (p.getWord().length()==5)
					PDict.insert(p.getWord(), p);

			}
			scanner.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}


		int maxCount = 0;
		int count = 0;
		String maxWord = "";

		int countNineHom = 0;

		for (Pronunciation pr : PDict.values()) {

			valueList.add(pr.getPhonemes());

		}
		

		Collections.sort(valueList);

		ArrayList<String> listOf9HomWord = new ArrayList<String>();
		ArrayList<String>  valueListWithoutDoubles =  new ArrayList<String>();
		
		ArrayList<String>  temp=  new ArrayList<String>();
		for (int i = 0; i < valueList.size() - 1; i++) {

			String first = valueList.get(i);
			String second = valueList.get(i + 1);

			

			if (first.equals(second)) {
				if (!temp.contains(first)) {
					temp.add(first);
				}
				count++;
				
			}

			else {
//				if (count == 9) { // comment if statement if you want the normal program
//					countNineHom++;
//					listOf9HomWord.add(first);
//				}
				valueListWithoutDoubles.add(first);
				count = 0;	
			}	

			if (count > maxCount) {
				maxCount = count;
				maxWord = valueList.get(i);

			}

		}
		
		
		for (String cur : valueListWithoutDoubles) {
			if (Collections.frequency(valueList, cur) >= 9 )
				countNineHom++;
		}
		

		for (Pronunciation pr2 : PDict.values()) {

			if (pr2.getPhonemes().equals(maxWord)) {
				System.out.println(pr2.getWord() + " " + pr2.getPhonemes());

			}

		}

		long endTime = System.nanoTime();
		System.out.println(temp);
		System.out.println(temp.size());
		
		
		System.out.println(valueList.size());

		System.out.println("there are: " + countNineHom + " words that have 9 or more homophones in the dictionary");

		System.out.println("Total execution time: " + (endTime - startTime));

	}

}
