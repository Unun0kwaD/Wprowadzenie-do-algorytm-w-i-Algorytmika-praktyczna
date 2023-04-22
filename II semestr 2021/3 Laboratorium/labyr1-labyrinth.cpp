#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
char  tab[1000][1000];
int C,R, maks=0;
int t,a=-1,b;
int czylisc(int x, int y){
    int l=0;
    if (x+1<R){
        if (tab[x+1][y]=='.') l++;}
    if (y+1<C){
        if (tab[x][y+1]=='.') l++;}
    if (x>0){
        if (tab[x-1][y]=='.') l++;}
    if (y>0){
        if (tab[x][y-1]=='.') l++;}
    return l;
}
pair<int,int> DFS_do_liscia(int x, int y){
    int c=czylisc(x,y);
    if(c==1){
        return {x,y};
    }
    if (c==0)
        return {-1,-1};
    if (x+1<R && tab[x+1][y]=='.')
        return DFS_do_liscia(x+1,y);
    if (y+1<C && tab[x][y+1]=='.')
        return DFS_do_liscia(x,y+1);
    if (x>0 && tab[x-1][y]=='.')
        return DFS_do_liscia(x-1,y);
    if (y>0 && tab[x][y-1]=='.')
        return DFS_do_liscia(x,y-1);
    return {-1,-1};
}
int w_glab(short int x,short int y, int gl,short int lx,short int ly,int tura){
    if(czylisc(x,y)==1){
        if (gl>maks){
            maks=gl;
            a=x;
            b=y;
        }/*
        if (tura==0)
            w_glab(x,y,0,-1,-1,1);*/
    }
    else if (czylisc(x,y)==0)
        return 0;
    if (x+1<R && tab[x+1][y]=='.' && x+1!=lx)
        w_glab(x+1,y,gl+1,x,y,tura);
    if (y+1<C && tab[x][y+1]=='.' && y+1!=ly)
        w_glab(x,y+1,gl+1,x,y,tura);
    if (x>0 && tab[x-1][y]=='.' && x-1!=lx)
        w_glab(x-1,y,gl+1,x,y,tura);
    if (y>0 && tab[x][y-1]=='.' && y-1!=ly)
        w_glab(x,y-1,gl+1,x,y,tura);

    return maks;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for (int i =1; i<=t; ++i){
        maks=0;
        cin>>C>>R;
        for (int j=0; j<R; j++){
            for (int k=0; k<C; k++){
                cin>>tab[j][k];
                if (tab[j][k]=='.' && czylisc(j,k)==1){
                    a=j;
                    b=k;
                }
            }
        }
        //pair<int,int> para=DFS_do_liscia(a,b);
        //cerr<<"pierwszy lisc:"<<para.first<<" "<<para.second;
        if (a==-1)
            cout<<"Maximum rope length is 0."<<endl;
        else{
            w_glab(a,b,0,-1,-1,0);
            cout<<"Maximum rope length is "<<w_glab(a,b,0,-1,-1,1)<<"."<<endl;
        }
    }
}
