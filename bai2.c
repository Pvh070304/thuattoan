#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Hàm lấy dư của a^b mod m.
long long modulo(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % m;
        b = b / 2;
        a = (a * a) % m;
    }
    return result;
}


bool isPrime(long long n, int k) {

    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;


    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    for (int i = 0; i < k; i++) {
        .
        long long a = 2 + rand() % (n - 3);


        long long x = modulo(a, d, n);


        if (x == 1 || x == n - 1) continue;


        bool isWitness = false;
        for (long long r = 1; r < d; r++) {
            x = (x * x) % n;
            if (x == n - 1) {
                isWitness = true;
                break;
            }
        }


        if (!isWitness) return false;
    }


    return true;
}


void printPrimesWithNDigits(int N) {
    long long start = pow(10, N - 1);
    long long end = pow(10, N);
    for (long long i = start; i < end; i++) {
        if (isPrime(i, 5)) {
            printf("%lld\n", i);
        }
    }
}

int main() {
    int N;
    printf("Nhap so N (2 <= N <= 10): ");
    scanf("%d", &N);
    if (N < 2 || N > 10) {
        printf("So N khong hop le.\n");
        return 1;
    }
    printf("Cac so nguyen to co %d chu so:\n", N);
    srand(time(NULL));
    printPrimesWithNDigits(N);
    return 0;
}
