#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
#define N 1000000

int maximum (int a, int b)
{
    if(a<=b)
        return b;
    return a;
}

int * MLP(char * window, char * text)
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

int * MatchLengthPosition(char * window,char * InputText)
{
        // printf("%s-%d ",window,strlen(window));
        // printf("%s-%d ",InputText,strlen(InputText));
        int *A;
        int max =-1;
        // int min_position=2147483647;
        int flag =0;
        int WindowSize = strlen(window);
        for(int j=0;j<strlen(window);j++)
        {
            char subwindow[WindowSize+1];
            subwindow[0]='\0';
            getsubstring(subwindow,window,0,(j+1));
            
            // printf("\t\t>%s-%d\n",subwindow,strlen(subwindow));
            
            int * A_temp=MLP(subwindow,InputText);
            if(A_temp[0]==1)
            {
                A_temp[1]=A_temp[1] +strlen(window)-strlen(subwindow) ;
                // if(A_temp[1]<0)
                //     printf("%s_%d %s_%d\n",window,strlen(window),subwindow,strlen(subwindow));

                // printf("\t\t\t>[%d,%d,%d]\n",A_temp[0],A_temp[1],A_temp[2]);
                
                if(A_temp[2]>=max)
                {
                    // printf("\t\t\t\t>A is changed\n");
                    A=A_temp;
                    max = A_temp[2];
                }
                flag =1;
            }
        }
        if(flag==0)
        {
            A=(int*)malloc(sizeof(int*)*2);
            A[0]=0;
            A[1]=InputText[0];
        }
        return A;
}

int main()
{
    int t;
    scanf("%d",&t);
    char temp;
    scanf("%c",&temp);
    while(t--)
    {
        char window[N];
        char text[N];
        // char temp;
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
        printf("%s-%d   (Text)\n%s-%d   (window)\n",text,strlen(text),window,strlen(window));
        if(A[0]==0)
            printf("\t\t> [%d,%c]\n\n",A[0],A[1]);
        else
        {
            printf("\t\t> [%d,%d,%d]\n\n",A[0],A[1],A[2]);
        }
        printf("-------------------------------------------------------------------\n");
    }
}