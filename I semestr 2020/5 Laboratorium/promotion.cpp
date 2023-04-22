#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int a,b,c,heapMIN[1000000],heapMAX[1000000],rozm=0,MAXsize=0,MINsize=0;
long long int suma=0;
using namespace std;
//przywracanie struktury po dodaniu elementu MAX
void push_upMAX(int idx){
    int son=idx;
    int father=idx/2;
    while (father>0 && heapMAX[father]<heapMAX[son]){
        swap(heapMAX[father],heapMAX[son]);
        son=father;
        father=son/2;
    }

}
//dodawanie elementu MAX
void insertMAX(int e){
    ++MAXsize;
    heapMAX[MAXsize]=e;
    push_upMAX(MAXsize);

}
// praywracanie struktury po usunieciu korzenia MAX
void push_downMAX(int idx){
    int father = idx;
    int son = 2*idx;

    while (son<= MAXsize){
        if (son<MAXsize && heapMAX[son+1]>heapMAX[son]){
            ++son;
        }
        if( heapMAX[son]>heapMAX[father]){
            swap(heapMAX[son],heapMAX[father]);
            father =son;
            son= father*2;
        } else break;
    }

}

//usuwanie i pobieranie 1 elementu MAX
int popMAX(){
    int res = heapMAX[1];
    heapMAX[1] = heapMAX[MAXsize];
    --MAXsize;
    push_downMAX(1);
    return res;

}
//przywracanie struktury po dodaniu elementu MIN
void push_upMIN(int idx){
    int son=idx;
    int father=idx/2;
    while (father>0 && heapMIN[father]>heapMIN[son]){
        swap(heapMIN[father],heapMIN[son]);
        son=father;
        father=son/2;
    }

}
//dodawanie elementu MIN
void insertMIN(int e){
    ++MINsize;
    heapMIN[MINsize]=e;
    push_upMIN(MINsize);

}
// praywracanie struktury po usunieciu korzenia MIN
void push_downMIN(int idx){
    int father = idx;
    int son = 2*idx;

    while (son<= MINsize){
        if (son<MINsize && heapMIN[son+1]<heapMIN[son]){
            ++son;
        }
        if( heapMIN[son]<heapMIN[father]){
            swap(heapMIN[son],heapMIN[father]);
            father =son;
            son= father*2;
        } else break;
    }

}

//usuwanie i pobieranie 1 elementu MIN
int popMIN(){
    int res = heapMIN[1];
    heapMIN[1] = heapMIN[MINsize];
    --MINsize;
    push_downMIN(1);
    return res;

}

int main() {
    cin>>a;
    /*for (int j=0; j<a; j++){
        cin>>b;
        insertMIN(b);}

    for (int j=0; j<a; j++){
        cout<<popMIN()<<" ";}*/
    for (int j=0; j<a; j++){
        cin>>b;
        for (int i=0; i<b; i++){
            cin>>c;
            insertMAX(c);
            insertMIN(c);
            }
        suma+=popMAX()-popMIN();
    }
    cout<<suma;
    return 0;
}
