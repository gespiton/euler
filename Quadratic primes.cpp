/*
Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n² + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/
#include<iostream>
#include<cmath>
#include<utility>
using namespace std;
pair<int,int> test (int a, int b)
{
    int ite=0;
    int counter=0;
    while(1) {
        int buf=ite*ite+a*ite+b;
        if(buf<0)
            return make_pair(counter,a*b);

        int End=sqrt(buf)+1;
        for(int i=2; i<End; ++i) {
            if(buf%i==0) {
                return make_pair(counter,a*b);
            }
        }
        ++counter;
        ++ite;
    }
}
int main()
{
    pair<int,int> Max{0,0};
    for(auto a=-999; a!=1000; ++a) {
        for(auto b=-999; b!=1000; ++b) {
            auto buf=test(a,b);
            if(buf.first>Max.first)
                Max=buf;
        }
    }
//   auto Max=test(-79,1601);
    cout<<Max.first<<"  "<<Max.second;
}
