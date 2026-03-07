import java.util.Random;

public class Book
{
   //stores the number of pages
   private int pages;
   
   //stores the title of the book
   private String title;
   
   //A constructor that accepts and creates a book object with the specified number of pages and title.
   public Book(int x, String s)
   {
      pages = x;
      title = s;
   }

  //This constructor will accept a book with random pages
   public Book()
   {
      randPages(); 
   }
   
   //this is used to randomly generate numbers for the random-n_pages book
   public void randPages()
   {
      Random generator = new Random();
      pages = generator.nextInt(101)+200;
   }

   //A getter method for pages.
   public int getPages()
   {
      return pages;
   }
   
   //A setter method for pages.
   public void setPages(int newPages) 
   {
      pages = newPages;  
   }
   
   //getter method for title 
   public String getTitle()
   {
      return title;
   }
   
   //A setter method title
   public void setTitle(String newTitle)
   {
      title = newTitle;
   }
   
   public boolean equals(Book book2)
   {
      return title.equals(book2.title) && pages == book2.pages;
   }
      
   // It returns the book’s number of pages.
   public String toString()
   {
      return "this book is called \""+ title+ "\" and has " + pages + " pages";   
   } 
   
   public int compareTo(Book book2)
   {
      int y = this.getPages();
      
      if (y < book2.getPages())
         return -1;
      
      else if (y == book2.getPages())
         return 0;
      
      else if (y > book2.getPages())
         return 1;
         
      return -2;
      
    }
        

}