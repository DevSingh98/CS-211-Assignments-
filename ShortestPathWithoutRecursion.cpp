#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
	static int weight[NUM_ROWS][NUM_COLS] = { { 3,4,1,2,8,6 },

	{ 6,1,8,2,7,4 },

	{ 5,9,3,9,9,5 },

	{ 8,4,1,3,2,6 },

	{ 3,7,2,8,6,4 } };
	// Declare the cost matrix.
	static int cost[NUM_ROWS][NUM_COLS]{};

	// Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
	for (int i = 0; i < NUM_ROWS; i++) {
		cost[i][0] = weight[i][0];
		path[i][0] = i;
	}

	// For each remaining column,
	// Calculate the cost of each square in the column (non-recursively),
	// and store the correct number in the cost matrix and the correct string in the path matrix.   
	int minValue, down, left, up;
	int g = cost[1][0];
	int v = 0;

	for (int i = 0; i < NUM_ROWS; i++) {
		if (cost[i][0] < g) {
			g = cost[i][0];
			v = i;
		}
	}

	path[0][0] += to_string(v);

	for (int c = 1; c < NUM_COLS; c++) {
		for (int r = 0; r < NUM_ROWS; r++) {
			up = cost[(NUM_ROWS - 1 + r) % NUM_ROWS][c - 1] + weight[r][c];
			left = cost[r][c - 1] + weight[r][c];
			down = cost[(r + 1) % NUM_ROWS][c - 1] + weight[r][c];
			minValue = min(min(up, left), down);
			cost[r][c] = minValue;

			//Path Section
			if (minValue == up) {
				path[r][c] = path[(r + (NUM_ROWS - 1)) % NUM_ROWS][c - 1] + to_string(r);
			}
			// If left is the minimum...
			else if (minValue == left) {
				path[r][c] = path[r][c - 1] + to_string(r);
			}
			// If down is the minimum...
			else {
				path[r][c] = path[(r + 1) % NUM_ROWS][c - 1] + to_string(r);
			}
		}
	}

	int minRow = 0;

	// Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow.
	int z = cost[0][NUM_COLS - 1];
	for (int i = 1; i < NUM_ROWS; i++) {
		if (cost[i][NUM_COLS - 1] < z) {
			minRow = i;
			z = cost[i][NUM_COLS - 1];
		}
	}
	cout << "The length of the shortest path is " << cost[minRow][NUM_COLS - 1];
	cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS - 1] << ".";
}

int main() {
	calculateCosts();
	return 0;

}

/* This program is pretty much the same as the recursive shortest path program, only difference is I start my calculations from the left side of the
board instead of the right, so i start by copying the left side of the cost into the cost array. then initialize the path array to the index for the 
corresponding cost index. Then i basically use what i did for the recursive shortest path, I calculate the cost of each square non recursivly using 
a for loop. Then i use the same logic i used in the recursive shortest path to check if the boxes next to the current boxes to see which has the lower
cost and storing that index in the path array.
*/
