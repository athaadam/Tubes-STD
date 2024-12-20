#include <iostream>
#include "MLL.h"
using namespace std;

int main() {
    ListTrainer LT;
    inisialisasiList(LT);

    int pilihan;
    string nama, asal;
    int umur;
    addr_trainer T;
    addr_member M;

    do {
        system("CLS");
        cout << "=== MENU GYM ===" << endl;
        cout << "1. Tambah Trainer" << endl;
        cout << "2. Tambah Member ke Trainer" << endl;
        cout << "3. Tampilkan Semua Trainer" << endl;
        cout << "4. Tampilkan Member dari Trainer" << endl;
        cout << "5. Hapus Trainer" << endl;
        cout << "6. Hapus Member dari Trainer" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama Trainer: ";
                cin >> nama;
                cout << "Umur Trainer: ";
                cin >> umur;
                tambahTrainer(LT, alokasiTrainer(nama, umur));
                break;
            case 2: {
                tampilkanTrainer(LT);
                cout << endl;
                cout << "Nama Trainer: ";
                cin >> nama;
                T = cariTrainer(LT, nama);
                if (T != NULL) {
                    cout << "Nama Member: ";
                    cin >> nama;
                    cout << "Asal Member: ";
                    cin >> asal;
                    cout << "Umur Member: ";
                    cin >> umur;
                    tambahMember(T, alokasiMember(nama, asal, umur));
                } else {
                    cout << "Trainer tidak ditemukan." << endl;
                }
                break;
            }
            case 3:
                tampilkanTrainer(LT);
                break;
            case 4:
                cout << "Nama Trainer: ";
                cin >> nama;
                T = cariTrainer(LT, nama);
                if (T != NULL) {
                    tampilkanMemberDariTrainer(T);
                } else {
                    cout << "Trainer tidak ditemukan." << endl;
                }
                break;
            case 5: // Hapus Trainer
                tampilkanTrainer(LT);
                cout << endl;
                cout << "Nama Trainer yang akan dihapus: ";
                cin >> nama;
                T = cariTrainer(LT, nama);
                if (T != NULL) {
                    hapusTrainer(LT, T);
                    cout << "Trainer berhasil dihapus!" << endl;
                } else {
                    cout << "Trainer tidak ditemukan!" << endl;
                }
                break;
            case 6: // Hapus Member dari Trainer
                tampilkanTrainer(LT);
                cout << endl;
                cout << "Nama Trainer: ";
                cin >> nama;
                T = cariTrainer(LT, nama);
                if (T != NULL) {
                    tampilkanMemberDariTrainer(T);
                    cout << "Nama Member yang ingin dihapus: ";
                    cin >> nama;
                    M = cariMember(T, nama);
                    if (M != NULL) {
                        hapusMember(T, M);
                        cout << "Member berhasil dihapus!" << endl;
                    } else {
                        cout << "Member tidak ditemukan!" << endl;
                    }
                } else {
                    cout << "Trainer tidak ditemukan!" << endl;
                }
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
        system("PAUSE");
    } while (pilihan != 0);

    return 0;
}
