#include <stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
   int id;
   int chinese;
   int math;
   int english;
   int score;
};

bool cmp(node a,node b)
{
   if(a.score!=b.score)
      return a.score > b.score;
   else if(a.chinese != b.chinese)
      return a.chinese > b.chinese;
   else
      return a.id < b.id;
}

node student[302]; 


int main()
{
   int n;
   cin >> n;
   for (int i = 1; i <= n;i++)
   {
      cin >> student[i].chinese >> student[i].math >> student[i].english;
      student[i].id = i;
      student[i].score = student[i].chinese + student[i].math + student[i].english;
   }
   sort(student + 1, student + n+1, cmp);

   if(n<5)  
   {
   for (int i = 1; i <= n;i++)
   {
      cout << student[i].id << " " << student[i].score<<"\n";
   }
   }
   for (int i = 1; i <= 5;i++)
   {
      cout << student[i].id << " " << student[i].score<<"\n";
   }
      return 0;
}