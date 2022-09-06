import java.util.Scanner;
public class Die
{
   //data declaration
   private int faceValue;
   
   private String color;
   
   
   //default constructor
   public Die()
   {
      roll(); 
   }
     
   // non default constructor
   public Die(int x)
   {
      faceValue = x;
   }

   public void roll()
   {
      faceValue = (int)(Math.random()*6)+1;
   }
   public int getFaceValue()
   {
      return faceValue;
   }
   
   public void setFaceValue(int newValue) 
   {
      faceValue = newValue;
      
   }
   public String toString()
   {
      return "this die has a face value " + faceValue + " and had color: "+ color;
      
   } 
   
   public String getDiceColor()
   {
      return color;
   }
   
   public void setColor(String newColor) 
   {
      color = newColor;
      
   }
   
            
      

   
}   
