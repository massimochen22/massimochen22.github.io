
/*
 * Define states to be used in solving the missionaries and
 * cannibals problem. 
 */


class State {
	int m; // missionaries on left bank
	int c; // cannibals on left bank
	int b; // 0 for boat on left bank, 1 for boat on the right
	State pred; // predecessor state

	State() { 
		m = 3;
		c = 3;
		b = 0;
	}

	State(State s) {
		m = s.m;
		c = s.c;
		b = s.b;
	}

	State(int M, int C, int B) {
		m = M;
		c = C;
		b = B;
	}

	boolean legal()
	/* is this a legal state? */
	{
		if (m < 0 || m > 3 || c < 0 || c > 3)
			return false;
		if (m > 0 && c > m) // can't have more cannibals on left...
			return false;
		if (3 - m > 0 && 3 - c > 3 - m) // ...or on right bank
			return false;
		return true;
	}

	boolean equiv(State s)
	/* Equivalent states? */
	{
                if(s.m == m && s.c == c && s.b == b)
                   return true;
                else
                   return false;
	}

	/**
	 * 
	 * move M missionaries and C cannibals and return the resulting state
	 */
	State move(int M, int C) {
		State newState = new State(this);
		if (b == 0) {
			newState.m = m - M;
			newState.c = c - C;
			newState.b = 1;
		} else {
			newState.m = m + M;
			newState.c = c + C;
			newState.b = 0;
		}
		newState.pred = this;
		return newState;
	}

	void display()
	{
		System.out.println(m + " " + c + " " + (b == 0 ? "Left" : "Right"));
	}
}
