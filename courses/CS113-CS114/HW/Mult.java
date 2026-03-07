public class MultRecursion

{
   public static long multRecursion(int a, int b)
   {
      if(a == 0) 
         return 0;
         
      if (a == 1)
         return b;
         
      else 
         return mult(a-1,b)+b; 
    }
    
    public static void main (String[] args)
    {
      //long startTime = System.nanoTime();
      long result = multRecursion(20000000,20000000);
      System.out.println(result);
      //long endTime = System.nanoTime();
      //System.out.println("Total execution time: " + (endTime - startTime));
    }

}