#include <stdio.h>

int a[3000];
int a1 = 0, a0 = 0;
int los = 0;

void qs(int x) //������
{
    los = 0;
    for (int i = 1; i < x;i++)
    {
        if((x % i)==0)
        {
            a[los] = i;
            los++;
        }
    }
}





int main()
{
    scanf("%d%d", &a0,&a1);

    qs(a0);

    int xa = 0;

    for (int i = 0; i < los;i++) //����x��a0���п��ܵĹ�Լ��
    {
        if(a[i]==a0)
            xa = i;
    }



        return 0;
}