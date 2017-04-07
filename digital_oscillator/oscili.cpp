#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main () {
	// calcolo parametri oscillatore
	float time = 10;
	float SR = 44100;
	int D = time * SR;
	float fx = 440;
	int N = 4096;
	float fn = (float) SR / N;
	float I = fx / fn;
	float phi = 0;
	vector<float> TAB(N + 1); // guard point

	// generazione tabella sinusoide
	for (int i = 0; i < N; ++i) {
		TAB[i] = sin (2. * M_PI * (float) i / N);
	}
	TAB[N] = TAB[0];

	ofstream out ("oscili.pcm", ios::binary);

	for (int i = 0; i < D; ++i) {
		int index = (int) phi;
		float frac = phi - index;
		float s = (1. - frac) * TAB[index] + frac * TAB[index + 1];
		//float s= TAB[index]; // no interpolazione
		//short c = (short) (s * 32000); // 16 bit
		//char c = (char) (s * 127); // 8 bit
		//out.write ((char*) &c, sizeof (char));
		out.write ((char*) &s, sizeof (float));
		phi = phi + I;
		if (phi > N) {
			phi = phi - N;
		}
	}
	return 0;
}