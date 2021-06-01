#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

struct vertice
{
    int id=-1;
    int w = 1;
    vector<int> c;
    int flag = 0;//标志被几个P覆盖
};

struct client
{
    int id;
    int dt=0;
    vector<int> v;
    int size = 0;
};

struct tube{
    int i=-1;
    int j=-1;
};

void initP();//对解进行初始化
void sumdt();//计算集合的dt
bool cmp(client a,client b);
bool isInP(client a);//判断集合a是否在P中
int findPair(int x);
void initU();
void tryToOpen(int i);

vertice V[5000];//顶点
client C[5000];//集合
vertice U[5000];//没有被覆盖的顶点
client P[5000];//代求解的集合
vector<tube> T;

int vnum = 0;//顶点的个数
int cnum = 0;//集合的个数
int pnum = 0;//要挑选的集合的个数
int unum = 0;//没有被覆盖的顶点的个数
int fx = 0;//整个方案的权重

int seed;
int tlimit;
double cosT;

clock_t start, finish;



int main(int argc, char *args[])
{
    start = clock();

    if (argc != 5)
    {
        printf("error!\n");
        return 0;
    }
    FILE *fs = freopen(args[1], "rb",stdin);
    FILE *ft = freopen(args[2], "wb+",stdout);
    tlimit = atoi(args[3]);
    seed = atoi(args[4]);
    srand(seed);

    if (!fs)
        return -1;

    int temp = 0;

    scanf("%d", &cnum);
    scanf("%d", &pnum);
    for (int i = 0; i < cnum; i++)
    {
        scanf("%d", C[i].size);
        C[i].id = i;
        for (int j = 0; j < C[i].size; j++)
        {
            scanf("%d", &temp);
            V[temp].c.push_back(i);
            if(V[temp].id==-1)
                V[temp].id = temp;
            C[i].v.push_back(temp);
            vnum = max(temp, vnum);
        }
    }
    fclose(fs);

    initP();
    sumdt();

    while (1)
    {
        finish = clock();
        cosT = (double)(finish - start) / CLOCKS_PER_SEC;
        if (cosT > tlimit)
            break;


    }

    finish=clock();
    cosT=(double) (finish-start)/ CLOCKS_PER_SEC;
    
    printf("%f",cosT);

    fclose(ft);
    return 0;
}








void initP()
{


}

void sumdt()
{
    for (int i = 0; i < cnum;i++)
    {
        if(isInP(C[i]))
        {
            for (int j = 0; j < C[i].size;j++)
            {
                if(V[C[i].v[j]].flag==1)
                    C[i].dt = +V[C[i].v[j]].w;
            }
        }
        else{
            for (int j = 0; j < C[i].size;j++)
            {
                if(V[C[i].v[j]].flag==0)
                    C[i].dt = +V[C[i].v[j]].w;
            }
        }
    }
}

bool cmp(client a,client b)
{
    if(a.size!=b.size)
        return a.size > b.size;
    else
        return a.id > b.id;
}


bool isInP(client a)
{
    for (int i = 0; i < pnum;i++)
    {
        if(P[i].id==a.id)
            return true;
    }
    return false;
}


int findPair(int x)
{

}

void initU()
{
    for (int i = 0; i < vnum; i++)
    {
        if (V[i].flag == 0)
        {
            U[unum] = V[i];
            unum++;
        }
    }
}


void tryToOpen(int i)
{
    for (int s = 0; s < C[i].size;s++)
    {
        int pcnum=0;
        for (int t = 0; t < V[C[i].v[s]].c.size();t++)
        {
            if(isInP(C[V[C[i].v[s]].c[t]]))
                pcnum++;
        }
        if(pcnum==1)
        {
            
        }
    }
}