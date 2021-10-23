import java.util.*;
import java.io.*;

public class chomp {
	static int[] prefixSums;
	static int k;
	public static void main(String[] args) throws IOException {
		
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int p = in.nextInt();
		
		for(int plate = 1; plate <= p; plate++){
			
			//variables from the input
			int n = in.nextInt();
			k = in.nextInt();
			
			//this are all the food items
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = in.nextInt();
			}
			
			
			//Since after the chomps the sum of all the items needs to the same (mod k),
			//the sum of the items with the sums together need to 0 (mod k)
			//This approaches finds all such pairs of intervals in O(n^2) time complexity 
			//The chomps of the problem are referred to as intervals
			
			//prefixSums[i] holds the sum of all a[j] s.t. 0 <= j <= i
			//It is used for the sumOverRange function
			prefixSums = new int[n];
			prefixSums[0] = a[0];
			for (int i = 1; i < a.length; i++) {
				prefixSums[i] = (prefixSums[i-1] + a[i])%k;
			}
			long answer = 0;
			
			//canMakeWithLeft[i] is The number of ways to make a interval which 
			//sums to i (mod k) such that the end point of the interval is 2 or more less than startOfRight
			int[] canMakeWithLeft = new int[k];
			
			//The start of the right interval can not be less than 2, as there needs to be at least one index for the
			//left interval and one index to separate them
			for(int startOfRight = 2; startOfRight < n; startOfRight++){
				int endOfLeft = startOfRight-2;
				//update canMakeWithLeft with the new end point that can used for the left intervals
				for(int startOfLeft = 0; startOfLeft <= endOfLeft; startOfLeft++){
					int sumLeft = sumOverRange(startOfLeft,endOfLeft,a);
					canMakeWithLeft[sumLeft]++;
				}
				
				for(int endOfRight = startOfRight; endOfRight < n; endOfRight++){
					int sumRight = sumOverRange(startOfRight,endOfRight,a);
					//I'm look for the sumLeft such that sumRight+sumLeft is 0 mod k
					//Therefore the sumLeft is (k - sumRight) mod k
					answer += canMakeWithLeft[(k-sumRight)%k];
				}
				
				
			}
			
			out.println("Plate #"+plate+": " + answer);
			
		}
		in.close();
		out.close();
	}
	
	//returns the sum (mod k) of all a[i] s.t. start <= i <= end.
	static int sumOverRange(int start, int end, int[] a){
		
		int sum =  prefixSums[end] - (prefixSums[start]-a[start]);
		sum %= k;
		if(sum < 0) sum += k;
		return sum;
	}

}
