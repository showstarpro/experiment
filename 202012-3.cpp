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
    int type;//��ͨ�ļ�����Ŀ¼�ļ�,0ΪĿ¼�ļ���1λ��ͨ�ļ�
    int size;//�ļ��Ĵ�С,�������ͨ�ļ�����������Ĵ�С�������Ŀ¼�ļ��������ܰ������ļ��Ĵ�С
    long int maxsize;//���Ĵ�С
};

int main()
{
    string s1;
    string s2;
    string s3;
    string s4;
    int n;//ָ������
    long int size = 0;//�ļ���С

    cin >> n;
    int locate[20] = {-1};
    node *head = (node *)malloc(sizeof(node)); //����ͷָ��
    head->bro = NULL;
    head->child = NULL;
    strcpy(head->name, "/");
    for (int i = 1; i <= n; i++) //��ָ��Ĵ���
    {
        cin >> s1;
        if(s1=="C")   //�����ļ�,�������ڴ�
        {
            cin >> s2;//�����ļ�·��
            cin >> size;//�����ļ��Ĵ�С
            int j = 0;
            locate[j] = s2.find("/", 0);
            while(locate[j]!=string::npos)  //ȷ��Ŀ¼���
            {
                j++;
                locate[j] = s2.find("/", locate[j - 1]+1);
            }

            char pname[21][100]={};
            for (int k = 0; k < j-1;k++)//��ȡ�ļ���
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
                while(Lbro!=NULL&&strcmp(Lbro->name,pname[k])!=0)//Ѱ�ұ���Ŀ¼
                {
                    Lbro = Lbro->bro;
                }

                if(Lbro==NULL)//��Ŀ¼�����ڣ�����
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

            if(Lbro->type==0)  //Ŀ¼�ļ�
            {
                //�����ļ��������⣬Ҫ����Ƿ�����ͬ���ļ������½��������滻

                //�������ļ��Ƿ��Ѿ�����
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
                    node *newbase = (node *)malloc(sizeof(node));//�ļ�
                    newbase->bro = Lbro->child;
                    Lbro->child = newbase;
                    newbase->type = 1;//��־���ļ�
                    strcpy(newbase->name, pname[j - 1]);
                    newbase->size = size;
                }
                else 
                {
                    temp->size = size;  //�����滻
                }

                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }



        }
        else if(s1=="R")//�Ƴ��ļ�
        {
            cin >> s2;//�����ļ�·��

            int j = 0;
            locate[j] = s2.find("/", 0);
            while(locate[j]!=string::npos)  //ȷ��Ŀ¼���
            {
                j++;
                locate[j] = s2.find("/", locate[j - 1]+1);
            }

            char pname[21][100]={};
            for (int k = 0; k < j-1;k++)//��ȡ�ļ���
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
                while(Lbro!=NULL&&strcmp(Lbro->name,pname[k])!=0)//Ѱ�ұ���Ŀ¼
                {
                    Lbro = Lbro->bro;
                }

                if(Lbro==NULL)//��Ŀ¼�����ڣ��򷵻�YES
                {
                    //printf("NO\n");
                    break;
                }
                fath = Lbro;
            }

            if(Lbro==NULL&&Lbro->type==1)//�ļ�������
            {
                printf("YES\n");
            }
            else//�Ƴ����ڵ�Ŀ¼���ļ�
            {
                node *temp = Lbro->child;

                if(strcmp(temp->name,pname[j-1])==0)//��һ������Ҫ�Ƴ����ļ���Ŀ¼
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
                        if(strcmp(temp1->name,pname[j-1])==0)//���ҵ����ļ�
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