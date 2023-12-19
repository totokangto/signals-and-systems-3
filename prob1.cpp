#include<iostream>
#include<fstream>
#include<cmath>
#include "complex.h"

#define N 1024
#define PI 3.141592

using namespace std;

int main() {
	
	ofstream prob1_mag_file;
	ofstream prob1_phase_file;
	prob1_mag_file.open("prob1_mag.txt");
	prob1_phase_file.open("prob1_phase.txt");

	complex* ip_x= new complex[N];   // ip_x = x[n]
	complex* W_exp = new complex[N];    // W_exp = exp(-j2¥ðkn/N)
	complex* op_X = new complex[N];  // op_X = X[k]

	// x[n] = 1(0 <= n <= 9), 0 (otherwise)
	for (int i = 0; i < N; i++) {
		if (i < 10) {
			ip_x[i] = complex(1, 0);
		}
		else {
			ip_x[i] = complex(0, 0);
		}
	}

	// define X[k] by DTFS
	for (int k = 0; k < N; k++) {
		op_X[k] = complex(0, 0);
		for (int j = 0; j < N; j++) {
			double a = -2 * PI * k * j / N;
			W_exp[j] = complex(cos(a), sin(a));
			op_X[k] += (ip_x[j] * W_exp[j]);
		}
	}

	// write to file
	for (int i = 0; i < N; i++) {
		prob1_mag_file << op_X[i].get_mag() << endl;
		prob1_phase_file << op_X[i].get_phase() << endl;
	}
	system("pause");
	return 0;
}