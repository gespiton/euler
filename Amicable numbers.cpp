#include<iostream>
#include<set>
#include<fstream>
using namespace std;
int sum(int);
set<int> seem;
int main()
{
    ofstream out("ha");
    int total=0;
    int buf=0;
    int first=0;
    for(int ite=1; ite!=10000; ++ite)
    {
        if(seem.find(ite)!=seem.end())
            continue;
        first=sum(ite);
        buf=sum(first);
            if(buf==ite&&ite!=first)
        {
            out<<ite<<"  "<<first<<endl;
            total+=first+ite;
            seem.insert(first);
        }
    }
    cout<<total;
}
    int sum(int scr)
    {
        int sum=0;
        for(int i=1; i!=scr; ++i)
        {
            if(scr%i==0)
                sum+=i;
        }
        return sum;
    }
