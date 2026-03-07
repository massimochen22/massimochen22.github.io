import java.util.*;

public class SumTo3{

      
   public boolean sumTo(int given, int goal, ArrayList <Integer> aList, int givenDigLen, int goalDigLen, String givenInStr){
      
   
      if (goal>given)
         return false;
         
      // else if (given==goal)
//          return true;
         
      else{
         
         int minValue = given;
         
         for (int i = 0; i < givenDigLen-goalDigLen; i++){ //the for loop is to get the smallest number with same digit first
         
            String tempString = givenInStr.substring(i,i+goalDigLen);
            int tempNum = Integer.parseInt(tempString);
            if (tempNum < minValue)
               minValue = tempNum;
         }
         
         String valueToDelete = Integer.toString(minValue); //change the minValue in string
         String newGivenInStr = givenInStr.replace(valueToDelete, ""); //deletes the smallest number with same digit in the original givenInStr
         ArrayList<Integer> updatedList = intToList(Integer.parseInt(newGivenInStr)); // transform the string "number" into list of integer again
         
         int totValue = 0;
         
         for (int x = 0; x <updatedList.size(); x++){ //sum all the single integers present in the list 
            totValue = totValue + updatedList.get(x);
         }
         
         if (goal-minValue < totValue) {
            return sumTo(given, goal, aList, givenDigLen, goalDigLen-1, String givenInStr); //do the same thing again but check for the smallest number with goalDigLen-1 digit
         }
         
         else if (goal-minValue == totValue)
            return true;
            
         else{
            
            int maxValue = 0;
            
            for (int y = 0; y < givenDigLen-goalDigLen; y++){ //the for loop is to get the largest number with same digit first
            
               String tempString = givenInStr.substring(i,i+goalDigLen);
               int tempNum2 = Integer.parseInt(tempString);
               if (tempNum2 > maxValue && maxValue<goal)
                  maxValue = tempNum2;
               
            }
            
            String valueToDelete2 = Integer.toString(maxValue); //change the maxValue in string
            String newGivenInStr2 = givenInStr.replace(valueToDelete2, ""); //deletes the largest number with same digit in the original givenInStr
            ArrayList<Integer> updatedList2 = intToList(Integer.parseInt(newGivenInStr2)); // transform the string "number" into list of integer again
            
            int totValue2 = 0;
            
            for (int x = 0; x <updatedList2.size(); x++){ //sum all the single integers present in the list 
               totValue2 = totValue2 + updatedList2.get(x);
            }
            
            if (goal-minValue < totValue2) {
               return sumTo(given, goal, aList, givenDigLen, goalDigLen-1, String givenInStr); //do the same thing again but check for the smallest number with goalDigLen-1 digit
            }
            
            else if (goal-minValue == totValue2)
               return true;
               


         }
      }
   
   }
   
   public static ArrayList intToList(int given){  //convert the integer to a list
   
      int num = given;
      ArrayList<Integer> templist = new ArrayList<Integer>( );
      ArrayList<Integer> arList = new ArrayList<Integer>( );
   
      while (num > 0) {   
         templist.add(num % 10);
         num = num / 10;         
      }  
      
      for (int i = templist.size()-1; i>=0; i--){
         arList.add(templist.get(i));   
      }
     
      return arList;   
    }
   


   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      String wholeString = scan.nextLine();
      
      
      String [] b = wholeString.split(" ");
      int firDigLen = b[0].length();
      int secDigLen = b[1].length();
      System.out.println(Arrays.toString(b));
      
      ArrayList<Integer> asd = intToList(Integer.parseInt(b[0]));      
      
      System.out.println(asd); 
      
      System.out.println(firDigLen);
      System.out.println(secDigLen);
      
   }


}