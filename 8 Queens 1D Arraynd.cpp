#include <iostream>
#include <cmath>
using namespace std;

//q[c]== row
//c== col

bool ok(int q[], int c){ // checks if there is a conflict with queen placements 
	for(int i=0; i<c; i++){
		if( q[i]== q[c] || ((c-i)== abs(q[c]-q[i]))){
			return false;
		}
	}
	return true;
}

void print(int q[], int c){ // prints the solution if there is no conflict 
	static int numSolutions = 0;
	cout<< "Solution #" << ++numSolutions << ": ";
	for(int i=0; i<8; i++){
		cout<< q[i];
	}
	cout<< endl;
}

int main(){
	int q[8]={};
	int c=0;
	q[0]=0;
	bool w;// just to make it a little easier to read
	while (c>=0){//NextCol
		c++;
		if(c==8){
			print(q, c);
			c--;
		}
		else {
			q[c]=-1;
		}
		
		while(c >=0){//nextrow
			q[c]++;
			if(q[c]==8){
				c--;
			}
			else{
				w= ok(q,c);
				if(w == true){
					break;
				}
			}
		}
	}
	return 0;
}

/* In this program it simulates the 8 queens problem, but instead of using a 2d array data structure, I used a 1d array, which interms made the code easier and less to write. 
I started by making a bool function called ok. The purpose of this function was to check to see if there were any conflicts with a queen placement. It would check if 
there was a queen on the same row( it would check to see if there was the same number in a previous index of the array), and if there was a queen in the same diagonal path.
Since I am using a 1D array, I was able to combine the checking for a queen in the up diagonal, and down diagonal into 1 test. This interms makes it more efficent. 
I was able to do this by calling on the absolute function from the cmath library, the absolute difference between the queens placement (q[c]) and the up and down diagonal(q[i]-q[c])
would be the same, if there was a queen in one of those diagonals. If there was a conflict, the program would simply return false, and then backtrack ( going back 1 column c--),
If there was no conflicts, the ok function would return true, and then the print function would be called. The print function would then print out that solution. Then the program
would backtrack to find another solution. Using the while loops, I was able to have a loop going to find all of the solutions. I set up parameters that would check periodically
if the program went out of bounds ( or off the chess board). If the row ( q[c]) was less then 0, we were off the board, if the column ( c) was less then 0, we were off the board.
If we were off the board, that meant we had backtracked all the way to the beginning, thus resulting in no more viable solutions can be found.*/ 


