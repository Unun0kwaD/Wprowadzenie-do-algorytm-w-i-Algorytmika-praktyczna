#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string cezar() {
    string a;
    bool eror=0;
    short int typ=0;
    getline(cin,a);
    int i = 0;
    while (i<a.length() && !eror)
    {
                if ((int(a[i+1])>64 && int(a[i+1])<91 && a[i]=='_' && i+1<a.length()) || a[i]<65 || (a[i]>90 && a[i]!='_' && a[i]<97) || a[i]>122
                    || (a[i]=='_' && i==a.length()-1) || a[0]=='_' || (int(a[0])>64 && int(a[0])<91) ){
                        if(!eror)
         cout<<"Error!"<<endl;
            eror=1;
        }
        else if (int(a[i])>64 && int(a[i])<91){
            char g='_';
            a.insert(i,1,g);
            i++;
            a[i]+=32;
             if (typ != 1 && typ != 0){

                    if(!eror)
                cout<<"Error!"<<endl;
                eror=1;
            }
            typ=1;
        }
        else if ( a[i]=='_' ){
            if (a[i+1] =='_'){
                    if(!eror)
                cout<<"Error!"<<endl;
                eror=1;
            }
            a[i+1]-=32;
            //string b=a;
            a.erase(i,1);
           // i++;
            if (typ != 2 && typ != 0){
                    if(!eror)
                cout<<"Error!"<<endl;
                eror=1;
            }
          //  i--;
            typ=2;
            }
        i++;
    }
    if (!eror)
    cout<<a<<endl;
    if ( a != "" ){
            cezar();}
    return "";
}
int main() {
    cezar();
}

