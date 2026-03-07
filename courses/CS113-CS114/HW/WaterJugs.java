import java.util.*;

public class WaterJugs {
	
	public static void main(String args[]) {
		
	    ArrayDeque<CheckState> dq = new ArrayDeque<CheckState>();
	    ArrayList<CheckState> visited = new ArrayList<CheckState>();
	    ArrayDeque<CheckState> seq = new ArrayDeque<CheckState>();
	    
	    Scanner scan = new Scanner(System.in);
	    
	    int gallon1 = scan.nextInt();
	    int gallon2 = scan.nextInt();
	    int gallon3 = scan.nextInt();
	    int goal    = scan.nextInt();
	    
	    CheckState start = new CheckState (gallon1,0,0,goal);
	    dq.addLast(start); // using deque as queue
	    visited.add(start); 
	   
	   
	   while(! dq.isEmpty()) {
	    	CheckState next = dq.removeFirst(); // dequeue
	    	//System.out.println(next);
	        if (next.equiv()) { //check if the goal is met
	          //System.out.println("working?1");
	          for (CheckState x = next; x != null; x = x.pred) {
	            seq.offerLast(x);
	          }
	          
	          CheckState s = seq.pollLast();
	          while(s != null) {
	              s.display();
	              s = seq.pollLast();
	          }
	          break;
	        }
	        
//	        if (next.c2 == 0 && next.c3 == 0 ) {
//	        	//System.out.println("working?2");
//	        	CheckState temporary1 = new CheckState(gallon1-gallon2,gallon2,0,goal);
//	        	CheckState temporary2 = new CheckState(gallon1-gallon3,0,gallon3,goal);
//	        	
//	        	dq.addLast(temporary1);
//	        	dq.addLast(temporary2);
//	        	visited.add(temporary1);
//	        	visited.add(temporary2);
//	        	
//	        }
	        
	        //else {
	        	//System.out.println("working?3");

	        	if (!(gallon1 < 2 || gallon2< 2 || gallon3 < 2 || goal < 2 || gallon1 > 100 || gallon2 > 100 || gallon3 > 100 || goal > 100)) { //check if the input is legal. If it is legal start to check all possible combination
	        		int remainder1 = gallon1 - next.c1; 
	        		int remainder2 = gallon2 - next.c2; 
	        		int remainder3 = gallon3 - next.c3; 
	      //---  		
	        		//System.out.println(remainder1+","+remainder2+","+remainder3);
	        		
	        		if ((remainder2 > 0 || remainder3 > 0) && next.c1 != 0) { //first type of case is when c1 is transfering to c1 or c2 
	        			if (remainder2 > 0) { //when c1 is transferable to c2 
	        				
	        				CheckState y1 = new CheckState(next.c1-remainder2,gallon2,next.c3,goal);
	        				if ((!y1.isThere(visited)) && y1.legal(gallon1,gallon2,gallon3)) {//check if the combination was seen. If not add to the deque and to the arrayList 
	        					dq.addLast(y1);
	        					visited.add(y1);
	        				}
	        			}
	        				
	        			if (remainder3 > 0) { //when c1 is transferable to c3
	        				CheckState y2 = new CheckState(next.c1-remainder3,next.c2,gallon3,goal);
	        				if ((!y2.isThere(visited)) && y2.legal(gallon1,gallon2,gallon3)) {//check if the combination was seen. If not add to the deque and to the arrayList
	        					dq.addLast(y2);
	        					visited.add(y2);
	        				}
	        			}	
	        		}
	        //---		
	        		if ((remainder1 > 0 || remainder3 > 0) && next.c2 != 0) { //second type of case is when c2 is transfering to c1 or c3 
	        			if (remainder1 > 0) { //when c2 is transferable to c1
	        				CheckState y3= new CheckState(next.c1+next.c2,0,next.c3,goal);
	        				if ((!y3.isThere(visited)) && y3.legal(gallon1,gallon2,gallon3)) {//check if the combination was seen. If not add to the deque and to the arrayList
	        					dq.addLast(y3);
	        					visited.add(y3);
	        				}	
	        			}
	        			
	        			if (remainder3 > 0) {//when c2 is transferable to c3
	        				if (next.c2+next.c3 > gallon3) {
		        				CheckState y4= new CheckState(next.c1,next.c2-remainder3,gallon3,goal);
		        				if ((!y4.isThere(visited)) && y4.legal(gallon1,gallon2,gallon3)) { //check if the combination was seen. If not add to the deque and to the arrayList
		        					dq.addLast(y4);
		        					visited.add(y4);
		        				}	
	        				}
	        				else if (next.c2+next.c3 <= gallon3) {
	        					CheckState y5= new CheckState(next.c1,0,next.c2+next.c3,goal);
		        				if ((!y5.isThere(visited)) && y5.legal(gallon1,gallon2,gallon3)) { //check if the combination was seen. If not add to the deque and to the arrayList
		        					dq.addLast(y5);
		        					visited.add(y5);
		        				}	
	        				}
	        			}
	        			
	        		}
	       //---
	        		if ((remainder1 > 0 || remainder2 > 0) && next.c3 != 0 ) {//third type of case is when c3 is transfering to c1 or c2
	        			if (remainder1 > 0) {// when c3 transfering to c1
	        				CheckState y6= new CheckState(next.c1+next.c3,next.c2,0,goal);
	        				if((!y6.isThere(visited)) && y6.legal(gallon1,gallon2,gallon3)) { //check if the combination was seen. If not add to the deque and to the arrayList
	        					dq.addLast(y6);
	        					visited.add(y6);
	        				}
	        			}
	        			
	        			if (remainder2 > 0) {// when c3 transfering to c2
	        				if (next.c2+next.c3 > gallon2) {
		        				CheckState y7= new CheckState(next.c1,gallon2,next.c3-remainder2,goal);
		        				if ((!y7.isThere(visited)) && y7.legal(gallon1,gallon2,gallon3)) { //check if the combination was seen. If not add to the deque and to the arrayList
		        					dq.addLast(y7);
		        					visited.add(y7);
		        				}
	        				}
	        				else if (next.c2+next.c3 <= gallon2) {
		        				CheckState y8= new CheckState(next.c1,next.c3+next.c2,0,goal);
		        				if ((!y8.isThere(visited)) && y8.legal(gallon1,gallon2,gallon3)) { //check if the combination was seen. If not add to the deque and to the arrayList
		        					dq.addLast(y8);
		        					visited.add(y8);
		        				}
	        				}
	        				
	        				
	        			}
	        		}
	        	}
	        }
	        
	    
//	
//  for (CheckState trying : visited) {
//	    	System.out.print("("+trying+"), ");
//	    }
//	    start.display();
//	    System.out.println(dq);
//	    System.out.println(visited);
	    
	    
	}
	    
	}


