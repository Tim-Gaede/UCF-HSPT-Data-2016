/*
 * To solve this problem, we will simply traverse the
 * maze using the strategy given in the problem until
 * we reach the end, can't move, or reach the
 * beginning again. 
 */
import java.util.*;
import java.io.*;
public class maze {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for(int z = 1; z <= n; z ++)
		{
			int r = input.nextInt();
			int c = input.nextInt();
			
			//The map of the maze
			boolean[][] map = new boolean[r][c];
			
			//The locations of S and E
			int starti = -1;
			int startj = -1;
			int endi = -1;
			int endj = -1;
			
			//Take in the input
			for(int i = 0; i < r; i ++)
			{
				String row = input.next();
				for(int j = 0; j < c; j ++)
				{
					if(row.charAt(j) == 'S')
					{
						starti = i;
						startj = j;
					}
					if(row.charAt(j) == 'E')
					{
						endi = i;
						endj = j;
					}
					if(row.charAt(j) != '#')
						map[i][j] = true;
				}
			}
			
			//Stores the number of seconds we have been traveling
			int time = 0;
			
			//Stores our current position (i, j) in the maze.
			int ati = starti;
			int atj = startj;
			
			/* Stores our current direction
			 * 0 means right
			 * 1 means up
			 * 2 means left
			 * 3 means down
			 */
			int direction = 0;
			
			//Determine starting direction based on where S is
			if(starti == 0)
				direction = 3;	
			if(starti == r - 1)
				direction = 1;
			if(startj == 0)
				direction = 0;
			if(startj == c - 1)
				direction = 2;
			
			/*
			 * Stores the four directions in which we can move, in 
			 * the order given in the problem. Same mapping as above.
			 */
			int[] dr = {0,-1,0,1};
			int[] dc = {1,0,-1,0};
			
			boolean foundEnd = false;

			while(true)
			{
				
				/*
				 * Try all 4 directions in order. If our direction is d then
				 * we will try directions in the order (d + 3)%4, d, (d + 1)%4,
				 * (d + 2)%4. 
				 * Record if we find the end, get stuck, or revisit the start.
				 */

				boolean stuck = true;
				
				//The direction to try moving
				int tryDirection = (direction+2)%4;

				for(int k = 0; k < 4; k ++)
				{
					tryDirection = (tryDirection + 1)%4;

					//Get the location of the space to move to
					int nexti = ati + dr[tryDirection];
					int nextj = atj + dc[tryDirection];

					//Check if this is a valid move. If not, keep looking.
					if(nexti < 0 || nexti >= r || nextj < 0 || nextj >=c || !map[nexti][nextj])
						continue;
					
					//Check if we are revisiting the start
					if(nexti == starti && nextj == startj)
						break;
					
					//Looks like we found a valid move!
					stuck = false;
					time+=5;
					
					//Check if this is the end.
					if(nexti == endi && nextj == endj)
						foundEnd = true;
					
					//Change our direction and location.
					ati = nexti;
					atj = nextj;
					direction = tryDirection;
					
					//Since we have made a valid move, stop looking.
					break;
				}
				
				/*
				 * We will keep moving until we have found the end or 
				 * the beginning or until we cannot move.
				 */
				if(stuck || foundEnd)
					break;
			}
			System.out.println("Maze #" + z + ": " + (foundEnd ? time + " seconds" : "Impossible"));
		}
		input.close();
	}
}
