#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

class String
{
  char *str;
 
 public:
  
  String();
  String(const char*);
  String(const String&);

  int    length()const;
  String concat(const String&) const;
  void   reverse();
  int    equals(const String&) const;
  int    equalsIgnoreCase(const String&) const;
  int    compareTo(const String&) const;
  int    compareToIgnoreCase(const String&) const;
  int    indexOf(char,int=0) const;
  int    lastIndexOf(char,int=-1) const;
  void   toUpper();
  void   toLower();
  char   charAt(int) const;
  int    count(char) const;                             //strstr(), strchr()
  int    count(const char*) const;
  char   delCharAt(int);
  int    rmvChar(char);
  int    rmvStr(const char*);
  int    isNumeric() const;
  int    isAlpha() const;
 
  String operator +() const;
  String operator -() const;
  String operator ~() const;
  int    operator !() const;

  String operator +(const char*) const;
  friend String operator +(const char*,const String&);
  String operator +(const String&) const;

  int    operator -(const char*) const;
  friend int operator -(const char*,const String&);
  int    operator -(const String&) const;

  String operator *(int) const;
  friend String operator *(int,const String&);

  int    operator /(const char*) const;
  friend int operator /(const char*,const String&);
  int    operator /(const String&) const;

  String operator %(const char*) const;
  friend String operator %(const char*,const String&);
  String operator %(const String&) const;

  int operator ==(const char*) const;
  friend int operator ==(const char*,const String&);
  int operator ==(const String&) const;
  int operator !=(const char*) const;
  friend int operator !=(const char*,const String&);
  int operator !=(const String&) const;

  int operator >(const char *) const;
  friend operator >(const char *,const String&);
  int operator >(const String&) const;
  int operator >=(const char *) const;
  friend operator >=(const char *,const String&);
  int operator >=(const String&) const;

  int operator <(const char *) const;
  friend operator <(const char *,const String&);
  int operator <(const String&) const;
  int operator <=(const char *) const;
  friend operator <=(const char *,const String&);
  int operator <=(const String&) const;


  friend ostream& operator <<(ostream&,const String &);
  friend istream& operator >>(istream&,String &);
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

String::String(const String &s)
{
 int i;
 str=new char[s.length()+1];
 for(i=0;s.str[i];i++)str[i]=s.str[i];
 str[i]='\0';
}

int String::length()const
{
 int l;
 for(l=0;str[l];l++);
 return l;
}

String String::concat(const String &s) const
{
 int i=0;
 String r;
 r.str==new char[length()+s.length()+1];
 for(i=0;str[i];i++)r.str[i]=str[i];
 for(int j=0;s.str[j];j++,i++)r.str[i]=s.str[j];
 r.str[i]='\0';
 return r;
}

void String::reverse()
{
 for(int i=0,j=length()-1;i<j;i++,j--)
 {
  char tmp=str[i];
  str[i]=str[j];
  str[j]=tmp;
 }
}

int String::equals(const String &s)const
{
 int i,d;
 for(i=d=0;(str[i]||s.str[i])&&d==0;i++)
  d=str[i]-s.str[i];

 return d==0;
}

int String::equalsIgnoreCase(const String &s)const
{
 int i,d;
 for(i=d=0;(str[i]||s.str[i])&&d==0;i++)
 {
  char x,y;
  x=str[i];
  y=s.str[i];
  if(x>='a'&&x<='z') x=x-32;
  if(y>='a'&&y<='z') y=y-32;
  d=x-y;
 }
 return d==0;
}

int String::compareTo(const String &s)const
{
 int i,d;
 for(i=d=0;(str[i]||s.str[i])&&d==0;i++)
  d=str[i]-s.str[i];

 return d;
}

int String::compareToIgnoreCase(const String &s)const
{
 int i,d;
 for(i=d=0;(str[i]||s.str[i])&&d==0;i++)
 {
  char x,y;
  x=str[i];
  y=s.str[i];
  if(x>='a'&&x<='z') x=x-32;
  if(y>='a'&&y<='z') y=y-32;
  d=x-y;
 }
 return d;
}

int String::indexOf(char c,int i)const
{
 while(str[i] && str[i]!=c) i++;
 return str[i]?i:-1;
}

int String::lastIndexOf(char c,int e)const
{
 if(e==-1) e=length()-1;
 
 int i,j=-1;
 for(i=0;i<e;i++)
 {
  if(str[i]==c) j=i;
 }
 return j;
}

void String::toUpper()
{
 for(int i=0;str[i];i++)
  if(str[i]>='a' && str[i]<='z')str[i]-=32;
}

void String::toLower()
{
 for(int i=0;str[i];i++)
  if(str[i]>='A' && str[i]<='Z')str[i]+=32;
}

char String::charAt(int i)const
{
 if(i<length()&&i>=0)
  return str[i];
 throw "index out of bounds..";
}

int String::count(char c)const
{
 int cnt=0;
 for(int i=0;str[i];i++)cnt+=(str[i]==c);
 return cnt;
}

int String::count(const char *s) const
{
 int cnt=0,l=strlen(s);
 char *p=strstr(str,s);
 while(p)
 {
  cnt++;
  p=strstr(p+l,s);
 }
 return cnt; 
}

char String::delCharAt(int i)
{
 if(i<0||i>length()) throw "index out of bounds..";

 char c=str[i++];
 while(str[i]) str[i-1]=str[i++];
 str[i-1]='\0';
 return c;
}

int String::rmvChar(char c)
{
 char *p=strchr(str,c);

 if(!p)return 0;
 
 for(p++;*p;p++) *(p-1)=*p;
 
 *(p-1)='\0';
 return 1;
}

int String::rmvStr(const char *s)
{
 char *p=strstr(str,s);

 if(!p)return 0;

 char *q=p+strlen(s);
 while(*q)
  *p++=*q++;
 *p='\0';
 return 1;
}

int String::isNumeric()const
{
 for(int i=0;str[i];i++)
  if(str[i]<'0'||str[i]>'9')return 0;
 return 1;
}

int String::isAlpha()const
{
 for(int i=0;str[i];i++)
  if(!(str[i]>='A'&&str[i]<='Z' || str[i]>='a'&&str[i]<='z'))return 0;
 return 1;
}

String String::operator +() const
{
 String r=str;
 r.toUpper();
 return r;
}

String String::operator -() const
{
 String r=str;
 r.toLower();
 return r;
}

String String::operator ~() const
{
 String r=str;
 r.reverse();
 return r;
}

int String::operator !() const
{
 return !*str;
}

String String::operator +(const char *s) const
{
 String r=strcat(str,s);
 return r;
}

String operator +(const char *p,const String &s)
{
 String r=p;
 strcat(r.str,s.str);
 return r;
}

String String::operator +(const String &s) const
{
 return concat(s);
}

int String::operator -(const char *s) const
{
 int i,d;
 for(i=d=0;(str[i]||s[i])&&d==0;i++)
  d=str[i]-s[i];
 return d;  
}

int operator -(const char *p,const String &s)
{
 int i,d;
 for(i=d=0;(p[i]||s.str[i])&&d==0;i++)
  d=p[i]-s.str[i];
 return d; 
}

int String::operator -(const String &s) const
{
 int i,d;
 for(i=d=0;(str[i]||s.str[i])&&d==0;i++)
  d=str[i]-s.str[i];
 return d; 
}

String String::operator *(int i) const
{
 if(i<0)
  throw "can't Multiply String with Negative  Number..";

 String r;
 while(i--)
  r=r.concat(*this);

 return r;
}

String operator *(int i,const String &s)
{
 if(i<0)
   throw "can't Multiply String with Negative  Number..";

 String r;
 while(i--)
  r=r.concat(s);

 return r;
}

int String::operator /(const char *s) const
{
 int n=0;
 int l=strlen(s);
 char *p=strstr(str,s);
 while(p)
 {
  n++;
  p=strstr(p+l,s);
 }
 return n;
}

int operator /(const char *s,const String &o)
{
 int n=0;
 int l=strlen(o.str);
 char *p=strstr(s,o.str);
 while(p)
 {
  n++;
  p=strstr(p+l,o.str);
 }
 return n;
}

int String::operator /(const String &s) const
{
 int n=0;
 int l=strlen(s.str);
 char *p=strstr(str,s.str);
 while(p)
 {
  n++;
  p=strstr(p+l,s.str);
 }
 return n;
}

String String::operator %(const char *s) const
{
 int l=strlen(s);
 char *tmp=new char[strlen(str)+1];
 *tmp='\0';
 char *q=str;
 char *p=strstr(str,s);
 while(p)
 {
  strncat(tmp,q,p-q);
  q=p+l;
  p=strstr(q,s);
 }
 strcat(tmp,q);
 return String(tmp);
}

String operator %(const char *s,const String &o)
{
 int l=strlen(o.str);
 char *tmp=new char[strlen(s)+1];
 *tmp='\0';
 char *q=o.str;
 char *p=strstr(s,o.str);
 while(p)
 {
  strncat(tmp,q,p-q);
  q=p+l;
  p=strstr(q,o.str);
 }
 strcat(tmp,q);
 return String(tmp);
}

String String::operator %(const String &s) const
{
 int l=strlen(s.str);
 char *tmp=new char[strlen(str)+1];
 *tmp='\0';
 char *q=str;
 char *p=strstr(str,s.str);
 while(p)
 {
  strncat(tmp,q,p-q);
  q=p+l;
  p=strstr(q,s.str);
 }
 strcat(tmp,q);
 return String(tmp);
}

int String::operator ==(const char *s) const
{
 return !strcmp(str,s);
}

int operator ==(const char *p,const String &s)
{
 return !strcmp(p,s.str);
}

int String::operator ==(const String &s) const
{
 return equals(s);
}

int String::operator !=(const char *s) const
{
 return !(*this==s);
}

int operator !=(const char *p,const String &s)
{
 return !(p==s);
}

int String::operator !=(const String &s) const
{
 return !equals(s);
}

int String::operator >(const char *s) const
{
 return strcmp(str,s)>0?1:0;
}

int operator >(const char *p,const String &s)
{
 return strcmp(p,s.str)>0?1:0;
}

int String::operator >(const String &s) const
{
 return compareTo(s)>0?1:0;
}

int String::operator >=(const char *s) const
{
 return strcmp(str,s)<0?0:1;
}

int operator >=(const char *p,const String &s)
{
 return strcmp(p,s.str)<0?0:1;
}

int String::operator >=(const String &s) const
{
 return compareTo(s)<0?0:1;
}

int String::operator <(const char *s) const
{
 return strcmp(str,s)<0?1:0;
}

int operator <(const char *p,const String &s)
{
 return strcmp(p,s.str)<0?1:0;
}

int String::operator <(const String &s) const
{
 return compareTo(s)<0?1:0;
}

int String::operator <=(const char *s) const
{
 return strcmp(str,s)>0?0:1;
}

int operator <=(const char *p,const String &s)
{
 return strcmp(p,s.str)>0?0:1;
}

int String::operator <=(const String &s) const
{
 return compareTo(s)>0?0:1;
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
/*

 y=-x
 y=+x
 y=~x
 !x
  
 z=x+" "
 z=" "+x
 z=x+y

 d=x-" "
 d=" "-x
 d=x-y

 y=x*3
 y=3*x
 
 q=x/" "
 q=" "/x
 q=x/y

 r=x%" "
 r=" "%x
 r=x%y

 x==" "
 " "==x
 x==y
 
 !=

 >
 <
 >=
 <=

 cin>>x
 cout<<x
*/
main()
{
 String x=("abcdmickeyefmickeymickeyghijklmickeymnopqrstmickeyuvwxyzmickey");
 String y=x%"mickey";

 cout<<"\n"<<y<<"\n";
}
