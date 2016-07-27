/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int total=0;
    int ite=1;                    // the indicator of the number of the circle
    int Size=1;                  // the size of the outest circle
    int SizeIte=0;              // iterate through the outest circle
    long num=0;                // num increases as the circle cursor goes on
    int gap=1;                  // gap is the break between each corner
    while(ite!=502) {
        const int gapStore=gap;
        while(SizeIte<=Size) {
//                      cout<<num<<"   ";             //
            if(SizeIte==gap) {
                total+=num;
                gap+=gapStore;
//               cout<<"_";
            }
            ++num;
            ++SizeIte;
        }
 //       cout<<endl;                     //
        Size=ite*8;
        gap=Size/4;
        SizeIte=1;
        ++ite;
    }
    cout<<endl<<total;
}
