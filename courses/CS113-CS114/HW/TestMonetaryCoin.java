import java.util.Random;

public class TestMonetaryCoin
{
   public static void main(String[] args)
   {
      Random rand = new Random();
      int[]coinType = {1,5,10,25,50,100};
      int[]coinList = new int[25];
      int count = 0;
      int totValue = 0;
      
      
      for (int i=0;i<25;i++)
      {
         int n = rand.nextInt(6);
         
         MonetaryCoin mon = new MonetaryCoin(coinType[n]);
         
         if (!mon.isHeads())
         {
            coinList[count] = mon.getValue();
            count++;
         } 
      
      }
      
      
      
      for (int num : coinList)
      {
         totValue = totValue +num;
      }
       
      System.out.println("There are "+count+" TAIL coins");
      
      System.out.println("The sum of all TAIL coins is: "+totValue);
      
      System.out.println("The average value is: "+totValue*1.0/count);
      
   }
}   