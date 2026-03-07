public class Line extends Figure
{
   public double length;
   private Point point1;
   private Point point2;
   
   public Line (Point p1, Point p2)
   {
      super("Line");
      point1 = p1;
      point2 = p2;
      perimeter();
   } 
   
   public Point getPoint1()
   {
      return point1;
   }
   
   public Point getPoint2()
   {
      return point2;
   }

   public void setPoint1(int x, int y)
   {
      point1 = new Point(x,y);
   }
   
   public void setPoint2(int x, int y)
   {
      point2 = new Point(x,y);
   }
   
   public double perimeter()
   {
      length = point1.distance(point2);
      return length;
   } 
   
   public boolean equals(Line line2)
   {
      return length == line2.length;
   }
   
   public String toString()
   {
      return super.toString()+": "+name+"\n"+"length: "+length;
   }
}