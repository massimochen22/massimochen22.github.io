
public class MonetaryCoin extends Coin
{
   private int value;
   
   public MonetaryCoin(int monValue)
   {
      super();
      value = monValue;
      
   }
   
   public void setValue(int newValue)
   {
      value = newValue;
   }
   
   public int getValue()
   {
      return value;  
   }
   
   public String toString()
   {
      return "value: "+ value;
   }
   
}