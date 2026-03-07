import java.security.PrivilegedExceptionAction;
import java.util.*;

public class SumTo {


      public static ArrayList<String> theList = new ArrayList<String>( );

      public static boolean combination(String a,String b){
          return combination(a,0,Integer.valueOf(b));
      }
      public static boolean combination(String a,int index, Integer goal){

          if(goal<=0||index>=a.length())
              return false;

          if(Integer.valueOf(a.substring(index,a.length()))<goal)
              return false;

          if(Integer.valueOf(a.substring(index,a.length())).equals(goal)){
                theList.add(a.substring(index,a.length()));
              return true;
          }
          //base case;
          for(int i=1;i<=a.length()-index;i++) {

              int left = Integer.valueOf(a.substring(index,index+i));
//              System.out.println(index+" "+i+" "+goal+" "+left);

              if(combination(a,index+i,goal-left)){
                  theList.add(a.substring(index,index+i));
                  return true;
              }
          }
          return false;
      }
      public static void main(String[] args){
          Scanner scan = new Scanner (System.in);
          String wholeString = scan.nextLine();
          String [] intList = wholeString.split(" ");

          if(combination(intList[0],intList[1])!= true)
              System.out.print(false);
           
          else{
          
             Collections.reverse(theList);
                       
             for(int y =0; y<theList.size(); y++) {
                  
                 System.out.print(theList.get(y));
                 if (y != theList.size()-1)
                     System.out.print("+");     
             }
          
          

      }
  }

}