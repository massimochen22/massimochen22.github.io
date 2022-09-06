import java.util.Scanner;
public class TestAccounts1
{
   public static void main (String[] args)
   {  
       Scanner scan = new Scanner(System.in);
       System.out.println("Please type in how many accounts you want to generate");
       int nAcc = scan.nextInt();
       for (int i = 0; i<nAcc; i++)
       {  
          String s = i + "";
          Account l = new Account(s);
          
        }
      System.out.println("There are a total of: "+Account.getNumAccounts()+" accounts.");       
       
    }

}

