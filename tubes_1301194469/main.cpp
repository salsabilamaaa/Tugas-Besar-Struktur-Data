#include <iostream>
#include "child.h"
#include "parent.h"
#include "relasi_1_n.h"


using namespace std;

int main()
{
    char pilih, pilih1, pilih2, pilih3;
    char pil = 'Y';
    string nama, alamat, jenis; // ini variabel buat data perusahaan, jenis itu buat data produk
    int jum_jual; // ini variabel buat data produksi produk
    adrCh Ch; // ini buat nampung alamat child dari function find child
    adrPr P;
    adrPr Pr; // ini buat nampung alamat parent
    listCh Lc; // ini buat nama list child
    listPr Lp; // ini buat nama list parent

    createListPr(Lp);
    createListCh(Lc);
    while(pil == 'Y' || pil == 'y' || pil != 't' || pil != 'T'){ //Looping terus selama user milih Y atau y
        if (pil == 'Y' || pil == 'y'){                           //Buat balik ke menu utama
            cout << "       SELAMAT DATANG" << endl;
            cout << "    Silahkan Pilih Menu" << endl;
            cout << endl;
            cout << "1. Tambah Data" << endl;
            cout << "2. Hapus Data" << endl;
            cout << "3. Lihat Data" << endl;
            cout << endl;
            cout << "Pilih : ";
            cin >> pilih;
            cout << "===========================================" << endl;
            if (pilih == '1'){
                cout << "   Silahkan Pilih Menu" << endl;
                cout << endl;
                cout << "1. Tambah Data Perusahaan" << endl;
                cout << "2. Tambah Data Produk" << endl;
                cout << endl;
                cout << "Pilih : ";
                cin >> pilih1;
                cout << "===========================================" << endl;
                if (pilih1 == '1'){
                    char j= '0';
                    char h;
                    while (j=='0'){
                        insertAscending(Lp, P);
                        cout << "Masih ingin input?"<<endl;
                        cout << "0.iya"<<endl;
                        cout << "1.tidak"<<endl;
                        cin >> h;
                        cout << "===========================================" << endl;
                        while (h!='0' && h!='1'){
                            cout<<"inputkan ulang"<<endl;
                            cin>>h;
                        }
                        if(h=='0'){
                            j=h;
                        } else {
                            j='1';
                        }
                    }
                }else if (pilih1 == '2'){
                    if (first(Lp) != NULL){
                        showPerusahaan(Lp);
                        cout << "Masukkan Nama Perusahaan : ";
                        cin >> nama;
                        cout << endl;
                        Pr = cariElemen(Lp, nama);
                        if (Pr != NULL){
                            char pilihan = 'y';
                            while (pilihan == 'y'){
                                cout << "   Masukkan Data Produk" << endl << endl;
                                cout << "Jenis Produk    : ";
                                cin >> jenis;
                                cout << "Jumlah Produksi : ";
                                cin >> jum_jual;
                                Ch = findCh(child(Pr), jenis);
                                if (Ch == NULL){
                                    insertCh(child(Pr), createElmCh(jenis, jum_jual));
                                    info(Pr).jum_produk = info(Pr).jum_produk + 1;
                                    cout << endl;
                                    cout << "Successed" << endl;
                                }else{
                                    cout << "Jenis Produk Sudah Ada di Perusahaan " << nama << endl;
                                }
                                cout << "Tambah Produk ? (Y/T) : ";
                                cin >> pilihan;
                                while(pilihan != 'y' && pilihan != 'Y' && pilihan != 't' && pilihan != 'T'){
                                    cout << "Maaf Pilihan Anda Salah. Silahkan pilih (Y/T) ? ";
                                    cin >> pilihan;
                                }
                                cout << endl;
                            }
                        }else{
                            cout << "Tidak Ada Perusahaan " << nama << endl;}
                    }else{
                        cout << "Tidak Ada Perusahaan" << endl;}
                }else {
                    cout << "Maaf Menu yang Anda Pilih Tidak Ada" << endl;
                }
            }else if (pilih == '2'){
                cout << "   Silahkan Pilih Menu" << endl;
                cout << endl;
                cout << "1. Hapus Data Perusahaan" << endl;
                cout << "2. Hapus Data Produk" << endl;
                cout << endl;
                cout << "Pilih : ";
                cin >> pilih2;
                cout << "===========================================" << endl;
                if (pilih2 == '1'){
                    if (first(Lp) == NULL) {
                        cout <<"Belum ada Perusahaan" <<endl;
                    }else {
                        showPerusahaan (Lp);
                        cout<<"Pilih Perusahaan (nama) : "<<endl;
                        cin >> nama;
                        Pr = cariElemen(Lp, nama);
                        if (Pr != NULL){
                            deleteParent(Lp, Pr);
                            cout << endl;
                            cout << "Successed";
                        }else{
                            cout << "Tidak Ada Perusahaan " << nama << endl;
                        }
                    }
                }else if (pilih2 == '2'){
                    if (first(Lp) != NULL){
                        showPerusahaan(Lp);
                        cout << "Masukkan Nama Perusahaan : ";
                        cin >> nama;
                        cout << endl;
                        Pr = cariElemen(Lp, nama);
                        if (Pr != NULL){
                            cout << "   Pilih Produk yang Akan di Hapus " << endl;
                            showCh(child(Pr));
                            if (first(child(Pr)) != NULL){
                                cout << "Masukkan Jenis Produk  : ";
                                cin >> jenis;
                                Ch = findCh(child(Pr), jenis);
                                if (Ch != NULL){
                                    hapusCh(child(Pr), Ch);
                                    info(Pr).jum_produk = info(Pr).jum_produk - 1;
                                    cout << endl;
                                    cout << "Successed";
                                }else{
                                    cout << "Tidak Ada Jenis " << jenis << endl;
                                }
                            }
                        }else {
                            cout << "Tidak Ada Perusahaan " << nama << endl;}
                    }else{
                        cout << "Tidak Ada Perusahaan" << endl;}
                }else {
                    cout << "Maaf Menu yang Anda Pilih Tidak Ada" << endl;
                }
            }else if (pilih == '3') {
                cout << "         Silahkan Pilih Menu" << endl;
                cout << endl;
                cout << "1. Perusahaan dan Produk Andalan" << endl;
                cout << "2. Produk berdasarkan Perusahaan" << endl;
                cout << "3. Perusahaan berdasarkan Jenis Produk" << endl;
                cout << "4. TOP 3 Perusahaan" << endl;
                cout << endl;
                cout << "Pilih : ";
                cin >> pilih3;
                cout << "===========================================" << endl;
                if (pilih3 == '1'){
                    showDataPerusahaan(Lp);
                }else if (pilih3 == '2'){
                    if (first(Lp) != NULL){
                        showPerusahaan(Lp);
                        cout << "Masukkan Nama Perusahaan : ";
                        cin >> nama;
                        Pr = cariElemen(Lp, nama);
                        if (Pr == NULL){
                            cout << "Tidak Ada Perusahaan " << nama << endl;
                        }else{
                            showCh(child(Pr));
                        }
                    }else{
                        cout << "Tidak Ada Perusahaan" << endl;}
                }else if (pilih3 == '3'){
                    if (first(Lp) != NULL){
                        cout << "Masukkan Produk : ";
                        cin >> jenis;
                        cout << endl;
                        showPrJenis(Lp, jenis);
                    }else{
                        cout << "Tidak Ada Perusahaan" << endl;}
                }else if (pilih3 == '4'){
                    if (first(Lp) != NULL){
                        perusahaanTop(Lp);
                    }else{
                        cout << "Tidak Ada Perusahaan " << endl;}
                }else{
                    cout << "Maaf Menu yang Anda Pilih Tidak Ada" << endl;
                }
            }else {
                cout << "Maaf Menu yang Anda Pilih Tidak Ada" << endl;
            }
            cout << endl;
            cout << "Kembali ke Menu Utama? (Y/T) : ";
            cin >> pil;
            cout << "===========================================" << endl;
        }else if (pil == 'T' || pil == 't'){
            return 0;
        }else{
            cout << endl;
            cout << "Maaf Menu yang Anda Pilih Tidak Ada" << endl;
            cout << endl;
            cout << "Kembali ke Menu Utama? (Y/T) : ";
            cin >> pil;
            cout << "===========================================" << endl;
            }
        }
    return 0;
}
