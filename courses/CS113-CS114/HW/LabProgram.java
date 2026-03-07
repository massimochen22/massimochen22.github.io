import java.util.Scanner;

public class LabProgram {
   public static void main(String[] args) {
   
   Scanner scnr = new Scanner(System.in);
   Scanner scnrr = new Scanner(System.in);
   Scanner scnrrr = new Scanner(System.in);
   
   String specChar;
   int numValues = scnr.nextInt();
   String [] wordList = new String [numValues];
   
   for (int i = 0; i<wordList.length;i++)
   {
      wordList[i] = scnrr.nextLine();
   }
   
   specChar = scnrr.nextLine();
   
   for (String value : wordList)
   {
      if(value.contains(specChar))
         System.out.println(value);
      
    }
   
   
}
}
