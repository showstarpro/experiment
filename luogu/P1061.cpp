#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int flag = 0;//��־û�и����������
const char num[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


int main()
{
    int s, t, w;
    char word[26];
    char maxn[26];
    char minn[26];
    char temp[26];//��������
    cin >> s >> t >> w;
    cin >> word;




    for (int i = w; i >= 1;i--)
    {
        maxn[i-1] = num[t-1 - (w - i)];//�������
    }

    for (int i = 0; i < w; i++)
    {
       temp[i] = word[i];
    }

    int num = 1;
    while(num<=5)//ִ��5��
    {


    int c = w - 1;

    while(c<w)
    {
        if (temp[c ]+1 <= maxn[c ]) //��cλ
        {
            temp[c]++;
            int i = 0;
            while (temp[i] != temp[c] && i<c)
                i++;//���cλ֮ǰ�Ƿ�ͬ
            if (i == c)//��cλ�����޸�
            {
                for (int j = c+1; j <= w - 1;j++)//cλ֮��
                {
                    temp[j] = temp[c];
                }
                c++;
            }
        }
        else 
        {
            c--;
        }
    }

    for (int a = 0; a < w;a++)
    {
        printf("%c", temp[a]);
    }
    printf("\n");
    num++;

    for (int k = 0; k < w;k++)
    {
        if(temp[k]==maxn[k])
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if(flag==1)
        break;
    }

    return 0;
}