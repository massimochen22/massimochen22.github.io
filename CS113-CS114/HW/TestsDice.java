public class TestsDice
{
   public static void main(String[] args)
   {
      Die[]dieList = new Die[50];
      int oddCounter = 0;
      
      for(int i=0; i<50; i++)
      {
         Die di = new Die();
         dieList[i] = di;
      } 
      
      for(Die dic : dieList)
      {
         if(dic.getFaceValue()%2 == 1)
            oddCounter ++;
         
      }
      
      for(Die dic : dieList)
      {
         System.out.print(dic.getFaceValue()+" ");
      }
      
      System.out.println("");
      System.out.println("");
      
      System.out.println("There are "+oddCounter+" odd dice values");
      
   }
   
}