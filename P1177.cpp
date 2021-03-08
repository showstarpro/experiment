#include <iostream>
#include<stdio.h>
using namespace std;

int map[100005];

int partion(int a[],int low,int high)
{
    int temp = a[low];
    while(high>low) 
    {
        while(high>low&&a[high]>temp)
            high--;
        a[low] = a[high];
        while(high>low&&a[low]<=temp)
            low++;
        a[high] = a[low];
    }
    a[low] = temp;
    return low;
}

void sort(int a[],int low,int high)
{
    if(low<high)
    {
        int pos = partion(a, low, high);
        sort(a, low, pos - 1);
        sort(a, pos + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n;i++)
    {
        scanf("%d",map+i);
    }

    sort(map, 1, n);

    for (int i = 1; i <n;i++)
    {
        printf("%d ", map[i]);
    }
    printf("%d\n", map[n]);

    return 0;

}