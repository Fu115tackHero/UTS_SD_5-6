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
