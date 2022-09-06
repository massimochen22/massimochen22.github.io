import java.util.Scanner;

public class Scratch {
   public static int count = 0;
   public static int count2 = 0;
   public static void printNumPattern(int n1, int n2)// TODO: Write recursive printNumPattern() method 
   {
      if (n1>0 && count ==0)
      {
         System.out.print(n1+" ");
         count2++;
         printNumPattern(n1-n2,n2);
      }
      
      else
      {
         count = 1;
         
         if (count2>=0)
         {
            System.out.print(n1+" ");
            count2--;
            printNumPattern(n1+n2,n2);
          }
          
       }
   }

  
   public static void main(String[] args) { 
      Scanner scnr = new Scanner(System.in);
      int num1;
      int num2;
      
      num1 = scnr.nextInt();
      num2 = scnr.nextInt();
      printNumPattern(num1, num2); 
   } 
} 