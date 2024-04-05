#include <stdio.h>

// Fungsi rekursif untuk pencarian biner
int binarySearch(int arr[], int low, int high, int key) {
  // Base case: jika low lebih besar dari high, artinya elemen  tidak ditemukan
  if (low > high)
    return -1;
  
  // Mencari nilai tengah
  int mid = low + (high - low) / 2;
  
  // Jika elemen tengah adalah kunci, maka kembalikan indeksnya
  if (arr[mid] == key)
    return mid;
  // Jika elemen tengah lebih kecil dari kunci, cari di bagian  kanan array
  else if (arr[mid] < key)
    return binarySearch(arr, mid + 1, high, key);
  // Jika elemen tengah lebih besar dari kunci, cari di bagian  kiri array
  else
    return binarySearch(arr, low, mid - 1, key);
}

int main() {
  int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 14;
  int result = binarySearch(arr, 0, n - 1, key);
  
  if (result == -1)
    printf("Elemen tidak ditemukan\n");
  else
    printf("Elemen ditemukan pada indeks %d\n", result);
    return 0;
}