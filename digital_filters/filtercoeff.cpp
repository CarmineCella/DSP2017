#include <iostream>
#include <cmath>

using namespace std;

int main () {
	float SR = 44100;
	float cutoff = 440;

	float omega = 2. * M_PI * cutoff /SR;
	float det = (2. - cos (omega));

	float b1 = cos (omega) - 2.0 + sqrt (det*det -1.0);
	float a0 = 1.0 + b1;

	cout << "b1 = " << b1 << endl;
	cout << "a0 = " << a0 << endl;

	return 0;
}