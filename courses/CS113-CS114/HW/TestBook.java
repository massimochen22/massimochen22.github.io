import java.util.Scanner;

public class TestBook
{
   public static void main (String[] args)
   {  
      double average;
      int n_pages,tot_pages;
      Scanner scan = new Scanner(System.in);
      
      
      System.out.println("Please, type in how many pages would you like in your book.");
      n_pages = scan.nextInt();
      
      Book book1 = new Book(n_pages);
      Book book2 = new Book();
      
      average = (book1.getter() + book2.getter())/2.0;
      System.out.println("The average pages between these two books is "+average);

      tot_pages = book1.getter() + book2.getter();
      Book book3 = new Book(tot_pages);
      System.out.println(book3.toString());
            
   }  
    
}

      