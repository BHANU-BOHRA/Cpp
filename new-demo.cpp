#include<iostream>
using namespace std;
main()
{
	int *p,n,i;
	cout<<"\nEnter the Number of Items : ";
	cin>>n;
	p=new int[n];
	cout<<"\nEnter the Values :-\n\n";
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter Item "<<i+1<<" : ";
		cin>>p[i];
	}
	cout<<"\nEntered Collection is :-\n\n";
	for(i=0;i<n;i++)cout<<p[i]<<" ";
	cout<<"\n";
	delete p;
}
