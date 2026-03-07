public class TestPairOfDice
{
   public static void main (String[] args)
   {
      PairOfDice p1 = new PairOfDice();
      p1.setD1Color();
      p1.setD2Color();
      System.out.println(p1);
      System.out.println("Sum of face values before roll: " +p1.pairSum());
      p1.rollDice();
      System.out.println("Sum of face values after roll: " + p1.pairSum());
      
   }
}  
    
