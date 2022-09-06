
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

/**
 * Find length of longest word in the first n lines of words.txt.
 */
 
 //The whole code time complexity is O(n^4log(n))

public class MostAnagrams 
{

   public static char[] WordArrPair(String word) // convert all words to a char list 
   {
        char []charArr = word.toCharArray(); 
        Arrays.sort(charArr); //time complexity of O(nlog(n))
        return charArr;
        
    }
    
    public static boolean isAnagram(char[] wordArrPair, char[]charArr)  // check if anagrams
    {
         return Arrays.equals(charArr, wordArrPair); //time complexity of O(n)
    }

	public static void main(String[] args) {
//		List<NewWordPair> wordList;
//		wordList = new ArrayList<NewWordPair>();
		File file = new File("words.txt"); // for your local machine  //113809 total lines
		 //File file = new File("../resource/asnlib/public/words.txt");
       
      long startTime = System.nanoTime();

		int maxWordLength = 0;
		
            
		Scanner inp = new Scanner(System.in);

		int numLines = inp.nextInt();
      
      String [] list = new String [numLines];
      
		int n = 0;
		try {
			Scanner scanner = new Scanner(file);
         
			while (scanner.hasNext()) {
				String line = scanner.next();  //O(n)
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

      
      
      
      for (int i=1 ;i<n; i++) 
      { 
        String temp = list[i]; 
        int j = i - 1; 
        while (j >= 0 && temp.length() < list[j].length()) //O(n^2)
        { 
            list[j+1] = list[j]; 
            j--; 
        } 
        list[j+1] = temp; 
     } 
      
      
      int maxAnagramCount = 0;
      ArrayList<String> newList = new ArrayList<String>();
      //int count = 0;
      for (int x=0; x<numLines-1;x++) //whole nested loop is O(n^4log(n))
      {        
      int count = 0;
      
      ArrayList<String> tempList = new ArrayList<String>();
      
      
        for (int y=x; y<numLines-1;y++) 
        {
            if(list[x].length()==list[y].length()&& list[x] != list[y] && isAnagram(WordArrPair(list[x]), WordArrPair(list[y]))) 
            {
               //tempList.add(list[y]);
            	if (list[x].length() == 5){ // IMPORTANT!!!! ONLY ADDS THE WORDS THAT ARE LENGHTH 5
	              newList.add(list[y]);
	               count++;
            	}
            }
               
            else if (list[x].length()!=list[y].length())
               break;
               
        }
        if (count > 0)
          newList.add(list[x]);
        
        if (count>=maxAnagramCount)
        {
              maxAnagramCount = count;
           newList = tempList;   
       }
        
                     
      }
      
      System.out.println(maxAnagramCount);
      
      for (int z = 0; z < newList.size();z++) //O(n^2)
	      { 		      
	          System.out.println(newList.get(z)); 		
	      }   
         
      
      long endTime = System.nanoTime();
      
//      for (String example : list)
//         System.out.println(example);
         
         //long startTime = System.nanoTime();
         //long endTime = System.nanoTime();

      
      System.out.println("Total execution time: " + (endTime - startTime));
      
      System.out.println(newList.size());
      
	}

}
