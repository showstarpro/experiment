#include <stdio.h>
#include <math.h>


int n;
int prices[10002];
int a[10002];


void init()
{
    for(int k=1;k<=n;k++)
    {
      a[k]=prices[k]-prices[1];
    }
  
}

int find(int i,int j)
{
  	
	int mid=(i+j)/2;
    if(mid==i)
      return 0;
    int ans=0;
	int low=(i+j)/2;
  	int high=(i+j)/2+1;
        
  	int li=find(i,low);
  	int ri=find(high,j);
  	
  	if(li>=ri) ans=li;
  	else ans=ri;
  	
      int temp=0;
    

      while (low >= i && high <= j)
      {
          if (temp < a[high]-a[low-1])
          {
              temp = a[high]-a[low-1];
              low--;
          }
           else if (temp < a[high+1]-a[low])
          {
              temp = a[high+1]-a[low];
              high++;
          }
         else 
         {
             low--;
             high++;
         }
    }  
      
    return std::max(temp,ans);

}

int main()
{
  scanf("%d",&n);
      for(int k=1;k<=n;k++)
    {
      scanf("%d",&prices[k]);
    }
  
  init();
      
  int value=find(0,n);
  
  printf("%d",value>0?value:0);
          return 0;

           
}





// #include <stdio.h>

// int n;
// int prices[10002];
// int a[10002];


// void init()
// {
//     for(int k=1;k<=n;k++£©
//     {
//       a[k]=princes[k]-prices[1];
//     }
  
// }

// int find(int i,int j)
// {
  	
// 	int mid=(i+j)/2;
//     if(mid==i)
//       return a[mid];
    
// 	int low=(i+j)/2;
//   	int high=(i+j)/2+1;
        
//   	int li=find(i,low);
//   	int ri=find(high,j);
//   	int ans=0;
      
// 	if((li+ri)>=li&&(li+ri)>ri) ans=li+ri;
//     else if(li>ri) ans=li;
//       else ans=ri;
  	
//       int temp=0;
      
//       while (low >= i && high <= j)
//       {
//           if (temp < a[high]-a[low-1])
//           {
//               temp = a[high]-a[low-1];
//               low--;
//           }
//            else if (temp < a[high+1]-a[low])
//           {
//               temp = a[high+1]-a[low];
//               high++;
//           }
//          else 
//          {
//              low--;
//              high++;
//          }
//     }  
      
//     return max(temp,ans);

// }

// int main()
// {
//   scanf("%d",&n);
//       for(int k=1;k<=n;k++£©
//     {
//       scanf("%d",&princes[k]);
//     }
  
//   init();
      
//   int value=find(0,n);
  
//   printf("%d",value>0?value:0);
//           return 0;
          
            
// } 