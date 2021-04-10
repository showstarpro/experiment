#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    char map[26];
    int flag[26] = {0};//密文被使用
    int ff[26] = {0};//明文被使用
    char a[4][101];
    int num = 0;
    for (int i = 1; i <= 3;i++)
    {
        scanf("%s", a[i]);
    }

    int length1 = strlen(a[1]);
    int length2 = strlen(a[2]);
    if(length1<26)
    {
        printf("Failed");
        return 0;
    }

    int locate = 0;
    int locate1 = 0;
    for (int i = 0; i < length1;i++)
    {
        locate = a[1][i] - 'A';
        locate1 = a[2][i] - 'A';
        if(flag[locate]==0&&ff[locate1]==0)
        {
            map[locate] = a[2][i];
            flag[locate] = 1;
            ff[locate1] = 1;
            num++;
        }
        else
        {
            flag[locate] = 1;
            if(map[locate]!=a[2][i])
            {
                printf("Failed");
                return 0;
            }
        }
    }
    
    if(num!=26)
    {
        printf("Failed");
        return 0;
    }

    for (int i = 0; i < strlen(a[3]);i++)
    {
        locate = a[3][i] - 'A';
        a[0][i] = map[locate];
        printf("%c", a[0][i]);
    }


        return 0;
}
