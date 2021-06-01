#include <iostream>
#include<stdio.h>
using namespace std;

int map[100005];


void sort(int low,int high)
{
    int mid = map[(low + high) / 2];
    int i = low, j = high;
    do
    {
        while(map[i]<mid)
            i++;
        while(map[j]>mid)
            j++;
        if(i<=j)
        {
            int temp = map[i];
            map[j] = map[i];
            map[i] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if(low<j)
        sort(low, j);
    if(high>i)
        sort(i, high);

}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n;i++)
    {
        scanf("%d",map+i);
    }

    sort( 1, n);

    for (int i = 1; i <n;i++)
    {
        printf("%d ", map[i]);
    }
    printf("%d\n", map[n]);

    return 0;

}