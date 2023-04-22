#include <iostream>
using namespace std;
short int tab[2000000];
long long int sum=0, odp=0;
int main(){
    int t = -1;
    while (t!=0){
        cin>>t;
        if (t>0){
            for ( int i=0; i<t; i++){
                cin>>tab[i];
                tab[i+t]=tab[i];
            }
            for (int i=2*t-1; i>=0; i--){
                sum+=tab[i];
                if (sum >-1){
                    if (i<t) odp++;
                    sum=0;
                }
            }
            cout<<odp<<endl;
            sum=0, odp=0;
        }
    }
}