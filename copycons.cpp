#include<iostream>
using namespace std;

class Complex
{
	 float real,imag;
	public:	
		Complex(){}
		void set(float,float);
		void show()const;
};

void Complex::set(float real,float imag)
{
	this->real=real;
	this->imag=imag;
}

void Complex::show()const
{
	cout<<"("<<real<<","<<imag<<")";
}

main()
{
	Complex x;
	x.set(1,2);
	
	Complex y(x);
}
