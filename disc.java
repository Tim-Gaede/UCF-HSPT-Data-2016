/*
 * To solve this problem, we will create all
 * permutations of the given array. For each 
 * permutation, we will compute its value. 
 * That is, the sum of the absolute values of the 
 * differences between each pair of consecutive 
 * elements. The maximum value over all of the 
 * permutations will be the answer.
 */
import java.util.*;
import java.io.*;
public class disc 
{
	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner input = new Scanner(new File("disc.in"));
		
		int t = input.nextInt();
		for(int z = 1; z <= t; z ++)
		{
			//Taking in the input:
			n = input.nextInt();
			a = new int[n];
			for(int i = 0; i < n; i ++)
				a[i] = input.nextInt();
			
			ans = 0;
			//Try all permutations and store the best result.
			getPermutations(new boolean[n], new int[n], 0);
			
			System.out.println("Wave #" + z + ": " + ans);
		}
	}
	
	//For a given permutation, get the value
	static int getValue(int[] p)
	{
		int ans = 0;
		for(int i = 1; i < n; i ++)
			ans += Math.abs(p[i] - p[i-1]);
		return ans;
	}
	
	/*
	 * Creates all permutations of the array. When it finishes
	 * a permutation, it gets its value and maxes it with
	 * the answer.
	 * 'perm' is the current permutation being built.
	 * 'p' is the current position that is being filled in 'perm'.
	 * 'used' stores, for each value in a, whether or not it has already 
	 * been used.
	 */
	static void getPermutations(boolean[] used, int[] perm, int p)
	{
		/*
		 * If p == n then we have filled every position in 'perm'.
		 * In other words, 'perm' now stores a finished permutation.
		 * We will now get the value of this permutation and max it 
		 * with 'ans'.
		 */
		if(p == n)
		{
			ans = Math.max(getValue(perm), ans);
			return;
		}
		
		/*
		 * For each value in 'a', if it has not been used, try placing
		 * it at position 'p' and recursing.
		 */
		for(int i = 0; i < n; i ++)
		{
			if(used[i])
				continue;
			perm[p] = a[i];
			used[i] = true;
			getPermutations(used, perm, p + 1);
			
			/*
			 * Now that we have already tried placing value a[i] in
			 * position 'p', we should reset the values of perm and 
			 * used for the next calls.
			 */
			perm[p] = 0;
			used[i] = false;
		}
	}
	
	//Stores the best answer found so far.
	static int ans;
	
	//Stores the given array.
	static int[] a;
	
	//Stores the size of 'a'.
	static int n;
}
