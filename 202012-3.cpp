#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <vector>


using namespace std;

struct node
{
    node *child;
    node *bro;
    char name[1000];
    int type;//普通文件还是目录文件,0为目录文件，1位普通文件
    int size;//文件的大小,如果是普通文件，则是自身的大小，如果是目录文件则是他能包含的文件的大小
    long int maxsize;//配额的大小
};

int main()
{
    string s1;
    string s2;
    string s3;
    string s4;
    int n;//指令数量
    long int size = 0;//文件大小

    cin >> n;
    int locate[20] = {-1};
    node *head = (node *)malloc(sizeof(node)); //建立头指针
    head->bro = NULL;
    head->child = NULL;
    strcpy(head->name, "/");
    for (int i = 1; i <= n; i++) //对指令的处理
    {
        cin >> s1;
        if(s1=="C")   //创建文件,并分配内存
        {
            cin >> s2;//输入文件路径
            cin >> size;//输入文件的大小
            int j = 0;
            locate[j] = s2.find("/", 0);
            while(locate[j]!=string::npos)  //确定目录层次
            {
                j++;
                locate[j] = s2.find("/", locate[j - 1]+1);
            }

            char pname[21][100]={};
            for (int k = 0; k < j-1;k++)//获取文件名
            {
                for (int l = locate[k] + 1; l < locate[k + 1];l++)
                {
                    pname[k][l - locate[k] - 1] = s2[l];
                }
            }

            for (int k = locate[j - 1] + 1; k<s2.length();k++)
            {
                pname[j - 1][k - locate[j - 1] - 1] = s2[k];
            }

            node *L = head;
            node *Lbro = L;
            node *fath = head;
            for (int k = 0; k < j-1;k++)
            {
                L = fath->child;
                Lbro = L;
                while(Lbro!=NULL&&strcmp(Lbro->name,pname[k])!=0)//寻找本层目录
                {
                    Lbro = Lbro->bro;
                }

                if(Lbro==NULL)//此目录不存在，则建立
                {
                    node *newbase = (node *)malloc(sizeof(node));
                    newbase->bro = L;
                    fath->child = newbase;
                    newbase->child = NULL;
                    strcpy(newbase->name, pname[k]);
                    newbase->type = 0;
                    Lbro = newbase;
                }
                fath = Lbro;
            }

            if(Lbro->type==0)  //目录文件
            {
                //创建文件，有问题，要检查是否有相同的文件才能新建，否则替换

                //查找是文件是否已经存在
                node *temp = Lbro->child;
                while(temp!=NULL)
                {
                    if(strcmp(temp->name,pname[j-1])==0)
                    {
                        break;
                    }
                    temp = temp->bro;
                }

                if(temp==NULL)
                {
                    node *newbase = (node *)malloc(sizeof(node));//文件
                    newbase->bro = Lbro->child;
                    Lbro->child = newbase;
                    newbase->type = 1;//标志是文件
                    strcpy(newbase->name, pname[j - 1]);
                    newbase->size = size;
                }
                else 
                {
                    temp->size = size;  //进行替换
                }

                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }



        }
        else if(s1=="R")//移除文件
        {
            cin >> s2;//输入文件路径

            int j = 0;
            locate[j] = s2.find("/", 0);
            while(locate[j]!=string::npos)  //确定目录层次
            {
                j++;
                locate[j] = s2.find("/", locate[j - 1]+1);
            }

            char pname[21][100]={};
            for (int k = 0; k < j-1;k++)//获取文件名
            {
                for (int l = locate[k] + 1; l < locate[k + 1];l++)
                {
                    pname[k][l - locate[k] - 1] = s2[l];
                }
            }

            for (int k = locate[j - 1] + 1; k<s2.length();k++)
            {
                pname[j - 1][k - locate[j - 1] - 1] = s2[k];
            }

            node *L = head;
            node *Lbro = L;
            node *fath = head;
            for (int k = 0; k < j-1;k++)
            {
                L = fath->child;
                Lbro = L;
                while(Lbro!=NULL&&strcmp(Lbro->name,pname[k])!=0)//寻找本层目录
                {
                    Lbro = Lbro->bro;
                }

                if(Lbro==NULL)//此目录不存在，则返回YES
                {
                    //printf("NO\n");
                    break;
                }
                fath = Lbro;
            }

            if(Lbro==NULL&&Lbro->type==1)//文件不存在
            {
                printf("YES\n");
            }
            else//移除存在的目录或文件
            {
                node *temp = Lbro->child;

                if(strcmp(temp->name,pname[j-1])==0)//第一个就是要移除的文件和目录
                {
                    Lbro->child = temp->bro;
                    free(temp);
                    printf("YES\n");
                }
                else
                {
                    node *temp1 = temp->bro;
                    while(temp1!=NULL)
                    {
                        if(strcmp(temp1->name,pname[j-1])==0)//查找到了文件
                        {
                            temp->bro = temp1->bro;
                            free(temp1);
                            
                            break;
                        }
                        temp = temp1;
                        temp1 = temp1->bro;
                    }
                    printf("YES\n");
                }
                
            }

        }
        else if(s1=="Q")
        {
            cout << "YES\n";
        }
    }

    return 0;
}