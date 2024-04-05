#include <stdio.h>

// membuat fungsi towerOfHanoi
void towerOfHanoi(int n, char from_rod[], char to_rod[], char aux_rod[])
{
  // melakukan pengecekan jika n sama dengan 1
  if (n == 1)
  {
    // mencetak pesan pindahkan gelang 1 dari from_rod ke to_rod
    printf("Pindahkan gelang 1 dari %s ke %s\n", from_rod, to_rod);
    return;
  }
  // melakukan rekursi dengan memanggil fungsi towerOfHanoi
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  // mencetak pesan pindahkan gelang n dari from_rod ke to_rod
  printf("Pindahkan gelang %d dari %s ke %s\n", n, from_rod, to_rod);
  // melakukan rekursi dengan memanggil fungsi towerOfHanoi
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
  // simpan banyakInputan ronde
  int input;
  // array untuk menyimpan jumlah gelang pada setiap ronde
  int banyakGelang[10];
  printf("Input\n");
  printf("Masukkan jumlah ronde: ");
  scanf("%d", &input);

  for (int i = 1; i <= input; i++)
  {
    int n;
    printf("Masukkan jumlah gelang pada ronde %d: ", i);
    scanf("%d", &n);
    banyakGelang[i] = n;
  }

  printf("\n Output: \n");
  for (int i = 1; i <= input; i++)
  {
    printf("Ronde %d:\n", i);
    printf("Langkah-langkah epik Anto dalam memindahkan gelang:\n");
    towerOfHanoi(banyakGelang[i], "Base Of Tower (A)", "Tower Of Triumph (B)", "Bootster Platform (C)");
    printf("\n");
  }

  return 0;
}