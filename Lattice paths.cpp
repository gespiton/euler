#include<iostream>
#include<utility>
using namespace std;
unsigned long long counter=0;
pair<int,int> position={0,0};
void move (int x,int y);
int main(){
move(0,0);
cout<<counter*21;
}
void move (int x,int y){
    //cout<<x<<"   "<<y<<endl;
    if(20==x&&20==y){
       ++ counter;
       return;
    }else{
        if(x<20){
            move(x+1,y);
        }


        if(x!=y&&y<20){
            move(x,y+1);
        }
    }
}
