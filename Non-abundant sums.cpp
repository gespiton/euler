#include<iostream>
#include<fstream>
#include<set>
#include<stdio.h>
using namespace std;

int main()
{
    //  FILE* out=fopen("ha","w");
    set<int> abun;
    int sum=0;
    for(int i=1; i<=28123; ++i)
    {
        sum=0;
        for(int ite=1; ite!=i; ++ite)
        {
            if(i%ite==0)
            {
                sum+=ite;
            }
        }
        if(sum>i)
        {
            abun.insert(i);
//            fprintf(out,"%d\n",i);
        }
    }
    sum=0;
    for(int i=1; i<=12; ++i)
        sum+=i;
    for(int i=13; i<=28123; ++i)
    {
        auto beg=abun.begin();
        auto en=abun.lower_bound(i);
        while(beg!=en)
        {
            if(abun.find(i-*beg)!=abun.end())
            {
                break;
            }
            ++beg;
        }
        if(beg==en)
            sum+=i;

    }
    cout<<sum;
}
