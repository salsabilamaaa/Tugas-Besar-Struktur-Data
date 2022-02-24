#include <iostream>
#include "child.h"
#include "parent.h"

using namespace std;

void createListCh(listCh &L)
{
    first(L) = NULL;
}

adrCh createElmCh(string jenis, int jum_jual)
{
    adrCh P = new elmCh;
    info(P).jenis = jenis;
    info(P).jum_jual = jum_jual;
    nextCh(P) = NULL;

    return P;
}

void insertCh(listCh &L, adrCh P)
{
    adrCh Q = first(L);
    if (first(L) != NULL){
        while (nextCh(Q) != NULL){
            Q = nextCh(Q);
        }
        nextCh(Q) = P;
    }else{
        first(L) = P;
    }
}

adrCh findCh(listCh L, string jenis)
{
    adrCh P = first(L);
    while (P != NULL){
        if (info(P).jenis == jenis){
            return P;
        }
        P = nextCh(P);
    }
    return NULL;
}

adrCh findAndalan(listCh L)
{
    adrCh P = first(L);
    adrCh Max = first(L);

    while (P != NULL) {
        if (info(P).jum_jual > info(Max).jum_jual){
            Max = P;
        }
        P = nextCh(P);
    }

    return Max;
}

void hapusCh(listCh &L, adrCh P)
{
    adrCh Q = first(L);
    if (Q == P){
        first(L) = nextCh(P);
    }else{
        while (nextCh(Q) != P){
            Q = nextCh(Q);
        }
        nextCh(Q) = nextCh(P);
    }
}

void showCh(listCh L)
{
    cout << endl;
    if (first(L) != NULL){
        cout << "Produk     : ";
        adrCh P = first(L);
        while (P != NULL){
            cout << info(P).jenis << ", ";
            P = nextCh(P);
        }
    }else{
        cout << "Tidak Ada Produk" << endl;
    }
    cout << endl;
}

int hitungJumJual(listCh L)
{
    int jum = 0;
    adrCh P = first(L);
    while (P != NULL){
        jum = jum + info(P).jum_jual;
        P = nextCh(P);
    }
    return jum;
}
