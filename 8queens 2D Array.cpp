#include <iostream>
using namespace std;

int main() {
      int b[8][8] = {0};
      int r, c = 0;
      b[r][c] = 1; 

nextCol: c++;
	if( c == 8){
		goto print;
	}
     r= -1;
nextRow: r++;
	if( r == 8){
		 goto backtrack;
	}

	for(int i=0; i<=c; i++){ //row test
		if(b[r][i]== 1){
			goto nextRow;
		}
	}
		
	for ( int w=1; (r-w)>=0 && (c-w)>=0; w++){ //updiag
		if ( b[r-w][c-w]==1) {
			goto nextRow;
		}
	}
	for( int t=1;(r+t) < 8 && (c-t)>=0;t++){ // down diag
		if(b[r+t][c-t]==1) {
			goto nextRow;
		}
	}
	
	b[r][c]=1;
	goto nextCol;

backtrack: c--;
	if(c==-1) return 0;

	r=0;
	while(b[r][c]!=1){
		r++;
	}
	b[r][c]=0;
		goto nextRow;
      

print:
      static int numSolutions = 0;
      cout << "Solution #" << ++numSolutions << ":\n";
      for(int i = 0; i<=7; i++){ //Use a nested loop to print the chessboard
      	for(int j = 0; j<=7; j++){
      		cout << b[i][j];
		  }
		  cout<< endl;
   	  }
   	  cout << endl;
      goto backtrack;
}


/*In this program, it simulates a chess board using a 2d array. It then trys to solve the "8 queens" problem. It starts by setting the 8 by 8 array's values to 0. 
Then it starts by placing a 1, which represents a queen, and then checks to see if it conflicts with another queen on the same row, up diagonally and down diagonally. 
If it does not conflict, it places a 1 there, if it does conflic, it moves to the next row. If it moves past the 8th row(0-7) it will go to backtrack which will move back
one column and look for the queen, erase it, and start from the row after that to find a spot. It will continue this process and when the column variable reaches the 9th column, 
it will print out that solution and go to backtrack to find another solution. It will find all possible solutions till there are none left. Once it has found all solutions, 
the column it looks at will go to -1, then triggering a return that ends the program.*/ 




