public class RecursiveMultiply

{
   public static long recursiveMultiply(int a, int b)
   {
      if(a == 0) 
         return 0;
         
      if (a == 1)
         return b;
         
      else 
         return recursiveMultiply(a-1,b)+b; 
    }
    
    public static void main (String[] args)
    {
      //long startTime = System.nanoTime();
      long result = recursiveMultiply(20,20);
      System.out.println(result);
      //long endTime = System.nanoTime();
      //System.out.println("Total execution time: " + (endTime - startTime));
    }

}