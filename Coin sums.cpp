/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<utility>
using namespace std;
int ways=0;
//set<double> duplicate;
set<pair<int,int>> duplicate;
ofstream out("ha");
bool add(int sum,int coins,string s)
{
//    if(duplicate.find(double(sum)/coins)!=duplicate.end())
//        return false;
//    duplicate.insert(double(sum)/coins);
    if(sum>10)
        return true;
    if(duplicate.find({sum,coins})!=duplicate.end())
        return false;
    if(sum==10) {
        ++ways;
        out<<ways<<"   "<<coins<<"  "<<s<<endl;
        duplicate.insert({sum,coins});
        return true;
    } else {
        duplicate.insert({sum,coins});
        if(add(sum+1,coins+1,s+" 1"))
            return false;
        if(add(sum+2,coins+1,s+" 2"))
            return false;
        if(add(sum+5,coins+1,s+" 5"))
            return false;
        if(add(sum+10,coins+1,s+" 10"))
            return false;
        if(add(sum+20,coins+1,s+" 20"))
            return false;
        if(add(sum+50,coins+1,s+" 50"))
            return false;
        if(add(sum+100,coins+1,s+" 100"))
            return false;
        return false;
    }
}
int main()
{
    string s;
    add(1,1,s+" 1");
    cout<<2<<endl;
    add(2,1,s+" 2");
    cout<<5<<endl;
    add(5,1,s+" 5");
    cout<<10<<endl;
    add(10,1,s+" 10");
    cout<<20<<endl;
    add(20,1,s+" 20");
    cout<<50<<endl;
    add(50,1,s+" 50");
    cout<<100<<endl;
    add(100,1,s+" 100");
    add(200,1,s+" 200");
    cout<<ways;
}
