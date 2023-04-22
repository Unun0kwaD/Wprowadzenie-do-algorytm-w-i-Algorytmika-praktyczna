#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a,b=1;
    cin>>a;
    int tab[a];
     for (int i=0;i<a;i++){
        cin>>tab[i];
         b=1;
        for (int j=0; j<tab[i]; j++){
            b=b*(j+1);
            if (b%1000==0) b/=1000;
            if (b%100==0) b/=100;
            if (b%10==0) b/=10;
            if (b>100000) b=b%100000;
            }
         cout<<b%10<<endl;
     }
    return 0;
}