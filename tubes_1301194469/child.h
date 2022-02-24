#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define nextCh(P) (P)->nextCh
#define info(P) (P)->info

using namespace std;

typedef struct dataProduk infoCh;
typedef struct elmCh *adrCh;

struct dataProduk
{
    string jenis;
    int jum_jual;
};

struct elmCh
{
    infoCh info;
    adrCh nextCh;
};

struct listCh
{
    adrCh first;
};

void createListCh(listCh &L);
adrCh createElmCh(string jenis, int jum_jual);
void insertCh(listCh &L, adrCh P);
adrCh findCh(listCh L, string jenis);
adrCh findAndalan(listCh L);
void showCh(listCh L);
void hapusCh(listCh &L, adrCh P);
int hitungJumJual(listCh L);
#endif // CHILD_H_INCLUDED
