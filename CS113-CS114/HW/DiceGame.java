import java.util.Scanner;
public class DiceGame
{
   public static void main (String[] args)
   {
      System.out.println("Tell me a number between 2 to 12. Roll two dice, and if you get the number you chose, you earn 5 points!");
      System.out.println("You have three chances.");
      System.out.println("If the number does not come up within 3 rolls, I will earn 3 points!");
      System.out.println("The first one who scores 100 wins!");
      Scanner scan = new Scanner(System.in);
      Scanner scan2 = new Scanner(System.in);

      int points1 = 0;
      int points2 = 0;
      
      
      while (points1 <= 100 && points2 <= 100)
      {
         System.out.println("Please type in the number you want to guess (between 2-12).");
         int num_guess = scan.nextInt();
         int chance = 0;
         
         for (int i=0; i<3; i++)
         {
            System.out.println("Type \"yes\" to roll the two dice. (incorrect input go back to the previous question)");
            String ans = scan2.nextLine();
            
            if (ans.equals("yes"))
            {
               Die d1 = new Die();
               Die d2 = new Die();
               int tot = d1.getFaceValue() + d2.getFaceValue();
               System.out.println("the total value of the two dice you rolled is: "+tot);
               if (num_guess == tot)
               {
                  System.out.println("congrats you guessed right. +5 points!");
                  points2 += 5;
                 
                  break;
                }
                else
                {
                  chance += 1;
                }
            }
            
            else 
            {
               break;
            }    
               
          }
          
         if (chance == 3)
         {
            System.out.println("You didn't guess it right within 3 chances. I got +3 points!");
            points1 += 3;
         
         }
         
         System.out.println("Your current score is: "+ points2+". My score is: "+points1);
          
      }
      if (points1>points2)
      {
         System.out.println("Game Over! I won!");
      }
      else
      {
         System.out.println("Congrats! You won!");  
         
      }
        
   }
   
}