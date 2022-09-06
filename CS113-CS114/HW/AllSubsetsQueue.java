
import java.util.LinkedList;
import java.util.Queue;

public class AllSubsetsQueue {

  /**
   * Print out all nonempty subsets of a string using a queue instead of
   * recursion.
   */

  public static void main(String args[]) {
    // Stack<CState> stack = new Stack<CState>();
    Queue<CState> q = new LinkedList<CState>();
    CState start = new CState("", "abcd");
    q.add(start);
    while (!q.isEmpty()) {
      CState next = q.poll(); // dequeue
      if (next.suff().length() > 0) {
        String newPrefix = next.pre() + next.suff().charAt(0);
        String newSuffix = next.suff().substring(1);
        System.out.println(newPrefix);
        CState n1 = new CState(newPrefix, newSuffix);
        CState n2 = new CState(next.pre(), newSuffix);
        q.add(n1);
        q.add(n2);
      }
    }
  }
}
