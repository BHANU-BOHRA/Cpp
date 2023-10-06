#include<iostream>
using namespace std;

class Vector
{
	int *items;
	int size,capacity;
	public :
		Vector();
		void add(int);
		void clear();
		void extend(const Vector&);//array add
		int indexOf(int,int)const;
		int lastIndexOf(int,int)const;
		int count(int)const;
		int get(int)const;
		int length()const;
		int pop();
		int remove(int);
		int removeItem(int);
};
Vector::Vector()
{
	capacity=10;
	size=0;
	items=new int[capacity];
}
void Vector::add(int n)
{
	if(size==capacity)
	{
		capacity+=10;
		int *tmp=new int[capacity];
		for(int i=0;i<size;i++)
			tmp[i]=items[i];
		delete items;
		items=tmp;
	}
	items[size++]=n;
}
void Vector::clear()
{
	delete items;
	size=capacity=0;
}
void Vector::extend(const Vector &v)
{
	if(capacity-size<v.size)
	{
		int d=v.size-(capacity-size);
		int n=d/10;
		if(n*10<d)n++;
		capacity=capacity+n*10;
		int *tmp=items;
		items=new int[capacity];
		for(int i=0;i<size;i++)
			items[i]=tmp[i];
		delete tmp;
	}
	for(int i=0;i<v.size;i++,size++)
		items[size]=v.items[i];
}
int Vector::indexOf(int n,int i=0)const
{
	while(i<size&&items[i]!=n)i++;
	if(i<size)return i;
	return -1;
}
int Vector::lastIndexOf(int n,int i=-1)const//Never iterate array in reverse i.e. Backwards (it may cause Problems)
{
	if(i==-1)i=size;
	int j,k=-1;
	for(j=0;j<size&&j<i;j++)
		if(items[j]==n)k=j;
	return k;
}
int Vector::count(int n)const
{
	int cnt=0;
	for(int i=0;i<=size;i++)
		cnt+=items[i]==n;
	return cnt;
}
int Vector::get(int i)const
{
	if(i>=size)
		throw "Index of out of Bounds..";
	return items[i];
}
int Vector::length()const
{
	return size;
}
int Vector::pop()
{
	if(size)
		return items[--size];
	throw "Vector is Empty";
}
int Vector::remove(int i)
{
	if(i>=size)throw "Index out of Bounds..";
	int n=items[i++];
	while(i<size)
	{
		items[i-1]=items[i];
		i++;
	}
	size--;
	return n;
}
int Vector::removeItem(int n)
{
	int i;
	for(int i=0;i<size&&items[i]!=n;i++);
	if(i<size)
	{
		for(i++;i<size;i++)
			items[i-1]=items[i];
		size--;
		return 1;
	}
	return 0;
}
main()
{
	int i,n;
	Vector v,a;
	v.add(1);
	v.add(2);
	v.add(3);
	v.add(4);
	v.add(5);
	v.add(6);
	for(i=0;i<v.length();i++)
		printf("%d ",v.get(i));
	printf("\n\n");
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	a.add(6);
	for(i=0;i<a.length();i++)
		printf("%d ",a.get(i));
	printf("\n\n");
	v.extend(a);
	for(i=0;i<v.length();i++)
		printf("%d ",v.get(i));
	printf("\n\n");
	printf("%d",v.indexOf(6));
	printf("\n\n%d",v.lastIndexOf(5,5));
	printf("\n\n%d",v.count(5));
	try
	{
		n=v.get(7);
	}
	catch(const char *s)
	{
		cerr<<"\nalert - "<<s;
		n=0;
	}
}
