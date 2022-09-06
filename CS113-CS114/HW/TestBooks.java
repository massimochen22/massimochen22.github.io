import java.util.ArrayList;
import java.util.Scanner;

public class TestBooks
{
   public static void main (String[] args)
   { 
      Scanner scan = new Scanner(System.in);
      Scanner scan2 = new Scanner(System.in);
      int numBooks;
      double avePages,pageSum;
      ArrayList<Book> listBooks = new ArrayList<Book>();
      
      pageSum = 0.0;
      
      System.out.print("How many books did you read this summer? ");
      numBooks = scan.nextInt(); 
      
      for(int i = 0;i != numBooks; i++)
      {  
      
         System.out.print("Please insert the n:"+ (i+1) + " book's total pages ");
         int n_page = scan.nextInt();
         pageSum += n_page;
         System.out.print("Please insert the n:"+ (i+1) + " book'title ");
         String title_b = scan2.nextLine();
         
         Book bi = new Book(n_page,title_b);
         listBooks.add(bi);
         
      }
      
      avePages = pageSum / numBooks;
      System.out.println("The average number of pages per book you read is "+ avePages);
      
      
      for(int j = 0;j != numBooks; j++)
      {  
         Book b1 = listBooks.get(j);
         int value = 0;
         for(int z = 0; z != numBooks; z++)
         {  
            Book b2 = listBooks.get(z);
            if (b1.compareTo(b2) == -1)
               value += 1;     
          } 
         if (value == (numBooks - 1))
            System.out.println(b1+ ". This is the smallest book you read.");
       }
      
    }
}
     