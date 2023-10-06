#include<iostream>

using namespace std;

class Sample
{
  static int sno;
  
  int val;
 public:
  Sample();
  ~Sample();
};
int Sample::sno;

Sample::Sample()
{
 val=++sno;
 cout<<"\nconstructing object : "<<val<<"\n";
}

Sample::~Sample()
{
 sno--;
 cout<<"\ndestroying   object : "<<val; 
 cout<<"\nobjects remaining   : "<<sno<<"\n";
}

main()
{
 cout<<"\n";

 Sample a,b,*p,*q;
 p=new Sample;

 {
  Sample c;
  q=new Sample;
 }
 
 delete p;
  
 cout<<"\nend of code..\n";
}
