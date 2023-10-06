#include<iostream>
using namespace std;
main()
{
	int n;
	cout<<"\nEnter the Number of Integers to input : ";
	cin>>n;
	int *arr=new int[n];
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Item "<<i+1<<" : ";
		cin>>arr[i];
	}
	cout<<"\nItems in the List : ";
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	cout<<"\n\n";
}
