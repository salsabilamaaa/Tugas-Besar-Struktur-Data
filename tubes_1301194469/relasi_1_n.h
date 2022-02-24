#ifndef RELASI_1_N_H_INCLUDED
#define RELASI_1_N_H_INCLUDED

#include "parent.h"
#include "child.h"

void deleteParent( listPr &L, adrPr P );
void deleteFirstParent( listPr &L, adrPr &P );
void deleteAfterParent( adrPr prec, adrPr &P );
void deleteLastParent( listPr &L, adrPr &P );


#endif // RELASI_1_N_H_INCLUDED
