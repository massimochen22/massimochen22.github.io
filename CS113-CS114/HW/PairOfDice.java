import java.util.Scanner;
public class PairOfDice
{
   
   String colorD1, colorD2;
   Die d1 = new Die();
   Die d2 = new Die();
   Scanner scan = new Scanner(System.in);

   
   
   public PairOfDice()
   {
      rollDice();
      pairSum();
      
   }
   public void rollDice()
   {
      d1.roll();
      d2.roll();
   }
   
   public Die getD1()
   {  
      return d1;
   }
   
   public Die getD2()
   {  
      return d2;
   }

   public void setD1(int valueD1) 
   {
      d1.setFaceValue(valueD1);    

   }
   
   public void setD2(int valueD2)
   {
      d2.setFaceValue(valueD2);  
   }
   
   public void setD1Color()
   {  
      System.out.print("Please, enter the color of your 1st die: ");
      String color = scan.nextLine();
      d1.setColor(color);
   }
    
   public void setD2Color()
   {  
      System.out.print("Please, enter the color of your 2nd die: ");
      String color = scan.nextLine();
      d2.setColor(color);
   }
   
   
   
   public int pairSum()
   {
      return d1.getFaceValue() + d2.getFaceValue();
     
   }    
   
   public String toString()
   {
      return   "Colors of the two dice: " + d1.getDiceColor() + "," + d2.getDiceColor(); 
   } 


}   
