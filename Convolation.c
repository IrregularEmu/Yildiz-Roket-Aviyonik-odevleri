#include <stdio.h>
#include <stdlib.h>

// Matris yazma fonksiyonu
void printMatrix(int matrix[][100], int M, int N) {
    for (int satir = 0; satir < M; satir++) {
        for (int sutun = 0; sutun < N; sutun++) {
            printf("%d ", matrix[satir][sutun]);
        }
        printf("\n");
    }
}

void konvolusyon(int G[][100], int M, int N, int F[][100], int k, int R[][100]) {
    int filtop = 0;

    for (int satir = 0; satir < k; satir++) {
        for (int sutun = 0; sutun < k; sutun++) {
            filtop += F[satir][sutun];
        }
    }

    if (filtop == 0) {
        printf("Filtreleme matrisi elemanlari toplami 0\n");
        exit(0);
    }

    // Konvolüsyon işlemi uygulaması
    for (int satir = 0; satir <= M - k; satir++) {
        for (int sutun = 0; sutun <= N - k; sutun++) {
            int sum = 0;
            // Filtreyi görüntü üzerinde kaydirarak islemi gerçeklestir
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    sum += G[satir + x][sutun + y] * F[x][y];
                }
            }
            // Ortalama al ve yeni matris R'ye yaz
            R[satir][sutun] = sum / filtop;
        }
    }
}

int main() {
    // Degiskenler belirleniyor
    int n;
    int M, N;
    int matris[100][100];
    int filter[100][100];
    int sonuc[50][50];

    // Matrisin satir ve sutun sayilarini giriyoruz
    while (1) {
        printf("Matrisin satir sayisini girin (M): ");
        if (scanf("%d", &M) == 1 && M > 0 && M <= 100) break;
        while (getchar() != '\n');
        printf("Hata: Lutfen 1 ile 100 arasinda bir tam sayi giriniz.\n");
    }

    while (1) {
        printf("Matrisin sutun sayisini girin (N): ");
        if (scanf("%d", &N) == 1 && N > 0 && N <= 100) break;
        while (getchar() != '\n');
        printf("Hata: Lutfen 1 ile 100 arasinda bir tam sayi giriniz.\n");
    }

    printf("Girdiginiz degerler: M = %d, N = %d\n", M, N);

    // Matristeki degerleri istiyoruz, sonra girilen matrisi gosteriyoruz
    printf("Matrisin degerlerini girin:\n");
    for (int satir = 0; satir < M; satir++) {
        for (int sutun = 0; sutun < N; sutun++) {
            scanf("%d", &matris[satir][sutun]);
        }
    }

    printf("Ana matris:\n");
    printMatrix(matris, M, N);

    while (1) {
        printf("Filtre boyutunu girin (NxN): ");
        if (scanf("%d", &n) == 1 && n > 0 && n <= M && n <= N) break;
        while (getchar() != '\n');
        printf("Hata: Lutfen 1 ile %d arasinda bir tam sayi giriniz.\n", M < N ? M : N);
    }

    printf("Girdiginiz deger: %d\n", n);

    // Filtre matrisinin degerlerini istiyoruz
    printf("Filtre matrisi degerlerini girin:\n");
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            scanf("%d", &filter[satir][sutun]);
        }
    }

    printf("Filtre matrisi:\n");
    printMatrix(filter, n, n);

    // Konvolüsyon islemini gerceklestir
    konvolusyon(matris, M, N, filter, n, sonuc);

    // Sonuc matrisini yazdir
    printf("Sonuc matrisi:\n");
    printMatrix(sonuc, M - n + 1, N - n + 1);

    return 0;
}
