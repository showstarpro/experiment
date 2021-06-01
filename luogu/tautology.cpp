#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool p, q, r, s, t;
bool temp0,temp1;
stack<char> WFF;
stack<int> w;
string st[101];


void check(int &n)
{
    int i = 0;
    while(i<st[n].size())
    {
        WFF.push(st[n][i]);
        i++;
    }
    while(!WFF.empty())
    {
        char temp = WFF.top();
        WFF.pop();
        switch(temp)
        {
            case 112:
                w.push(p);
                break;
            case 113:
                w.push(q);
                break;
            case 114:
                w.push(r);
                break;
            case 115:
                w.push(s);
                break;
            case 116:
                w.push(t);
                break;
            case 65://或运算
                temp0 = w.top();
                w.pop();
                temp1 = w.top();
                w.pop();
                temp0 = temp0 || temp1;
                w.push(temp0);
                break;
            case  75://与运算
                temp0 = w.top();
                w.pop();
                temp1 = w.top();
                w.pop();
                temp0 = temp0 && temp1;
                w.push(temp0);
                break;
            case  78://非运算
                temp0 = w.top();
                w.pop();
                temp0 = !temp0;
                w.push(temp0);
                break;
            case  67://implis
                temp0 = w.top();
                w.pop();
                temp1 = w.top();
                w.pop();
                temp0 = (!temp0) || temp1;
                w.push(temp0);
                break;
            case  69://equel
                temp0 = w.top();
                w.pop();
                temp1 = w.top();
                w.pop();
                if(temp0==temp1)
                    w.push(1);
                    else
                        w.push(0);
                break;
        }
    }
}

int main()
{
    string ss = "0";
    int j = 0;
    getline(cin,st[j]);
    while(st[j]!=ss)
    {
        j++;
         getline(cin,st[j]);
    }
    bool checkl;
    int k = 0;
 start:while(k<100&&st[k]!="0")
    {
            for (int i = 0; i < 32; i++)
            {
                int n = i;
                p = n % 2;
                n = n / 2;
                q = n % 2;
                n = n / 2;
                r = n % 2;
                n = n / 2;
                s = n % 2;
                n = n / 2;
                t = n % 2;
                check(k);
                checkl = w.top();
                w.pop();
                if (!checkl)
                {
                    k++;
                    cout << "not\n";
                    goto start;
                }
            }
            k++;
            cout << "tautology\n";
    }
    return 0;
}