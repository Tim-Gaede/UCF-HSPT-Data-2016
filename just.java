// This line is just generally a good idea for coding most contest problems
import java.util.*;

// Start the class
public class just
{
	// Run main
	public static void main(String[] args)
	{
		// Make the scanner
		Scanner in = new Scanner(System.in);
		
		// Input how many times the program will run
		int N = in.nextInt();
		
		// Flush the input of newlines so that N isn't taken as a line
		in.nextLine();
		
		// Start the loop
		for(int n = 1; n <= N; n++)
		{
			// Input the dream
			String dream = in.nextLine();
			
			// Just do it
			System.out.println(dream + " Just do it!");
		}
		
		// Close the scanner
		in.close();
	}
}
