import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class AllHomophones {
		
	public static void main(String[] args) {
		UALDictionary<String, Pronunciation> PDict = new UALDictionary<String, Pronunciation>();
		
		
		File file = new File("cmudict.0.7a.txt");
		Scanner scan = new Scanner(System.in);
		String theWord = scan.nextLine(); 
		scan.close();
	    int countTotWord = 0;
		
		//File file = new File("shuffledDictionary.txt");

		try {
			Scanner scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				if (line.substring(0, 3).equals(";;;"))
					continue; // skip comment lines
				Pronunciation p = new Pronunciation(line);
				if (p.getWord().length() ==7) {
					PDict.insert(p.getWord(), p);
					countTotWord++;
				}
				
			}
			scanner.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		

		String pTheWord = PDict.find(theWord).getPhonemes(); 
		
		
		for (Pronunciation pr : PDict.values()) {
			
			if (pr.getPhonemes().equals(pTheWord)){
				System.out.println(pr.getWord()); 
			}
					
		}
		
		System.out.println(countTotWord); 
		
					
	}

}
