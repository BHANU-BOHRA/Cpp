#include<iostream>
#include<iomanip>
using namespace std;
main()
{
	char names[][10]={"Debbie","Ron","Veronica","Su","Ryan"};
	float comm[]={2050.75,47.25,32709.5,303.6};
	cout<<setprecision(2)<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed);
	for(int i=0;i<4;i++)
	{
		cout<<setiosflags(ios::left)<<setfill('.')<<setw(12)<<names[i];
		cout<<setiosflags(ios::right)<<setfill('*')<<setw(8)<<comm[i]<<endl;
		cout<<resetiosflags(ios::right);
	}
}
