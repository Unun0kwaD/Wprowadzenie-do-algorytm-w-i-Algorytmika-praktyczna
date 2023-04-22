#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string cezar() {
    string a;
    getline(cin,a);
    int i = 0;
    while (i<a.length())
    {
        if (int(a[i])>64 && int(a[i])<88)
            a[i]+=3;
        else if (int(a[i])>87 && int(a[i])<91 )
            a[i]-=23;
        i++;
    }
    cout<<a;
    if ( a != ""){
            cout<<endl;
            cezar();}
    return "";
}
int main() {
    cezar();
}
