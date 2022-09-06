import java.util.Scanner;

public class Executives extends Executive
{
   public Executives(String eName, String eAddress, String ePhone,
                    String socSecNumber, double rate, double execBonus)
   {
      super(eName, eAddress, ePhone, socSecNumber, rate);
 
      bonus = execBonus;
   }
   

   public String toString()
   {
      String result = super.toString();

      result += "\nBonus Amount: " + bonus;

      return result;
   }

   
   public static void main (String[] args) throws OutOfRangeException
   {
      final int MIN = 0, MAX = 10000;
      Scanner scan = new Scanner(System.in);
      Scanner scan2 = new Scanner(System.in);
      Scanner scan3 = new Scanner(System.in);
      int count = 0;
      
      
      System.out.print("How many executives do you want? ");
      int x = scan.nextInt();
      
      Executives[] newList = new Executives[x];
      
      OutOfRangeException exept =new OutOfRangeException("Bonus can't be more than 10000$ or less than 0$.");
      
      for (int i = 0; i<newList.length;i++)
      {
         System.out.println("");
         try
         {
            System.out.print("Type in executive number: "+(i+1)+" bonus:");
            double execBonus = scan3.nextDouble();
            
            if (execBonus  < MIN || execBonus  > MAX)  
               throw exept;
         
            System.out.print("Type in the name of the executive number: "+(i+1));
            String eName = scan2.nextLine();
            
            System.out.print("Type in his/her address");
            String eAddress = scan2.nextLine();
            System.out.print("Type in his/her phone number in this format: 000-0000");
            String ePhone = scan2.nextLine();
            System.out.print("Type in his/her social security number in this format: 000-00-0000");
            String socSecNumber = scan2.nextLine();
            
            System.out.print("Type in his/her pay rate");
            double rate = scan3.nextDouble();
            
            

            
            newList[i] = new Executives(eName,eAddress,ePhone, socSecNumber,rate,execBonus);
            count++;
            
         }
         
         catch(OutOfRangeException exeption)
         {
            System.out.println(exept.getMessage());
            double execBonus = 0;
            System.out.print("Type in the name of the executive number: "+(i+1));
            String eName = scan2.nextLine();
            
            System.out.print("Type in his/her address");
            String eAddress = scan2.nextLine();
            System.out.print("Type in his/her phone number in this format: 000-0000");
            String ePhone = scan2.nextLine();
            System.out.print("Type in his/her social security number in this format: 000-00-0000");
            String socSecNumber = scan2.nextLine();
            
            System.out.print("Type in his/her pay rate");
            double rate = scan3.nextDouble();

            newList[i] = new Executives(eName,eAddress,ePhone, socSecNumber,rate,execBonus);
         }
         
         
      } 
      
      for (Executives v:newList)
      {
         System.out.println(v);
         System.out.println("-----------------");
      }
      
      
      System.out.println("Total number of executives with valid bonuses is: "+count);

      
      
   }
   
}
