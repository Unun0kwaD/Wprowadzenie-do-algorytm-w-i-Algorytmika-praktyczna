#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
//t_na_min()
int main(){
    double t,i=0,czasp,czask;
    cin>>t;
    while (i<t){
        string pocz,kon;
        cin>>pocz>>kon;
        czasp=(pocz[0]-48)*600+(pocz[1]-48)*60+(pocz[3]-48)*10+(pocz[4]-48);
        czask=(kon[0]-48)*600+(kon[1]-48)*60+(kon[3]-48)*10+(kon[4]-48);
        double j=czasp,k=0;
        //cout<<czasp<<"  "<<czask<<endl;
        while (czask>=j){
               if (fmod(j , 65.45454545454545)<1 && j!=czasp) {
                   /* if (
                        (j==0 || j==720 || j==65 || j==131 || j==196 || j==262 || j== 327 || j==393 || j== 458 || j== 524 || j==589 || j==655 || j==1440 || j==65+720 || j==131+720 || j==196+720 || j==262+720 || j== 327+720 || j==393+720 || j== 458+720 || j== 524+720 || j==589+720 || j==655+720) && j!=czasp){*/
                        k++;
                        if (j+63<czask)
                            j+=63;
                    }
            j++;
        }
        cout<<k<<endl;
        //cin>>kon;
        i++;
    }

}