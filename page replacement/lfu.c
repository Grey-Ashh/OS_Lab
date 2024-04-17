#include<stdio.h> 
#include<conio.h> 
#include<math.h> 
void main() 
{ 
int i,k,l,lc,bf,bn=0,c=0,flag=0,n,st[10],b[10],r[10]; 
clrscr(); 
for(i=0;i<10;i++) 
{ 
st[i]=0;
b[i]=0;
r[i]=0;
 } 
printf("enter the no. of blocks\n");
 scanf("%d",&bf);
  printf("\n enter the length of page sequence: ");
   scanf("%d",&n); printf("\n enter the page sequence: ");
    for(i=0;i<n;i++)
     scanf("%d",&st[i]);
      for(i=0;i<n;i++) 
      printf(" %d",st[i]);
       for(i=0;i<n;i++)
        { 
        flag=0; 
        printf("\n i= %d ",st[i]); 
        for(k=0;k<bn;k++) 
        if(st[i]==b[k]) 
        { 
        r[k]=r[k]+1;flag=1;
        break; 
        } 
        if(flag==0) 
        { 
        if(bn<bf) 
        { 
        b[bn]=st[i]; 
        r[bn]=r[bn]+1;
         bn++;
          } 
          else
           {
            l=n;
             for(k=0;k<bf;k++)
              if(r[k]<l)
               {
                l=r[k];
                 lc=k;
                  }
                   b[lc]=st[i];
                    c=0;
                     for(k=0;k<=i;k++) 
                     if(st[i]==st[k]) 
                     c=c+1;
                      r[lc]=c;
                       }
                        } 
                        printf("\n");
                         for (k=0;k<bf;k++)
                          printf(" %d",b[k]);
                           } 
                           getch();
                            }
