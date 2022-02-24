#include "relasi_1_n.h"

void deleteParent(listPr &L, adrPr P) {
    adrPr Q;
    if ( first( L ) == NULL ) {
        cout << "data kosong";
    } else if (first(L) == P ){
        if (first(L) == last(L)){
            first( L ) = NULL;
            last( L ) = NULL ;
        }else{
            deleteFirstParent(L, Q);
        }
    }else if ( last(L) == P ) {
        deleteLastParent(L, Q);
    }else {
        adrPr Prec = first( L );
        while ( next( Prec ) != P ) {
            Prec = next( Prec );
        }
        deleteAfterParent(Prec, Q);
    }
};

void deleteFirstParent( listPr &L, adrPr &P ) {
    P = first(L);
    first( L ) = next( first(L) );
    next( last(L) ) = first( L );
    prev( first(L) ) = last( L );
    next( P ) = NULL;
    prev( P ) = NULL;
};

void deleteAfterParent(adrPr prec, adrPr &P) {
    P = next( prec );
    next( prec ) = next( P );
    prev( next( P )) = prec;
    next( P ) = NULL;
    prev( P ) = NULL;
};

void deleteLastParent( listPr &L, adrPr &P ) {
    P = last( L );
    next( prev(P) ) = first( L );
    prev( first(L) ) = prev( P );
    last( L ) = prev( P );
    next( P ) = NULL;
    prev( P ) = NULL;
};
