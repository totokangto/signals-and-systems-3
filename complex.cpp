#include <iostream>
#include <math.h>
#include "complex.h"
#define PI 3.141592

using namespace std;

double complex::get_mag() {
	return sqrt(re_num*re_num + im_num*im_num); // 크기 구해서 반환
}
double complex::get_phase() {
	// 복소수 --> 페이저 변환
	if (re_num == 0.0) {
		if (im_num >= 0.0) return PI / 2.0; // 90도
		else return -PI / 2.0; // -90도
	}
	else return atan(im_num / re_num);
}
complex complex::operator/(const complex& y) {

	complex c;
	c = complex(y.re_num, -y.im_num); // 복소수 y의 켤레복소수
	if (re_num == 0.0 && im_num == 0.0) { cout << " complex: divided by 0\n"; return c; } // 예외처리
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