#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include "child.h"
#include <iostream>
using namespace std;

#define info(P) P->info
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next

#define prev(P) P->prev
#define child(P) P->child

struct DataPerusahaan
{
    string namaPT;
    int jum_produk;
};

typedef DataPerusahaan infotypePr;
typedef struct elmPr  *adrPr;

struct elmPr {
    infotypePr info;
    adrPr next;
    adrPr prev;
    listCh child;
};

struct listPr {
    adrPr first;
    adrPr last;
};

void createListPr (listPr &L);
void alokasi (adrPr &P);
void insertFirst( listPr &L, adrPr P );
void insertAfter(listPr &L, adrPr P );
void insertLast(listPr &L, adrPr P );
void insertAscending(listPr &L, adrPr P);
adrPr pilihPerusahaan( listPr L, int nomor );
adrPr cariElemen( listPr L, string x );
void perusahaanTop( listPr L );
void showPerusahaan (listPr &L);
void showDataPerusahaan (listPr L);
void showPrJenis(listPr L, string jenis);

#endif // PARENT_H_INCLUDED
