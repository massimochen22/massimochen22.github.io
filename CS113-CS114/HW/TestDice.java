public class TestDice
{
   public static void main (String[] args)
   {
      Die d1 = new Die();
      Die d2 = new Die();
      
      
      //d1.roll();
      //d2.roll();
      
      
      // System.out.println(d1.getFaceValue());
//       
//       System.out.println(d2.getFaceValue());
      
      //d1.setFaceValue(3);
      //prints the address
      System.out.println(d1);
      d1.setColor("red");
      System.out.println(d1.getDiceColor());
   }
   
}
      
      