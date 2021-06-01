#include<stdio.h>

char x;
long long cur, k, b,opp;

int main()
{
    char s;
    s = getchar();

    bool valueget = false;
    opp = 1;
    k = 0;
    b = 0;
    cur = 0;
    long long value=0;
    int sign = 1;
    while(true)
    {
        if(s>='a'&&s<='z')
        {
            x = s;
            if(cur==0&&valueget==false)
            {
                k = 1;
            }
            else
            {
                k = k + value * opp * sign;
                value = 0;
                sign = 1;
            }
        }

        else if(s>='0'&&s<='9')
        {
            value = value * 10 + s - '0';
        }
        else if(s=='-')
        {
            b = b + value * opp * sign;
            value = 0;
            sign = -1;
        }
        else if(s=='+')
        {
            b = b + value * opp * sign;
            value = 0;
            sign = 1;
        }
        else if(s=='=')
        {
            b = b + value * opp * sign;
            value = 0;
            sign = 1;
            opp = -1;
        }
        else
        {
            b = b + value * opp * sign;
            break;
        }
        cur++;
        s = getchar();
    }

    double ss = (double)k;
    double t = (double)b;
    double ans = (double)(-1 * t / ss);
    if(ans==0)
        ans = 0;

    printf("%c=%0.3f", x, ans);

    return 0;
}