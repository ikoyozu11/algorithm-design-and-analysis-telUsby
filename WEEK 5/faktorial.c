#include <stdio.h>

unsigned long long factorial(int n) {
  // Base case: faktorial dari 0 dan 1 adalah 1
  if (n == 0 || n == 1) {
  return 1;
  }
  // Recursive case: faktorial dari n adalah n * faktorial(n - 1)
  else {
    return n * factorial(n - 1);
  }
}

int main() {
  int num;
  
  printf("Masukkan bilangan untuk menghitung faktorial: ");
  scanf("%d", &num);
  
  // Memanggil fungsi faktorial
  unsigned long long result = factorial(num);
  
  // Menampilkan hasil
  printf("Faktorial dari %d adalah: %llu\n", num, result);
  return 0;
}