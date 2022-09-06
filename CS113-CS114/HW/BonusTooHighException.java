import java.util.Scanner;

public class BonusTooHighException extends Executive
{
   public BonusTooHighException(String eName, String eAddress, String ePhone,
                    String socSecNumber, double rate, double execBonus)
   {
      super(eName, eAddress, ePhone, socSecNumber, rate);
 
      bonus = execBonus;
   }
   
   public static void main (String[] args) throws OutOfRangeException
   {
      final int MIN = 0, MAX = 10000;
      Scanner scan = new Scanner(System.in);
      Scanner scan2 = new Scanner(System.in);
      Scanner scan3 = new Scanner(System.in);
      
      
      System.out.print("How many executives do you want? ");
      int x = scan.nextInt();
      
      BonusTooHighException[] newList = new BonusTooHighException[x];
      
      OutOfRangeException exept =new OutOfRangeException("Bonus can't be more than 10000$ or less than 0$.");
      
      for (int i = 0; i<newList.length;i++)
      {
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
         
         
         System.out.print("Type in his/her bonus");
         double execBonus = scan3.nextDouble();
         
         if (execBonus  < MIN || execBonus  > MAX)
           throw exept;
         
         
         newList[i] = new BonusTooHighException(eName,eAddress,ePhone, socSecNumber,rate,execBonus);
      } 
   }
   
}
