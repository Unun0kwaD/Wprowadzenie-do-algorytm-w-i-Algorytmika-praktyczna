#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector <int> rodzic;
vector <int> rozmiar;
vector <pair<short,short>> frto;
vector <int> weight;
short f,t;
int w;
int nodes,edges;
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
    }
}
void merges(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2],Lf[n1], Rf[n2],Lt[n1], Rt[n2];
    for (int i = 0; i < n1; i++){
        L[i] = weight[l + i];
        Lf[i]=frto[l + i].first;
        Lt[i]=frto[l + i].second;}
    for (int j = 0; j < n2; j++){
        R[j] = weight[m + 1 + j];
        Rf[j]=frto[m + 1 + j].first;
        Rt[j]=frto[m + 1 + j].second;}
    int i = 0,j=0,k=l;
    while (i < n1 && j < n2) {
        if (L[i] > R[j]){
            frto[k].first=Rf[j];
            frto[k].second=Rt[j];
            weight[k++] = R[j++];}
        else{
            frto[k].first=Lf[i];
            frto[k].second=Lt[i];
            weight[k++] = L[i++];}
    }
    while (i < n1) {
        frto[k].first=Lf[i];
        frto[k].second=Lt[i];
        weight[k++] = L[i++]; }
    while (j < n2) {
        frto[k].first=Rf[j];
        frto[k].second=Rt[j];
        weight[k++] = R[j++];    }
}
void mergeSort(int l,int r){
    if(l>=r)
        return;
    int m = (l+r-1)/2;
    mergeSort(l,m);
    mergeSort(m+1,r);
    merges(l,m,r);
}
int main() {
    cin>>nodes>>edges;
    for (int i=0; i<edges;i++){
        cin>>f>>t>>w;
        weight.push_back(w);
        frto.push_back({f,t});
    }
    int sum=0;
    for(int i=0; i<=nodes; ++i) {
        rodzic.push_back(i);
         rozmiar.push_back(1);
    }
    mergeSort(0,edges-1);
    for (int i=0; i<edges;i++){
        if (finda(frto[i].first)!=finda(frto[i].second)){
            sum+=weight[i];
            unia(finda(frto[i].first),finda(frto[i].second));
        }
    }
    cout<<sum;
    return 0;
}

