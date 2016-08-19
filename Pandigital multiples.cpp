#include<vector>
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int len(const list<string>& buf);
list<string> isPan(const list<string>& buf)
{

    if(buf.size()==0)
        return buf;
    if(len(buf)!=9)
    {
        auto i =list<string>();
        i.push_back("1");
        return i;
    }
    else
    {
        string final="";
        for_each(buf.begin(),buf.end(),[&](const string s)
        {
            final += s;
        });
        sort(final.begin(),final.end());
        if(unique(final.begin(),final.end())!=final.end())
        {
            auto i =list<string>();
            i.push_back("1");
            return i;
        }
        else
            return buf;
    }
}



int len(const list<string>& buf)
{
    int Len=0;
    for (auto &i :buf)
    {
        Len += i.size();
        if(Len>9)
            return 0;
    }
    return Len;
}



list<string> list_generator(int Max,int i)
{
    int Min = 1;
    list<string> buf;
    while(Min<=Max)
    {

        buf.push_back(to_string(Min*i));
//        cout<<buf.back()<<"   "<<buf.back().size()<<endl;
        ++Min;
        if(len(buf)==0)
            return list<string>();                      /// return the empty list if this i is the max we can proceed, imform the main() that we should try next Max
    }
    return buf;
    if(len(buf)==9)
        return buf;
    else
    {
        auto i = list<string>();
        i.push_back("1");
        return i;
    }
}
string order(list<string>&& buf_r,string final)     /// !!! I make this parameter a rvalue, so that I can simplify the expression when I need to use this function and also/// improve the performance cause this is a rvalue, save soem space for me
{
    if(buf_r.size()==0)
        return final;
    auto Max = buf_r.begin(),ite = buf_r.begin();
    while(ite!=buf_r.end())
    {
        if(*ite>*Max)
            Max = ite;
        ++ite;
    }
    final+=*Max;
    buf_r.erase(Max);
    return order(std::move(buf_r),final);
}
string Max_num ="";
int main()
{
    list<string>result;
    int Max = 9;
    while(Max>1)
    {
        int number=1;
        while(true)
        {
            auto s = order(isPan(list_generator(Max,number)),string());
//            cout<<number<<"   "<<Max<<endl;
            if(s.size()==0)
                break;
            if(s>Max_num)
                result.push_back(s);
            Max_num = s;
            ++number;
        }
        --Max;
        cout<<"max = "<<Max<<endl;
    }
    cout<<endl<<endl;
    for(auto i:result)
        cout<<i<<endl;
}
