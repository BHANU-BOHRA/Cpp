#include<iostream>
using namespace std;
int x=10;
namespace dmatics
{
 int x=20;
 void show()
 {
  cout<<"\ndmatics[x] : "<<x;
  }
 }
main()
{
 int x=30;
 if(x>10)
 {
  int y=x;
  int x=40;
  cout<<"\n"<<y;
  cout<<"\n"<<x;
  cout<<"\n"<<::x;
  cout<<"\n"<<dmatics::x;
  x=50;
  ::x=60;
 }
 cout<<"\n";
 cout<<"\n"<<x;
 cout<<"\n"<<::x;
 //show();
 dmatics::show();
} 
