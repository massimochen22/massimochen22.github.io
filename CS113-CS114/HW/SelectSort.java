public class SelectSort{

   public static void selectsort(int[] A) {
   for (int i = 0; i < A.length; i++) {
   // Select i-th record
      int lowindex = i; // Remember its index
      for (int j = A.length - 1; j > i; j--)
   // Find the least value
         if (A[j] < A[lowindex])
            lowindex = j; // Put it in place
   // swap A[i] with A[lowindex];
      int temp = A[i];
      A[i] = A[lowindex];
      A[lowindex] = temp;
      
    }
   }
   
   public static void main (String[] args){
      int [] nArray = {1,2,5,6,8,9,8,5};
      selectsort(nArray);
      for (int x = 0; x < nArray.length; x++)
         System.out.println(nArray[x]);
   }
 }
 