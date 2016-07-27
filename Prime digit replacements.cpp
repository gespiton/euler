#include<iostream>
#include<stdio.h>
#include<math.h>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class sortt
{
public:
    sortt(int i,int origin):sizz(i),origin(origin)
    {
        go(sizz);
//        for(auto &i:method)
//        {
//            for(auto ii:i)
//                cout<<ii<<"  ";
//            cout<<endl;
//        }
    }
    void print()
    {
        for(auto &i:method)
        {
            for(auto ii:i)
                cout<<ii<<"  ";
            cout<<endl;
        }
    }
    set<vector<int>> & get()
    {
        return method;
    }
private:
    void go(const int num)
    {
        Go(0, {});
    }
    void Go(int ite,vector<int> ve)
    {
        if(ite==sizz)
        {
            sort(ve.begin(),ve.end());
            method.insert(ve);
            return;
        }
        for(int i=0; i!=origin; ++i)
        {
            if(used.find(i)!=used.end())
                continue;
            else
            {
                ve.push_back(i);
                used.insert(i);
                Go(ite+1,ve);
                used.erase(i);
                ve.pop_back();
            }
        }
    }
    set<vector<int>> method;
    int sizz;
    int origin;
    set<int> used;
};
vector<vector<sortt>> Amethod;
set<int> data;
int destney=8;
int trans(int input,vector<int> method,const int des);
void find(set<int>::iterator _begin,set<int>::iterator _end,const int quan);
int main()
{
    vector<sortt>buffer;
    /// amethod start from two digit number
    for(int ite=2; ite<=9; ++ite)
    {
        buffer.clear();
        for(int itee=1; itee!=ite; ++itee)
            buffer.push_back(sortt(itee,ite));
        Amethod.push_back(buffer);
    }
    for(int i=11; i!=5000000; ++i)
    {
        int ite=1;
        const int bound=sqrt(i)+1;
        while(ite!=bound&&(i%ite!=0||ite==1))
            ++ite;
        if(ite==bound)
        {
            data.insert(i);
        }
    }
    int quan=100; ///
    auto _begin=data.begin();  ///
    auto _end=data.lower_bound(quan);  ///
    while(quan!=10000000)
    {
        find(_begin,_end,quan);
        _begin=_end;
        quan*=10;
        _end=data.lower_bound(quan);
    }
}
void find(set<int>::iterator _begin,set<int>::iterator _end,const int quan)
{
    set<int> seen; ///
    // if i see a number before than I should pass ?
    auto methodITE=Amethod[to_string(quan).size()-3].begin();
    auto End=Amethod[to_string(quan).size()-3].end();
    const auto save_begin=_begin;
    int foundCnt=0;
    vector<int> result;
    while(methodITE!=End)
    {
        for(auto &method:methodITE->get())
        {
            _begin=save_begin;
            seen.clear();
            // we change _begin everytime,
            while(_begin!=_end)
            {
                // if already seen before
                result.clear();
                foundCnt=0;
                if(seen.find(*_begin)!=seen.end())
                {
                    ++_begin;
                    continue;
                }
                int i=0;
                if(method.front()==0)
                    i=1;
                for(; i<=9; ++i)
                {

                    int tranED=trans(*_begin,method,i);
                    if(data.find(tranED)!=data.end())
                    {
                        ++foundCnt;
                        seen.insert(tranED);
                        result.push_back(tranED);
                    }
                }
                if(foundCnt==destney)
                {
                    for(auto i:result)
                        cout<<i<<endl;
                    cout<<*_begin<<endl;
                    exit(0);
                }
                ++_begin;
            }
        }
        ++methodITE;
    }
}
int trans(int input,vector<int> method, int des)
{
    string s=to_string(input);
    auto _begin=method.begin();
    auto _end=method.end();
    while(_begin!=_end)
    {
        s[*_begin]=des+'0';
        ++_begin;
    }
    return stoi(s);
}
