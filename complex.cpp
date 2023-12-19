#include <iostream>
#include <math.h>
#include "complex.h"
#define PI 3.141592

using namespace std;

double complex::get_mag() {
	return sqrt(re_num*re_num + im_num*im_num); // ũ�� ���ؼ� ��ȯ
}
double complex::get_phase() {
	// ���Ҽ� --> ������ ��ȯ
	if (re_num == 0.0) {
		if (im_num >= 0.0) return PI / 2.0; // 90��
		else return -PI / 2.0; // -90��
	}
	else return atan(im_num / re_num);
}
complex complex::operator/(const complex& y) {

	complex c;
	c = complex(y.re_num, -y.im_num); // ���Ҽ� y�� �ӷ����Ҽ�
	if (re_num == 0.0 && im_num == 0.0) { cout << " complex: divided by 0\n"; return c; } // ����ó��
	c = (*this + c) / (y.re_num * y.re_num + y.im_num * y.im_num);
	return c;
}
complex& complex::operator=(const complex& x) {
	re_num = x.re_num;
	im_num = x.im_num;
	return *this;
}
complex& complex::operator+=(const complex& y) {
	re_num += y.re_num;
	im_num += y.im_num;
	return *this;
}
complex complex::operator+(const complex& y) {
	complex c;
	c.re_num = re_num + y.re_num;
	c.im_num = im_num + y.im_num;
	return c;
}
complex complex::operator-(const complex& y) {
	complex c;
	c.re_num = re_num - y.re_num;
	c.im_num = im_num - y.im_num;
	return c;
}
complex complex::operator*(const complex& y) {
	complex c;
	c.re_num = re_num*y.re_num - im_num*y.im_num;
	c.im_num = re_num*y.im_num + im_num*y.re_num;
	return c;
}
complex complex::operator/(const double& y) {
	complex c;
	c.re_num = re_num / y;
	c.im_num = im_num / y;
	return c;
}
complex complex::operator*(const double& y) {
	complex c;
	c.re_num = re_num*y;
	c.im_num = im_num*y;
	return c;
}