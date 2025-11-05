#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int V, E;
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int S, K;
    cout << "Node Awal dan Hari Terinfeksi: ";
    cin >> S >> K;

    vector<bool> visited(V, false);
    queue<pair<int,int>> q;

    q.push({S, 0});
    visited[S] = true;

    vector<int> infectedDayK;

    while(!q.empty()){
        int curr = q.front().first;
        int day = q.front().second;
        q.pop();

        if(day == K) infectedDayK.push_back(curr);
        if(day > K) break;

        for(int next : graph[curr]){
            if(!visited[next]){
                visited[next] = true;
                q.push({next, day + 1});
            }
        }
    }

    cout << "Node terinfeksi: ";
    if(infectedDayK.empty()){
        cout << "(TIDAK ADA)";
    } else {
        sort(infectedDayK.begin(), infectedDayK.end());
        for(int x : infectedDayK) cout << x << " ";
    }
    cout << endl;

    return 0;
}
/*Program ini mensimulasikan penyebaran infeksi di dalam sebuah jaringan menggunakan metode Breadth-First Search (BFS).
Pertama, program memanggil beberapa pustaka seperti iostream, vector, queue, dan algorithm agar bisa melakukan input-output, menyimpan data, dan mengurutkan hasil. Kemudian pengguna diminta memasukkan jumlah vertex (titik) dan edge (sisi), yaitu jumlah node dan hubungan antar node.
Program membuat struktur adjacency list menggunakan vector<vector<int>> graph(V); untuk menyimpan siapa terhubung dengan siapa. Setiap pasangan u v yang dimasukkan menunjukkan bahwa node u terhubung dengan v, dan sebaliknya (graph[u].push_back(v) dan graph[v].push_back(u)), karena graf bersifat tidak berarah.
Setelah itu, program meminta node awal (S) dan hari ke-K (K). Node awal adalah titik yang pertama kali terinfeksi pada hari ke-0. Program menggunakan queue untuk menyimpan node yang sedang menularkan penyakit, bersama dengan hari infeksinya.
Proses BFS dimulai dari node awal. Setiap node yang terinfeksi akan menularkan ke semua tetangganya yang belum terinfeksi, dengan waktu infeksi bertambah satu hari. Jika ada node yang terinfeksi tepat pada hari ke-K, node tersebut disimpan dalam daftar infectedDayK.
Setelah semua proses selesai, program menampilkan node-node yang terinfeksi pada hari ke-K. Jika tidak ada, akan ditampilkan “(TIDAK ADA)”.
Singkatnya, program ini melacak penyebaran infeksi dari satu titik ke seluruh jaringan dan menunjukkan siapa saja yang terinfeksi tepat pada hari ke-K.*/    
