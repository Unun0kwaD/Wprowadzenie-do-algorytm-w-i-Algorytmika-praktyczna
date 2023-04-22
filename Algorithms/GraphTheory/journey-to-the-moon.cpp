#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector <int> rodzic;
vector <int> rozmiar;
vector <int> reprezentanci;
int n,q,k,l,l_rep=0;
int finda(int a) {
    if (a==rodzic[a]) return a;
    return rodzic[a]=finda(rodzic[a]);
}
void unia(int a, int b) {
    a=finda(a);
    b=finda(b);
    if(a!=b) {
        if(rozmiar[a] < rozmiar[b]) swap(a,b);
        rodzic[b]=a;
        rozmiar[a]+=rozmiar[b];
        rozmiar[b]=0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<=100000; ++i) {
        rodzic.push_back(i);
        rozmiar.push_back(1);
    }
    cin>>n>>q;
    for(int i=0; i<q; i++) {
        cin>>k>>l;
        unia(k,l);
    }
    for (int i=0;i<n;++i){
        if (rozmiar[i]!=0){
            reprezentanci.push_back(rozmiar[i]);
        }
    }
    long long int sum=0;
    long long int subsum=0;
    for (int i=reprezentanci.size()-1; i>0;--i){
        subsum+=reprezentanci[i];
        sum+=subsum*reprezentanci[i-1];
    }
    cout<<sum;
    return 0;
}