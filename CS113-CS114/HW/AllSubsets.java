import java.util.ArrayList;

public class AllSubsets {

  public static void main(String[] args) {
    ArrayList al = new ArrayList();
    al.add("a");
    al.add("b");
    al.add("c");
    System.out.println("All nonempty subsets of:");
    System.out.println
    (al);
    System.out.println("are as follows:");
    printAllSubsets(new ArrayList(), al);
  }

  static void printAllSubsets(ArrayList prefix, ArrayList suffix) {
    if (!suffix.isEmpty()) {
      ArrayList newPrefix = new ArrayList(prefix);
      newPrefix.add(suffix.get(0));
      ArrayList newSuffix = new ArrayList(suffix);
      newSuffix.remove(0);
      System.out.println(newPrefix);
      printAllSubsets(newPrefix, newSuffix);
      printAllSubsets(prefix, newSuffix);
    }
  }
}
