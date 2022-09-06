
import java.util.Scanner; 

public class HW7
{
// Problem 1
//    Implement a recursive method printDigits that takes an integer num as a parameter and
//    prints its digits in reverse order, one digit per line.
   public static void printDigits(int n)
   {
        
     if (n < 10)  
         System.out.print(n);

     else 
     {   
         System.out.print(n % 10);
         printDigits(n/10);
      }            
   }
   
   
   
// Problem 2   
// Design and implement a program that implements Euclid’s algorithm for finding the
// greatest common divisor of two positive integers. The greatest common divisor is the
// largest integer that divides both values without producing a remainder. An iterative
// version of this method was part of the RationalNumber class presented in Chapter 6. In a
// class called DivisorCalc, define a static method called gcd that accepts two integers,
// num1 and num2. Create a driver to test your implementation. The recursive algorithm is
// derived as follows:
// - gcd(num1, num2) is num2 if num2<=num1 and num2 divides num1
// - gcd(num1, num2) is gcd(num2, num1) if num1<num2
// - gcd(num1, num2) is gcd(num2, num1%num2) otherwise
          
   public static void gcd(int n1, int n2)
   {
      if (n2<=n1 && n1%n2 == 0)
         System.out.print(n2);
         
      else if (n2>n1)
         gcd(n2,n1);
      
      else 
         gcd(n2, n1%n2);
      
      
   }       
   
   
//    Problem 3
//    "Design and implement a recursive program to determine and print the Nth line of
//    Pascal's Triangle, as shown below. Each interior value is the sum of the two values above
//    it. Hint: use an array to store the values on each line."

    public static int[] PascT(int number)
    {
         int[] list = new int[number+1];
         if(number == 0)
         {
            list[0] = 1;
            return list;
         } 
         else
         {
            int[] list2 = PascT(number-1);
            
            list[0] = list[number] = 1;
            for(int i = 1; i < list2.length; i++)
               list[i] = list2[i-1] + list2[i];    
         }     
         
         return list;
     }
     
          
   
   public static void main(String[] args)
   { 
       Scanner scan = new Scanner(System.in);
       
       // try Problem 1
       System.out.println("please enter a number for problem 1");
       int numb1 = scan.nextInt();
       printDigits(numb1); 
       
       System.out.println("");
       
       // try problem 2
       System.out.println("please enter two numbers for problem 2 in order to check their GCD");
       int numb2 = scan.nextInt();
       int numb3 = scan.nextInt();
       gcd(numb2, numb3);   
       
       System.out.println("");
       
       // try problem 3
       System.out.println("please enter the nth line of the pascal triangle you want");
       int numb4 = scan.nextInt();
       int []list2 = PascT(numb4);
       for (int i =0; i<list2.length;i++)  
          System.out.print(list2[i]+" ");

   } 
} 