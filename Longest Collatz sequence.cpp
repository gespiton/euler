#include<iostream>
using namespace std;
int main()
{
   unsigned int largest=0;
   unsigned long length=0,counter=0;

    for(unsigned long ii=2; ii<=1000000; ++ii)
    {
        auto i=ii;
        counter=0;
        while(i!=1)
        {
            if(i%2)
                i=3*i+1;
            else
                i/=2;
            ++counter;
        }
        cout<<ii<<endl;
        if(counter>length){
            length=counter;
            largest=ii;
        }
    }
    cout<<length<<"  "<<largest;
}
