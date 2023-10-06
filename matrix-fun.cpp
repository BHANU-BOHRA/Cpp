#include<iostream>
#include<iomanip>
using namespace std;

int **getMatrix();
int **getMatrix(int);
int **getMatrix(int,int);
int **getMatrix(int,int,int);
int **getMatrix(int**,int,int);
void input(int**,int,int);
void printMatrix(int**,int,int);
int **create(int,int);

main()
{
	int **x;
	x=getMatrix(3,4,7);
	int **y;
	y=getMatrix(x,3,4);
	cout<<"Printing Matrix x :-\n\n";
	printMatrix(y,3,4);
	cout<<"\n\nPrinting Matrix y :-\n\n";
	printMatrix(y,3,4);
}
int **create(int r,int c)
{
	int **x;
	x=new int*[r];
	for(int i=0;i<r;i++)x[i]=new int[c];
	return x;
}
void input(int **m,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Enter Item["<<i<<"]["<<j<<"] : ";
			cin>>m[i][j];
		}
		cout<<"\n";
	}
}
void printMatrix(int **m,int r,int c)
{
	cout<<"\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)cout<<setw(5)<<m[i][j]<<" ";
		cout<<"\n";
	}
}
int **getMatrix()
{
	int r,c;
	cout<<"Enter the No. of Rows : ";
	cin>>r;
	cout<<"Enter the No. of Cols : ";
	cin>>c;
	int **m;
	m=create(r,c);
	input(m,r,c);
	return m;
}
int **getMatrix(int n)
{
	int **m;
	m=create(n,n);
	input(m,n,n);
	return m;
}
int **getMatrix(int r,int c)
{
	int **m;
	m=create(r,c);
	input(m,r,c);
	return m;
}
int **getMatrix(int r,int c,int n)
{
	int **m;
	/*m=new int*[r];
	for(int i=0;i<r;i++)
	{
		m[i]=new int[c];
		for(int j=0;j<c;j++)m[i][j]=n;
	}
	return m;*/
	m=create(r,c);
	for(int i=0;i<r;i++)
	 for(int j=0;j<c;j++)
	  m[i][j]=n;
	  return m;
}
int **getMatrix(int **m,int r,int c)
{
	int **p;
	/*m=new int*[r];
	for(int i=0;i<r;i++)
	{
		m[i]=new int[c];
		for(int j=0;j<c;j++)m[i][j]=x[i][j];
	}*/
	p=create(r,c);
	for(int i=0;i<r;i++)
	 for(int j=0;j<c;j++)
	  p[i][j]=m[i][j];
	return m;
}
