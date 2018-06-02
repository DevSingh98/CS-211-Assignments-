#include <iostream>
#include <cmath>
using namespace std;

bool test(int cross[], int x) {
	static int checkList[8][5] = {
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
	for(int i=0; checkList[x][i]!= -1; i++){
		if(abs(cross[checkList[x][i]]-cross[x])==1)
			return false;
	}
	for(int i=0; i<x; i++){
		if( cross[i]== cross[x] )
			return false;
	}
	return true; 
}


void print(int cross[], int cap) {
	static int count = 0;
	cout << " Soultion number: " << ++count << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
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
				w= test(q,c);
				if(w == true){
					break;
				}
			}
		}
	}
	return 0;
}

/* In this program I demonstrate the use of my algorithm from the 1d 8 queens problem, but with a different data structure, I was able to solve a different problem with it.
I used a 1d array to store numbers, i used a already set up data structure that allows the program to know which numbers are to be in sequence and which arent allowed. 
I used two different functions, one that checks if the ordering of a sequence is legal, and one that will be triggered if we have a legal order and prints it. The test function 
basically checks if two consecutive numbers are adjacent to eachother by using the premade list/array that lets it know which numbers are next to eachother and compares
it with a given sequence. It also checks if the same number is used twice in the sequence, if any of those conditions are true, it will return false and try another number.
If it legal, it will print. If the program runs up to 8 in a slot, it will backtrack to the previous box and try a different number. It does it a number of times till all possible
placement of numbers have been tried. It only prints the legal sequence which happens to be 4 different sequences. In the main function I created the 1d array, and use a nested loop 
of two while loops. The outerloops represents the movement of columns. The inner loops reprecents the movements for rows. 
*/ 
