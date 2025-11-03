#include<iostream>
#include <string>
#include <queue>
using namespace std;


int main (){
    queue<string> antrian_utama;
    queue<string> antrian_darurat;
    string perintah;
    string nama_pasien;
    string pasien_dilayani;
    int n;

    cout << "Masukan jumlah perintah: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Masukan perintah (DATANG ,DARURAT ,dan LAYANI) dan nama pasien" << endl;
        cin >> perintah;

        for (char &c : perintah) {
            c = toupper(c);
        }

        if (perintah == "DATANG"){
            cin >> nama_pasien;
            antrian_utama.push(nama_pasien);
        } else if (perintah == "DARURAT"){
            cin >> nama_pasien;
            antrian_darurat.push(nama_pasien);
        } else if (perintah == "LAYANI") {
            if (!antrian_darurat.empty()) {
                pasien_dilayani = antrian_darurat.front();
                antrian_darurat.pop();
                cout <<pasien_dilayani << " Dari antrian darurat" << endl;             
            } else if (!antrian_utama.empty()) {
                pasien_dilayani = antrian_utama.front();
                antrian_utama.pop();
                cout << pasien_dilayani << " Dari antrian normal" << endl;          
            } else {
                cout << "tidak ada pasien di antrian." << endl;
            }
        } else {
            cout << "Perintah tidak Valid" << endl;
            i--;
        }
    }
    cout <<"Program Sudah Selesai";
    return 0;
}
/*
===========================
Penjelasan Algoritma
===========================
Program ini berifat case insensitive yang dimana tidak dipengaruhi huruf besar dan kecil dimana digunakan di bagian input perintah.

Pertama Program akan meminta input jumlah perintah yang akan dijalankan.
Kedua Program melakukan pengulangan sesuai dengan inputan jumlah perintah.
Ketiga Program akan menyuruh kita memasukan perintah dan nama pasien.
Keempat Program mengubah kata perintah menjadi Huruf besar semuar agar menjadi case insensitive.
Kelima Program akan menjalankan program sesuai perintah:
    a.Jika Datang maka program akan memasukan nama_pasien ke belakang antrian utama.
    b.Jika Darurat maka program akan memasukan nama_pasien ke belakang antrian darurat.
    c.Jika Layani program akan melayani pasien dari antrian darurat dulu dan jika tidak ada atau sudah habis maka program akan melayani pasien dari antrian utama.
    d.Jika perintah yang diinput bukan Datang ,Darurat ,atau Layani maka akan muncul output tulisan Perintah tidak valid.
Keenam Program akan selesai jika jumlah perintah udah sesuai dengan jumlah perintah yang diinput (Perintah yang tidak valid tidak dihitung).
*/
