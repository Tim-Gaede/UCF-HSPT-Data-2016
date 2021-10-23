import java.util.Scanner;

public class fishy {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		// Read in the number of days to process.
		int n = in.nextInt();
		
		// Loop through each day.
		for(int curDay = 1; curDay <= n; ++curDay) {
			// Read the number of fish.
			int num = in.nextInt();
			
			// Get the first power of two greater than or equal to the number.
			int powerOf2 = (int)(Math.ceil(Math.log(num)/Math.log(2)));
			int fishTree =  1 << powerOf2;
			
			// Find the number of fish remaining on the tree.
			int remaining = fishTree - num;
			
			// Print the answer.
			System.out.printf("Day #%d: %d extra fish\n", curDay, remaining);
		}
		
		in.close();
	}
}
