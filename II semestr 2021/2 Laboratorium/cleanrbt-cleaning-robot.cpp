#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
char  tab[20][20];
int tab2[20][20];
int C=2,R, maks=0,l_brudu=0,mini=0,bi,bj;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >  Q;
void display(){
        for (int j=0; j<R; j++){
            for (int k=0; k<C; k++){
                cerr<<tab2[j][k]<<" ";
            }
        cerr<<endl;
    }
}
void relax(int ui, int uj, int vi,int vj){
   // cerr<<"relaks"<<endl;
    if (tab2[vi][vj] > tab2[ui][uj]+1 ){
       // cerr<<"udany relaks"<<endl;
        tab2[vi][vj]=tab2[ui][uj]+1;
        Q.push({tab2[vi][vj],{vi,vj}});
    }
}
int djikstra(int i,int j){
    memset(tab2,9999,sizeof tab2);
    tab2[i][j]=0;
    Q.push({tab2[i][j],{i,j}});
    while(!Q.empty()){
        bi=Q.top().second.first;
        bj=Q.top().second.second;
       // cerr<<"robot:"<<bi<<" "<<bj<<endl;
        Q.pop();
        if (tab[bi][bj]=='*'){
            cerr<<"siema"<<endl;
            tab[bi][bj]='.';
            Q = priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >  ();
            mini+=tab2[bi][bj];
            cerr<<"dist:"<<tab2[bi][bj]<<endl;
            return 0;
        }
        if (bi>0 && tab[bi-1][bj]!='x'){
            relax(bi,bj,bi-1,bj);
        }
        if (bj>0 && tab[bi][bj-1]!='x'){
            relax(bi,bj,bi,bj-1);
        }
        if (bi<R-1 && tab[bi+1][bj]!='x'){
            relax(bi,bj,bi+1,bj);
        }
        if (bj<C-1 && tab[bi][bj+1]!='x'){
            relax(bi,bj,bi,bj+1);
        }
    }
    return 0;
}
void odpal_robota(int a, int b){
    bi=a;
    bj=b;
    for (int i=0; i<l_brudu;i++){
        djikstra(bi,bj);
        display();
        cerr<<"brud:"<<bi<<" "<<bj<<endl;
    }
}
int main(){
    int t,a,b;
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    while(C!=0){
        l_brudu=0;
        mini=0;
        cin>>C>>R;
        for (int j=0; j<R; j++){
            for (int k=0; k<C; k++){
                cin>>tab[j][k];
                if (tab[j][k]=='o'){
                    a=j;
                    b=k;
                }
                if (tab[j][k]=='*')
                    l_brudu++;
            }
        }
        memset(tab2,9999,sizeof tab2);
        odpal_robota(a,b);
        if (mini==0 && C!=0)
            cout<<-1<<endl;
        else if (C!=0) cout<<mini<<endl;
    }
}
