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
};

struct Tim {
    string namaTim;
    Player daftarPlayer[MAX];
    int jumlahPlayer;
};

bool login(string username, string password){
    return (username == "ulung" && password == "051");
}

// read tim dan player
void lihatTim(Tim *daftarTim, int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada data tim." << endl;
        return;
    }

    for (int i = 0; i < jumlahTim; i++) {
        cout << "\nTim " << i+1 << ": " << (daftarTim+i)->namaTim << endl;

        for (int j = 0; j < (daftarTim+i)->jumlahPlayer; j++) {
            cout << j+1 << ". "
                << (daftarTim+i)->daftarPlayer[j].nickname << " | "
                << (daftarTim+i)->daftarPlayer[j].role << " | "
                << (daftarTim+i)->daftarPlayer[j].nationality << " | "
                << (daftarTim+i)->daftarPlayer[j].status << endl;
        }
    }
}

// create tim
void tambahTim(Tim *daftarTim, int *jumlahTim) {
    if (*jumlahTim >= MAX) {
        cout << "Kapasitas tim penuh!" << endl;
        return;
    }

    cout << "Masukkan nama tim: ";
    cin.ignore();
    getline(cin, (daftarTim + *jumlahTim)->namaTim);

    (daftarTim + *jumlahTim)->jumlahPlayer = 0;

    (*jumlahTim)++; 

    cout << "Tim berhasil ditambahkan." << endl;
}

// create player
void tambahPlayer(Tim *daftarTim, int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada tim." << endl;
        return;
    }

    int pilihTim;

    cout << "Daftar Tim:" << endl;
    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih nomor tim: ";
    cin >> pilihTim;
    pilihTim--;

    Tim *timDipilih = (daftarTim + pilihTim);

    if (timDipilih->jumlahPlayer >= MAX) {
        cout << "Player sudah penuh." << endl;
        return;
    }

    int index = timDipilih->jumlahPlayer;

    cout << "Nickname: ";
    cin >> (timDipilih->daftarPlayer + index)->nickname;
    cout << "Role: ";
    cin >> (timDipilih->daftarPlayer + index)->role;
    cout << "Nationality: ";
    cin >> (timDipilih->daftarPlayer + index)->nationality;
    cout << "Status: ";
    cin >> (timDipilih->daftarPlayer + index)->status;

    timDipilih->jumlahPlayer++;

    cout << "Player berhasil ditambahkan." << endl;
}

// update player
void updatePlayer(Tim *daftarTim, int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada tim." << endl;
        return;
    }

    int pilihTim, pilihPlayer;

    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih tim: ";
    cin >> pilihTim;
    pilihTim--;

    Tim *timDipilih = (daftarTim + pilihTim);

    for (int j = 0; j < timDipilih->jumlahPlayer; j++) {
        cout << j+1 << ". " << (timDipilih->daftarPlayer + j)->nickname << endl;
    }

    cout << "Pilih player: ";
    cin >> pilihPlayer;
    pilihPlayer--;

    Player *playerDipilih = (timDipilih->daftarPlayer + pilihPlayer);

    cout << "Nickname baru: ";
    cin >> playerDipilih->nickname;
    cout << "Role baru: ";
    cin >> playerDipilih->role;
    cout << "Nationality baru: ";
    cin >> playerDipilih->nationality;
    cout << "Status baru: ";
    cin >> playerDipilih->status;

    cout << "Data berhasil diupdate." << endl;
}

// delete player
void hapusPlayer(Tim *daftarTim, int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada tim." << endl;
        return;
    }

    int pilihTim, pilihPlayer;

    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih tim: ";
    cin >> pilihTim;
    pilihTim--;

    Tim *timDipilih = (daftarTim + pilihTim);

    for (int j = 0; j < timDipilih->jumlahPlayer; j++) {
        cout << j+1 << ". " << (timDipilih->daftarPlayer + j)->nickname << endl;
    }

    cout << "Pilih player yang dihapus: ";
    cin >> pilihPlayer;
    pilihPlayer--;

    for (int j = pilihPlayer; j < timDipilih->jumlahPlayer - 1; j++) {
        *(timDipilih->daftarPlayer + j) = *(timDipilih->daftarPlayer + j + 1);
    }

    timDipilih->jumlahPlayer--;

    cout << "Player berhasil dihapus." << endl;
}

// delete tim
void hapusTim(Tim *daftarTim, int *jumlahTim) {
    if (*jumlahTim == 0) {
        cout << "Belum ada tim." << endl;
        return;
    }

    int hapus;

    for (int i = 0; i < *jumlahTim; i++) {
        cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
    }

    cout << "Pilih tim yang dihapus: ";
    cin >> hapus;
    hapus--;

    for (int i = hapus; i < *jumlahTim - 1; i++) {
        *(daftarTim+i) = *(daftarTim+i+1);
    }

    (*jumlahTim)--;

    cout << "Tim berhasil dihapus." << endl;
}

// main program
int main() {
    while (kesempatan > 0) {
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;

        if (login(username, password)) {
            cout << "Login berhasil! Selamat Datang!\n";
            break;
        } else {
            kesempatan--;
            cout << "Login gagal. Sisa kesempatan: " << kesempatan << endl;
        }
    }

    if (kesempatan == 0) {
        cout << "Program berhenti." << endl;
        return 0;
    }

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
        cout << "7. Keluar" << endl;
        cout << "Pilih: ";
        cin >> menu;

        switch(menu) {

            case 1:
                lihatTim(daftarTim, jumlahTim);
                break;

            case 2:
                tambahTim(daftarTim, &jumlahTim); 
                break;

            case 3:
                tambahPlayer(daftarTim, jumlahTim);
                break;

            case 4:
                updatePlayer(daftarTim, jumlahTim);
                break;

            case 5:
                hapusPlayer(daftarTim, jumlahTim);
                break;

            case 6:
                hapusTim(daftarTim, &jumlahTim); 
                break;
        }

    } while(menu != 7);
}