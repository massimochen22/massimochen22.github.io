import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class HuayaHua {
	
	public static void main(String[] args) {

		File file = new File("huayahua.txt");
	    
		//File file = new File("shuffledDictionary.txt");

		try {
			
			for (int i = 0; i < 50; i++) {
				Scanner scanner = new Scanner(file);
				while (scanner.hasNextLine()) {
					String line = scanner.nextLine();
					System.out.println(line);
					
				}
			}
		
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
