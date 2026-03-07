import java.util.Scanner;
public class MyMethods
{
   public int surface()
   {
      int n_width,n_length,n_height,area;
      
      Scanner scan = new Scanner(System.in);
      System.out.print("Enter width: ");
      n_width = scan.nextInt(); 
      System.out.print("Enter lenght: ");
      n_length = scan.nextInt();
      System.out.print("Enter height: ");
      n_height = scan.nextInt();
      area = 2*(n_length * n_width) + 2*(n_length * n_height) + 2*(n_height * n_width);
      
      System.out.print("The total surface area is: ");
      return  area;
      
   }
   
   
    
   public double rightTriangle()
   {
      double sideA, hypotenuseB;
      double sideC=0;
      Scanner scan = new Scanner(System.in);

      
      System.out.print("Enter side: ");
      sideA = scan.nextDouble();
      System.out.print("Enter hypotenuse: ");
      hypotenuseB = scan.nextDouble();
      System.out.print("The second side is: ");
      sideC = Math.pow((Math.pow(hypotenuseB,2) - Math.pow(sideA,2)),0.5);
      return sideC;  
    }
    
    
    
    public Die comboDie()
    {
      Die d1 = new Die();
      Die d2 = new Die();
      String d3_color;
      int d3_value;
      
      d1.setColor("red");
      d2.setColor("blue");
      
      d3_color = d1.getDiceColor() +"-"+ d2.getDiceColor();
      d3_value = (d1.getFaceValue() + d2.getFaceValue()) / 2;
      
      Die d3 = new Die(d3_value);
      d3.setColor(d3_color);
//       use these two lines below (in comment to check the value of the two dices
//       System.out.println(d1.getFaceValue());
//       System.out.println(d2.getFaceValue());
      return d3;
      
      }
 
 
       
   public static void main(String[] args)
   {  
      MyMethods m1 = new MyMethods();
      //hw n1
      System.out.println(m1.surface());
      //hw n2
      System.out.println(m1.rightTriangle());
      //hw n3
      System.out.println(m1.comboDie());
              
    }

}