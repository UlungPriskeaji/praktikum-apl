#include <iostream>
#include <string>
using namespace std;

#define MAX 10

string username, password;
int kesempatan;

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

int main() {
    kesempatan = 3;
    while (kesempatan > 0) {
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;

        if (username == "ulung" && password == "051") {
            cout << "Login Berhasil! Selamat Datang!\n" << endl;
            break;
        } else {
            kesempatan--;
            cout << "Login Gagal! Username atau Password Salah! Kesempatan Tersisa: " << kesempatan << endl;
        }
    }

    if (kesempatan == 0) {
        cout << "Anda Telah Mencoba Login Sebanyak 3 Kali. Program Akan Berhenti." << endl;
        return 0;
    }


    Tim daftarTim[MAX];
    int jumlahTim = 0;
    int menu;

do {
    cout << "\n=== MENU MANAJEMEN ROSTER TIM E-SPORT MPL ===" << endl;
    cout << "1. Lihat Daftar Tim dan Player" << endl;
    cout << "2. Tambah Tim" << endl;
    cout << "3. Tambah Player ke Tim" << endl;
    cout << "4. Update Player" << endl;
    cout << "5. Hapus Player" << endl;
    cout << "6. Hapus Tim" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih Menu (1-7): ";
    cin >> menu;
    cin.ignore();

    switch (menu) {
        case 1:
            if (jumlahTim == 0) {
                cout << "Belum ada data tim." << endl;
            }
            else {
                for (int i = 0; i < jumlahTim; i++) {
                    cout << "\nTim: " << i+1 << ". " << daftarTim[i].namaTim << endl;
                    for (int j = 0; j < daftarTim[i].jumlahPlayer; j++) {
                        cout << j + 1 << ". "
                        << daftarTim[i].daftarPlayer[j].nickname << " | "
                        << daftarTim[i].daftarPlayer[j].role << " | "
                        << daftarTim[i].daftarPlayer[j].nationality << " | "
                        << daftarTim[i].daftarPlayer[j].status << endl;
                }
            }
        }
        break;

        case 2:
            if (jumlahTim < MAX) {
                cout << "Masukkan nama tim: ";
                getline(cin, daftarTim[jumlahTim].namaTim);
                daftarTim[jumlahTim].jumlahPlayer = 0;
                jumlahTim++;
                cout << "Tim berhasil ditambahkan." << endl;
            } else {
                cout << "Kapasitas tim penuh!" << endl;
            }
            break;

        case 3:
            if (jumlahTim == 0) {
                cout << "Belum Ada Tim." << endl;
            } else {
                int pilihTim;
                cout << "Daftar Tim:" << endl;
                for (int i = 0; i < jumlahTim; i++) {
                    cout << i + 1 << ". " << daftarTim[i].namaTim << endl;
                }
                cout << "Masukkan nomor tim: ";
                cin >> pilihTim;
                pilihTim--; 
                if (daftarTim[pilihTim].jumlahPlayer < MAX) {
                    int index = daftarTim[pilihTim].jumlahPlayer;
                    cout << "Nickname: ";
                    cin >> daftarTim[pilihTim].daftarPlayer[index].nickname;
                    cout << "Role: ";
                    cin >> daftarTim[pilihTim].daftarPlayer[index].role;
                    cout << "Nationality: ";
                    cin >> daftarTim[pilihTim].daftarPlayer[index].nationality;
                    cout << "Status (Main/Sub/Staff): ";
                    cin >> daftarTim[pilihTim].daftarPlayer[index].status;
                    daftarTim[pilihTim].jumlahPlayer++;
                    cout << "Player berhasil ditambahkan." << endl;
                } else {
                    cout << "Player sudah penuh." << endl;
                }
            }
            break;

        case 4:
            if (jumlahTim == 0) {
                cout << "Belum ada tim." << endl;
            } else {
                int pilihTim, pilihPlayer;
                for (int i = 0; i < jumlahTim; i++) {
                    cout << i + 1 << ". " << daftarTim[i].namaTim << endl;
                }
                cout << "Pilih tim: ";
                cin >> pilihTim;
                pilihTim--;
                for (int j = 0; j < daftarTim[pilihTim].jumlahPlayer; j++) {
                    cout << j + 1 << ". " << daftarTim[pilihTim].daftarPlayer[j].nickname << endl;
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
        break;

        case 5:
            if (jumlahTim == 0) {
                cout << "Belum ada tim." << endl;
            } else {
                int pilihTim, pilihPlayer;
                for (int i = 0; i < jumlahTim; i++) {
                    cout << i + 1 << ". " << daftarTim[i].namaTim << endl;
                }
                cout << "Pilih tim: ";
                cin >> pilihTim;
                pilihTim--;
                for (int j = 0; j < daftarTim[pilihTim].jumlahPlayer; j++) {
                    cout << j + 1 << ". " << daftarTim[pilihTim].daftarPlayer[j].nickname << endl;
                }
                cout << "Pilih player yang dihapus: ";
                cin >> pilihPlayer;
                pilihPlayer--;
                for (int j = pilihPlayer; j < daftarTim[pilihTim].jumlahPlayer - 1; j++) {
                    daftarTim[pilihTim].daftarPlayer[j] = daftarTim[pilihTim].daftarPlayer[j+1];
                }
                daftarTim[pilihTim].jumlahPlayer--;
                cout << "Player berhasil dihapus." << endl;
            }
        break;

        case 6:
            if (jumlahTim == 0) {
                cout << "Belum ada tim." << endl;
            } else {
                int hapus;
                for (int i = 0; i < jumlahTim; i++) {
                    cout << i + 1 << ". " << daftarTim[i].namaTim << endl;
                }
                cout << "Pilih tim yang dihapus: ";
                cin >> hapus;
                hapus--;
                for (int i = hapus; i < jumlahTim - 1; i++) {
                    daftarTim[i] = daftarTim[i+1];
                }
                jumlahTim--;
                cout << "Tim berhasil dihapus." << endl;
            }
        break;

        case 7:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Menu tidak tersedia." << endl;
        }
    } while(menu != 7);
}