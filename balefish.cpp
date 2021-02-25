#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include<cstdio>
#include<string.h>
#include<map>
using namespace std;
map<string,string> mp;
int main()
{
	char a[100],b[100],c[100];
	while(gets(a)&&a[0]!='\0')
	{
		sscanf(a,"%s %s",b,c);
		mp[c]=b;
	}
	while(gets(a))
	{
		if(mp.find(a)!=mp.end())
		{
			cout<<mp[a]<<endl;
		}
		else cout<<"eh"<<endl;
	}
}