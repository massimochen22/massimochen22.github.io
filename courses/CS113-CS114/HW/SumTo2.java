import java.security.PrivilegedExceptionAction;
import java.util.*;

public class SumTo {
      public static boolean combination(String a,String b){
          return combination(a,0,Integer.valueOf(b));
      }
      public static boolean combination(String a,int index, Integer goal){

          if(goal<=0||index>=a.length())
              return false;

          if(Integer.valueOf(a.substring(index,a.length()))<goal)
              return false;

          if(Integer.valueOf(a.substring(index,a.length())).equals(goal)){
                System.out.print(a.substring(index,a.length())+" ");
              return true;
          }
          //base case;
          for(int i=1;i<=a.length()-index;i++) {

              int left = Integer.valueOf(a.substring(index,index+i));
              //System.out.println(index+" "+i+" "+goal+" "+left);

              if(combination(a,index+i,goal-left)){
                  System.out.print(a.substring(index,index+i)+" ");
                  return true;
              }
          }
          return false;
      }
      public static void main(String[] args){
          System.out.println(combination("123456789","4248"));
      }
  }
