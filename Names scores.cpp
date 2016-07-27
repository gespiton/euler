#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<functional>
using namespace std;
bool comp(const string &lhs,const string &rhs);
string get(istringstream & in);
int calc(const string&,const int );
int main()
{
    unsigned long res=0;
    ifstream inn("name");
    ofstream out("ha");
    string s;
    inn>>s;
    istringstream in(s);
    set<string,function<bool(const string&,const string&)>> store(&comp);
    while(in)
    {
        store.insert(get(in));
    }
    int line=1;
    for(auto &i:store)
    {
        res+=calc(i,line);
 //       out<<i<<endl;
        ++line;
    }
    cout<<res;

}
string get(istringstream & in)
{
    while(true)
    {
        while(in.get()=='\"')
        {
            string result;
            char buf;
            while(true)
            {

                buf=in.get();
                if(buf=='\"')
                {
                    in.get();
                    return result;
                }
                result+=buf;
            }
        }
    }
}
bool comp(const string &lhs,const string &rhs)
{
    int len=min(lhs.size(),rhs.size());
    int ite=0;
    while(ite!=len)
    {
        if(lhs[ite]==rhs[ite])
        {
            ++ite;
            continue;
        }
        else if(lhs[ite]<rhs[ite])
            return true;
        else
            return false;
    }
    if(lhs.size()>rhs.size())
    {
        return false;
    }
    else
        return true;
}
int calc(const string& s,const int line){
    int sum=0;
    for(auto &i:s){
        sum+=i-64;
    }
    return sum*line;
}
