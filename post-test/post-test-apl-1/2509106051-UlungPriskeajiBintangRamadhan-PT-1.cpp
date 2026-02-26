#include <iostream>
using namespace std;

string username;
string password;
int kesempatan;
int pilihan;

float jam;
float menit;
float detik;

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

    while (true) {
        cout << "MENU KONVERSI WAKTU!" << endl;
        cout << "1. Jam ke Menit dan Detik" << endl;
        cout << "2. Menit ke Jam dan Detik" << endl;
        cout << "3. Detik ke Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih Menu: 1-4: ";

        cin >> pilihan;
        if (pilihan == 1) {
            cout << "Masukkan Jam: ";
            cin >> jam;
            menit = jam * 60;
            detik = jam * 3600;
            cout << jam << " Jam = " << menit << " Menit = " << detik << " Detik\n" << endl;
        } else if (pilihan == 2) {
            cout << "Masukkan Menit: ";
            cin >> menit;
            jam = menit / 60;
            detik = menit * 60;
            cout << menit << " Menit = " << jam << " Jam = " << detik << " Detik\n" << endl;
        } else if (pilihan == 3) {
            cout << "Masukkan Detik: ";
            cin >> detik;
            jam = detik / 3600;
            menit = detik / 60;
            cout << detik << " Detik = " << jam << " Jam = " << menit << " Menit\n" << endl;
        } else if (pilihan == 4) {
            cout << "Terima Kasih Sudah Menggunakan Program Ini!" << endl;
            break;
        } else {
            cout << "Pilihan Tidak Valid! Coba Lagi" << endl;
        }
    }
}
