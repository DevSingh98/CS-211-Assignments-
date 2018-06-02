#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Returns the cost of the shortest path from the left to the square in row i, column j.
int calculateCost(int i, int j) {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},

                                            {6,1,8,2,7,4},

                                            {5,9,3,9,9,5},

                                            {8,4,1,3,2,6},

                                            {3,7,2,8,6,4}};
   
   // Declare the cost matrix
   static int cost[NUM_ROWS][NUM_COLS] {};

   // If the cost has already been calculated, return it.
   if(cost[i][j] != 0) return cost[i][j]; //If there is already a value in cost

   // Check for the base case.
   if (j == 0) {
      path[i][j] = to_string(i);
      return weight[i][j];
   }

   // Calculate the costs of the 3 adjacent squares by calling the function recursively.
   int up = calculateCost((NUM_ROWS - 1 + i) % NUM_ROWS, j - 1);
   int left = calculateCost(i, j - 1);
   int down = calculateCost((i + 1) % NUM_ROWS, j - 1);
   
   // Find the minimum of the 3 costs.
   int minCost = min(min(up,left),down); //Takes three ints representing costs, and calculates lowest one.
   
   // Update the path matrix (store the path to the current square in path[i][j]):
   // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
    if(minCost == up){
	  	path[i][j] = path[(i + (NUM_ROWS - 1)) % NUM_ROWS][j - 1] + to_string(i);
	}

   // If left is the minimum...
    else if(minCost == left){
		path[i][j] = path[i][j - 1] + to_string(i);
	}
	
   // If down is the minimum...
    else{
    	path[i][j] = path[(i + 1) % NUM_ROWS][j - 1] + to_string(i);
	}

   // Calculate the cost of the current square, store the correct number in the cost matrix, and return the cost.
   cost[i][j] = minCost + weight[i][j];
   
   return cost[i][j];
}

int main() {
   int minRow = 0;

   // Call the calculateCost function once for each square in the rightmost column of the grid.
   // Check which one has the lowest cost and store the row number in minRow.
   for(int i = 1; i < NUM_ROWS; i ++){
		minRow = i;
   }
   
   cout << "The length of the shortest path is " << calculateCost(minRow, NUM_COLS - 1);
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS - 1] << ".";
   
   return 0;
}

/*In this program I calculate the shortest path from the left side to the right side. But I calculate the cost in reverse. I start from the right most side by checking which box
has the lowest amount in cost. It is then stored in cost array which helps me save time by not having to recalculate the same numbers over again with each recursive call.
It then check the 3 adjacent boxes ( top left, left, botton left) to see which has the shortest cost. Depending on which one has the shortest cost, it stores that path in the path 
array. Top left being i + 1 less the the number of rows and j-1 since its 1 above, left being i and j-1, bottom left being 1 more then 1 mod the number of rows and 1 less then j.
it stores the cost for each of those and stores it in the cost array. It then prints the total amount for the lowest cost to get across the board and prints out the path from the
path array.
*/
