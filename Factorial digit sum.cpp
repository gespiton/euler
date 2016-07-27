#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
void clear ( int* );
void mul ( int*,int  );
using namespace std;
int main ( void )
{
    int n;
    int arr[160];
    int nnn=1;
    memset(arr,0,sizeof arr);
    arr[0]=1;
    int ite=1;
    while(ite++!=100)
    {
        mul(arr,ite);
        clear(arr);
    }
    int* iterator=arr+159;
//skip 0
    while(*iterator--==0);
    ++iterator;
    printf("%d ! =  ",100);
    int sum=0;
    while(iterator>=arr)
    {
        sum+=*iterator;
        --iterator;
    }
    cout<<sum;
    return 0;
}
//mutiple every element in arr with number
void mul ( int*i, int num )
{
    int count = 0;
    while (count++ != 160)
    {
        *(i++) *= num;
    }
}
//go through the array, make sure every element in their position
void clear ( int* i )
{
    int count = 0,buf=0,res;
    while (count++ != 160)
    {
        if ( *i||buf)
        {
            res=buf+*i;
            *i=res%10;
            buf=res/10;
            ++i;
            continue;
        }
        ++i;
    }
}
