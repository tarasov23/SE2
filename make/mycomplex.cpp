#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
	@brief ����������� ������ Complex � ������� � ���� �������������� � ������ ������
*/
Complex::Complex(double Real, double Imaginary)
{
	Re = Real;   
	Im = Imaginary;
}

/*!
	@brief ����������� ������ Complex � ������� � ���� ���������� �������������� � ������ ������
*/
Complex::Complex(const Complex& aRval)
{
	Re = aRval.Re; 
	Im = aRval.Im;
}

/*!
	@brief ���������� ������ Complex, �.�. ��������� �������������� � ������ ������
*/
Complex::~Complex()
{
	Re = 0.0;
	Im = 0.0;
}

void Complex::Set(double Real, double Imaginary)
{
	Re = Real; 
	Im = Imaginary;
}

/*!
	@brief ����� ������ Complex, ������������ ������ ������������ �����
*/
Complex::operator double()
{
	return abs();
}

/*!
	@brief ����� ������ Complex, ����������� ������ ������������ �����
*/
double Complex::abs()
{
	return sqrt(Re * Re + Im * Im);
}

/*!
	@brief ����� ������ Complex, ����������� ����� ������������ ������������ ����� � ��������� ������������ �����
*/
Complex Complex::operator+ (const Complex& aRval)
{
	Complex Result;
	Result.Re = Re + aRval.Re;
	Result.Im = Im + aRval.Im;
	return Result;
}

/*!
	@brief ����� ������ Complex, ����������� �������� ������������ ������������ ����� � ��������� ������������ �����
*/
Complex Complex::operator- (const Complex& aRval)
{
	Complex Result;
	Result.Re = Re - aRval.Re;
	Result.Im = Im - aRval.Im;
	return Result;
}

/*!
	@brief ����� ������ Complex, ������������� �������� ����� ������������ �����
*/
Complex Complex::operator+ (const double& aLval)
{
	Complex Result;
	Result.Re = Re + aLval;
	Result.Im = Im;
	return Result;
}

/*!
	@brief ����� ������ Complex, ����������� �������� ����� ������������ �����
*/
Complex Complex::operator- (const  double& aRval)
{
	Complex Result(*this);
	Result.Re = Re - aRval;
	return Result;
}

/*!
	@brief ����� ������ Complex, ���������� ����������� ����������� ����� �� �������� ����������� �����
*/
Complex Complex::operator* (const Complex& aRval)
{
	Complex Result; 
	Result.Re = Re * aRval.Re - Im * aRval.Im; 
	Result.Im = Re * aRval.Im + Im * aRval.Re;
	return Result;
}

/*!
	@brief ����� ������ Complex, ���������� ����������� ����������� ����� �� ���������
*/
Complex Complex::operator* (const double& aRval)
{
	Complex Result;
	Result.Re = Re * aRval;
	Result.Im = Im * aRval;
	return Result;
}

/*!
	@brief ����� ������ Complex, ����������� ��������� ������� ������������ ������������ ����� �� ���������
*/
Complex Complex::operator/ (const double& aRval)
{
	Complex Result;
	Result.Re = Re / aRval;
	Result.Im = Im / aRval;
	return Result;
}

/*!
	@brief ����� ������ Complex, ������������� ������������ ����� �������� ����� ������������ � ��������� ����������� �����
*/
Complex& Complex::operator+= (const   Complex& aRval)
{
	Re += aRval.Re;
	Im += aRval.Im;
	return *this;
}

/*!
	@brief ����� ������ Complex, ������������� ������������ ����� �������� �������� ������������ � ��������� ����������� �����
*/
Complex& Complex::operator-= (const Complex& aRval)
{
	Re -= aRval.Re;
	Im -= aRval.Im; 
	return *this;
}

/*!
	@brief ����� ������ Complex, ������������� ������������ ����� �������� ������������ ������������ � ��������� ����������� �����
*/
Complex& Complex::operator*= (const Complex& aRval)
{
	double tmpRe = Re; 
	Re = Re * aRval.Re - Im * aRval.Im;
	Im = Im * aRval.Re + tmpRe * aRval.Im; 
	return *this;
}

/*!
	@brief ����� ������ Complex, ������������� �������� ����� ������������ ����� �������� ����� ���� ����� � �������� ������
*/
Complex& Complex::operator+= (const double& aRval)
{
	Re += aRval;
	return*this;
}

/*!
	@brief ����� ������ Complex, ������������� �������� ����� ������������ ����� �������� �������� ���� ����� � ��������� �����
*/
Complex& Complex::operator-= (const double& aRval)
{
	Re -= aRval;
	return *this;
}

/*!
	@brief ����� ������ Complex, ������������� ������������ ����� �������� ������������ ������������ � ��������� ����������� �����
*/
Complex& Complex::operator*= (const  double& aRval)
{
	Re *= aRval;
	Im *= aRval;
	return *this;
}

/*!
	@brief ����� ������ Complex, ������������� �������� ����� ������������ ����� �������� ����� ���� ����� � �������� ������
*/
Complex& Complex::operator/= (const double& aRval)
{
	Re /= aRval;
	Im /= aRval;
	return *this;
}

/*!
	@brief ����� ������ Complex, ������������� ������������ ������������ ����� �������� ��������� ������������ �����
*/
Complex& Complex::operator= (const Complex& aRval)
{
	Re = aRval.Re;
	Im = aRval.Im;
	return *this;
}

/*!
	@brief ����� ������ Complex, ������������ ����������� ����� � �������� ��������
*/
Complex& Complex::operator= (const double& aRval)
{
	Re = aRval;
	Im = 0.0;
	return *this;
}

/*!
	@brief ����� ������ Complex, �����������, ������ �� ����������� ����� ���������
*/
istream& operator>> (istream& stream, Complex& min)
{
	char tmp[256];  
	stream >> min.Re >> min.Im >> tmp;
	return stream;
}

/*!
	@brief ����� ������ Complex, �����������, ������ �� ����������� ����� ���������
*/
ostream& operator<< (ostream& stream, Complex& max)
{
	stream << max.Re;  
	if (!(max.Im < 0)) stream << '+';  
	stream << max.Im << 'i';  
	return stream;
}

/*!
	@brief ����� ������ Complex, ����������� ����� ������������ ������������ ����� � �������� ������������ � ��������� �����
*/
Complex operator+ (const double& aLval, const Complex& aRval)
{
	Complex Result; 
	Result.Re = aLval + aRval.Re;  
	Result.Im = aRval.Im;
	return Result;
}

/*!
	@brief ����� ������ Complex, ����������� �������� ������������ ������������ ����� � �������� ������������ � ��������� �����
*/
Complex operator- (const double& aLval, const Complex& aRval)
{
	Complex Result;
	Result.Re = aLval - aRval.Re;
	Result.Im = -aRval.Im;
	return Result;
}

/*!
	@brief ����� ������ Complex, ����������� ������������ ������������ ������������ ����� � �������� ������������ � ��������� �����
*/
Complex operator* (const double& aLval, const Complex& multiplier)
{
	Complex Result;
	Result.Re = aLval * multiplier.Re;
	Result.Im = aLval * multiplier.Im;
	return Result;
}
