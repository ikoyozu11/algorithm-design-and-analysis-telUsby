#include <stdio.h>

// Fungsi untuk  implementasi rekursif untuk menyelesaikan permasalahan Tower of Hanoi.
// Fungsi ini menerima empat parameter: n (jumlah gelang yang harus dipindahkan), dari_tiang (nomor tiang asal), tiang_bantuan (nomor tiang bantuan), dan tujuan (nomor tiang tujuan).
// Fungsi ini tidak mengembalikan nilai (void).
void towerOfHanoi(int n, int dari_tiang, int tiang_bantuan, int tujuan)
{
  // Mendeklarasikan array of pointer tiang yang berisi nama-nama tiang dengan indeks yang sesuai.
  // Ini akan digunakan untuk mencetak nama tiang dalam setiap langkah penyelesaian.
  char *tiang[] = {"Base of Power", "Tower of Triumph", "Booster Platform"};

  // Untuk memeriksa apakah hanya ada satu gelang yang perlu dipindahkan. Jika iya, maka cetak langkah untuk memindahkan gelang tersebut dan kembali dari rekursi.
  if (n == 1)
  {
    printf("Pindahkan gelang 1 dari %s ke %s\n", tiang[dari_tiang - 1], tiang[tiang_bantuan - 1]);
    return;
  }

  // Rekursi pada fungsi towerOfHanoi untuk memindahkan n - 1 gelang dari tiang asal ke tiang bantuan, dengan menukar posisi tiang bantuan dan tujuan.
  towerOfHanoi(n - 1, dari_tiang, tujuan, tiang_bantuan);
  // Mencetak langkah untuk memindahkan gelang n dari tiang asal ke tiang tujuan.
  printf("Pindahkan gelang %d dari %s ke %s\n", n, tiang[dari_tiang - 1], tiang[tiang_bantuan - 1]);
  // Rekursi pada fungsi towerOfHanoi untuk memindahkan n - 1 gelang dari tiang bantuan ke tiang tujuan, dengan menukar posisi tiang asal dan bantuan.
  towerOfHanoi(n - 1, tujuan, tiang_bantuan, dari_tiang);
}

// Program Utama
int main()
{
  // Pendeklarasian variable
  int T, round;

  // Mencetak pesan dan meminta inputan
  printf("Masukkan ronde: ");
  scanf("%d", &T);
  //  Mendeklarasikan array rounds dengan ukuran T untuk menyimpan jumlah gelang dalam setiap ronde.
  int rounds[T];
  // Loop for untuk mengulangi proses input jumlah gelang untuk setiap ronde.
  for (round = 0; round < T; round++)
  {
    // meminta input jumlah gelang dalam ronde tertentu dan menyimpannya dalam array rounds.
    scanf("%d", &rounds[round]);
  }
  // Loop for untuk mengulangi proses menyelesaikan Tower of Hanoi untuk setiap ronde.
  for (round = 0; round < T; round++)
  {
    // Mencetak pesan untuk menunjukkan ronde yang sedang dieksekusi.
    printf("\n Ronde %d:\n", round + 1);
    // Mencetak pesan sebelum mencetak langkah-langkah pemindahan gelang.
    printf("Langkah-langkah epik Anto dalam memindahkan gelang:\n");
    // Memanggil fungsi towerOfHanoi untuk menyelesaikan Tower of Hanoi dengan jumlah gelang yang sesuai untuk ronde tertentu, dengan tiang awal, bantuan, dan tujuan yang telah ditentukan.
    towerOfHanoi(rounds[round], 1, 2, 3);
  }
  return 0;
}