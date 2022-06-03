#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
#define N 1000000

int * MatchLengthPosition(char * window, char * text)
{
    int *A = (int * )malloc(sizeof(int)*3);
    int flag =0;
    for(int i=0;i<strlen(window);i++)
    {   
        if(strncmp(&window[i],&text[0],strlen(window)-i)==0)
        {
            A[0]=1;
            A[1]=strlen(window)-i-1;
            A[2]= strlen(window)-i;
            flag =1;
            break;
        }
    }
    if(flag==0)
    {
        A[0]=0;
        A[1]=text[0];
    }
    return A;
}

int main()
{
    char window[N];
    char text[N];
    char temp;
    int k=0;
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

    int * A = MatchLengthPosition(window,text);
    
    if(A[0]==0)
        printf("[%d,%c]\n",A[0],A[1]);
    else
    {
        printf("[%d,%d,%d]\n",A[0],A[1],A[2]);
    }
}