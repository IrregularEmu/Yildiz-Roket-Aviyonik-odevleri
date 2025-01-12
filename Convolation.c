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

// Matris yazma fonksiyonu
void printmatris(int matrix[][100], int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
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
inputn:
    printf("Matrisin satir sayisini girin (M): ");
    if (scanf("%d", &M) != 1 || M <= 0) {
        while (getchar() != '\n');
        printf("Hata: Lutfen bir tam sayi giriniz.\n");
        goto inputn;
    }

    printf("Matrisin sutun sayisini girin (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        while (getchar() != '\n');
        printf("Hata: Lutfen bir tam sayi giriniz.\n");
        goto inputn;
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

inputf:
    printf("Filtre boyutunu girin (NxN): ");
    if (scanf("%d", &n) != 1) {
        while (getchar() != '\n');
        printf("Hata: Lutfen bir tam sayi giriniz.\n");
        goto inputf;
    } else if (n > M || n > N) {
        printf("Hata: Lutfen en az ana matrisin satir veya sütun sayilarina esit deger giriniz.\n");
        goto inputf;
    } else {
        printf("Girdiginiz deger: %d\n", n);
    }

    // Filtre matrisinin degerlerini istiyoruz
    printf("Filtre matrisi degerlerini girin:\n");
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            scanf("%d", &filter[satir][sutun]);
        }
    }

    printf("Filtre matrisi:\n");
    printmatris(filter, n, n);

    // Konvolüsyon islemini gerceklestir
    konvolusyon(matris, M, N, filter, n, sonuc);

    // Sonuc matrisini yazdir
    printf("Sonuc matrisi:\n");
    printMatrix(sonuc, M - n + 1, N - n + 1);

    return 0;
}
