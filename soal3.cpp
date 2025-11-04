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
//Masukkan jawaban disini
