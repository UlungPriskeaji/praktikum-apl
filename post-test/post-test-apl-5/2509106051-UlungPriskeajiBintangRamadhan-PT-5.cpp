#include <iostream>
#include <string>
using namespace std;

#define MAX 10

string username, password;
int kesempatan = 3;

struct Player {
    string nickname;
    string role;
    string nationality;
    string status;
    int umur;
};

struct Tim {
    string namaTim;
    Player daftarPlayer[MAX];
    int jumlahPlayer;
};

bool login(string username, string password){
    return (username == "ulung" && password == "051");
}

// lihat tim dan player
void lihatTim(Tim *daftarTim, int *jumlahTim) {
    if (*jumlahTim == 0) {
        cout << "Belum Ada Data Tim." << endl;
        return;
    }

    for (int i = 0; i < *jumlahTim; i++) {
        Tim *t = &(*(daftarTim + i));
        cout << "\nTim " << i+1 << ": " << t->namaTim << endl;

        for (int j = 0; j < t->jumlahPlayer; j++) {
            Player *p = &(*(t->daftarPlayer + j));
            cout << j+1 << ". "
                << p->nickname << " | "
                << p->role << " | "
                << p->nationality << " | "
                << p->status << " | "
                << p->umur << " tahun" << endl;
        }
    }
}

// create tim
void tambahTim(Tim *daftarTim, int *jumlahTim) {
    if (*jumlahTim >= MAX) {
        cout << "Kapasitas tim penuh!\n";
        return;
    }

    cin.ignore();
    Tim *t = &(*(daftarTim + *jumlahTim));

    cout << "Masukkan nama tim: ";
    getline(cin, t->namaTim);

    t->jumlahPlayer = 0;
    (*jumlahTim)++;

    cout << "Tim berhasil ditambahkan." << endl;
}

//  create player
void tambahPlayer(Tim *daftarTim, int *jumlahTim) {
    if (*jumlahTim == 0) {
        cout << "Belum Ada Data Tim"<< endl;
        return;
    }

    int pilihTim;

    cout << "Daftar Tim:" << endl;
    for (int i = 0; i < *jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih Nomor Tim: ";
    cin >> pilihTim;
    pilihTim--;

    Tim *t = &(*(daftarTim + pilihTim));

    if (t->jumlahPlayer >= MAX) {
        cout << "Player Sudah Penuh!" << endl;
        return;
    }

    Player *p = &(*(t->daftarPlayer + t->jumlahPlayer));

    cin.ignore(); 

    cout << "Nickname: ";
    getline(cin, p->nickname);
    cout << "Role: ";
    getline(cin, p->role);
    cout << "Nationality: ";
    cin >> p->nationality;
    cout << "Status: ";
    cin >> p->status;
    cout << "Umur: ";
    cin >> p->umur;

    t->jumlahPlayer++;

    cout << "Player Berhasil Ditambahkan." << endl;
}

// update player
void updatePlayer(Tim *daftarTim, int *jumlahTim) {
    if (*jumlahTim == 0) {
        cout << "Belum Ada Data Tim." << endl;
        return;
    }

    int pilihTim, pilihPlayer;

    for (int i = 0; i < *jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih Nomor Tim: ";
    cin >> pilihTim;
    pilihTim--;

    Tim *t = &(*(daftarTim + pilihTim));

    for (int j = 0; j < t->jumlahPlayer; j++) {
        cout << j+1 << ". " << (t->daftarPlayer + j)->nickname << endl;
    }

    cout << "Pilih Nomor Player: ";
    cin >> pilihPlayer;
    pilihPlayer--;

    Player *p = &(*(t->daftarPlayer + pilihPlayer));

    cin.ignore();

    cout << "Nickname Baru: ";
    getline(cin, p->nickname);
    cout << "Role Baru: ";
    getline(cin, p->role);
    cout << "Nationality Baru: ";
    cin >> p->nationality;
    cout << "Status Baru: ";
    cin >> p->status;
    cout << "Umur Baru: ";
    cin >> p->umur;

    cout << "Data Berhasil Diupdate." << endl;
}

// delete player
void hapusPlayer(Tim *daftarTim, int *jumlahTim) {
    if (*jumlahTim == 0) {
        cout << "Belum Ada Data Tim." << endl;
        return;
    }

    int pilihTim, pilihPlayer;

    for (int i = 0; i < *jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih Nomor Tim: ";
    cin >> pilihTim;
    pilihTim--;

    Tim *t = &(*(daftarTim + pilihTim));

    for (int j = 0; j < t->jumlahPlayer; j++) {
        cout << j+1 << ". " << (t->daftarPlayer + j)->nickname << endl;
    }

    cout << "Pilih Nomor Player: ";
    cin >> pilihPlayer;
    pilihPlayer--;

    for (int j = pilihPlayer; j < t->jumlahPlayer - 1; j++) {
        *(t->daftarPlayer + j) = *(t->daftarPlayer + j + 1);
    }

    t->jumlahPlayer--;

    cout << "Player Berhasil Dihapus." << endl;
}

// delete player
void hapusTim(Tim *daftarTim, int *jumlahTim) {
    if (*jumlahTim == 0) {
        cout << "Belum Ada Data Tim." << endl;
        return;
    }

    int hapus;

    for (int i = 0; i < *jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih Nomor Tim: ";
    cin >> hapus;
    hapus--;

    for (int i = hapus; i < *jumlahTim - 1; i++) {
        *(daftarTim+i) = *(daftarTim+i+1);
    }

    (*jumlahTim)--;

    cout << "Tim Berhasil Dihapus." << endl;
}

//sorting

// Bubble Sort Nama Tim
void sortNamaTimAsc(Tim *daftarTim, int jumlahTim) {
    for (int i = 0; i < jumlahTim - 1; i++) {
        for (int j = 0; j < jumlahTim - i - 1; j++) {
            if ((daftarTim+j)->namaTim > (daftarTim+j+1)->namaTim) {
                swap(*(daftarTim+j), *(daftarTim+j+1));
            }
        }
    }

    cout << "\n=== HASIL SORT NAMA TIM ===\n";
    lihatTim(daftarTim, &jumlahTim);
}

// Insertion Sort Player
void sortPlayerAsc(Tim *daftarTim, int jumlahTim) {
    int pilih;

    cout << "Pilih Nomor Tim:" << endl;
    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }
    cout << "Pilih Nomor Tim: ";
    cin >> pilih;
    pilih--;

    Tim *t = &(*(daftarTim + pilih));

    for (int i = 1; i < t->jumlahPlayer; i++) {
        Player key = *(t->daftarPlayer + i);
        int j = i - 1;

        while (j >= 0 && (t->daftarPlayer+j)->nickname > key.nickname) {
            *(t->daftarPlayer+j+1) = *(t->daftarPlayer+j);
            j--;
        }

        *(t->daftarPlayer+j+1) = key;
    }

    cout << "\n=== HASIL SORT PLAYER ===\n";
    lihatTim(daftarTim, &jumlahTim);
}

// Selection Sort Umur
void sortUmurDesc(Tim *daftarTim, int jumlahTim) {
    int pilih;

    cout << "Pilih Nomor Tim:" << endl;
    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih Nomor Tim: ";
    cin >> pilih;
    pilih--;

    Tim *t = &(*(daftarTim + pilih));

    for (int i = 0; i < t->jumlahPlayer - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < t->jumlahPlayer; j++) {
            if ((t->daftarPlayer+j)->umur > (t->daftarPlayer+maxIndex)->umur) {
                maxIndex = j;
            }
        }

        swap(*(t->daftarPlayer+i), *(t->daftarPlayer+maxIndex));
    }

    cout << "\n=== HASIL SORT UMUR ===\n";
    lihatTim(daftarTim, &jumlahTim);
}

// main program
int main() {

    while (kesempatan > 0) {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (login(username, password)) {
            cout << "Login berhasil! Selamat Datang!" << endl;
            break;
        } else {
            kesempatan--;
            cout << "Login gagal. Sisa kesempatan: " << kesempatan << endl;
        }
    }

    if (kesempatan == 0) return 0;

    Tim daftarTim[MAX];
    int jumlahTim = 0;
    int menu;

    do {
        cout << "\n=== MENU MANAJEMEN ROSTER MPL ===" << endl;
        cout << "1. Lihat Tim dan Player" << endl;
        cout << "2. Tambah Tim" << endl;
        cout << "3. Tambah Player" << endl;
        cout << "4. Update Player" << endl;
        cout << "5. Hapus Player" << endl;
        cout << "6. Hapus Tim" << endl;
        cout << "7. Sort Nama Tim" << endl;
        cout << "8. Sort Player" << endl;
        cout << "9. Sort Umur" << endl;
        cout << "10. Keluar" << endl;
        cout << "Pilih: ";
        cin >> menu;

        switch(menu) {
            case 1: lihatTim(daftarTim, &jumlahTim);
            break;
            case 2: tambahTim(daftarTim, &jumlahTim);
            break;
            case 3: tambahPlayer(daftarTim, &jumlahTim);
            break;
            case 4: updatePlayer(daftarTim, &jumlahTim); 
            break;
            case 5: hapusPlayer(daftarTim, &jumlahTim); 
            break;
            case 6: hapusTim(daftarTim, &jumlahTim);
            break;
            case 7: sortNamaTimAsc(daftarTim, jumlahTim); 
            break;
            case 8: sortPlayerAsc(daftarTim, jumlahTim); 
            break;
            case 9: sortUmurDesc(daftarTim, jumlahTim); 
            break;
        }

    } while(menu != 10);

    return 0;
}