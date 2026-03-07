
import java.util.*; 

public class ScratchPaper {
	
	
	public static String longestCommonPrefix(String[] strs) {
		
		
	    if(strs == null || strs.length == 0)    return "";
	    String pre = strs[0];
	    int i = 1;
	    while(i < strs.length){
	    	System.out.println("Starting while loop");
	    	System.out.println("value of i: "+i);
	        while(strs[i].indexOf(pre) != 0) {
	            pre = pre.substring(0,pre.length()-1);
	            System.out.println(pre);
	            System.out.println("while statement"+strs[i].indexOf(pre));
	        }
	        i++;
	        System.out.println("end while loop");
	        System.out.println("");
	    }
	    
	    System.out.println("now it will print the return statement: ");
	    return pre;
	}
	
	
	public static void main(String[] args) {
		
		
		String[]list = {"hello", "helo", "hellllo", "helll"};
				
		System.out.println(longestCommonPrefix(list));
		

	}

}
