//***********************
//File Name: Hello.class
//Author : Massimo Chen
//Date:  2/7/2020
//Purpose: Homework1 
//***********************

import java.util.Scanner;

public class Hw1_HaoMassimoChen
{
   public static void main (String[]args)
   {
      // This is the first part (2.5)
      // It converts inches in feet
      float inches, feet;
      
      Scanner conv = new Scanner(System.in);
      
      System.out.print("Please, insert how many inches you want to convert in feet");
      
      inches = conv.nextFloat();
      
      feet = inches/12;
      
      System.out.println("In Feet = "+ feet);
      
      // This is the second part (2.6)
      // It converts grams in pound
     
      double grams, pound;   
      
      System.out.print("Please, insert how many grams you want to convert in pound:");
      
      grams = conv.nextDouble();
      
      pound = grams / 453.59237;
      
      System.out.println("In Pounds = "+ pound);
      
      // This is the third part (2.8)
      // It reads the input (weight) in milligrams
      
      float kg, g, mg, milligrams;
           
      System.out.print("Enter kilograms:");
      
      kg = conv.nextFloat();
      
      System.out.print("Enter grams:");
      
      g = conv.nextFloat();
      
      System.out.print("Enter milligrams:"); 
      
      mg = conv.nextFloat(); 
      
      milligrams = (kg*1000000)+(g*1000)+ mg;
      
      System.out.println("In Milligrams = " + milligrams);
      
      // This is the fourth part (2.9)
      // It reads the input (weight) from milligrams to kilograms,grams, and milligrams
      
      int kg2, g2, mg2, milligrams2;
      
      System.out.print("Please enter milligrams:");
      
      milligrams2 = conv.nextInt();
      
      kg2 = milligrams2 / 1000000;
      
      g2 = (milligrams2 / 1000)-(kg2*1000);
      
      mg2 = milligrams2 - (g2*1000 + kg2*1000000);
      
      System.out.print("Kilograms="+ kg2 + " grams="+g2+" milligrams="+mg2);
      
 
    }
    
}
       