#include <stdio.h>

// Matris yazma fonksiyonu
void printMatrix(int matrix[][100], int M, int N) {
    for (int satir = 0; satir < M; satir++) {
        for (int sutun = 0; sutun < N; sutun++) {
            printf("%d ", matrix[satir][sutun]);
        }
        printf("\n");
    }
}

/* sola ve saga dondurme fonksiyonu*/
void soladondur(int matrix[][100], int M, int N, int donmus[][100]) {
    for (int satir = 0; satir < M; satir++) {
        for (int sutun = 0; sutun < N; sutun++) {
            donmus[N - sutun - 1][satir] = matrix[satir][sutun];
        }
    }
}

void sagadondur(int matrix[][100], int M, int N, int donmus[][100]) {
    for (int satir = 0; satir < M; satir++) {
        for (int sutun = 0; sutun < N; sutun++) {
            donmus[sutun][M - satir - 1] = matrix[satir][sutun];
        }
    }
}

int main() {
    // Degiskenler belirleniyor
    int M, N;
    char direction;
    int matris[100][100];
    int donmus[100][100];

    // Matrisin satir ve sutun sayilarini giriyoruz
inputn:
    printf("Matrisin satir sayisini girin (M): ");
    if (scanf("%d", &M) != 1 && N<=0) {
        while ((M = getchar()) != '\n' && M != EOF);
        printf("Hata: Lutfen bir tam sayi giriniz.\n");
        goto inputn;
    }

    printf("Matrisin sutun sayisini girin (N): ");
    if (scanf("%d", &N) != 1 && N<=0) {
        while ((N = getchar()) != '\n' && N != EOF);
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

    printf("Orijinal Matris:\n");
    printMatrix(matris, M, N);

    // Matrisin hangi tarafa donecegini soruyoruz, donmus degeri kullanýcýya veriyoruz
donme:
    printf("Saga (R) veya sola (L) dondurmek icin R veya L girin: ");
    scanf(" %c", &direction);

    if (direction == 'L' || direction == 'l') {
        soladondur(matris, M, N, donmus);
        printf("Sola Donmus Matris:\n");
        printMatrix(donmus, N, M);  // Dönmüþ matrisin boyutlarý deðiþir: N x M
    } else if (direction == 'R' || direction == 'r') {
        sagadondur(matris, M, N, donmus);
        printf("Saga Donmus Matris:\n");
        printMatrix(donmus, N, M);  // Dönmüþ matrisin boyutlarý deðiþir: N x M
    } else {
        printf("Gecersiz yon! L veya R giriniz.\n");
        goto donme;
    }

    return 0;
}
