#ifndef MLL_H_
#define MLL_H_
#include <iostream>
using namespace std;

#define firstT(L) L.firstTrainer
#define nextT(P) P->nextTrainer
#define infoT(P) P->infoTrainer
#define firstM(P) P->firstMember
#define lastM(P) P->lastMember
#define nextM(P) P->nextMember
#define prevM(P) P->prevMember
#define infoM(P) P->infoMember

typedef struct trainer *addr_trainer;
typedef struct member *addr_member;

struct infotypeTrainer {
    string nama;
    int umur;
};

struct infotypeMember {
    string nama;
    string asal;
    int umur;
};

struct ListTrainer {
    addr_trainer firstTrainer;
};

struct trainer {
    infotypeTrainer infoTrainer;
    addr_trainer nextTrainer;
    addr_member firstMember;
    addr_member lastMember;
};

struct member {
    infotypeMember infoMember;
    addr_member nextMember;
    addr_member prevMember;
};

void inisialisasiList(ListTrainer &L);
addr_trainer alokasiTrainer(string nama, int umur);
addr_member alokasiMember(string nama, string asal, int umur);
void tambahTrainer(ListTrainer &L, addr_trainer T);
void tambahMember(addr_trainer Trainer, addr_member M);
addr_trainer cariTrainer(ListTrainer L, string namaTrainer);
addr_member cariMember(addr_trainer Trainer, string namaMember);
void tampilkanTrainer(ListTrainer L);
void tampilkanMemberDariTrainer(addr_trainer Trainer);
void hapusTrainer(ListTrainer &L, addr_trainer &T);
void hapusMember(addr_trainer Trainer, addr_member M);

#endif
