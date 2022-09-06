import java.util.Scanner;
import java.util.Random;

public class NameApp
{
   public static void main (String[] args)
   {  
      // This is the first part of the Homework
      //It creates an username with the first character
      //of your first name, 5 first characters of the last name
      // and a random number from 10 to 99
      
      String first_name, last_name, five_lett;
      int rand_num;
      Random generator = new Random();    
      Scanner scan = new Scanner(System.in);
      
      System.out.println("Please, type in your first Name.");
      first_name = scan.nextLine();
      System.out.println("Please, type in your last Name.");
      last_name = scan.nextLine();
      char first_char = first_name.charAt(0);
      five_lett = last_name.substring(0,5);
      rand_num = generator.nextInt(90)+10;
      
      System.out.println("your username is: "+first_char+five_lett+rand_num);
      
      //This is the second part of the homework 
      //It tells the average lenght of the three names that the user input
      //and also it prints the first characters of the three names
      
      String name1, name2, name3, totname;
      String chara1, chara2, chara3;
      double average;
      int len1, len2, len3;
      
      System.out.println("Please insert a name");
      name1 = scan.nextLine();
      System.out.println("Please insert a second name");
      name2 = scan.nextLine();
      System.out.println("Please type insert a third name");
      name3 = scan.nextLine();
      
      len1 = name1.length();
      len2 = name2.length();
      len3 = name3.length();
      
      chara1 = name1.substring(0,1);
      chara2 = name2.substring(0,1);
      chara3 = name3.substring(0,1);
      
      
      average = (len1 + len2 + len3) / 3.0;
      totname = chara1 + chara2 + chara3;
      
      System.out.println(average);
      
      System.out.println(totname);
      
            
     
    }

}