
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n,m,x,y,t;
    cin>>n;
    short int tab[n];
    for (int i=0;i<n;i++){
        cin>>tab[i];
    }
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>t;
        cin>>x>>y;
        if (t){
            x--;
            y--;
            long long int maxsum=INT_MIN,maksnow=0;
            for(int j=x;j<=y;j++){
                maksnow=maksnow+tab[j];
                if( maksnow>maxsum){
                    maxsum=maksnow;
                }
                if (maksnow<0)
                    maksnow=0;
            }
            cout<<maxsum<<endl;}
        else
            tab[x-1]=y;
    }
    return 0;
}
