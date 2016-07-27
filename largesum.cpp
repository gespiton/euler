#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream in("ha");
    string buffer;
    vector<string>ve;
    while(in>>buffer)
        ve.push_back(buffer);
        cout<<ve[99].substr(0,11)<<endl;
    unsigned long long result=0;
    for(auto &ite:ve){
        result+=stol(ite.substr(0,11));
    }
    cout<<result;

}
