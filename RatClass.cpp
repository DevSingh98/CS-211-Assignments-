#include <iostream>
#include <cmath>
using namespace std;

class Rat {
private:
	int n;
	int d;
public:
	// constructors
	// default constructor
	Rat() {
		n = 0;
		d = 1;
	}
	// 2 parameter constructor
	Rat(int i, int j) {
		n = i;
		d = j;
	}
	// conversion constructor
	Rat(int i) {
		n = i;
		d = 1;
	}
	//accessor functions (usually called get() and set(...) )
	int getN() { return n; }
	int getD() { return d; }
	void setN(int i) { n = i; }
	void setD(int i) { d = i; }

	//arithmetic operators
	Rat operator+(Rat r) {
		Rat t;
		t.n = n * r.d + d * r.n;
		t.d = d * r.d;
		simplify(t);
		return t;
	}
	// Write the other 3 operators (operator-, operator*, operator/).
	Rat operator-(Rat r) {
		Rat t;
		t.n = n * r.d - d * r.n; 
		t.d = d * r.d; 
		simplify(t);
		return t;
	}

	Rat operator*(Rat r) {
		Rat t;
		t.n = n * r.n; 
		t.d = d * r.d;
		simplify(t);
		return t;
	}

	Rat operator/(Rat r) {
		Rat t;
		t.n = n * r.d;
		t.d = d * r.n;
		simplify(t);
		return t;
	}

	void simplify(Rat &t) {
		int gcd = t.gcd(t.getN(), t.getD());
		t.n = t.n / gcd;
		t.d = t.d / gcd;
	}

	// Calculate the GCD (ryba the goat for giving us the gcd recursive code in 111)
	int gcd(int n, int d){
		if (d == 0){
			return n;
		}
		else{
			return gcd(d, n % d);
		}
	}

	// 2 overloaded i/o operators
	friend ostream& operator<<(ostream& os, Rat r);
	friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

   // operator<<() is NOT a member function but since it was declared a friend of Rat
   // it has access to its private parts.
ostream& operator<<(ostream& os, Rat r) {
	if (r.n == r.d)
		os << 1;

	else if (r.n%r.d == 0)
		os << (r.n) / (r.d);

	else if (r.n == 0)
		os << 0;

	else if (r.n>r.d) {
		int whole, fraction;
		whole = r.n / r.d;
		fraction = r.n - (whole)* r.d;
		os << "This is a mixed fraction, so " << r.n << "/" << r.d << " will be written as :";
		os << whole << " " << fraction << "/" << r.d;
	}

	else {
		os << r.n << "/" << r.d;
	}
	return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
istream& operator>>(istream& is, Rat& r) {
	is >> r.n >> r.d;
	return is;
}

int main() {
	Rat r1(16, 7), r2(4, 3);
	cout << "r1-> " << r1 << endl;
	cout << "r2-> " << r2 << endl;
	cout << "r1 + r2: " << r1 + r2 << endl;
	cout << "r1 - r2: " << r1 - r2 << endl;
	cout << "r1 * r2: " << r1 * r2 << endl;
	cout << "r1 / r2: " << r1 / r2 << endl;
	return 0;
}

/* In this program i modified the rat class by overloading the + * / operators to work with fractions. I started with the subtraction operator
which was the same as the addition operator except i just changed the + to a minus when combining the top portion of the fraction. For * operator
i just cross multiplied, rat 1 top * rat 2's bottom, and rat 2's top * rat 1's bottom, then i wrote a function called simplify that calls another 
function i wrote(got from ryba last semester) called gcd which will calculate the gcd between both fractions and return it. It then divides the top and bottom by the gcd and 
sets the new top and bottom.the << member function which prints the fraction, and if the top is bigger then the botton, it divides the top and bottom
then mods the top and bottom and sets that as the new top
*/
