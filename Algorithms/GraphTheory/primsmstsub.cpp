#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int rozmiar=0;
typedef pair<int, int> pi;
struct wierzch{
    vector<pair<int,int>> somsiedzi;//{wieght,id}
    char przynaleznosc;
};
int main(){
    int n,e,a,b,w,s;
    cin>>n>>e;
    wierzch graf[n+1];
    for ( int i = 0; i<e; i++){
        cin>>a>>b>>w;
        graf[a].somsiedzi.push_back({w,b});
        graf[b].somsiedzi.push_back({w,a});
    }
    cin>>s;
    graf[s].przynaleznosc='A';
    for (int i = 1; i<=n; i++){
        if (i!=s)
            graf[i].przynaleznosc='Q';

    }
    priority_queue<pi, vector<pi>, greater<pi> > que;
    for (int i = 0; i<graf[s].somsiedzi.size(); i++){
        que.push(graf[s].somsiedzi[i]);
    }
    while (!que.empty()){
        pair<int,int> u=que.top();
        //cerr<<u.first<<" "<<u.second<<endl;
        que.pop();
        if (graf[u.second].przynaleznosc=='Q'){
            graf[u.second].przynaleznosc='A';
            rozmiar+=u.first;
            for (int i = 0; i<graf[u.second].somsiedzi.size(); i++){
                que.push(graf[u.second].somsiedzi[i]);
            }
        }
    }
    cout<<rozmiar;
}
