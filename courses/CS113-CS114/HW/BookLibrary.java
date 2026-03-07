
import java.util.Scanner;
public class BookLibrary
{
   public static void main (String[] args)
   {
      Scanner scan = new Scanner(System.in);
      Book [] bookList = new Book[10];
      
      
      System.out.println("MENU");
      
      System.out.println("a - add a book");
      System.out.println("d - delete a book");
      System.out.println("r - Replace a book");
      System.out.println("q - Quit");
      System.out.println("");
      System.out.print("Choose an option:");
      String option = scan.nextLine();
      
      while (! option.equals("q"))
      {
         if (option.equals("a"))
         {
            int count = 0;
            for (int i=0; i<10; i++)
            {
               if(bookList[i]==null)
                  count++;
            }
            
            if (count>0)
            {
               System.out.println("Please type in the title of the book");
               String bookName1 = scan.next();
               
               if(count == 10)
               {
                  System.out.println("How many pages does "+bookName1+" have?");
                  int nPages = scan.nextInt();
                  bookList[0] = new Book(nPages,bookName1);
               }
               
               else
               {
                  int count2 = 0;
                  
                  for(int i = 0; i<10; i++)
                  {
                     if (bookList[i]!=null)
                     {
                        Book checkBook = bookList[i];
                        String checkBookName = checkBook.getTitle();
                        if(bookName1.equals(checkBookName))
                        {
                           System.out.println("no duplicated books titles are allowed");
                           count2++;
                        }
                     }
                  }
                  
                  if (count2==0)
                  {
                     System.out.println("How many pages does "+bookName1+" have?");
                     int nPages = scan.nextInt();
                     for (int i=0; i<10; i++)
                     {  
                        if(bookList[i]==null)
                        {
                           bookList[i] = new Book(nPages,bookName1);
                           break;
                        }
                     }

                  }
               
               }
                  
            }
                
            else
               System.out.println("You already have 10 Books in your library."); 
                     
            
           for (Book value: bookList)
           {
            if (value!=null)
               System.out.println(value);
           }
              
          }
          
          
         if (option.equals("d"))
         {
            int count = 0;
            for (int i=0; i<10; i++)
            {
               if(bookList[i]==null)
                  count++;
            }
            
            if(count == 10)
            {
               System.out.println("The library is empty!");
            }
            
            else
            {
               int count2 = 0;
               System.out.println("What is the title of the book you want to delete?");
               String delTitle = scan.next();
               
               for(int i = 0; i<10; i++)
               {
                  if(bookList[i]!= null)
                  {
                     if (delTitle.equals(bookList[i].getTitle()))
                     {
                        bookList[i] = null;
                        count2++;
                     }
                  }
                  
               }
               
               if(count2==0)
                  System.out.println("The book is not in the library!");
               
            }
               
            for (Book value: bookList)
            {
               if (value!=null)
                  System.out.println(value);
            }
 
         }
            

         if (option.equals("r"))
         {
            int count = 0;
            for (int i=0; i<10; i++)
            {
               if(bookList[i]==null)
                  count++;
            }
            if(count == 10)
            {
               System.out.println("The library is empty!");
            }
            else
            {
               int count2 = 0;
               System.out.println("What is the title of the book you want to change the infos?");
               String delTitle = scan.next();
               
               for(int i = 0; i<10; i++)
               {
                  if(bookList[i]!= null)
                  {
                     if (delTitle.equals(bookList[i].getTitle()))
                     {
                        System.out.println("What is the name of the new book?");
                        String newName = scan.next();
                        System.out.println("How many pages does "+newName+" have?");
                        int newPages = scan.nextInt();
                        bookList[i] = new Book(newPages,newName);
                        count2++;
                     }
                  }
               }
               
               if(count2==0)
                  System.out.println("The book is not in the library!");
            }
               
            for (Book value: bookList)
            {
               if (value!=null)
                  System.out.println(value);
            }
 
                        

         }

          
          
          
          
          
         System.out.println("MENU");
         
         System.out.println("a - add a book");
         System.out.println("d - delete a book");
         System.out.println("r - Replace a book");
         System.out.println("q - Quit");
         System.out.println("");
         System.out.println("Choose an option:");
         option = scan.next();

          }
          
                 
       
                
      }
       
 }
 
 

