#include<iostream>
#include<iomanip>
using namespace std;
main()
{
	int r,c;
	cout<<"\nEnter the Number of Rows for the Matrix : ";
	cin>>r;
	cout<<"\nEnter the Number of Cols for the Matrix : ";
	cin>>c;
	int **m;
	m=new int*[r];
	for(int i=0;i<r;i++)m[i]=new int[c];
	cout<<"\n\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Item["<<i<<"]["<<j<<"] : ";
			cin>>m[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)cout<<setw(3)<<m[i][j]<<" ";
		cout<<"\n";
	}
	for(int i=0;i<r;i++)delete m[i];
	delete m;
}
