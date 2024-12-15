/*!
	@file
	@brief ������������ ���� ������ Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

/*!
	@brief ����� ������������ ����� Complex
*/

class Complex
{
	/*!
		@brief �������������� ����� �����
	*/
	double Re;

	/*!
		@brief ������ ����� �����
	*/
	double Im;

public:
	Complex(double Real = 0, double Imaginary = 0);

	Complex(const Complex&);

	~Complex();

	void Set(double Real, double Imaginary = 0);

	operator double();

	double abs();

	friend istream& operator>> (istream&, Complex&);

	friend ostream& operator<< (ostream&, Complex&);

	Complex operator+ (const Complex&);

	Complex operator- (const Complex&);

	Complex operator+ (const double&);

	friend Complex operator+ (const double&, const Complex&);

	Complex operator- (const double&);

	friend Complex operator- (const double&, const Complex&);

	Complex operator* (const Complex&);

	Complex operator* (const double&);

	friend Complex operator* (const double&, const Complex&); 

	Complex operator/ (const double&);

	Complex& operator+= (const Complex&);

	Complex& operator-= (const Complex&);

	Complex& operator*= (const Complex&);  

	Complex& operator+= (const double&);

	Complex& operator-= (const double&);

	Complex& operator*= (const double&);

	Complex& operator/= (const double&);

	Complex& operator= (const Complex&);

	Complex& operator= (const double&);
};
#endif
