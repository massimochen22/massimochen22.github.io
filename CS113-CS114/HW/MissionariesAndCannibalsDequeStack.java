import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.ArrayDeque;

public class MissionariesAndCannibalsDequeStack {

  /**
   * Solve the "missionaries and cannibals" problem. Start with 3 of each on
   * left bank, get them all across without ever having missionaries outnumbered
   * by cannibals on either bank. Boat can carry at most 2 people.
   * In this version we use a dequeue as a stack.
   */
  public static void main(String args[]) {
    int numberTrips = -1;
    ArrayDeque<State> dq = new ArrayDeque<State>();
    ArrayList<State> visited = new ArrayList<State>();
    ArrayDeque<State> seq = new ArrayDeque<State>();
    State start = new State(3, 3, 0);
    dq.addLast(start); // using deque as stack
    visited.add(start); 
    while (! dq.isEmpty()) {
      State next = dq.removeLast(); // pop
      if (next.m == 0 && next.c == 0 && next.b == 1) {
        for (State x = next; x != null; x = x.pred) {
          seq.offerLast(x);
        }
        numberTrips = seq.size()-1;
        State s = seq.pollLast();
        while(s != null) {
            s.display();
            s = seq.pollLast();
        }
        break;
      }
      // generate all possible next states;
      // i represents number of missionaries in boat, j number of cannibals
      for (int i = 0; i <= 2; i++)
        for (int j = 0; i + j <= 2; j++) {
          if (i == 0 && j == 0)
            continue; // can't have empty boat
          State p = next.move(i, j);
          if (!p.legal())
            continue;
          //if (visited.contains(p))
            //continue;
          boolean beenHere = false;
          for(State s : visited) {
             if (s.equiv(p)) {
               beenHere = true;
               break;
             }
          }
          if(beenHere)
            continue;
          dq.addLast(p); // push
          visited.add(p); 
          p.display();
        }
    }
    System.out.println("It required " + numberTrips + " crossings");
  }
}
