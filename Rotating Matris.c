#include <stdio.h>

// Matris yazma fonksiyonu
void printMatrix(int matrix[][100], int n) {
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            printf("%d ", matrix[satir][sutun]);
        }
        printf("\n");
    }
}

/* sola ve saga dondurme fonksiyonu*/
void soladondur(int matrix[][100], int n, int donmus[][100]) {
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            donmus[n - sutun - 1][satir] = matrix[satir][sutun];
        }
    }
}


void sagadondur(int matris[][100], int n, int donmus[][100]) {
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            donmus[sutun][n - satir - 1] = matris[satir][sutun];
        }
    }
}



int main() {
/*degiskenler belirleniyor */
    int n;
    char direction;
    int matris[100][100];
     int donmus[100][100];

/*matrisin boyutunu istiyoruz, girilen deðerin dopru olduðunu kontrol ediyoruz */
inputn:
    printf("Matrisin boyutunu girin (NxN): ");



   if (scanf("%d", &n) != 1) {

        while ((n = getchar()) != '\n' && n != EOF);
        printf("Hata: Lutfen bir tam sayý giriniz.\n");
        goto inputn;
    } else if (n <= 0) {
        printf("Hata: Lutfen sifirdan buyuk bir tam sayi giriniz.\n");
        goto inputn;
    } else {

        printf("Girdiginiz deger: %d\n", n);
    }


//matristeki degerleri istiyoruz sonra girilen matrisi gosteriyoruz
    printf("Matrisin degerlerini girin:\n");
    for (int satir = 0; satir < n; satir++) {
        for (int sutun = 0; sutun < n; sutun++) {
            scanf("%d", &matris[satir][sutun]);
        }
    }


    printf("Orijinal Matris:\n");
    printMatrix(matris, n);

    /* Matrisin Hangi tarafa donecegini soruyoruz, donmus deðeri kullanýcýya veriyoruz */
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
