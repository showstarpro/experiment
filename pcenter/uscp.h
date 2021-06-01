#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>

using namespace std;

struct node
{
    int w = 0;
    int flag = 0; //是否存在这个点
};

struct set
{
    int chide[5000];
    int length = 0;
    int d = 0;
    int fp = 0;
};

struct sp
{
    int p = 0; //需要确定中心的个数
    int s[500];
    int fx = 0;
};

set s[5000];    //所有的集合
node n[5000];   //所有的顶点
int tube[5000]; //禁忌表
sp pcenter;

clock_t start, finish;
double tm;
int length = 0;  //集合的个数
int nodenum = 0; //顶点的个数

int stringToInt(char a[])
{
    int temp = a[0] - '0';
    int i = 1;
    while (a[i] >= '0' && a[i] <= '9')
    {
        temp = temp * 10 + a[i] - '0';
        i++;
    }
    return temp;
}

int findn(set st, int n) //顶点n是否被集合st覆盖
{
    if (n >= nodenum)
        return -1;
    if (st.fp == 1)
    {
        for (int i = 0; i < st.length; i++)
        {
            if (st.chide[i] == n)
                return i;
        }
    }
    return -1;
}

//计算某个集合的d
void setd(int t)
{
    for (int i = 0; i < s[t].length; i++)
    {
        int tt = 0;
        for (int j = 0; j < pcenter.p; j++)
        {
            if (findn(s[pcenter.s[j]], s[t].chide[i]) == -1)
            {
                tt++;
            }
            else if (t == pcenter.s[j])
            {
                tt++;
            }
        }
        if (tt == pcenter.p)
        {
            s[t].d++;
        }
    }
}


void swap(int i,int j)
{
    
}