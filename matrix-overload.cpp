#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>

using namespace std;

class Matrix
{
  int rows,cols;
  int **mat;

  void create();
  void input();
  void clear();
 public:

  Matrix();
  void set(int,int);

  Matrix operator +()const;                             // y=x;
  friend Matrix operator -(const Matrix&);              // y=-x
  int operator !()const;                                // if(!x)
  Matrix operator ++();                                 // y=++x
  Matrix operator ++(int);                              // y=x++;
  Matrix operator --();
  Matrix operator --(int);
  Matrix operator ~()const;                             // y=~x;
        
  Matrix operator +(int) const;                         // y=x+3;  
  friend Matrix operator +(int, const Matrix&);         // y=3+x;  
  Matrix operator +(const Matrix &)const;               // z=x+y;  

  Matrix operator -(int) const;                           
  friend Matrix operator -(int, const Matrix&);           
  Matrix operator -(const Matrix &)const;                 

  Matrix operator *(int) const;                           
  friend Matrix operator *(int, const Matrix&);           
  Matrix operator *(const Matrix &)const;                 

  int operator ==(const Matrix&)const;
  int operator !=(const Matrix&)const;
  
  Matrix operator =(const Matrix&);                       // z=y=x;
  void  operator +=(int);                                 // y+=5;
  void  operator +=(const Matrix&);                       // y+=x;
  void  operator -=(int);                                 
  void  operator -=(const Matrix&);                       
  void  operator *=(int);                                 
  void  operator *=(const Matrix&);
  operator char*() const;                      

  friend ostream& operator <<(ostream&,const Matrix&);
  friend istream& operator >>(istream&,Matrix&);
};

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

void Matrix::set(int rows,int cols)
{
 clear();
 this->rows=rows;
 this->cols=cols;
 create();
}

Matrix Matrix::operator +()const
{
 Matrix m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j];
 return m;
}

Matrix operator -(const Matrix &x)
{
 Matrix m;
 m.rows=x.rows;
 m.cols=x.cols;
 m.create();
 for(int i=0;i<x.rows;i++)
  for(int j=0;j<x.cols;j++)
   m.mat[i][j]=-x.mat[i][j];
 return m;
}

int Matrix::operator !()const
{
 if(rows==0)return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if(mat[i][j])return 0;
  }
 }
 return 1;
}

Matrix Matrix::operator ++()
{
 Matrix m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=++mat[i][j];
 return m;
}

Matrix Matrix::operator ++(int)
{
 Matrix m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]++;
 return m;
}

Matrix Matrix::operator --()
{
 Matrix m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=--mat[i][j];
 return m;
}

Matrix Matrix::operator --(int)
{
 Matrix m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]--;
 return m;
}

Matrix Matrix::operator ~()const
{
 Matrix t;
 t.rows=cols;
 t.cols=rows;
 t.create();
 for(int i=0;i<t.rows;i++)
  for(int j=0;j<t.cols;j++)
   t.mat[i][j]=mat[j][i];
 return t;
}

Matrix Matrix::operator +(int n)const
{
 Matrix m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]+n;
 return m; 
}

Matrix operator +(int n,const Matrix &x)
{
 Matrix m;
 m.rows=x.rows;
 m.cols=x.cols;
 m.create();
 for(int i=0;i<x.rows;i++)
  for(int j=0;j<x.cols;j++)
   m.mat[i][j]=n+x.mat[i][j];
 return m; 
}

Matrix Matrix::operator +(const Matrix &x)const
{
 if(rows!=x.rows || cols!=x.cols)
  throw "cannot add matrices of different orders..";

 Matrix m;
 m.rows=x.rows;
 m.cols=x.cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]+x.mat[i][j];  
 return m;
}

Matrix Matrix::operator -(int n)const
{
 Matrix m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]-n;
 return m; 
}

Matrix operator -(int n,const Matrix &x)
{
 Matrix m;
 m.rows=x.rows;
 m.cols=x.cols;
 m.create();
 for(int i=0;i<x.rows;i++)
  for(int j=0;j<x.cols;j++)
   m.mat[i][j]=n-x.mat[i][j];
 return m; 
}

Matrix Matrix::operator -(const Matrix &x)const
{
 if(rows!=x.rows || cols!=x.cols)
  throw "cannot subtract matrices of different orders..";
 Matrix m;
 m.rows=x.rows;
 m.cols=x.cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]-x.mat[i][j];  
 return m;
}

Matrix Matrix::operator *(int n)const
{
 Matrix m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]*n;
 return m; 
}

Matrix operator *(int n,const Matrix &x)
{
 Matrix m;
 m.rows=x.rows;
 m.cols=x.cols;
 m.create();
 for(int i=0;i<x.rows;i++)
  for(int j=0;j<x.cols;j++)
   m.mat[i][j]=n*x.mat[i][j];
 return m; 
}

Matrix Matrix::operator *(const Matrix &x)const
{
 if(cols!=x.rows)
  throw "cannot multiply matrices of invalid orders..";
 Matrix m;
 m.rows=rows;
 m.cols=x.cols;
 m.create();
 for(int i=0;i<m.rows;i++)
  for(int j=0;j<m.cols;j++)
   for(int k=m.mat[i][j]=0;k<cols;k++)
    m.mat[i][j]+=mat[i][k]*x.mat[k][j];
 return m;
}

int Matrix::operator ==(const Matrix &x)const
{
 if(rows==x.rows && cols==x.cols)
 {
  for(int i=0;i<rows;i++)
   for(int j=0;j<cols;j++)
    if(mat[i][j]!=x.mat[i][j])return 0;
  return 1;
 }
 return 0;
}

int Matrix::operator !=(const Matrix &x)const
{
 return !(*this==x);
}

Matrix Matrix::operator =(const Matrix &m)
{
 clear();
 rows=m.rows;
 cols=m.cols;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]=m.mat[i][j];
 return m;
}

void Matrix::operator +=(int n)
{
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]+=n;
}

void Matrix::operator +=(const Matrix &m)
{
 if(rows!=m.rows || cols!=m.cols)
  throw "cannot add matrices of different orders..";
 
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]+=m.mat[i][j];
}

void Matrix::operator -=(int n)
{
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]-=n;
}

void Matrix::operator -=(const Matrix &m)
{
 if(rows!=m.rows || cols!=m.cols)
  throw "cannot subtract matrices of different orders..";

 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]-=m.mat[i][j];
}

void Matrix::operator *=(int n)
{
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]*=n;
}

void Matrix::operator *=(const Matrix &x)
{
 if(cols!=x.rows)
  throw "cannot multiply matrices of invalid orders..";

 int r,c,**m;
 r=rows;
 c=x.cols;
 m=new int*[r];
 for(int i=0;i<r;i++) m[i]=new int[c];
 
 for(int i=0;i<r;i++)
  for(int j=0;j<c;j++)
   for(int k=m[i][j]=0;k<cols;k++)
     m[i][j]+=mat[i][k]*x.mat[k][j];
 clear(); 
 mat=m;
 rows=r;
 cols=c;
}

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

Matrix::operator char*() const
{
 char *s=new char[rows*cols*7+rows+1];
 *s='\0';
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   char str[10];
   sprintf(str,"%5d  ",mat[i][j]);
   strcat(s,str);
  }
  strcat(s,"\n");
 }
 return s;
}

main()
{
 /*Matrix x,y,z;
 cin>>x;
 cin>>y;

 try
 {
  z=x+y;
 }
 catch(const char *msg)
 {
  cerr<<"\nalert - "<<msg<<"\n";
  z.set(0,0);
 }
 
 cout<<"\nAddition of Matrices - \n"<<z;*/
 Matrix m;
 cin>>m;
 cout<<"\nMatrix :-"<<m;
 char *s;
 s=m;
 cout<<"\n\nString :-\n"<<s<<"\n\nLength : "<<strlen(s);
}
