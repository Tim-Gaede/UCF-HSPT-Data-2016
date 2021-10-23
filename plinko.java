import java.util.Scanner;
public class plinko {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt(); // Number of test cases
	for(int t = 1; t <= T; t++)
	{
		int m = input.nextInt(), n = input.nextInt(); // Board dimensions
		
		char[][] grid = new char[n][m];
		for(int i = 0; i<n; i++)
		{
			grid[i] = input.next().toCharArray();
		}
		
		int bestScore = 0;
		int bestColumn = -1;
		// Try all possible columns
		for(int i = 1; i<m-1; i++)
		{
			int score = simulate(grid, 0, i, 0);
			if(score > bestScore)
			{
				bestScore = score;
				bestColumn = i;
			}
		}
		if(bestScore > 0)
		{
			System.out.printf("Board #%d: Drop at column %d for a score of %d points.\n\n", t, bestColumn, bestScore);
		}
		else
		{
			System.out.printf("Board #%d: Don't even bother dropping a coin. You can't win!\n\n", t);
		}
	}
}
/*
 * dir is 0 if the coin is falling down, -1 if it is moving left, or 1 if it is moving right.
 */
static int simulate(char[][] grid, int row, int col, int dir)
{
	if(row == grid.length - 1)
	{
		return grid[row][col] - '0';
	}
	char cur = grid[row][col];
	if(cur == '|') return 0;
	if(cur == '.') return simulate(grid, row+1, col, 0);
	if(cur == '\\')
	{
		if(dir != 0) return 0;
		return simulate(grid, row, col+1, 1);
	}
	if(cur == '/')
	{
		if(dir != 0) return 0;
		return simulate(grid, row, col-1, -1);
	}
	if(cur == '_')
	{
		if(dir == 0) return 0;
		return simulate(grid, row, col+dir, dir);
	}
	return 0;
}
}

