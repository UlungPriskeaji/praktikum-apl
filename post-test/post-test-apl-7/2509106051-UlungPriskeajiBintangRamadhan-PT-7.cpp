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
    try {
        if (*jumlahTim == 0)
            throw "Belum Ada Data Tim."; 

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
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

// create tim
void tambahTim(Tim *daftarTim, int *jumlahTim) {
    try {
        if (*jumlahTim >= MAX)
            throw "Kapasitas tim penuh!";

        cin.ignore();
        Tim *t = &(*(daftarTim + *jumlahTim));

        cout << "Masukkan nama tim: ";
        getline(cin, t->namaTim);

        if (t->namaTim.empty())
            throw "Nama tim tidak boleh kosong!";

        t->jumlahPlayer = 0;
        (*jumlahTim)++;

        cout << "Tim berhasil ditambahkan.\n";
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

//  create player
void tambahPlayer(Tim *daftarTim, int *jumlahTim) {
    try {
        if (*jumlahTim == 0)
            throw "Belum Ada Data Tim.";

        int pilihTim;

        cout << "Daftar Tim:\n";
        for (int i = 0; i < *jumlahTim; i++)
            cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;

        cout << "Pilih Nomor Tim: ";
        cin >> pilihTim;

        if (cin.fail()) throw "Input harus angka!";
        pilihTim--;

        if (pilihTim < 0 || pilihTim >= *jumlahTim)
            throw "Pilihan tim tidak valid!";

        Tim *t = &(*(daftarTim + pilihTim));

        if (t->jumlahPlayer >= MAX)
            throw "Player sudah penuh!";

        Player *p = &(*(t->daftarPlayer + t->jumlahPlayer));

        cin.ignore();
        cout << "Nickname: "; 
        getline(cin, p->nickname);

        if (p->nickname.empty())
            throw "Nickname tidak boleh kosong!";

        cout << "Role: "; 
        getline(cin, p->role);

        if (p->role.empty())
            throw "Role tidak boleh kosong!";

        cout << "Nationality: "; 
        cin >> p->nationality;

        if (p->nationality.empty())
            throw "Nationality tidak boleh kosong!";

        cout << "Status: "; 
        cin >> p->status;

        if (p->status.empty())
            throw "Status tidak boleh kosong!";

        cout << "Umur: "; 
        cin >> p->umur;

        if (cin.fail()) throw "Umur harus angka!";

        t->jumlahPlayer++;

        cout << "Player berhasil ditambahkan.\n";
    } catch (const char* e) {
        cout << "Error: " << e << endl;
        cin.clear(); 
        cin.ignore(1000,'\n');
    }
}

// update player
void updatePlayer(Tim *daftarTim, int *jumlahTim) {
    try {
        if (*jumlahTim == 0)
            throw "Belum Ada Data Tim.";

        int pilihTim, pilihPlayer;

        for (int i = 0; i < *jumlahTim; i++)
            cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;

        cout << "Pilih Tim: ";
        cin >> pilihTim;

        if (cin.fail()) throw "Input harus angka!";
        pilihTim--;

        if (pilihTim < 0 || pilihTim >= *jumlahTim)
            throw "Tim tidak valid!";

        Tim *t = &(*(daftarTim + pilihTim));

        if (t->jumlahPlayer == 0)
            throw "Belum ada player!";

        for (int j = 0; j < t->jumlahPlayer; j++)
            cout << j+1 << ". " << (t->daftarPlayer+j)->nickname << endl;

        cout << "Pilih Player: ";
        cin >> pilihPlayer;

        if (cin.fail()) throw "Input harus angka!";
        pilihPlayer--;

        if (pilihPlayer < 0 || pilihPlayer >= t->jumlahPlayer)
            throw "Player tidak valid!";

        Player *p = &(*(t->daftarPlayer + pilihPlayer));

        cin.ignore();

        cout << "Nickname Baru: ";
        getline(cin, p->nickname);
        if (p->nickname.empty())
            throw "Nickname tidak boleh kosong!";

        cout << "Role Baru: ";
        getline(cin, p->role);
        if (p->role.empty())
            throw "Role tidak boleh kosong!";

        cout << "Nationality Baru: ";
        cin >> p->nationality;
        if (p->nationality.empty())
            throw "Nationality tidak boleh kosong!";

        cout << "Status Baru: ";
        cin >> p->status;
        if (p->status.empty())
            throw "Status tidak boleh kosong!";

        cout << "Umur Baru: ";
        cin >> p->umur;

        if (cin.fail()) throw "Umur harus angka!";

        cout << "Data berhasil diupdate.\n";
    } catch (const char* e) {
        cout << "Error: " << e << endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

// delete player
void hapusPlayer(Tim *daftarTim, int *jumlahTim) {
    try {
        if (*jumlahTim == 0)
            throw "Belum Ada Data Tim.";

        int pilihTim, pilihPlayer;

        for (int i = 0; i < *jumlahTim; i++)
            cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;

        cout << "Pilih Tim: ";
        cin >> pilihTim; pilihTim--;

        if (pilihTim < 0 || pilihTim >= *jumlahTim)
            throw "Tim tidak valid!";

        Tim *t = &(*(daftarTim + pilihTim));

        if (t->jumlahPlayer == 0)
            throw "Tidak ada player!";

        for (int j = 0; j < t->jumlahPlayer; j++)
            cout << j+1 << ". " << (t->daftarPlayer+j)->nickname << endl;

        cout << "Pilih Player: ";
        cin >> pilihPlayer; pilihPlayer--;

        if (pilihPlayer < 0 || pilihPlayer >= t->jumlahPlayer)
            throw "Player tidak valid!";

        for (int j = pilihPlayer; j < t->jumlahPlayer - 1; j++)
            *(t->daftarPlayer + j) = *(t->daftarPlayer + j + 1);

        t->jumlahPlayer--;

        cout << "Player berhasil dihapus.\n";
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

// delete tim
void hapusTim(Tim *daftarTim, int *jumlahTim) {
    try {
        if (*jumlahTim == 0)
            throw "Belum Ada Data Tim.";

        int hapus;

        for (int i = 0; i < *jumlahTim; i++)
            cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;

        cout << "Pilih Tim: ";
        cin >> hapus; hapus--;

        if (hapus < 0 || hapus >= *jumlahTim)
            throw "Tim tidak valid!";

        for (int i = hapus; i < *jumlahTim - 1; i++)
            *(daftarTim+i) = *(daftarTim+i+1);

        (*jumlahTim)--;

        cout << "Tim berhasil dihapus.\n";
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

//sorting

// Bubble Sort Nama Tim
void sortNamaTimAsc(Tim *daftarTim, int jumlahTim) {
    try {
        if (jumlahTim == 0) throw "Belum ada tim!";

        for (int i = 0; i < jumlahTim-1; i++)
            for (int j = 0; j < jumlahTim-i-1; j++)
                if ((daftarTim+j)->namaTim > (daftarTim+j+1)->namaTim)
                    swap(*(daftarTim+j), *(daftarTim+j+1));

        cout << "\n=== HASIL SORT NAMA TIM ===\n";
        lihatTim(daftarTim, &jumlahTim);
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}


// Insertion Sort Player
void sortPlayerAsc(Tim *daftarTim, int jumlahTim) {
    try {
        if (jumlahTim == 0) throw "Belum ada tim!";

        int pilih;
        cout << "Pilih Tim:\n";
        for (int i = 0; i < jumlahTim; i++)
            cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;

        cin >> pilih;
        if (cin.fail()) throw "Input harus angka!";
        pilih--;

        if (pilih < 0 || pilih >= jumlahTim) throw "Tim tidak valid!";

        Tim *t = &(*(daftarTim + pilih));

        if (t->jumlahPlayer == 0) throw "Tidak ada player!";

        for (int i = 1; i < t->jumlahPlayer; i++) {
            Player key = *(t->daftarPlayer+i);
            int j = i-1;

            while (j >= 0 && (t->daftarPlayer+j)->nickname > key.nickname) {
                *(t->daftarPlayer+j+1) = *(t->daftarPlayer+j);
                j--;
            }
            *(t->daftarPlayer+j+1) = key;
        }

        cout << "\n=== HASIL SORT PLAYER ===\n";
        lihatTim(daftarTim, &jumlahTim);
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

// Selection Sort Umur
void sortUmurDesc(Tim *daftarTim, int jumlahTim) {
    try {
        if (jumlahTim == 0) throw "Belum ada tim!";

        int pilih;
        cout << "Pilih Tim:\n";
        for (int i = 0; i < jumlahTim; i++)
            cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;

        cin >> pilih;
        if (cin.fail()) throw "Input harus angka!";
        pilih--;

        if (pilih < 0 || pilih >= jumlahTim) throw "Tim tidak valid!";

        Tim *t = &(*(daftarTim + pilih));

        if (t->jumlahPlayer == 0) throw "Tidak ada player!";

        for (int i = 0; i < t->jumlahPlayer-1; i++) {
            int maxIndex = i;
            for (int j = i+1; j < t->jumlahPlayer; j++)
                if ((t->daftarPlayer+j)->umur > (t->daftarPlayer+maxIndex)->umur)
                    maxIndex = j;

            swap(*(t->daftarPlayer+i), *(t->daftarPlayer+maxIndex));
        }

        cout << "\n=== HASIL SORT UMUR ===\n";
        lihatTim(daftarTim, &jumlahTim);
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}


// searching
// linear search nama player
void cariNamaPlayer(Tim *daftarTim, int jumlahTim) {
    try {
        if (jumlahTim == 0) throw "Belum ada tim!";

        string cari;
        cin.ignore();
        cout << "Masukkan nama: ";
        getline(cin, cari);

        bool ditemukan = false;

        for (int i = 0; i < jumlahTim; i++) {
            Tim *t = &(*(daftarTim+i));
            for (int j = 0; j < t->jumlahPlayer; j++) {
                if ((t->daftarPlayer+j)->nickname == cari) {
                    cout << "Ditemukan di tim: " << t->namaTim << endl;
                    ditemukan = true;
                }
            }
        }

        if (!ditemukan) throw "Player tidak ditemukan!";
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

// binary search umur player
void cariUmurPlayer(Tim *daftarTim, int jumlahTim) {
    try { 

        if (jumlahTim == 0) {
            throw "Belum Ada Data Tim."; 
        }

        int pilih, cari;

        cout << "Pilih Tim:" << endl;
        for (int i = 0; i < jumlahTim; i++) {
            cout << i+1 << ". " << (daftarTim+i)->namaTim << endl;
        }

        cout << "Pilih: ";
        cin >> pilih;

        if (cin.fail()) throw "Input harus angka!"; 

        pilih--;

        if (pilih < 0 || pilih >= jumlahTim)
            throw "Pilihan tim tidak valid!"; 

        Tim *t = &(*(daftarTim + pilih));

        if (t->jumlahPlayer == 0)
            throw "Tidak ada player dalam tim ini!"; 

        // sorting umur player terlebih dahulu menggunakan bubble sort(ascending)
        for (int i = 0; i < t->jumlahPlayer - 1; i++) {
            for (int j = 0; j < t->jumlahPlayer - i - 1; j++) {
                if ((t->daftarPlayer+j)->umur > (t->daftarPlayer+j+1)->umur) {
                    swap(*(t->daftarPlayer+j), *(t->daftarPlayer+j+1));
                }
            }
        }

        cout << "Masukkan Umur Yang Ingin Dicari: ";
        cin >> cari;

        if (cin.fail()) throw "Umur harus berupa angka!"; 

        int low = 0, high = t->jumlahPlayer - 1;
        bool ditemukan = false;

        while (low <= high) {
            int mid = (low + high) / 2;

            if ((t->daftarPlayer+mid)->umur == cari) {
                cout << "\nDitemukan:\n";
                ditemukan = true;

                int i = mid;

                // ke kiri
                while (i >= 0 && (t->daftarPlayer+i)->umur == cari) {
                    cout << (t->daftarPlayer+i)->nickname << " | "
                        << (t->daftarPlayer+i)->role << " | "
                        << (t->daftarPlayer+i)->umur << " tahun\n";
                    i--;
                }

                // ke kanan
                i = mid + 1;
                while (i < t->jumlahPlayer && (t->daftarPlayer+i)->umur == cari) {
                    cout << (t->daftarPlayer+i)->nickname << " | "
                        << (t->daftarPlayer+i)->role << " | "
                        << (t->daftarPlayer+i)->umur << " tahun\n";
                    i++;
                }

                break;
            }
            else if ((t->daftarPlayer+mid)->umur < cari) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (!ditemukan) {
            throw "Data Tidak Ditemukan.";
        }

    } catch (const char* e) { 
        cout << "Error: " << e << endl;
        cin.clear();              // reset status error
        cin.ignore(1000, '\n');   // buang sisa input
    }
}

// main program
int main() {

    try {
        while (kesempatan > 0) {
            cout << "Username: "; cin >> username;
            cout << "Password: "; cin >> password;

            if (login(username, password)) {
                cout << "Login Berhasil!\n";
                break;
            } else {
                kesempatan--;
                if (kesempatan == 0)
                    throw "Kesempatan login habis!";
                cout << "Login gagal. Sisa: " << kesempatan << endl;
            }
        }
    } catch (const char* e) {
        cout << e << endl;
        return 0;
    }

    Tim daftarTim[MAX];
    int jumlahTim = 0;
    int menu;

// // ALTER EGO
// daftarTim[jumlahTim].namaTim = "Alter Ego";
// daftarTim[jumlahTim].jumlahPlayer = 9;

// daftarTim[jumlahTim].daftarPlayer[0] = {"Nino","Explaner","Indonesia","Main",20};
// daftarTim[jumlahTim].daftarPlayer[1] = {"Reyy","Jungler","Indonesia","Main",20};
// daftarTim[jumlahTim].daftarPlayer[2] = {"Hijumee","Midlaner","Indonesia","Main",23};
// daftarTim[jumlahTim].daftarPlayer[3] = {"Arfy","Goldlaner","Indonesia","Main",21};
// daftarTim[jumlahTim].daftarPlayer[4] = {"alekk","Roamer","Indonesia","Main",21};
// daftarTim[jumlahTim].daftarPlayer[5] = {"Yazukee","Jungler","Indonesia","Sub",22};
// daftarTim[jumlahTim].daftarPlayer[6] = {"Cyruz","Midlaner","Indonesia","Sub",20};
// daftarTim[jumlahTim].daftarPlayer[7] = {"Xepher","Head Coach","Indonesia","Staff",29};
// daftarTim[jumlahTim].daftarPlayer[8] = {"Styx","Assistant Coach","Indonesia","Staff",23};

// jumlahTim++;

// ONIC
daftarTim[jumlahTim].namaTim = "ONIC";
daftarTim[jumlahTim].jumlahPlayer = 8;

daftarTim[jumlahTim].daftarPlayer[0] = {"Lutpiii","Explaner","Indonesia","Main",20};
daftarTim[jumlahTim].daftarPlayer[1] = {"Kairi","Jungler","Filipina","Main",21};
daftarTim[jumlahTim].daftarPlayer[2] = {"SANZ","Midlaner","Indonesia","Main",23};
daftarTim[jumlahTim].daftarPlayer[3] = {"Kelra","Goldlaner","Filipina","Main",21};
daftarTim[jumlahTim].daftarPlayer[4] = {"SamueL","Roamer","Indonesia","Sub",19};
daftarTim[jumlahTim].daftarPlayer[5] = {"Kiboy","Roamer","Indonesia","Main",23};
daftarTim[jumlahTim].daftarPlayer[6] = {"CW","Head Coach","Indonesia","Staff",25};
daftarTim[jumlahTim].daftarPlayer[7] = {"Paddington","Assistant Coach","Indonesia","Staff",24};

jumlahTim++;

// EVOS
daftarTim[jumlahTim].namaTim = "EVOS";
daftarTim[jumlahTim].jumlahPlayer = 10;

daftarTim[jumlahTim].daftarPlayer[0] = {"Luke","Explaner","Indonesia","Main",22};
daftarTim[jumlahTim].daftarPlayer[1] = {"Alberttt","Jungler","Indonesia","Main",22};
daftarTim[jumlahTim].daftarPlayer[2] = {"Treacky","Midlaner","Indonesia","Sub",20};
daftarTim[jumlahTim].daftarPlayer[3] = {"Erlan","Goldlaner","Indonesia","Main",20};
daftarTim[jumlahTim].daftarPlayer[4] = {"EgaTzy","Roamer","Indonesia","Sub",20};
daftarTim[jumlahTim].daftarPlayer[5] = {"Vell","Explaner","Indonesia","Sub",20};
daftarTim[jumlahTim].daftarPlayer[6] = {"Pheww","Midlaner","Filipina","Main",26};
daftarTim[jumlahTim].daftarPlayer[7] = {"Kyy","Roamer","Indonesia","Main",22};
daftarTim[jumlahTim].daftarPlayer[8] = {"VYN","Head Coach","Indonesia","Staff",25};
daftarTim[jumlahTim].daftarPlayer[9] = {"Bravo","Analyst","Indonesia","Staff",26};

jumlahTim++;


    do {
        cout << "\n=== MENU MANAJEMEN ROSTER MPL ===" << endl;
        cout << "1. Lihat Tim dan Player" << endl;
        cout << "2. Tambah Tim" << endl;
        cout << "3. Tambah Player" << endl;
        cout << "4. Update Player" << endl;
        cout << "5. Hapus Player" << endl;
        cout << "6. Hapus Tim" << endl;
        cout << "7. Sort Nama Tim(Ascending)" << endl;
        cout << "8. Sort Player(Ascending)" << endl;
        cout << "9. Sort Umur(Descending)" << endl;
        cout << "10. Cari Nama Player(Linear Search)" << endl;
        cout << "11. Cari Umur Player(Binary Search)" << endl;
        cout << "12. Keluar" << endl;
        cout << "Pilih: ";
        cin >> menu;

        try {
            if (cin.fail()) throw "Menu harus angka!";

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
            case 10: cariNamaPlayer(daftarTim, jumlahTim);
            break;
            case 11: cariUmurPlayer(daftarTim, jumlahTim); 
            break;
        }
    } catch (const char* e) {
        cout << "Error: " << e << endl;
        cin.clear(); cin.ignore(1000,'\n');
    }

    } while(menu != 12);
    return 0;
}
