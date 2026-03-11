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
    if(username == "ulung" && password == "051"){
        return true;
    }else{
        return false;
    }
}

// prosedur lihat tim dan player wok
void lihatTim(Tim daftarTim[], int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada data tim." << endl;
        return;
    }

    for (int i = 0; i < jumlahTim; i++) {
        cout << "\nTim " << i+1 << ": " << daftarTim[i].namaTim << endl;

        for (int j = 0; j < daftarTim[i].jumlahPlayer; j++) {
            cout << j+1 << ". "
                << daftarTim[i].daftarPlayer[j].nickname << " | "
                << daftarTim[i].daftarPlayer[j].role << " | "
                << daftarTim[i].daftarPlayer[j].nationality << " | "
                << daftarTim[i].daftarPlayer[j].status << endl;
        }
    }
}

// kalo ini tambah tim wok
int tambahTim(Tim daftarTim[], int jumlahTim) {
    if (jumlahTim >= MAX) {
        cout << "Kapasitas tim penuh!" << endl;
        return jumlahTim;
    }
    cout << "Masukkan nama tim: ";
    cin.ignore();
    getline(cin, daftarTim[jumlahTim].namaTim);
    daftarTim[jumlahTim].jumlahPlayer = 0;
    jumlahTim++;
    cout << "Tim berhasil ditambahkan." << endl;

    return jumlahTim;
}

// sama aja tapi ini buat tambah player ke tim yang udah ada wok
void tambahPlayer(Tim daftarTim[], int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada tim." << endl;
        return;
    }

    int pilihTim;

    cout << "Daftar Tim:" << endl;
    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << daftarTim[i].namaTim << endl;
    }
    cout << "Pilih nomor tim: ";
    cin >> pilihTim;
    pilihTim--;
    if (daftarTim[pilihTim].jumlahPlayer >= MAX) {
        cout << "Player sudah penuh." << endl;
        return;
    }
    int index = daftarTim[pilihTim].jumlahPlayer;
    cout << "Nickname: ";
    cin >> daftarTim[pilihTim].daftarPlayer[index].nickname;
    cout << "Role: ";
    cin >> daftarTim[pilihTim].daftarPlayer[index].role;
    cout << "Nationality: ";
    cin >> daftarTim[pilihTim].daftarPlayer[index].nationality;
    cout << "Status: ";
    cin >> daftarTim[pilihTim].daftarPlayer[index].status;
    daftarTim[pilihTim].jumlahPlayer++;
    cout << "Player berhasil ditambahkan." << endl;
}

// ini buat update data player yang udah ada wok, jadi bisa ganti nickname, role, dll.
void updatePlayer(Tim daftarTim[], int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada tim." << endl;
        return;
    }
    int pilihTim, pilihPlayer;

    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << daftarTim[i].namaTim << endl;
    }
    cout << "Pilih tim: ";
    cin >> pilihTim;
    pilihTim--;

    for (int j = 0; j < daftarTim[pilihTim].jumlahPlayer; j++) {
        cout << j+1 << ". " << daftarTim[pilihTim].daftarPlayer[j].nickname << endl;
    }
    cout << "Pilih player: ";
    cin >> pilihPlayer;
    pilihPlayer--;
    cout << "Nickname baru: ";
    cin >> daftarTim[pilihTim].daftarPlayer[pilihPlayer].nickname;
    cout << "Role baru: ";
    cin >> daftarTim[pilihTim].daftarPlayer[pilihPlayer].role;
    cout << "Nationality baru: ";
    cin >> daftarTim[pilihTim].daftarPlayer[pilihPlayer].nationality;
    cout << "Status baru: ";
    cin >> daftarTim[pilihTim].daftarPlayer[pilihPlayer].status;
    cout << "Data berhasil diupdate." << endl;
}

// ini delete player yang ada di tim wok
void hapusPlayer(Tim daftarTim[], int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada tim." << endl;
        return;
    }

    int pilihTim, pilihPlayer;

    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << daftarTim[i].namaTim << endl;
    }
    cout << "Pilih tim: ";
    cin >> pilihTim;
    pilihTim--;

    for (int j = 0; j < daftarTim[pilihTim].jumlahPlayer; j++) {
        cout << j+1 << ". " << daftarTim[pilihTim].daftarPlayer[j].nickname << endl;
    }
    cout << "Pilih player yang dihapus: ";
    cin >> pilihPlayer;
    pilihPlayer--;

    for (int j = pilihPlayer; j < daftarTim[pilihTim].jumlahPlayer - 1; j++) {
        daftarTim[pilihTim].daftarPlayer[j] =
        daftarTim[pilihTim].daftarPlayer[j+1];
    }

    daftarTim[pilihTim].jumlahPlayer--;

    cout << "Player berhasil dihapus." << endl;
}

// ini untuk delete tim yang ada wok
int hapusTim(Tim daftarTim[], int jumlahTim) {
    if (jumlahTim == 0) {
        cout << "Belum ada tim." << endl;
        return jumlahTim;
    }
    int hapus;
    for (int i = 0; i < jumlahTim; i++) {
        cout << i+1 << ". " << daftarTim[i].namaTim << endl;
    }
    cout << "Pilih tim yang dihapus: ";
    cin >> hapus;
    hapus--;

    for (int i = hapus; i < jumlahTim - 1; i++) {
        daftarTim[i] = daftarTim[i+1];
    }

    jumlahTim--;

    cout << "Tim berhasil dihapus." << endl;
    return jumlahTim;
}

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
                jumlahTim = tambahTim(daftarTim, jumlahTim);
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
                jumlahTim = hapusTim(daftarTim, jumlahTim);
                break;
        }
    } while(menu != 7);
}