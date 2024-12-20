#include "MLL.h"
#include <iostream>

void inisialisasiList(ListTrainer &L) {
    L.firstTrainer = NULL;
}

addr_trainer alokasiTrainer(string nama, int umur) {
    addr_trainer newTrainer = new trainer;
    infoT(newTrainer).nama = nama;
    infoT(newTrainer).umur = umur;
    newTrainer->nextTrainer = NULL;
    newTrainer->firstMember = NULL;
    newTrainer->lastMember = NULL;
    return newTrainer;
}
addr_member cariMember(addr_trainer Trainer, string namaMember) {
    addr_member M = Trainer->firstMember;
    while (M != NULL && infoM(M).nama != namaMember) {
        M = nextM(M);
    }
    return M;
}


addr_member alokasiMember(string nama, string asal, int umur) {
    addr_member newMember = new member;
    infoM(newMember).nama = nama;
    infoM(newMember).asal = asal;
    infoM(newMember).umur = umur;
    newMember->nextMember = NULL;
    newMember->prevMember = NULL;
    return newMember;
}

void tambahTrainer(ListTrainer &L, addr_trainer T) {
    if (L.firstTrainer == NULL) {
        L.firstTrainer = T;
    } else {
        addr_trainer temp = L.firstTrainer;
        while (temp->nextTrainer != NULL) {
            temp = temp->nextTrainer;
        }
        temp->nextTrainer = T;
    }
}

void tambahMember(addr_trainer Trainer, addr_member M) {
    if (Trainer->firstMember == NULL) {
        Trainer->firstMember = M;
        Trainer->lastMember = M;
    } else {
        Trainer->lastMember->nextMember = M;
        M->prevMember = Trainer->lastMember;
        Trainer->lastMember = M;
    }
}

addr_trainer cariTrainer(ListTrainer L, string namaTrainer) {
    addr_trainer T = L.firstTrainer;
    while (T != NULL && infoT(T).nama != namaTrainer) {
        T = nextT(T);
    }
    return T;
}

void tampilkanTrainer(ListTrainer L) {
    addr_trainer T = L.firstTrainer;
    if(T == NULL){
        cout << "data masih kosong" << endl;
    } else{
        cout << "Daftar Trainer:" << endl;
        while (T != NULL) {
            cout << "Nama: " << infoT(T).nama << ", Umur: " << infoT(T).umur << endl;
            T = nextT(T);
        }
    }
}

void tampilkanMemberDariTrainer(addr_trainer Trainer) {
    cout << "Daftar Trainer: " << endl;
    cout << "Daftar Member dari Trainer: " << infoT(Trainer).nama << endl;
    addr_member M = Trainer->firstMember;
    if(M == NULL){
        cout << "data masih kosong" << endl;
    } else{
        while (M != NULL) {
            cout << "Nama: " << infoM(M).nama
                << ", Asal: " << infoM(M).asal
                << ", Umur: " << infoM(M).umur << endl;
            M = M->nextMember;
        }
    }
}

// Fungsi menghapus Trainer (Parent) beserta seluruh Member (Child)-nya
void hapusTrainer(ListTrainer &LT, addr_trainer &T) {
    addr_member currentMember, tempMember;
    addr_trainer PrecTrainer = firstT(LT);

    // Hapus semua member pada trainer
    currentMember = firstM(T);
    while (currentMember != NULL) {
        tempMember = nextM(currentMember);
        delete currentMember;
        currentMember = tempMember;
    }

    // Menghapus trainer dari list parent
    if (T == firstT(LT)) { // Trainer adalah elemen pertama
        firstT(LT) = nextT(T);
    } else { // Trainer bukan elemen pertama
        while (nextT(PrecTrainer) != T) {
            PrecTrainer = nextT(PrecTrainer);
        }
        nextT(PrecTrainer) = nextT(T);
    }

    nextT(T) = NULL;
    delete T;
    T = NULL;
}

// Fungsi menghapus Member (Child) dari Trainer
void hapusMember(addr_trainer Parent, addr_member M) {
    if (M == firstM(Parent) && M == lastM(Parent)) { // Satu-satunya member
        firstM(Parent) = NULL;
        lastM(Parent) = NULL;
    } else if (M == firstM(Parent)) { // Member pertama
        firstM(Parent) = nextM(M);
        prevM(firstM(Parent)) = NULL;
    } else if (M == lastM(Parent)) { // Member terakhir
        lastM(Parent) = prevM(M);
        nextM(lastM(Parent)) = NULL;
    } else { // Member di tengah
        nextM(prevM(M)) = nextM(M);
        prevM(nextM(M)) = prevM(M);
    }

    nextM(M) = NULL;
    prevM(M) = NULL;
    delete M;
}

