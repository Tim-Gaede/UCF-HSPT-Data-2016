/*
The problem's description essentially told us exactly what we needed to do to solve this problem, so this was mostly an implementation exercise.
That being said, the implementation could get a bit tricky, especially when determining which direction Andrew would be facing after making a move.
One approach would be to hard-code every direction Andrew would face after making a certain move facing a certain direction, but this would be rather ugly.
The approach used in this solution is to store information about turns in parallel arrays and use these arrays to make determining the next direction easier.
 */

#include <stdio.h>
#include <stdlib.h>

/*
These arrays store the directions Andrew can move in a grid. The first dimension corresponds to the direction he's currently facing, and the second dimension
corresponds to the direction he is attempting to move to. The order for both of these is right, forward, left, backward, as per the problem statement.
For example if Andrew was facing left and attempting to move behind him, he would add DY[2][3] to his current row and DX[2][3] to his current column.
 */
const int DX[4][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}, {0, -1, 0, 1}, {-1, 0, 1, 0}};
const int DY[4][4] = {{1, 0, -1, 0}, {0, -1, 0, 1}, {-1, 0, 1, 0}, {0, 1, 0, -1}};

int inBounds(int r, int c, int rows, int cols); //Explained below

int main(int argc, char **argv)
{
	//First we read in the number of test cases we have
	int runs, z;
	scanf("%d", &runs);

	//We loop until we run out of test cases and process the test cases as we get them
	for(z = 1; z <= runs; z++)
	{
		//Read in the number of rows and columns for the current maze
		int rows, cols;
		scanf("%d %d\n", &rows, &cols);
		//Allocate memory for the grid we're going to read in
		char **grid = malloc(sizeof(char *) * rows);
		//These variables will store where Andrew's start position is and where the end of the maze is
		int startR, startC, endR, endC;

		int i, j;
		for(i = 0; i < rows; i++)
		{
			//Allocate memory for the current row (we include space for the string's null terminator)
			grid[i] = malloc(sizeof(char) * cols + 1);
			for(j = 0; j <= cols; j++)
			{
				scanf("%c", &grid[i][j]); //Read in the character at position (i, j)
				//If the character we read in is S or E, update our start or end variables
				if(grid[i][j] == 'S')
				{
					startR = i;
					startC = j;
				}
				else if(grid[i][j] == 'E')
				{
					endR = i;
					endC = j;
				}
			}
		}

		/*
		dir stores the direction we're facing, which is initially forwards
		r stores the row we're currently on, which is initially the start row specified in the input
		c stores the column we're currently on, which is initially the start column specified in the input
		steps stores the number of steps we've taken, which is initially zero since we haven't tried moving yet
		*/
		int dir = 1, r = startR, c = startC, steps = 0;
		//found stores whether or not we've reached the end or returned to the start (which obviously hasn't happened yet)
		int found = 0;

		//We loop until we reach the end or return to the start
		while(!found)
		{
			//Stores if we've been able to take a step in this position
			int takenStep = 0;

			//We loop over all four directions we can try in order of Andrew's priority, but we break out if we find a valid one
			for(i = 0; i < 4; i++)
			{
				//nextR and nextC store the position we're attempting to walk to
				int nextR = r + DY[dir][i], nextC = c + DX[dir][i];

				//This is only a valid move if we don't exit the grid and the position we're trying to move to is not a wall
				if(inBounds(nextR, nextC, rows, cols) && grid[nextR][nextC] != '#')
				{
					//Since this is a valid move, we mark that we've taken the first valid step available and update our current row and column
					takenStep = 1;
					r = nextR;
					c = nextC;

					/*
					Since moving right is the first option for Andrew's movement, our position in the DY/DX array will move back by one, move nowhere if he
					moves forward, move up by one if he moves left, and move up by two if he moves right. We also have to account for our current direction
					(for example, going right when facing left will have us facing forwards). So want to add i and subtract 1 from our current direction. To
					avoid doing a check to see if dir is still in the range [0, 3], we can just add 3 and mod by 4 rather than subtracting 1.
					*/
					dir = (dir + 3 + i) % 4;

					//If we've reached the end, update our found variable
					if(r == endR && c == endC)
						found = 1;
					//If we've returned to the start, update our found variable
					else if(r == startR && c == startC)
						found = 2;

					//Since we've taken a step, increment our total number of steps, and since we've found our first valid move, we don't need to check more
					steps++;
					break;
				}
			}

			//If there aren't any valid steps for us to take, we have to conclude that the maze is impossible
			if(!takenStep)
				found = 2;
		}

		//Print our result! If it was possible to finish the maze, the time it took is 5 times the number of steps since Andrew moves once every five seconds
		if(found == 1)
			printf("Maze #%d: %d seconds\n", z, steps * 5);
		else
			printf("Maze #%d: Impossible\n", z);

		//Free the memory we allocated earlier
		for(i = 0; i < rows; i++)
			free(grid[i]);
		free(grid);
	}
	return 0;
}

//This function checks to see if the current position is inside the maze and returns true if it is
int inBounds(int r, int c, int rows, int cols)
{
	return r >= 0 && r < rows && c >= 0 && c < cols;
}
