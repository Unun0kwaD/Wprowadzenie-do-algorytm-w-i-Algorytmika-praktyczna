#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int tab [6100][6100];
int czysc(int a){
    for (int i=0;i<=a;i++){
        for (int j=0;j<=a;j++){
            tab[i][j]=-1;
        }
    }
    return 0;
}
int aibohp(int p, int k, string &str){
    if(tab[p][k]!=-1)
        return tab[p][k];
    if(k<=p)
        return 0;
    if(str[p]==str[k])
        tab[p][k]=aibohp(p+1,k-1,str);
    else
        tab[p][k]=min( aibohp(p,k-1,str), aibohp(p+1,k,str))+1;
    return tab[p][k];
}
int main() {
    string palindrom;
    int t;
    cin>>t;
    while(t--){
        cin>>palindrom;
        czysc(palindrom.length());
        int ans=aibohp(0,palindrom.length()-1,palindrom);
        cout<<ans<<endl;
    }
    return 0;
}