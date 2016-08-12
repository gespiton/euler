/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/
#include<iostream>
#include<set>
#include<vector>
#include<cmath>
#include<stdlib.h>
using namespace std;
long long total = 0;
void cal (int);
bool jud(int,int,int);
FILE* file = fopen("ha","w");
int main()
{
    for(int i=1; i!=99999; ++i)
        cal(i);
    cout<<total;
}
void cal (int product)
{
    int bound = sqrt(product)+1;
    for(int i=2; i!=bound; ++i)
    {
        if(product%i==0)
        {
            if(jud(product,i,product/i))
            {
                fprintf(file,"%5d  %5d  %5d\n",product/i, i, product);
                total+=product;
                return;
            }
        }
    }
}
bool jud(int lhs,int mhs,int rhs)
{
    vector<int> duplicate;
    set<int> get;
    while(lhs)
    {
        get.insert(lhs%10);
        duplicate.push_back(lhs%10);
        lhs/=10;
    }
    while(mhs)
    {
        get.insert(mhs%10);
        duplicate.push_back(mhs%10);
        mhs/=10;
    }
    while(rhs)
    {
        get.insert(rhs%10);
        duplicate.push_back(rhs%10);
        rhs/=10;
    }
    if(duplicate.size()==9&&get.size()==9&&get.find(0)==get.end())
        return true;
    else
        return false;
}
