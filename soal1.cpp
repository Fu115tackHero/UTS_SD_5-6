#include <iostream>
using namespace std;

void rotateLeft(int arr[], int n, int d, int result[]) {
    // 1. Pastikan jumlah rotasi tidak melebihi ukuran array
    d = d % n;

    int index = 0;

    // 2. Pindahkan elemen mulai dari posisi d sampai akhir ke depan
    for (int i = d; i < n; i++) {
        result[index] = arr[i];
        index++;
    }

    // 3. Lalu pindahkan bagian awal (0 sampai d-1) ke belakang
    for (int i = 0; i < d; i++) {
        result[index] = arr[i];
        index++;
    }
}

int main() {
    int n, d;

    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result[n];
    rotateLeft(arr, n, d, result);

    cout << "Hasil rotasi: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
===================
PENJELASAN PROGRAM 
===================


--------------------------
BAGIAN FUNGSI rotateLeft()
--------------------------
Fungsi ini menerima array asli (`arr`), jumlah elemen (`n`), dan banyak rotasi (`d`),
lalu menyusun array baru (`result`) berisi hasil rotasi.

Langkah-langkahnya:
1  d = d % n
     → Jika d lebih besar dari panjang array, kita hanya ambil sisa rotasinya.
        Contoh: n = 5, d = 7 → rotasi 7 kali sama dengan rotasi 2 kali.

2  Ambil elemen dari arr mulai indeks ke-d hingga akhir,
     lalu masukkan ke depan array hasil.
        Contoh:
        arr = [1, 2, 3, 4, 5], d = 2
        → ambil [3, 4, 5] → letakkan di awal result → result = [3, 4, 5]

3  Ambil sisa elemen dari awal (indeks 0 s.d d-1)
     dan letakkan di belakang.
        → ambil [1, 2] → tambahkan di akhir result → result = [3, 4, 5, 1, 2]

4️  Setelah dua langkah ini selesai, rotasi kiri selesai dilakukan.

-------------
BAGIAN main()
-------------
1 Program meminta input:
     - n (jumlah elemen)
     - d (jumlah rotasi kiri)
     - n buah angka untuk isi array

2 Panggil fungsi rotateLeft untuk melakukan perhitungan.

3 Cetak hasil array yang telah dirotasi ke layar.

------------------
CONTOH PEMROSESAN
------------------
Input:
5 4
1 2 3 4 5

Proses di rotateLeft():
- n = 5, d = 4
- Elemen dari indeks ke-4 sampai akhir → [5]
- Elemen dari indeks ke-0 sampai ke-3 → [1, 2, 3, 4]
- Gabungkan → [5, 1, 2, 3, 4]

Output:
Hasil rotasi: 5 1 2 3 4


*/
