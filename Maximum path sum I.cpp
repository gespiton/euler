#include<fstream>
#include<vector>
#include<iostream>
#include<sstream>
#include<map>
using namespace std;
int main()
{
    vector<vector<int>> sr;
    ifstream fin("ha");
    map<int,int> store;
    int Lnum=0;
    string Ssr;
    while(getline(fin,Ssr))
    {
        static string buffer;
        static vector<int> buf;
        istringstream is(Ssr);
        while(is>>buffer)
        {
            buf.push_back(stoi(buffer));
        }
        sr.push_back(buf);
        buf.clear();
        ++Lnum;
    }
//    cout<<sr[1][0];
//}
//    for(auto i:sr)
//    {
//        for(auto ii:i)
//        {
//            cout<<ii<<"  ";
//        }
//        cout<<endl;
//    }
    const int totalLine=sr.size();
    int curLine=1;
    // as a buf of every iteration
    vector<int> buf(2*totalLine,0);
    // set the first element
    store[0]=sr[0][0];
    while(curLine!=totalLine)
    {
        for(int ite=0; ite<=curLine; ++ite)
        {
            if(ite==0)
            {
                buf[0]=store[0]+sr[curLine][0];
            }
            else if(ite==curLine)
            {
                buf[ite]=store[ite-1]+sr[curLine][ite];
            }
            else
            {
                buf[ite]=( (store[ite-1]>=store[ite])?
                             store[ite-1]:store[ite] )+sr[curLine][ite];
            }
        }
        // refresh store
        for(auto ite=0;ite<=curLine;++ite){
            store[ite]=buf[ite];
  //          cout<<store[ite]<<"  ";
        }
  //      cout<<endl;
        ++curLine;
    }
    int max=0;
    for(auto ite=0;ite!=2*totalLine;++ite){
        if(store[ite]>max)
            max=store[ite];
    }
    cout<<max;
}
