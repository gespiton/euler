#include<iostream>
#include<string>
#include<bitset>
using namespace std;
bool isPalindromes(string s)
{
    auto lite=s.begin();
    while(*lite=='0')
        ++lite;
    auto mid = lite+ (s.end()-lite)/2;
    auto rite = s.rbegin();
    for(; lite!=mid; ++lite,++rite)
        if(*lite!=*rite)
            return false;
    return true;

}
int main()
{
    long sum = 0;
    for(int i=1; i<=1000000; ++i)
        if(isPalindromes(to_string(i)))
            if(isPalindromes(bitset<32>(i).to_string()))
                sum+=i;
    cout<<sum;
//    cout<<isPalindromes(bitset<32>(65).to_string())<<endl;
//    cout<<to_string(0101);
//    cout<<a.at(0);
}
