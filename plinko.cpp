/*
 * Plinko - plinko
 * Solution written by Joshua Linge
 */

/*
Sample Input:
2
20 6
|..................|
|\____.\__.__/\./\.|
|.____/..|.|...\__.|
|\__|....|.|....._/|
||.......|\_.......|
|987654321123456789|
7 5
|.....|
|\__._|
|..._.|
|.....|
|12345|

Sample Output:
Board #1: Drop at column 14 for a score of 7 points.

Board #2: Don’t even bother dropping a coin. You can’t win!

 */

#include <cstdio>
using namespace std;

int dropCoin(int startColumn, int width, int height, char** board);

int main() {

    // Total number of boards to consider.
    int numBoards;
    scanf("%d", &numBoards);

    // Go through each board and find the best score.
    for(int curBoard = 1; curBoard <= numBoards; ++curBoard) {

        // Width and height of the current board.
        int width;
        int height;
        scanf("%d %d", &width, &height);

        // The current board.
        char** board = new char*[height];

        for(int h = 0; h < height; ++h) {
            board[h] = new char[width];
            scanf("%s", board[h]);
        }

        int bestScore = 0;
        int bestColumn = -1;

        // Go through each column and try dropping the coin.
        for(int curColumn = 1; curColumn < width-1; ++curColumn) {

            // Drop the coin at this column.
            int score = dropCoin(curColumn, width, height, board);

            // The score for this column is better than the best score we
            // have found so far, save the new best score and column.
            if(score > bestScore) {
                bestScore = score;
                bestColumn = curColumn;
            }
        }

        // Print answer
        printf("Board #%d: ", curBoard);

        if(bestScore == 0) {
            printf("Don't even bother dropping a coin. You can't win!\n\n");
        } else {
            printf("Drop at column %d for a score of %d points.\n\n", bestColumn, bestScore);
        }

        // Free memory
        for (int row = 0; row < height; ++row) {
            delete[] board[row];
        }
        delete[] board;
    }

	return 0;
}

int dropCoin(int startColumn, int width, int height, char** board) {

    // Current row and column location within the board.
    int row = 0;
    int col = startColumn;

    // Current direction of movement.
    int deltaRow = 1;
    int deltaCol = 0;

    // Keep trying to move the coin until it reaches to the bottom row.
    while (row != height-1) {

        // If the coin's location is a bar, stop the coin.
        if (board[row][col] == '|'){
            break;
        }

        // If the coin's location is a slope to the right.
        else if (board[row][col] == '\\') {

            // If the coin is moving down, start moving to the right.
            if(deltaRow != 0 && deltaCol == 0) {
                deltaRow = 0;
                deltaCol = 1;
                ++col;
            }

            // If the coin was moving horizontally, stop the coin.
            else if (deltaRow == 0 && deltaCol != 0) {
                break;
            }
        }

        // If the coin's location is a slope to the left.
        else if (board[row][col] == '/') {

            // If the coin is moving down, start moving to the left.
            if(deltaRow != 0 && deltaCol == 0) {
                deltaRow = 0;
                deltaCol = -1;
                --col;
            }

            // If the coin was moving horizontally, stop the coin.
            else if (deltaRow == 0 && deltaCol != 0) {
                break;
            }
        }

        // If the coin's location is a flat piece.
        else if (board[row][col] == '_') {

            // If the coin is moving horizontally, continue moving in that direction.
            if(deltaRow == 0 && deltaCol != 0) {
                col += deltaCol;
            }

            // If the coin is moving vertically, stop the coin.
            else if(deltaRow != 0 && deltaCol == 0) {
                break;
            }
        }

        // If the coin's location is empty.
        else if (board[row][col] == '.') {

            // If the coin was moving horizontally, change the coin to moving vertically.
            if(deltaRow == 0 && deltaCol != 0) {
                deltaRow = 1;
                deltaCol = 0;
            }
            ++row;
        }
    }

    // If the coin is at the bottom row, return the point value for this cell.
    if (row == height-1) {
        return (int)(board[row][col] - '0');
    }
    // Not at the bottom row, the coin stopped early. Return 0 points.
    return 0;
}
