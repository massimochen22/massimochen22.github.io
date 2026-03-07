import java.util.Scanner;

public class ThreeBiasedCoins
{
   public static void main (String[] args)
   {
      Scanner scan = new Scanner(System.in);
      Coin c1 = new Coin();
      System.out.println("Please, insert the bias for the second coin (a fraction from 0-1)");
      double b1 = scan.nextDouble();
      Coin c2 = new Coin(b1);
      System.out.println("Please, insert the bias for the third coin (a fraction from 0-1)");
      double b2 = scan.nextDouble();
      Coin c3 = new Coin(b2);
      
      int count1 = 0,count2 = 0,count3 = 0;
      for (int i=0;i<100; i++)
      {
         c1.flip();
         c2.flip();
         c3.flip();
         if (c1.isHeads())
            count1 += 1;
         if (c2.isHeads())  
            count2 += 1;
         if (c3.isHeads())  
            count3 += 1;
      
       }
    
       System.out.println("count1: "+count1);
       System.out.println("count2: "+count2);             
       System.out.println("count3: "+count3);
       
   }
   
}