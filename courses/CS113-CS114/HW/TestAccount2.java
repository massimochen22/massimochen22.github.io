import java.util.Scanner;
public class TestAccount2
{  
   public static void main (String[] args)
      {  
         Scanner scan = new Scanner(System.in);
         System.out.println("Please insert your name");
         String name1 = scan.nextLine();
         System.out.println("Ok. Please insert your second name");
         String name2 = scan.nextLine();
         System.out.println("Ok. Please insert your third name");
         String name3 = scan.nextLine();
         
         Account acct1 = new Account(100,name1);
         Account acct2 = new Account(100,name2);
         Account acct3 = new Account(100,name3);
         
         System.out.println(acct1);
         System.out.println(acct2);
         System.out.println(acct3);
         
         acct1.close();
         
         System.out.println(Account.consolidate (acct2,acct3));
         System.out.println(acct1);
         System.out.println(acct2);
         System.out.println(acct3);
         
         System.out.println("There are a total of: "+Account.getNumAccounts()+" accounts."); 
         
      }
      
}