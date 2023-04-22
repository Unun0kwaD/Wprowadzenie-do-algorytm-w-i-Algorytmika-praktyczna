#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

    long long unsigned totaltime=0;
    int n,rtime;
    int timen[50000],timep[50000];
int main() {
    cin>>n;
    for (int i =0; i<n;i++){
        cin>>timen[i];
        totaltime+=timen[i];
    }
    int j=1;
    int mindelta=1000000000;
    while(j<totaltime){
       // cerr<<"Time:"<<j<<endl;
        for (int i=0; i<n;i++){
            if(timen[i]){
                mindelta=min(mindelta,timen[i]);
                timen[i]--;
                timep[i]=j;
                j++;
            }
            }
        for (int i=0; i<n;i++){
            if(timen[i]){
                timen[i]-=mindelta-1;
                j+=mindelta-1;
                timep[i]=j;
            }
        }

    }
    for (int i =0; i<n;i++){
        cout<<timep[i]<<endl;
    }
    return 0;
}
