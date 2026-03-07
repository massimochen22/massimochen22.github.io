public class tryLine
{
   public static void main (String args[])
   {
      Point p1 = new Point (0,0);
      Point p2 = new Point (3,4);
      Line line = new Line(p1,p2);
      //System.out.print(line);
      Point p3 = new Point (0,0);
      Point p4 = new Point (1,5);
      Line line2 = new Line(p3,p4);
      line2.setPoint1(3,3);
      System.out.println(line2.getPoint1());
      
   }

}
   