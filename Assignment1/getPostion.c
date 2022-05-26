#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int * MatchLengthPosition(char * window, char * text)
{
    int *A = (int * )malloc(sizeof(int)*3);
    int flag =0;
    for(int i=strlen(window)-1;i>=0;i--)
    {   
        for(int j=0;j<strlen(text)-i;j++)//
        {   
            // printf("i=%d j=%d\n",i,j);
            // printf("%s,%s,%d,%d\n",&window[0],&text[j],(i+1),strncmp(&window[0],&text[j],(i+1)));
            if(strncmp(&window[0],&text[j],(i+1))==0)
            {
                A[0]=1;
                A[1]=i;
                A[2]=i+1;
                flag =1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==0)
    {
        A[0]=0;
        A[1]=window[0];
    }
    return A;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {    
    char window[100000];
    char text[100000];
    
    char temp;
    int k=0;
    scanf("%c",&temp);
    while(1)
    {
        scanf("%c",&temp);
        if(temp=='\n')
            break;
        window[k++]=temp;
    }
    window[k]='\0';
    k=0;
    while(1)
    {
        scanf("%c",&temp);
        if(temp=='\n')
            break;
        text[k++]=temp;
    }
    text[k]='\0';

    // printf("%s%s\n",window,text);
    
    int* A  = MatchLengthPosition(window,text);
    if(A[0]==1)
        printf("[%d,%d,%d]\n",A[0],A[1],A[2]);
    else
        printf("[%d,%c]\n",A[0],A[1]);
    }
}