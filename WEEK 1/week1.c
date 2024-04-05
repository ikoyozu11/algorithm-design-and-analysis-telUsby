#include <stdio.h>
#include <stdlib.h>

int divsum(int n){
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n%i == 0)
        {
            sum += i;
        }
        
    }
    return sum;
}

int main(){
    int suminput, input;
    int *hasil = (int *)malloc(suminput * sizeof(int));
    scanf("%d", &suminput);
    for (int i = 0; i < suminput; i++)
    {
        scanf("%d", &input);
        hasil[i] = divsum(input);
    }
    for (int i = 0; i < suminput; i++)
    {
        printf("%d\n", hasil[i]);
    }
    
    return 0;
}