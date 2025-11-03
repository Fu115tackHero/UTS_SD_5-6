//Masukkan jawaban disini#include <iostream>
using namespace std;

// Fungsi untuk melakukan rotasi kiri pada array
void rotateLeft(int arr[], int n, int d) {
    // Pastikan jumlah rotasi tidak lebih besar dari ukuran array
    d = d % n;  

    // Lakukan rotasi sebanyak d kali
    for (int i = 0; i < d; i++) {
        int temp = arr[0]; // Simpan elemen pertama
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1]; // Geser semua elemen ke kiri
        }
        arr[n - 1] = temp; // Letakkan elemen pertama di posisi paling kanan
    }
}

int main() {
    int n, d;

    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;

    int arr[n];

    // Input elemen-elemen array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Panggil fungsi rotasi kiri
    rotateLeft(arr, n, d);

    // Tampilkan hasil array setelah dirotasi
    cout << "Hasil rotasi: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
=====================
PENJELASAN ALGORITMA
=====================

1 Program meminta dua input pertama: 
   - n = jumlah elemen array
   - d = banyaknya rotasi kiri yang akan dilakukan

2 Kemudian program membaca n elemen array dari pengguna.

3 Fungsi rotateLeft() melakukan proses rotasi sebanyak d kali:
   - Setiap rotasi:
     a. Simpan elemen pertama (arr[0]) ke variabel sementara `temp`.
     b. Geser semua elemen satu langkah ke kiri:
        contoh: [1,2,3,4,5] → [2,3,4,5,?]
     c. Masukkan nilai `temp` ke posisi terakhir.
        hasil akhir setelah 1 rotasi: [2,3,4,5,1]

4 Proses ini diulang sebanyak d kali.

5 Setelah selesai, array hasil rotasi dicetak ke layar.

==========================================================
CONTOH:
Input:
5 4
1 2 3 4 5

Proses rotasi kiri 4 kali menghasilkan:
5 1 2 3 4

==========================================================
Kompleksitas:
- Waktu: O(n * d)
- Ruang tambahan: O(1)
==========================================================
*/
