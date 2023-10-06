#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

class Record
{
  static int empno;
 
  int   eno;
  char  nam[15];
  int   age;
  float bas;
  
  void get();
  void print() const;
 public:
  static void   setStartingEmpNo(int);
  static Record *getRecs(int);
  static void   sortRecs(Record*,int);
  static void   printRecs(Record*,int);
};
int Record::empno;

void Record :: setStartingEmpNo(int n)
{
 Record::empno=n;
}

Record* Record::getRecs(int n)
{
 Record *e=new Record[n];
 for(int i=0;i<n;i++)
 {
  e[i].get();
 }
 return e;
}

void Record :: printRecs(Record *r,int n)
{
 cout<<"\n\n\tEmp No.      Name      Age   Basic";
 cout<<"\n\t----------------------------------\n";

 for(int i=0;i<n;i++)
  r[i].print();
} 

void Record::sortRecs(Record *r,int n)
{
 for(int i=1;i<n;i++)
 {
  for(int j=0;j<n-i;j++)
  {
   if(stricmp(r[j].nam,r[j+1].nam)>0)
   {
    Record tmp=r[j];
    r[j]=r[j+1];
    r[j+1]=tmp;
   }
  }
 }
}

void Record::get()
{
 eno=empno++;

 cout<<"\n";
 cout<<"\nEmployee No.  : "<<eno<<"\n";
 cin.ignore(100,'\n');
 cout<<"Enter Name    : ";
 cin.getline(nam,15);

 cout<<"Enter Age     : ";
 cin>>age;

 cout<<"Enter Basic   : ";
 cin>>bas;
}

void Record::print() const
{
 cout<<"\n\t  "<<eno<<setw(4)<<"";
 cout<<setiosflags(ios::left)<<setw(12)<<nam<<"  "
     <<setiosflags(ios::right)<<setw(3)<<age<<"   ";
 cout<<setprecision(2)<<setiosflags(ios::fixed)
     <<setiosflags(ios::showpoint)<<setw(8)<<bas; 
 cout<<resetiosflags(ios::right); 
}

main()
{
 int n;

 cout<<"\nEnter the Starting Emp. No. : ";
 cin>>n;

 Record::setStartingEmpNo(n);

 cout<<"\nEnter the No. of Employees  : ";
 cin>>n;

 Record *r=Record::getRecs(n);
 Record::sortRecs(r,n);
 Record::printRecs(r,n);

}
