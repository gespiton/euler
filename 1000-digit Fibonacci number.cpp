/*
The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<vector>
using namespace std;
class data;
data operator+(const data&lhs,const data&rhs);
class data
{
public:
    data(int i)
    {
        out.open("ha",ios_base::app);
        ve.push_back(i);
    }
    data(vector<int>&v):ve(v)
    {
        out.open("ha",ios_base::app);
    }
    data(const data&rhs):ve(rhs.ve)
    {
        out.open("ha",ios_base::app);
    }
    data& operator=(const data&rhs)
    {
        ve=rhs.ve;
    }

    friend data operator+(const data&lhs,const data&rhs);
    void print()
    {
        for(auto End=ve.end()-1; End>=ve.begin(); --End)
            out<<*End;
        out<<"  "<<ve.size();
        out<<endl;
    }
    size_t size()
    {
        return ve.size();
    }
private:
    vector<int> ve;
    ofstream out;
};
int main()
{
    data arr[3]= {{0},{0},{1}};
    int ite=2;
    while(1) {
        arr[ite%3].print();
        arr[(ite+1)%3]=arr[(ite-1)%3]+arr[ite%3];
        if(arr[ite%3].size()==1000) {
            return 0;
        }
        ++ite;
    }
}
data operator+(const data&lhs,const data&rhs)
{
    vector<int> New;
    const int LMax=lhs.ve.size();
    const int RMax=rhs.ve.size();
    bool advance=0;
    const    vector<int>& lhsV=lhs.ve;
    const vector<int>& rhsV=rhs.ve;
    int ite;
    int buf;
    for(ite=0; ite!=RMax; ++ite) {
        if(ite>=LMax) {
            buf=rhsV[ite];
        } else {
            buf=lhsV[ite]+rhsV[ite];
        }
        if(advance) {
            ++buf;
            advance=0;
        }
        if(buf>9) {
            advance=true;
            buf%=10;
        }
        New.push_back(buf);
    }
    if(advance)
        New.push_back(1);
    return data(New);
}
