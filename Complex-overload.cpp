#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

class Complex
{
  float real,imag;
 public:
  Complex();
  Complex(float,float);
  
  Complex operator +()const;
  friend Complex operator -(const Complex&);
  Complex operator ++();
  Complex operator ++(int);
  Complex operator --();
  Complex operator --(int);
  int operator !()const;

  friend void operator <<(ostream&,const Complex&);
};

Complex::Complex()
{
 real=imag=0;
}

Complex::Complex(float real,float imag)
{
 this->real=real;
 this->imag=imag;
}

Complex Complex::operator +()const
{
 Complex c;
 c.real=real;
 c.imag=imag;
 return c;
}

Complex operator -(const Complex &c)
{
 Complex d;
 d.real=-c.real;
 d.imag=-c.imag;
 return d;
}

Complex Complex::operator ++()
{
 Complex c;
 c.real=++real;
 c.imag=++imag;
 return c;
}

Complex Complex::operator ++(int)
{
 Complex c;
 c.real=real++;
 c.imag=imag++;
 return c;
}

Complex Complex::operator --()
{
 Complex c;
 c.real=--real;
 c.imag=--imag;
 return c;
}

Complex Complex::operator --(int)
{
 Complex c;
 c.real=real--;
 c.imag=imag--;
 return c;
}

int Complex::operator !()const
{
 return real==0&&imag==0;
}

void operator <<(ostream &put, const Complex &c)
{
 put<<setprecision(2)<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed);
 put<<c.real<<setiosflags(ios::showpos)<<c.imag<<"j";
 put<<resetiosflags(ios::showpos); 
}

main()
{
 Complex x(1.5,-2.3);
 Complex y,z;

 y=-x;
 cout<<"\nx : "<<x;
 cout<<"\ny : "<<y;
 cout<<"\n";
 
 z=x++;
 cout<<"\nx : "<<x;
 cout<<"\nz : "<<z;
 cout<<"\n";

 Complex c;

 if(!c)
  cout<<"\nc is not assigned..\n";
 else
  cout<<"\nc is assigned..\n";

 cout<<"\n";

}
