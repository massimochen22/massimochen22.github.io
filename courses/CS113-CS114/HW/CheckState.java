import java.util.ArrayList;

public class CheckState {
	
	
	int c1; // first gallon
	int c2; // second gallon
	int c3; // third gallon
	int d;
	
	CheckState pred;
	
	
	CheckState(int C1,int C2, int C3, int D) {
		
		c1 = C1;
		c2 = C2;
		c3 = C3;
		d = D;
		
	}
	
	boolean legal(int B1, int B2, int B3){
		if (c1 < 0 || c2 < 0 || c3 < 0 || c1 > B1 || c2 > B2 || c3 > B3 ) //check if input are less than 0 or greater than the capacity of the gallons
			return false;
//		if (c1 < d) // check if the goal is to have a greater amount of water than the total water provided
//			return false;
		return true;		
}
//	

	boolean equiv(){ //check if the goal is met
		if(c1 == d || c2 == d|| c3 == d)
			return true;
		else
			return false;
		}
	
	
	boolean isThere(ArrayList<CheckState> cSList) {
		
		for (CheckState tempObject : cSList) {
			if (c1 == tempObject.c1 && c2 == tempObject.c2 && c3 == tempObject.c3)
				return true;
		}
		
		return false;
		
	}
	
	CheckState predState(CheckState current) {
		this.pred = current;
		return pred;
	}

	
	
//
		void display()
		{
			System.out.println(c1 + " " + c2+ " " +c3);
		}
		
		public String toString() {
			return c1 + " " + c2 + " "+ c3;
		}
	}



