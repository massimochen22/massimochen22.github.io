//************************************************************
// A bank account class with methods to deposit to, withdraw from,
// change the name on, and get a String representation
// of the account.
//************************************************************
import java.util.Random;
public class Account
{
   private double balance;
   private String name;
   private long acctNum;
   private static int numAccounts;
   //-------------------------------------------------
   //Constructor -- initializes balance, owner, and account number
   //-------------------------------------------------
   public Account(double initBal, String owner, long number)
   {
      balance = initBal;
      name = owner;
      acctNum = number;
      numAccounts += 1;
   }
   
   public Account(double initBal, String owner)
   {
      Random gen = new Random();
      balance = initBal;
      name = owner;
      acctNum = Math.abs(gen.nextInt());
      numAccounts += 1;
   }
   
   public Account(String owner)
   {
      Random gen = new Random();
      balance = 0;
      name = owner;
      acctNum = Math.abs(gen.nextInt());
      numAccounts += 1;
   }
   
   public void withdraw(double amount)
   {  
      double fee = 2.5;
      if (balance >= (amount+fee))
         balance -= (amount+fee); 
      
      else
         System.out.println("Insufficient funds");
   }
   
   public void close()
   {
      name += " CLOSED";
      balance = 0.0;
      numAccounts -= 1;
   }
      
   //-------------------------------------------------
   // Adds deposit amount to balance.
   //------------------------------------------------- 
   // 110 Chapter 7: Object-Oriented Design
   public void deposit(double amount)
   {
      balance += amount;
   }
   //-------------------------------------------------
   // Returns balance.
   //-------------------------------------------------
   public double getBalance()
   {
      return balance;
   }
   
   public String getName()
   {
      return name;
   }
   
   public long getAcctNum()
   {
      return acctNum;
   }


   
   public static int getNumAccounts()
   {
      return numAccounts;
   }
   
   //-------------------------------------------------
   // Returns a string containing the name, account number, and balance.
   //-------------------------------------------------
   public String toString()
   {
      return "Name:" + name +
      "\nAccount Number: " + acctNum +
      "\nBalance: " + balance;
   }
   
   public static Account consolidate (Account acct1, Account acct2)
   {
      double sum = acct1.getBalance() + acct2.getBalance();
      String name1 = acct1.getName();
      String name2 = acct2.getName();
      long acctNum1 = acct1.getAcctNum();
      long acctNum2 = acct2.getAcctNum();
      
      if ((name1.equals(name2))&& (acctNum1 != acctNum2))
      {
         Account newAcc = new Account (sum,name1);
         acct1.close();
         acct2.close();
         
         return newAcc;
      }
      
      else
      {
         System.out.println("Error! your accounts have either same account numbers or different account names.");
         return null;
      }
      
      
   }
}