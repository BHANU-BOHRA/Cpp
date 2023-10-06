#include<iostream>
#include<iomanip>
using namespace std;

class Complex
{
  float real,imag;
 
 public:
  
  Complex();
  
  void set(float,float);
  void get();
  void print()const;
  int equals(const Complex&)const;
  
  Complex add(const Complex&)const;
  static Complex sum(const Complex&,const Complex&);
  void add(const Complex&,const Complex&);
  void sub(const Complex&,const Complex&);
  void mul(const Complex&,const Complex&);
  void div(const Complex&,const Complex&);
  
  Complex operator +()const;
  friend Complex operator -(const Complex&);
  Complex operator ++();
  Complex operator ++(int);
  Complex operator --();
  Complex operator --(int);
  int operator !()const;
  
  Complex operator +(float)const;
  Complex operator +(const Complex&)const;
  friend Complex operator +(float, const Complex&);
  Complex operator -(float)const;
  Complex operator -(const Complex&)const;
  friend Complex operator -(float, const Complex&);
  
  Complex operator *(float)const;
  Complex operator *(const Complex&)const;
  friend Complex operator *(float, const Complex&);
  Complex operator /(float)const;
  Complex operator /(const Complex&)const;
  friend Complex operator /(float, const Complex&);
  
  int operator ==(const Complex&)const;
  int operator !=(const Complex&)const;
  
  friend ostream& operator <<(ostream&,const Complex&);
  friend istream& operator >>(istream&,Complex&);
  
  void operator +=(float);
  void operator +=(const Complex&);
  void operator -=(float);
  void operator -=(const Complex&);
};

Complex::Complex()
{
 real=imag=0;
}

void Complex::set(float real,float imag)
{
 this->real=real;
 Complex::imag=imag;
}

void Complex::get()
{
 cout<<"\nEnter the Real part  : ";
 cin>>real;
 cout<<"\nEnter the Imag. part : ";
 cin>>imag;
}

void Complex::print()const
{
 cout<<setprecision(2)<<setiosflags(ios::showpoint);
 cout<<"("<<real<<setiosflags(ios::showpos)<<imag<<"j)";
 cout<<resetiosflags(ios::showpos);
}

int Complex::equals(const Complex &c)const
{
 return real==c.real&&imag==c.imag;
}

Complex Complex::add(const Complex &x)const
{
 Complex n;
 n.real=real+x.real;
 n.imag=imag+x.imag;
 return n;
}

Complex Complex::sum(const Complex &x,const Complex &y)
{
 Complex n;
 n.real=x.real+y.real;
 n.imag=x.imag+y.imag;
 return n;
}

void Complex::add(const Complex &x,const Complex &y)
{
 real=x.real+y.real;
 imag=x.imag+y.imag;
}

void Complex::sub(const Complex &x,const Complex &y)
{
 real=x.real-y.real;
 imag=x.imag-y.imag;
}

void Complex::mul(const Complex&x,const Complex &y)
{
 real=x.real*y.real-x.imag*y.imag;
 imag=x.imag*y.real+x.real*y.imag;
}

void Complex::div(const Complex&x,const Complex &y)
{
 real=(x.real*y.real+x.imag*y.imag)/(y.real*y.real+y.imag+y.imag);
 imag=(x.imag*y.real+x.real*y.imag)/(y.real*y.real+y.imag+y.imag);
}

Complex Complex::operator +()const
{
 Complex c;
 c.real=real;
 c.imag=imag;
 return c;
}


Complex operator -(const Complex &n)
{
 Complex c;
 c.real=-n.real;
 c.imag=-n.imag;
 return c;
}

Complex Complex::operator ++()
{
 Complex c;
 c,real=++real;
 c.imag=++imag;
 return c;
}

Complex Complex::operator ++(int)
{
 Complex c;
 c,real=real++;
 c.imag=imag++;
 return c;
}

Complex Complex::operator --()
{
 Complex c;
 c,real=--real;
 c.imag=--imag;
 return c;
}

Complex Complex::operator --(int)
{
 Complex c;
 c,real=real--;
 c.imag=imag--;
 return c;
}

int Complex::operator !()const
{
 return real==0&&imag==0;
}

Complex Complex::operator +(float n)const
{
 Complex c;
 c.real=real+n;
 c.imag=imag+n;
 return c;
}

Complex Complex::operator +(const Complex& n)const
{
 Complex c;
 c.real=real+n.real;
 c.imag=imag+n.imag;
 return c;
}

Complex operator +(float n,const Complex& x)
{
 Complex c;
 c.real=n+x.real;
 c.imag=n+x.imag;
 return c;
}

Complex Complex::operator -(float n)const
{
 Complex c;
 c.real=real-n;
 c.imag=imag-n;
 return c;
}

Complex Complex::operator -(const Complex& n)const
{
 Complex c;
 c.real=real-n.real;
 c.imag=imag-n.imag;
 return c;
}

Complex operator -(float n,const Complex& x)
{
 Complex c;
 c.real=n-x.real;
 c.imag=n-x.imag;
 return c;
}

Complex Complex::operator *(float n)const
{
 Complex c;
 c.real=n*real;
 c.imag=n*imag;
 return c;
}

Complex Complex::operator *(const Complex& n)const
{
 Complex c;
 c.real=real*n.real-imag*n.imag;
 c.imag=imag*n.real+real*n.imag;
 return c;
}

Complex operator *(float n,const Complex& x)
{
 Complex c;
 c.real=n*x.real;
 c.imag=n*x.imag;
 return c;
}

Complex Complex::operator /(float n)const
{
 Complex c;
 c.real=real/n;
 c.imag=imag/n;
 return c;
}

Complex Complex::operator /(const Complex& n)const
{
 Complex c;
 c.real=(real*n.real+imag*n.imag)/(n.real*n.real+n.imag+n.imag);
 c.imag=(imag*n.real+real*n.imag)/(n.real*n.real+n.imag+n.imag);
 return c;
}

Complex operator /(float n,const Complex& x)
{
 Complex c;
 c.real=(n*x.real)/(x.real*x.real+x.imag+x.imag);
 c.imag=-(n*x.imag)/(x.real*x.real+x.imag+x.imag);
 return c;
}

int Complex::operator ==(const Complex& n)const
{
 return real==n.real&&imag==n.imag;
}

int Complex::operator !=(const Complex& n)const
{
 return real!=n.real||imag!=n.imag;
}

ostream& operator <<(ostream &put, const Complex &c)
{
  put<<setprecision(2)<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed);
  put<<c.real<<setiosflags(ios::showpos)<<c.imag<<"j";
  put<<resetiosflags(ios::showpos);
  return put;
}

istream& operator >>(istream &get,Complex &c)
{
 cout<<"Enter Real Part  : ";
 get>>c.real;
 cout<<"Enter Imag. Part : ";
 cin>>c.imag;
 return get;
}

void Complex::operator +=(float n)
{
 real+=n;
 imag+=n;
}

void Complex::operator +=(const Complex &n)
{
 real+=n.real;
 imag+=n.imag;
}

void Complex::operator -=(float n)
{
 real-=n;
 imag-=n;
}

void Complex::operator -=(const Complex &n)
{
 real-=n.real;
 imag-=n.imag;
}

main()
{
 Complex x,y,z;
 cin>>x;
 cin>>y;

 z=x+y;

 cout<<"\nx : "<<x;
 cout<<"\ny : "<<y;
 cout<<"\nz : "<<z;

 cout<<"\n\n";
}
