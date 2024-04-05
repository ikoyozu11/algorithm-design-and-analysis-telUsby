#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define NUM_STRINGS 100

void insertionSort(char str[]) {
    int n = strlen(str);
    for (int i = 1; i < n; i++) {
        char key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j = j - 1;
        }
        str[j + 1] = key;
    }
}

void sortStrings(char arr[][MAX_STRING_LENGTH], int n) {
    for (int i = 0; i < n; i++) {
        // Mengonversi semua huruf dalam string menjadi huruf kecil
        for (int j = 0; arr[i][j]; j++) {
            arr[i][j] = tolower(arr[i][j]);
        }
        insertionSort(arr[i]);
    }
}

int main() {
    char strings[NUM_STRINGS][MAX_STRING_LENGTH];
    int num_strings;

    printf("Enter number of strings: ");
    scanf("%d", &num_strings);

    printf("Enter %d strings:\n", num_strings);
    for (int i = 0; i < num_strings; i++)
        scanf("%s", strings[i]);
  
    sortStrings(strings, num_strings);
  
    printf("\nSorted strings:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
