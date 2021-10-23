import java.io.PrintWriter;
import java.util.Scanner;

/*
 * Guessing Game - guessing
 * Solution written by Joshua Linge
 */

/*
Sample input:
2
1 100 33
1 3 2

Sample output:
Game #1: 4 guesses
Game #2: 1 guess

 */
public class guessing {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		// Total number of games.
		int n = in.nextInt();
		
		// Loop through each game played.
		for(int curGame = 1; curGame <= n; ++curGame) {
			
			// Lower bound on Adam's chosen number range.
			int a = in.nextInt();
			
			// Upper bound on Adam's chosen number range.
			int b = in.nextInt();
			
			// Adam's chosen number.
			int x = in.nextInt();
			
			// Start our guessing range with the lower bound 
			// at a and our upper bound at b. 
			int lowerBound = a;
			int upperBound = b;
			
			// Start with zero guesses initially.
			int guessCount = 0;
			
			// Keep guessing until we find Adam's chosen number. 
			while(true) {
				// Take the average of our range, rounding up.
				int mid = (lowerBound + upperBound + 1) / 2;

				// Increase our guess count.
				++guessCount;
				
				if(mid == x) {			// Guess was correct, game is over.
					break;
				} else if(mid > x) {	// Guess was too high, decrease the upper bound.
					upperBound = mid-1;
				} else {				// Guess was too low, increase the lower bound.
					lowerBound = mid+1;
				}
			}
			
			// Print output.
			if(guessCount > 1) {
				out.println("Game #"+curGame +": "+guessCount +" guesses");
			} else { 
				out.println("Game #"+curGame +": 1 guess");
			}
		}
		
		out.close();
		in.close();
	}

}
