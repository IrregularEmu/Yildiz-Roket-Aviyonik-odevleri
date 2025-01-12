#include <stdio.h>

// Matris yazma fonksiyonu
void printMatrix(char matrix[][100], int n) {
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            printf("%c ", matrix[satir][sutun]);
        }
        printf("\n");
    }
}

/* sola ve saga dondurme fonksiyonu*/
void soladondur(char matrix[][100], int n, char donmus[][100]) {
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            donmus[n - sutun - 1][satir] = matrix[satir][sutun];
        }
    }
}

void sagadondur(char matris[][100], int n, char donmus[][100]) {
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            donmus[sutun][n - satir - 1] = matris[satir][sutun];
        }
    }
}

int main() {
    /* degiskenler belirleniyor */
    int n;
    char direction;
    char matris[100][100];
    char donmus[100][100];

    /* matrisin boyutunu istiyoruz, girilen degerin dogru oldugunu kontrol ediyoruz */
    inputn:
    printf("Matrisin boyutunu girin (NxN): ");

    if (scanf("%d", &n) != 1) {
        while ((n = getchar()) != '\n' && n != EOF);
        printf("Hata: Lutfen bir tam sayi giriniz.\n");
        goto inputn;
    } else if (n <= 0) {
        printf("Hata: Lutfen sifirdan buyuk bir tam sayi giriniz.\n");
        goto inputn;
    } else {
        printf("Girdiginiz deger: %d\n", n);
    }

    // matristeki degerleri istiyoruz, sonra girilen matrisi gosteriyoruz
    printf("Matrisin degerlerini girin:\n");
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            scanf(" %c", &matris[satir][sutun]);
        }
    }

    printf("Orijinal Matris:\n");
    printMatrix(matris, n);

    /* Matrisin hangi tarafa donecegini soruyoruz, donmus degeri kullaniciya veriyoruz */
    donme:
    printf("Saga (R) veya sola (L) dondurmek icin R veya L girin: ");
    scanf(" %c", &direction);

    if (direction == 'L' || direction == 'l') {
        soladondur(matris, n, donmus);
        printMatrix(donmus, n);
    } else if (direction == 'R' || direction == 'r') {
        sagadondur(matris, n, donmus);
        printMatrix(donmus, n);
    } else {
        printf("Gecersiz yon! L veya R giriniz.\n");
        goto donme;
    }

    return 0;
}
