public class Tester
{
static public void main (String[] args)
{
String[] numbers={"57", "fifty", "-50", "39"};
PosNumberException problem=new PosNumberException("positive ");

for (int i=0;i<numbers.length;i++)
{
 try{
 if (Integer.parseInt(numbers[i])>0) throw problem;
 System.out.print("negative ");

 }

 catch (PosNumberException e){
 System.out.print(e.getMessage());

 }
 catch (NumberFormatException e){
 System.out.print("none ");

 }
}
}
}