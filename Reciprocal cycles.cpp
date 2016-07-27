/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/
///if after a iteration the buff will have the same value with one in left, then ,the cycle appear
#include<string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    FILE* file=fopen("ha","w");
    vector<int> buf;
    vector<int> left;
    int in;
    for(int d=2; d!=1000; ++d) {
        int cycle=0;
        int buff=1;
        buf.clear();
        left.clear();
        do {
            in=int(buff*10/d);
            buf.push_back(in);
            left.push_back(buff);
            buff=buff*10%d;
            if(buff==0) {
                break;
            }
        } while(find(left.begin(),left.end(),buff)==left.end());
//        if(cycle==0)
//            cycle=left.size();
        for(auto i:buf)
            fprintf(file,"%d",i);
        fprintf(file,"    --     %d\n",cycle+1);
    }
}
