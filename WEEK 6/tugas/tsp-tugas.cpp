#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Menggunakan pair karena mengembalikan dua nilai sekaligus yaitu biaya perjalanan minimum dan urutan kota terbaik yang ditemukan.
pair<int, vector<int>> tsp_brute_force(vector<vector<int>> &dist_matrix) {
    // Menyimpan baris dan jumlah kota dari matrik kedalam variabel n
    int n = dist_matrix.size();
    // Menyimpan urutan kota yang akan dikunjungi
    vector<int> kota(n);
    
    // Menginisialisasi urutan kota awal misal ada 4 kota, urutan awal akan menjadi 0, 1, 2, dan 3.
    for (int i = 0; i < n; ++i) {
        kota[i] = i;
    }
    
    // Menyimpan biaya perjalanan minimum yang ditemukan.
    int min_cost = INT_MAX;
    // Menyimpan urutan kota terbaik yang ditemukan.
    vector<int> best_path;
    // Loop do-while mencoba semua kemungkinan permutasi dari urutan kota.
    // Menghitung biaya perjalanan dari kota pertama ke kota terakhir dan kembali ke kota awal.
    do {
        int cost = 0;
        for (int i = 0; i < n - 1; ++i) {
            cost += dist_matrix[kota[i]][kota[i + 1]];
        }
        cost += dist_matrix[kota[n - 1]][kota[0]];
        // Memeriksa apakah biaya perjalanan saat ini lebih rendah dari min_cost
        // Jika ya, kita memperbarui min_cost dengan nilai biaya perjalanan saat ini dan best_path dengan urutan kota saat ini.
        if (cost < min_cost) {
            min_cost = cost;
            best_path = kota;
        }
    // Untuk menghasilkan permutasi berikutnya dari urutan kota.
    // Loop akan terus berjalan sampai semua kemungkinan permutasi telah dicoba.
    } while (next_permutation(kota.begin() + 1, kota.end()));
    
    // Mengembalikan pasangan nilai yang terdiri dari min_cost dan best_path.
    return {min_cost, best_path};
}

int main() {
    vector<vector<int>> dist_matrix = {
        //A  B  C  D
        {0, 10, 30, 25}, //A
        {10, 0, 20, 15}, //B
        {30, 20, 0, 35}, //C
        {25, 15, 35, 0}}; //D
    
    // Pemanggilan fungsi tsp_brute_force() dengan matriks dist_matrix.
    // Mengembalikan pasangan nilai yang terdiri dari biaya perjalanan minimum (int) dan urutan kota yang dilalui (vector<int>).
    pair<int, vector<int>> result = tsp_brute_force(dist_matrix);

    // Mencetak biaya perjalanan minimum dan Mencetak urutan kota
    cout << "Minimum Cost: " << result.first << endl;
    cout << "Kota yang dilalui (perjalanan) : ";
    
    // loop yang mencetak urutan kota yang dilalui yang berisi indeks kota yang dilalui, kemudian mencetaknya sebagai karakter. 
    // Menggunakan 'A' + i, kita mengonversi indeks kota menjadi karakter yang sesuai (misalnya, 0 menjadi 'A', 1 menjadi 'B', dst).
    for (int i : result.second) {
        cout << char('A' + i) << ' ';
    }
    // Mencetak kembali kota awal 'A', menandakan bahwa rute telah kembali ke kota asal setelah mengunjungi semua kota.
    cout << 'A' << endl;
    
    return 0;
}