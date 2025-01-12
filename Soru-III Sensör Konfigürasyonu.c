#include <stdio.h>
#include <stdint.h>

// GRange Bandwidth OperationMode için enum dizisi oluþturuyoruz
typedef enum {
    G_2G = 0b00,
    G_4G = 0b01,
    G_8G = 0b10,
    G_16G = 0b11
} GRange;

typedef enum {
    BW_7_81Hz = 0b000,
    BW_15_63Hz = 0b001,
    BW_31_25Hz = 0b010,
    BW_62_5Hz = 0b011,
    BW_125Hz = 0b100,
    BW_250Hz = 0b101,
    BW_500Hz = 0b110,
    BW_1000Hz = 0b111
} Bandwidth;

typedef enum {
    NORMAL = 0b000,
    SUSPEND = 0b001,
    LOW_POWER_1 = 0b010,
    STANDBY = 0b011,
    LOW_POWER_2 = 0b100,
    DEEP_SUSPEND = 0b101
} OperationMode;

// Verilen degerleri bir struct yapisi altinda topluyoruz.
typedef struct {
    GRange gRange;
    Bandwidth bandwidth;
    OperationMode operationMode;
    uint8_t accConfigValue; // Konfigirasyonun son hali
} AccConfig;


// Config degerlerinin kaydirilarak dogru yere getirliyor
void confighesapla(AccConfig *config) {
    config->accConfigValue = (config->gRange & 0b11) |
                             ((config->bandwidth & 0b111) << 2) |
                             ((config->operationMode & 0b111) << 5);
}

//Bulunan deðeri binary ondalik ve onaltilik þekilde yazdýrýyoruz
void configgoster(const AccConfig *config) {
    printf("Decimal: %d\n", config->accConfigValue);
    printf("Hexadecimal: 0x%X\n", config->accConfigValue);
    printf("Binary: 0b");
    for (int i = 7; i >= 0; --i) {
        printf("%d", (config->accConfigValue >> i) & 1);
    }
    printf("\n");
}

int main() {
    AccConfig config;
//Hangi modun kullanýlacagý seçiliyor.

rangesecim: ;
    // User selects configuration
    int gRangeInput, bandwidthInput, operationModeInput;
    printf("Select G Range (1: 2G, 2: 4G, 3: 8G, 4: 16G): ");
    scanf("%d", &gRangeInput);
    if(gRangeInput<=0 || gRangeInput>=5){
    printf("Yanlýþ deðer girdiniz \n");
    goto rangesecim;
    }
    config.gRange = (GRange)(gRangeInput - 1);
bandsecim:
    printf("Select Bandwidth (1: 7.81Hz, 2: 15.63Hz, 3: 31.25Hz, 4: 62.5Hz, 5: 125Hz, 6: 250Hz, 7: 500Hz, 8: 1000Hz): ");
    scanf("%d", &bandwidthInput);
     if(bandwidthInput<=0 || bandwidthInput >=9){
    printf("Yanlýþ deðer girdiniz \n");
    goto bandsecim;
    }
    config.bandwidth = (Bandwidth)(bandwidthInput - 1);


opsecim:
    printf("Operasyon Modu Seçin (1: Normal, 2: Suspend, 3: Low Power 1, 4: Standby, 5: Low Power 2, 6: Deep Suspend): ");
    scanf("%d", &operationModeInput);
     if(operationModeInput<=0 || operationModeInput>=7 ){
    printf("Yanlýþ deðer girdiniz \n");
    goto opsecim;
    }

    config.operationMode = (OperationMode)(operationModeInput - 1);

    // Config deðerini hesapla ve göster
    confighesapla(&config);
    configgoster(&config);

    return 0;
}
