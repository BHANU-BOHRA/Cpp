#include<iostream>
using namespace std;

void print();
class Complex
{
	float real;
	public:
		float imag;
		void set(float,float);
		void print();
		void show();
};
void Complex::set(float real,float imag)
{
	this->real=real;
	Complex::imag=imag;
}
void Complex::show()
{
	cout<<"\n("<<real<<", "<<imag<<"j)";
}
void Complex::print()
{
	cout<<"\n("<<real<<", "<<imag<<"j)";
}
void print()
{
	cout<<"\nThis is Global Function\n";
}
main()
{
	//real=1;
	//imag=2;
	//set(1,2);
	print();
	Complex c;
	Complex *p;
	p=new Complex;
	//c.real=1;
	c.imag=2;
	//p->real=3;
	p->imag=4;
	c.set(1.5,3.2);
	p->set(1.1,5.7);
	p->print();
	c.show();
}
