// #include <iostream>
// using namespace std;

// int main() {
//     cout << "Hello, World!" << endl;
//     cout << "Halo, Dunia!";
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
// int angka = 50;
// int *pAngka;
// // Pointer menyimpan alamat variabel angka
// pAngka = &angka;
// // Menampilkan nilai dan alamat
// cout << "Nilai variabel angka : " << angka << endl;
// cout << "Alamat variabel angka : " << &angka << endl;
// cout << "Alamat yang disimpan pointer : " << pAngka << endl;
// cout << "Nilai yang diakses melalui pointer : " << *pAngka << endl;
// return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
// int data[5] = {10, 20, 30, 40, 50};
// int *p = data; // Pointer menunjuk ke elemen pertama array
// // Pointer bergerak selama masih berada dalam batas array
// while (p < data + 5) {
// cout << "Nilai: " << *p << ", Alamat: " << p << endl;
// p++; // Maju ke elemen berikutnya
// }
// return 0;
// }

#include <iostream>
using namespace std;
struct Mahasiswa {
string nama;
int nim;
};
int main() {
Mahasiswa mhs1;
Mahasiswa *mhsPtr = &mhs1;
mhs1.nama = "Yunjin";
mhs1.nim = 321;
cout << mhs1.nama << " - " << mhs1.nim << endl;
mhsPtr->nama = "Chaewon";
mhsPtr->nim = 123;
cout << mhs1.nama << " - " << mhs1.nim << endl;
cout << mhsPtr->nama << " - " << mhsPtr->nim << endl;
return 0;
}