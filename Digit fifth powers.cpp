/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 14 + 64 + 34 + 44
    8208 = 84 + 24 + 04 + 84
    9474 = 94 + 44 + 74 + 44

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    int total=0;
    for(int ite=10;ite!=10000000;++ite){
        int sum=0;
        int iteb=ite;
        while(iteb){
            sum+=pow(iteb%10,5);
            iteb/=10;
        }
        if(ite==sum){
            cout<<ite<<endl;
            total+=ite;
        }
    }
    cout<<total;
}
//Actually you can. The maximum value for one digit is 9^5 = 59049.
//We can find out the maximum possible sum for a given number of digits by multiplying 59049 with the number of digits.
//Let's say we're gonna check the number 123456789. That's 9 digits, so the maximum sum would be 9*59049 = 531441,
//which doesn't even come close to 123456789. So we know we can forget about any number 9-digit number because we'll
//never be able to reach a big enough sum. And it'll only get worse with larger numbers :)
