#include<iostream>
#include<fstream>
#include<cmath>
#include "complex.h"

#define N 1000
#define k0 200
#define PI 3.141592

using namespace std;

int main() {

	ofstream prob2_mag_file;
	ofstream prob2_phase_file;
	ofstream prob2_index_file;
	prob2_mag_file.open("prob2_mag.txt");
	prob2_phase_file.open("prob2_phase.txt");
	prob2_index_file.open("prob2_index.txt");

	complex* ip_x = new complex[N];   // ip_x = x[n]
	complex* W_exp = new complex[N];    // W_exp = exp(-j2πkn/N)
	complex* op_X = new complex[N];  // op_X = X[k]

	// x[n] = exp(-j2πnk0/N) (0 <= n < N)
	for (int n = 0; n < N; n++) {
		double theta = 2 * PI * k0 * n / N;
		ip_x[n] = complex(cos(theta), sin(theta));
	}

	// define X[k] by DTFS
	for (int k = 0; k < N; k++) {
		op_X[k] = complex(0, 0);
		for (int n = 0; n < N; n++) {
			double theta = -2 * PI * k * n / N;
			W_exp[n] = complex(cos(theta), sin(theta));
			op_X[k] += (ip_x[n] * W_exp[n]);
		}
	}

	// write to file
	for (int i = 0; i < N; i++) {
		prob2_index_file << i << endl;
		prob2_mag_file << op_X[i].get_mag() << endl;
		prob2_phase_file << op_X[i].get_phase() << endl;
	}
	system("pause");
	return 0;
}
