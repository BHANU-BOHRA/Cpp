#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std;

class String;

class Matrix
{
  int rows,cols;
  int **mat;
  void create();
  void input();
  void clear();
 public:
  Matrix();
  friend ostream& operator <<(ostream&,const Matrix&);
  friend istream& operator >>(istream&,Matrix&);
  operator String() const;
  //friend String::String(const Matrix&);
};

ostream& operator <<(ostream &put,const Matrix &m)
{
 put<<"\n";
 for(int i=0;i<m.rows;i++)
 {
  for(int j=0;j<m.cols;j++)put<<setw(5)<<m.mat[i][j]<<" ";
  put<<"\n";
 }
 return put;
}

Matrix::Matrix()
{
 rows=cols=0;
}

void Matrix::create()
{
 if(rows<=0||cols<=0)
 {
  rows=cols=0;
  return;
 }
 mat=new int*[rows];
 for(int i=0;i<rows;i++)mat[i]=new int[cols];
}

void Matrix::input()
{
 cout<<"\n";
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   cout<<"Enter Item["<<i<<"]["<<j<<"] : ";
   cin>>mat[i][j];
  }
  cout<<"\n";
 }
}

void Matrix::clear()
{
 if(rows)
 {
  for(int i=0;i<rows;i++)delete mat[i];
  delete mat;
  rows=cols=0;
 }
}

istream& operator >>(istream &get,Matrix &m)
{
 m.clear();

 cout<<"\n";
 cout<<"Enter the No. of Rows : ";
 cin>>m.rows;
 cout<<"Enter the No. of Cols : ";  
 get>>m.cols;

 m.create();

 cout<<"\n";

 for(int i=0;i<m.rows;i++)
 {
  for(int j=0;j<m.cols;j++)
  {
   cout<<"Enter Item["<<i<<","<<j<<"] : ";
   get>>m.mat[i][j];
  }
  cout<<"\n";
 }
 return get;
}

class String
{
  char *str;
 public:
  String();
  String(const char*);
  //String(const Matrix&);
  
  friend ostream& operator <<(ostream&,const String &);
  friend istream& operator >>(istream&,String &);
  friend Matrix::operator String() const;
};

String::String()
{
 str=new char;
 *str='\0';
}

String::String(const char *s)
{
 int i;
 for(i=0;s[i];i++);
 str=new char[i+1];
 for(i=0;s[i];i++)str[i]=s[i];
 str[i]='\0';
}

istream &operator >>(istream &get,String &s)
{
 char tmp[1000];
 fflush(stdin);
 gets(tmp);
 fflush(stdin);

 delete s.str;
 s.str=new char[strlen(tmp)+1];
 int i;
 for(i=0;tmp[i];i++) s.str[i]=tmp[i];
 s.str[i]='\0';
 
 return get;
}

ostream &operator <<(ostream &put,const String &s)
{
 put<<s.str;
 return put;
}

Matrix::operator String() const
{
 String s;
 //delete s.str;
 s.str=new char[rows*cols*7+rows+1];
 *s.str='\0';
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   char str[10];
   sprintf(str,"%5d  ",mat[i][j]);
   strcat(s.str,str);
  }
  strcat(s.str,"\n");
 }
 return s;
}


/*String::String(const Matrix &m)
{
 delete str;
 str=new char[m.rows*m.cols*7+m.rows+1];
 *str='\0';
 for(int i=0;i<m.rows;i++)
 {
  for(int j=0;j<m.cols;j++)
  {
   char s[10];
   sprintf(s,"%5d  ",m.mat[i][j]);
   strcat(str,s);
  }
  strcat(str,"\n");
 }
}*/

main()
{
 Matrix m;
 cin>>m;
 String s;
 s=m;
 cout<<"\nMatrix :-"<<m;
 cout<<"\n\nString :-\n"<<s;
 
}
