#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles (each rectangle should have a width of .0001)
// and adding up the areas of the individual rectangles.
// For a rectangle at horizontal position x, the height will be f(x).
// (when you call f(x) it'll call whatever function you passed as the first parameter)
double integrate(FUNC f, double a, double b) {
   // Fill in.
  double dx= 0;
  for(double x= a; x <=b; x+=0.0001){
  	dx= dx+(f(x) * 0.0001); // adds the area for each rectangle up 
  }
  return dx;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   return 0;
}


/* In this program I use a function called integration to calcuate the total area under the curve for a given function. I used a function pointer to  reference the input function. 
when i say f(x) it is calcuating the f(x) for the function that was used to call the integration function. I then use a for loop to calculate the area of rectangles under the curve
the hieght being f(x), and the width for each rectangle is 0.0001. I then add each rectangle up to find the area under the curve which is then returned. */
