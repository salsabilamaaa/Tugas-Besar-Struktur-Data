#include "parent.h"
#include "child.h"

void createListPr (listPr &L){
    first( L ) = NULL;
    last( L ) = NULL;
};

void alokasi (adrPr &P){
    string namaPT;
    cout << "     Masukan Nama Perusahaan" << endl;
    cout << endl;
    P = new elmPr;
    cout << "Nama       : ";
    cin.get();
    getline( cin, namaPT );
    info(P).namaPT = namaPT;
    info(P).jum_produk= 0;
    next(P) = NULL;
    prev(P) = NULL;
    first(child(P)) = NULL;
};

void insertFirst( listPr &L, adrPr P ){
    if ( first( L ) == NULL ) {
        first( L ) = P;
        last( L ) = P;
        next( first(L) ) = last( L );
        prev( last(L) ) = first( L );
    } else {
        next( P ) = first( L );
        prev( P ) = last( L );
        next( last(L) ) = P;
        prev( first(L) ) = P;
        first( L ) = P;
    }
}

void insertAfter(listPr &L, adrPr P ){
    adrPr Q = first(L);
    while ( info(P).namaPT > info(next(Q)).namaPT && Q != last(L) ) {
        Q = next( Q );
    }
    adrPr prec = Q ;
    next(P)=next(prec);
    prev(next(prec))=P;
    next(prec)=P;
    prev(P)=prec;
}

void insertLast(listPr &L, adrPr P ){
    next(P)=first(L);
    prev(P)=last(L);
    next(last(L))=P;
    prev(first(L))=P;
    last(L)=P;
}

void insertAscending(listPr &L, adrPr P){
    alokasi(P);
    adrPr Q = cariElemen( L, info(P).namaPT );
    if ( Q == NULL ){
        if(first(L)==NULL){
            first( L ) = P;
            last( L ) = P;
            next( first(L) ) = last( L );
            prev( last(L) ) = first( L );
        } else if (info(P).namaPT < info(first(L)).namaPT){
            insertFirst(L, P);
        }else if(info(P).namaPT > info(last(L)).namaPT){
            insertLast(L, P);
        }else{
            insertAfter(L, P);
        }
    } else {
        cout << "Sudah Ada Perusahaan " << info(P).namaPT << endl;
    }
    cout << endl;
}

adrPr cariElemen( listPr L, string x ) {
    adrPr Q = first( L );
    if (Q != NULL){
        do {
            if (info(Q).namaPT == x) {
                return Q;
            }
            Q = next(Q);
        }while(Q != first(L));
    }
    return NULL;
};

void showPerusahaan (listPr &L){
    adrPr P;
    int i = 1;
    P = first(L);
    if ( first( L ) == NULL ) {
        cout << "Tidak Ada Perusahaan";
    } else {
        cout << "   Daftar Multi-Perusahaan " << endl;
        cout << endl;
        do {
            cout << i << ". "<< info(P).namaPT << endl;
            i++;
            P=next(P);
        } while (P!=first(L));
        cout << endl;
    }
}

void showDataPerusahaan (listPr L){
    adrPr P;
    int i = 1;
    P=first(L);
    if ( first( L ) == NULL ) {
        cout << "Belum ada Perusahaan" << endl;
    } else {
        do {
            cout<< i<< ". "<<"Nama Perusahaan   : ";
            cout<<info(P).namaPT<<endl;
            cout<<"   Jumlah Produk     : ";
            cout<<info(P).jum_produk<<endl;
            cout<<"   Produk            : ";
            adrCh Ch = findAndalan(child(P));
            if (Ch != NULL){
                cout<< info(Ch).jenis<< endl;
            }else{
                cout << "-" << endl;
            }
            cout << endl;

            i++;
            P=next(P);
        } while (P!=first(L));
    }
}

void perusahaanTop(listPr L)
{
    adrPr P;
    adrPr max1 = NULL;
    adrPr max2 = NULL;
    adrPr max3 = NULL;
    int jum1 = 0;
    int jum2 = 0;
    int jum3 = 0;


    P = first(L);
    do {
        int jum = hitungJumJual(child(P));
        if(jum > jum1){
            jum3 = jum2;
            jum2 = jum1;
            jum1 = jum;
            max3 = max2;
            max2 = max1;
            max1 = P;
        }else if (jum > jum2){
            jum3 = jum2;
            jum2 = jum;
            max3 = max2;
            max2 = P;
        }else if (jum > jum3){
            jum3 = jum;
            max3 = P;
        }
        P = next(P);
    }while (P != first(L));

    if (max1 == NULL && max2 == NULL && max3 == NULL){
        cout << "Tidak Ada TOP 3 Perusahaan " << endl;
    }else if (max1 != NULL && max2 == NULL && max3 == NULL){
        cout << "       TOP 3 Perusahaan" << endl;
        cout << "1. " << info(max1).namaPT<< "(" << jum1 << ")" << endl;
    }else if (max1 != NULL && max2 != NULL && max3 == NULL){
        cout << "       TOP 3 Perusahaan" << endl;
        cout << "1. " << info(max1).namaPT << "(" << jum1 << ")" << endl;
        cout << "2. " << info(max2).namaPT << "(" << jum2 << ")" << endl;
    }else {
        cout << "       TOP 3 Perusahaan" << endl;
        cout << "1. " << info(max1).namaPT << "(" << jum1 << ")" << endl;
        cout << "2. " << info(max2).namaPT << "(" << jum2 << ")" << endl;
        cout << "3. " << info(max3).namaPT << "(" << jum3 << ")" << endl;
    }
}

void showPrJenis(listPr L, string jenis)
{
    int i = 0;
    adrPr Pr = first(L);
    cout << "Perusahaan yang memproduksi " << jenis << endl;
    do {
        adrCh Ch = findCh(child(Pr), jenis);
        if (Ch != NULL){
            cout << info(Pr).namaPT << ", ";
            i++;
        }
        Pr = next(Pr);
    }while (Pr != first(L));

    if (i == 0){
        cout << "Tidak Ada" << endl;
    }
    cout << endl;
}
