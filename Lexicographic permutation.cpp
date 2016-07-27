#include<iostream>
#include<vector>
#include<set>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;
set<int>used;
set<long> result;
vector<int> ve;
FILE* file=fopen("ha","w");
void calc()
{
    if(used.size()==10)
    {
        string buf;
        for_each(ve.begin(),ve.end(),[&](const int &r)
        {
            buf+=r+'0';
        });
        result.insert(stol(buf));
    }
    else
    {
        for(int i=0; i!=10; ++i)
        {
            if(used.find(i)!=used.end())
                continue;
            else
            {
                used.insert(i);
                ve.push_back(i);
                calc();
                ve.pop_back();
                used.erase(i);
            }
        }
    }
}
int main()
{
    calc();
    for(auto i:result)
    {
        fprintf(file,"%ld\n",i);
    }
}

