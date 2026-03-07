//***********************
//File Name: Hello.class
//Author : Massimo Chen
//Date:  1/27/2020
//***********************
import java.util.Random;

public class EV 
{  
   private int range;
   private String model;
   
   public EV(int r, String m)
   {
      range = r;
      model = m;
   }
   
   public int getRange()
   {
      return range;
   }   
   public String getModel()
   {
      return model;
   }  
   
   public void setRange(int newRange)
   {
      range = newRange;
   }
   
   public String toString()
   {
     return model+","+range;
   }
   
   public int compareTo(EV other)
   {
      if (range > other.getRange())
         return 1;
         
      else if (range < other.getRange())
         return -1;
         
      else 
         return 0;  
      
   }
   
   public boolean sameModel(EV other)
   {
      return model.equals(other.getModel());
      
   }
}

   