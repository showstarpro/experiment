#include <stdio.h>
#include <iostream>

#define   N   50000 

int main()
{
    int a;
    int b;
    int na[N];
    int nb[N];
    scanf("%d", &a);
    for (int i = 0; i < a;i++)
    {
        scanf("%d", na + i);
    }

    scanf("%d", &b);
    for (int i = 0; i < b;i++)
    {
        scanf("%d", nb+i);
    }

    for (int i = 0; i < b;i++)
    {
        int j = a+1;
        int k = 0;
        int r = j / 2+1;
        int temp = 10000 - nb[i];
        while(j!=k+1)
        {
            if(temp==na[r-1])
            {
                printf("YES");
                return 0;
            }
            else if(temp<na[r-1])
            {
                j = r;
                if((k+j)%2==1)
                    r = (k + j) / 2 + 1;
                else r = (k + j) / 2;
            }
            else{
                k = r;
                if((k+j)%2==1)
                    r = (k + j) / 2 + 1;
                else r = (k + j) / 2;
            }
        }
    }
    printf("NO");
    return 0;
}