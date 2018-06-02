#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
	for(int i=0; i<c; i++){
		if( q[i]== q[c] || ((c-i)== abs(q[c]-q[i]))){
			return false;
		}
	}
	return true;
   // Reuse the ok function from your 1D 8 queens program.
}

// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
	int Nsolution=0;
	int *q;
	q = new int [n];
   // Dynamically declare an array of size n and initialize the first element to 0.
   // Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
   // Delete the array.
   // Return the number of solutions.
	int c=0;
	q[0]=0;
	bool w;// just to make it a little easier to read
	while (c>=0){//NextCol
		c++;
		if(c==n){
			++Nsolution;
			c--;
		}
		else {
			q[c]=-1;
		}
		
		while(c >=0){//nextrow
			q[c]++;
			if(q[c]==n){
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
	delete []q;

	return Nsolution;
}

int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}

/* Pretty straight foward, it literally does what the 1d queens program does, except its dynamic to any variable of queens. The only things that are different is, i had to make 
the array variable, depending on the number of queens, so i had to make q a pointer, and then intialize the array to be of a new int n. then i replaced where the #8 is in with n, 
for example, c==8 would become c==n; if c is equal to n, then we have a solution, q[c] == 8 becomes q[c] == n, if q[c] == n that means we went off the board and need to backtrack.
The part that took me a while was returning the number of soultions, it was obvious that i had to make it static to keep track the number of soultions there were. I would
then return that number of soultions once i reached a point where i've backtracked off the board. The part that caused me a headache was, once we returned the number of solutions
and want to move on to the next n of queens, the static variable needs to be reset, took me a while to realize that nSolutions wasnt reseeting and just adding up all the previous
solutions, so i created a variable j that would hold the current # of solutions, i would set the static variable equal to 0, and then return j, and j would then get reset as its out
of its scope. */
