#include<iostream>
#include<iomanip>
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

  void set();
  void set(int);
  void set(int,int);
  void set(int,int,int);
  void set(const Matrix&);
  void print()const;

  int isSqrMatrix()const;
  int isNullMatrix()const;
  int isIdentityMatrix()const;
  int isUnitMatrix()const;
  int isSymmetricMatrix()const;
  int equals(const Matrix&)const;

  Matrix getTranspose()const;//Bad Version(Dangling Pointer)
  void transposeOf(const Matrix&);//Good Version(No Dangling Pointer)
  static Matrix add(const Matrix&,const Matrix&);//Bad Version(Dangling Pointer)
  Matrix sum(const Matrix&)const;//Bad Version(Dangling Pointer)
  int sum(const Matrix&,const Matrix&);//Good Version(No Dangling Pointer)
  static Matrix sub(const Matrix&,const Matrix&);//Bad Version(Dangling Pointer)
  Matrix difference(const Matrix&)const;//Bad Version(Dangling Pointer)
  int difference(const Matrix&,const Matrix&);//Good Version(No Dangling Pointer)
  static Matrix mul(const Matrix&,const Matrix&);//Bad Version(Dangling Pointer)
  Matrix product(const Matrix&)const;//Bad Version(Dangling Pointer)
  int product(const Matrix&,const Matrix&);//Good Version(No Dangling Pointer)
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
void Matrix::set()
{
 clear();
 cout<<"\n";
 cout<<"Enter the Number of Rows : ";
 cin>>rows;
 cout<<"Enter the Number of Cols : ";
 cin>>cols;
 create();
 input();
}
void Matrix::set(int n)
{
 clear();
 rows=cols=n;
 create();
 input();
}
void Matrix::set(int rows,int cols)
{
 clear();
 this->rows=rows;
 this->cols=cols;
 create();
 input();
}
void Matrix::set(int rows,int cols,int n)
{
 clear();
 Matrix::rows=rows;
 Matrix::cols=cols;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]=n;
}
void Matrix::set(const Matrix &x)
{
 clear();
 rows=x.rows;
 cols=x.cols;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]=x.mat[i][j];
}
void Matrix::print()const
{
 cout<<"\n";
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)cout<<setw(5)<<mat[i][j]<<" ";
  cout<<"\n";
 }
}
int Matrix::isSqrMatrix()const
{
 if(rows==0)return 0;
 return rows==cols;
}
int Matrix::isNullMatrix()const
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
int Matrix::isUnitMatrix()const
{
 if(rows==0)return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if(mat[i][j]!=1)return 0;
  }
 }
 return 1;
}
int Matrix::isIdentityMatrix()const
{
 if(!isSqrMatrix())return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if((i==j&&mat[i][j]!=1)||(i!=j&&mat[i][j]!=0))return 0;
  }
 }
 return 1;
}
int Matrix::isSymmetricMatrix()const 
{
 if(!isSqrMatrix())return 0;
 if(rows!=cols)return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=i+1;j<cols;j++)
  {
   if(mat[i][j]!=mat[j][i])return 0;
  }
 }
 return 1;
}
int Matrix::equals(const Matrix &x)const
{
 if(rows!=x.rows||cols!=x.cols)return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if(mat[i][j]!=x.mat[i][j])return 0;
  }
 }
 return 1;
}
Matrix Matrix::getTranspose()const
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
void Matrix::transposeOf(const Matrix &m)
{
 clear();
 rows=m.cols;
 cols=m.rows;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]=m.mat[j][i];
}
Matrix Matrix::add(const Matrix &x,const Matrix &y)
{
 Matrix m;
 if(x.rows==y.rows&&x.cols==y.cols)
 {
  m.rows=x.rows;
  m.cols=x.cols;
  m.create();
  for(int i=0;i<m.rows;i++)
   for(int j=0;j<m.cols;j++)
    m.mat[i][j]=x.mat[i][j]+y.mat[i][j];
 }
 return m;
}
Matrix Matrix::sum(const Matrix &x)const
{
 Matrix m;
 if(rows==x.rows&&cols==x.cols)
 {
  m.rows=rows;
  m.cols=cols;
  m.create();
  for(int i=0;i<m.rows;i++)
   for(int j=0;j<m.cols;j++)
    m.mat[i][j]=mat[i][j]+x.mat[i][j];
 }
 return m;
}
int Matrix::sum(const Matrix &x,const Matrix &y)
{
 clear();
 if(x.rows==y.rows&&x.cols==y.cols)
 {
  rows=x.rows;
  cols=x.cols;
  create();
  for(int i=0;i<rows;i++)
   for(int j=0;j<cols;j++)
    mat[i][j]=x.mat[i][j]+y.mat[i][j];
  return 1;
 }
 return 0;
}
Matrix Matrix::sub(const Matrix &x,const Matrix &y)
{
 Matrix m;
 if(x.rows==y.rows&&x.cols==y.cols)
 {
  m.rows=x.rows;
  m.cols=x.cols;
  m.create();
  for(int i=0;i<m.rows;i++)
   for(int j=0;j<m.cols;j++)
    m.mat[i][j]=x.mat[i][j]-y.mat[i][j];
 }
 return m;
}
Matrix Matrix::difference(const Matrix &x)const
{
 Matrix m;
 if(rows==x.rows&&cols==x.cols)
 {
  m.rows=rows;
  m.cols=cols;
  m.create();
  for(int i=0;i<m.rows;i++)
   for(int j=0;j<m.cols;j++)
    m.mat[i][j]=mat[i][j]-x.mat[i][j];
 }
 return m;
}
int Matrix::difference(const Matrix &x,const Matrix &y)
{
 clear();
 if(x.rows==y.rows&&x.cols==y.cols)
 {
  rows=x.rows;
  cols=x.cols;
  create();
  for(int i=0;i<rows;i++)
   for(int j=0;j<cols;j++)
    mat[i][j]=x.mat[i][j]-y.mat[i][j];
  return 1;
 }
 return 0;
}
Matrix Matrix::mul(const Matrix &x,const Matrix &y)
{
 Matrix m;
 if(x.cols==y.rows)
 {
  m.rows=x.rows;
  m.cols=y.cols;
  m.create();
  for(int i=0;i<m.rows;i++)
   for(int j=0;j<m.cols;j++)
    for(int k=m.mat[i][j]=0;k<x.cols;k++)
     m.mat[i][j]+=x.mat[i][k]*y.mat[k][i];
 }
 return m;
}
Matrix Matrix::product(const Matrix &x)const
{
 Matrix m;
 if(cols==x.rows)
 {
  m.rows=rows;
  m.cols=x.cols;
  m.create();
  for(int i=0;i<m.rows;i++)
   for(int j=0;j<m.cols;j++)
    for(int k=m.mat[i][j]=0;k<cols;k++)
     m.mat[i][j]+=mat[i][k]*x.mat[k][i];
 }
 return m;
}
int Matrix::product(const Matrix &x,const Matrix &y)
{
 clear();
 if(x.cols==y.rows)
 {
  rows=x.rows;
  cols=y.cols;
  create();
  for(int i=0;i<rows;i++)
   for(int j=0;j<cols;j++)
    for(int k=mat[i][j]=0;k<x.cols;k++)
     mat[i][j]+=x.mat[i][k]*y.mat[k][i];
  return 1;
 }
 return 0;
}
main()
{       
 Matrix m,t,r;
 m.set(2,3,7);
 t.set(3,2,7);
 if(!r.product(m,t))cerr<<"\nMatrices cannot be Added..\n";
 else r.print();
}
