#pragma once
#ifndef __COMPLEX
#define __COMPLEX
#include <math.h>
class complex {
public:
	// �Ǽ� ��� ����
	double re_num, im_num;
	// ������
	complex() { re_num = im_num = 0; }; // argument ���� ��
	complex(double x, double y) { re_num = x; im_num = y; }; //argument 2��
	complex(double theta) { re_num = cos(theta); im_num = sin(theta); }; // argument 1��

	// ��� �Լ�
	double get_mag();
	double get_phase();

	// ������ �����ε�
	complex& operator=(const complex&);
	complex& operator+=(const complex&);
	complex operator+(const complex&);
	complex operator-(const complex&);
	complex operator*(const complex&); // ��� ���ϱ�
	complex operator/(const double&);  // �Ǽ��� ������
	complex operator/(const complex&); // ����� ������
	complex operator*(const double&);  // �Ǽ� ���ϱ�

};
#endif#pragma once
