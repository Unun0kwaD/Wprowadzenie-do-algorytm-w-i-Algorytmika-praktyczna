#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
double dp[4000];//kat prostej
int wsp[200][2];
int N=1;
double kat(int i, int j){
    if (wsp[i][1]-wsp[j][1]==0)
        return 1;
    if ((wsp[i][0]-wsp[j][0])==0)
        return 0;
    return (wsp[i][0]-wsp[j][0])/(wsp[i][1]-wsp[j][1]);
}
int main() {
    while(N!=0){
        int h=1;
        scanf ("%d",&N);
        for (int i=0; i<N;i++){
            scanf ("%d %d",&wsp[i][0],&wsp[i][1]);

        }
        for (int i=0; i<N-1;i++){
            for (int j=i+1; j<N;j++){
                    dp[h]=kat(i,j);
                    //cout<<dp[h]<<endl;
                for (int m=h-1; m>=0; m--){
                        if (dp[m]==dp[h] && m!=h){
                                h--;
                        }
                }
               // cout<<" "<<h<<endl;
                h++;
            }
        }
        if (N)
       cout<<h<<endl;
        }
    return 0;
}