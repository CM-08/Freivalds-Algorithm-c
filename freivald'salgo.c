#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define k 10

void matvecmul(int n,int mat[n][n],int vec[n],int res[n])
{
    for(int i=0;i<n;i++)
    {
        res[i]=0;
        for(int j=0;j<n;j++)
        {
            res[i]+=(mat[i][j]*vec[j]);
        }
    }
}

int isequal(int n,int a[n],int b[n])
{
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            return 0;
        }
    }
    return 1;
}

int algo(int n,int A[n][n],int B[n][n],int C[n][n])
{
    int X[n],BX[n],ABX[n],CX[n];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            X[j]=rand()%2;
        }

        matvecmul(n,B,X,BX);
        matvecmul(n,A,BX,ABX);
        matvecmul(n,C,X,CX);

        if(!isequal(n,ABX,CX))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    int n,i,j;
    scanf("%d",&n);
    int a[n][n],b[n][n],c[n][n];
    printf("Enter matrix A\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter matrix B\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("Enter matrix C\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    if(algo(n,a,b,c))
    {
        printf("AB=C (probably correct)\n");
    }
    else
    {
        printf("AB!=C (definetly incorrect)\n");
    }
    return 0;
}
