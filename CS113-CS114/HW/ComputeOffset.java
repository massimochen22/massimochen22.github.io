//***********************
//File Name: Hello.class
//Author : Massimo Chen
//Date:  1/27/2020
//***********************

import java.util.Scanner;

public class ComputeOffset {

   public static void main (String [] args) {
      Scanner scnr = new Scanner(System.in);
      final int SCORES_SIZE = 4;
      int[] oldScores = new int[SCORES_SIZE];
      int[] newScores = new int[SCORES_SIZE];
      int i;

      for (i = 0; i < oldScores.length; ++i) {
         oldScores[i] = scnr.nextInt();
      }

      for (i = 0; i < oldScores.length; ++i) {
         newScores[i] = oldScores[oldScores.length-(1+i)];
      }

      for (i = 0; i < newScores.length; ++i) {
         System.out.print(newScores[i] + " ");
      }
      System.out.println();
   }
}