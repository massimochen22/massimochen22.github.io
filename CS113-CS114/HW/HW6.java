import java.util.*;
public class HW6
{
   static boolean abc(int[] a, int n) {
    if (n <= 1)
        return false;
    for (int i = 0; i < n - 2; ++i)
        for (int j = i; j < n - 1; ++j)
            if (a[i] + a[j] == a[n - 1])
                return true;
    return abc(a, n - 1); 
   }

   public static void main(String[] args)
   {
    
    // int num=1020; // int number
//     while (num > 0) {
// 
      String n = new String ("SFASD");
      System.out.println( n.substring(1));

      // num = num / 10;

      }


   }

