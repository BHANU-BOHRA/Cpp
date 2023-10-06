#include<iostream>

using namespace std;

class Alfa
{
  int n;
 protected:
  int x;
 public:
  void set(int,int);
  void print();
};

class Beta : public Alfa
{
  int x;
 public:
  void set(int,int,int);
  void show();
};

void Alfa::set(int n,int x)
{
 Alfa::n=n;
 Alfa::x=x;
}

void Alfa::print()
{
 cout<<"\n\n";
 cout<<"\nAlfa[n] : "<<n;
 cout<<"\nAlfa[x] : "<<x;
}

void Beta::set(int n,int x,int y)
{
 //n=0;           //invalid.. no such member
 Alfa::x=x;       //ok
 
 //instead of all of the above

 Alfa::set(n,x);

 Beta::x=y;
}

void Beta::show()
{
 cout<<"\n\n";
 //cout<<"\nAlfa[n] : "<<n;
 cout<<"\nAlfa[x] : "<<Alfa::x;
 cout<<"\nBeta[x] : "<<x;
}

main()
{
 Beta b;
 b.set(10,20,30);
 b.print();
 b.show();
} 
