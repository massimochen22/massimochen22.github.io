public class TotalOdds
{  
   private int count = 0;
   public TotalOdds(int[]numArray)
   {    
      for(int value : numArray)
      {
         if (value%2 != 0)
            count += 1;
      }
          
   }
   
   public String toString()
   {
      return "there are "+count+" odds";
   }
    
}  