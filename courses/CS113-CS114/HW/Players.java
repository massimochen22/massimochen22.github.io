//***********************
//File Name: Players.class
//Author : Massimo Chen
//Date:  1/27/2020
//***********************
import java.util.Scanner; 

public class Players {

   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      int [][] rostList = new int [2][5];
      
      for (int i = 0; i<5; i++)
      {
         System.out.println("Enter player "+(i+1)+"'s jersey number:");
         rostList[0][i] = scnr.nextInt();
         System.out.println("Enter player "+(i+1)+"'s rating:");
         rostList[1][i] = scnr.nextInt();
         System.out.println("");
      }
      
      
      System.out.println("ROSTER");
      for (int i = 0; i<5; i++)
      {
         System.out.println("Player "+(i+1)+" -- Jersey number: "+rostList[0][i]+", Rating: "+rostList[1][i]);
      }
      
      System.out.println("");
      System.out.println("MENU");
      System.out.println("u - Update player rating");
      System.out.println("a - Output players above a rating");
      System.out.println("r - Replace player");
      System.out.println("o - Output roster");
      System.out.println("q - Quit");
      System.out.println("");
      System.out.println("Choose an option:");
      
      String option = scnr.next();

         
      
      while (! option.equals("q"))
      {
                  
         if (option.equals("u"))
         {
            System.out.println("Enter a jersey number:");
            int checkNum = scnr.nextInt();
            System.out.println("Enter a new rating for player:");
            int newRating = scnr.nextInt();
            
            for (int i = 0; i<5; i++)
            {
               if (rostList[0][i]==checkNum)
                  rostList[1][i]=newRating;
            }

         }
         
         if (option.equals("a"))
         {
            System.out.println("Enter a rating:");
            int checkRating = scnr.nextInt();
            System.out.println("");
            System.out.println("ABOVE "+checkRating);
            for (int i = 0; i<5; i++)
            {
               if (rostList[1][i]>checkRating)
                  System.out.println("Player "+(i+1)+" -- Jersey number: "+rostList[0][i]+", Rating: "+rostList[1][i]);
  
            }
         }
         
         if (option.equals("r"))
         {
            System.out.println("Enter a jersey number:");
            int chNum = scnr.nextInt();
            
            for (int i = 0; i<5; i++)
            {
               if (rostList[0][i]==chNum)
               {
                  System.out.println("Enter a new jersey number:");
                  int repNum = scnr.nextInt();
                  System.out.println("Enter a rating for the new player:");
                  int repRating = scnr.nextInt();
                  rostList[0][i] = repNum;
                  rostList[1][i] = repRating;
               }
                           
            }
         }
         
         if (option.equals("o"))
         {
            System.out.println("ROSTER");
            for (int i = 0; i<5; i++)
            {
               System.out.println("Player "+(i+1)+" -- Jersey number: "+rostList[0][i]+", Rating: "+rostList[1][i]);
            }

         }
         
         System.out.println("");
         System.out.println("MENU");
         System.out.println("u - Update player rating");
         System.out.println("a - Output players above a rating");
         System.out.println("r - Replace player");
         System.out.println("o - Output roster");
         System.out.println("q - Quit");
         System.out.println("");
         System.out.println("Choose an option:");      
         option = scnr.next();
         

      }
   }
}

