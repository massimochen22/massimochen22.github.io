public abstract class Figure{
 protected String name;
 public Figure(String s){
 name=s;
 }
 public abstract double perimeter();
//returns the total length between the vertices in figure
 public String toString(){
 return "figure";
 }
}