#include<iostream>
#include<fstream>
#include<cmath>
#include "complex.h"


#define PI 3.141592

using namespace std;

int main() {

	ofstream prob3_mag_file;
	ofstream prob3_phase_file;
	ofstream prob3_index_file;
	prob3_mag_file.open("prob3_mag.txt");
	prob3_phase_file.open("prob3_phase.txt");
	prob3_index_file.open("prob3_index.txt");

	/*
		x(t) = 3cos(4πt) - 2sin(4πt) 
		t = nTs, Ts = 0.001s
		x[n] = x(0.001*n)
		nomalized radian freq = 4π/1000, N = 500
		x[n] = 3cos(4πn/1000) - 2sin(4πn/1000), 0 <= n < 500

		Index of array starts from 0
		I want to indicate X[k] grpah range -50 ~ 50 for k
		To accomplish it, assgin 2*range_num to array op_X so that op_X[k+range_num] equal to X[k]
		For example, X[-50] = op_X[0](op_X[-50+50])
	*/

	int N = 500;
	int range_num = 50;
	
	complex* ip_x = new complex[N];   // ip_x = x[n]
	complex* W_exp = new complex[N];    // W_exp = exp(-j4πkn/1000)
	complex* op_X = new complex[2*range_num];  // op_X = X[k]

	// x[n] = 3cos(4πn/1000) - 2sin(4πn/1000) (0 <= n < 500)
	for (int n = 0; n < N; n++) {
		double theta = 4 * PI *  n / (double)1000;
		ip_x[n] = complex(3 * cos(theta) - 2 * sin(theta),0);
	}

	// define X[k] by DTFS ,range is (-50,50)
	for (int k = -range_num; k < range_num; k++) {
		op_X[k+range_num] = complex(0, 0);
		for (int n = 0; n < N; n++) {
			double theta = -4 * PI * k * n / (double)1000;
			W_exp[n] = complex(cos(theta), sin(theta));
			op_X[k+range_num] += (ip_x[n] * W_exp[n])/(double)N;
		}
	}

	// write to file
	for (int i = 0; i < range_num*2; i++) {
		prob3_index_file << i-range_num << endl;
		prob3_mag_file << op_X[i].get_mag() << endl;
		prob3_phase_file << op_X[i].get_phase() << endl;
	}
	system("pause");
	return 0;
}