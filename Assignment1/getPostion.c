#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int maximum (int a, int b)
{
    if(a<=b)
        return b;
    return a;
}

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

void getsubstring(char * window,char * InputText , int start , int end)
{
    int j=0;
    for(int i=start;i<end;i++)
        window[j++]=InputText[i];
    window[j]='\0';
}

void ParseSWLZ(char * InputText,int WindowSize)
{
    for(int i=0;i<strlen(InputText);i++)
    {
        char window[WindowSize+1];
        window[0]='\0';
        int start = maximum(0,i-16);
        int end = i;
        getsubstring(window,InputText,start,end);//gives substring from start to end -1
        printf("%s-%d\n",window,strlen(window));
        for(int j=0;j<strlen(window);j++)
        {
            char subwindow[WindowSize+1];
            subwindow[0]='\0';
            start = j;end = i;
            getsubstring(subwindow,window,start,end);
            printf("\t\t>%s-%d\n",subwindow,strlen(subwindow));
        }
        printf("----------------\n");
    }
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
    
    // int* A  = MatchLengthPosition(window,text);
    // if(A[0]==1)
    //     printf("[%d,%d,%d]\n",A[0],A[1],A[2]);
    // else
    //     printf("[%d,%c]\n",A[0],A[1]);
    ParseSWLZ(text,16);
    printf("----------------------------------\n");
    }
}