#include <stdio.h>
#include <string.h>

// Bu satýrlar, kullanýlacak fonksiyonlarýn prototiplerini tanýmlar. Bu, derleyiciye bu fonksiyonlarýn ne tür parametreler alacaðýný ve ne tür bir deðer döndüreceðini bildirir.
void sifrele(char *metin, int anahtar);
void coz(char *metin, int anahtar);
//Bu bölüm, kullanýcýdan metin ve anahtar deðerini alýr, þifreleme ve çözme fonksiyonlarýný çaðýrýr, ardýndan sonuçlarý ekrana yazdýrýr.
int main() {
    char metin[100];
    int anahtar;

    // Kullanýcýdan metin ve anahtar deðeri alýnýr
    printf("Metni girin: ");
    fgets(metin, sizeof(metin), stdin);

    printf("Anahtar degerini girin: ");
    scanf("%d", &anahtar);

    // Girilen metni þifrele
    sifrele(metin, anahtar);
    printf("Sifrelenmis metin: %s\n", metin);

    // Þifreli metni çöz
    coz(metin, anahtar);
    printf("Cozulmus metin: %s\n", metin);

    return 0;
}

// Bu fonksiyon, verilen metni þifrelemek için kullanýlýr. Her karakterin ASCII deðerine göre küçük harf mi yoksa büyük harf mi olduðuna bakarak þifreleme iþlemini gerçekleþtirir.
void sifrele(char *metin, int anahtar) {
    int uzunluk = strlen(metin);

    for (int i = 0; i < uzunluk; i++) {
        char karakter = metin[i];

        if (karakter >= 'a' && karakter <= 'z') {
            metin[i] = (karakter - 'a' + anahtar) % 26 + 'a';
        } else if (karakter >= 'A' && karakter <= 'Z') {
            metin[i] = (karakter - 'A' + anahtar) % 26 + 'A';
        }
    }
}

// Bu fonksiyon, þifreli metni çözmek için kullanýlýr. Þifreleme fonksiyonu tekrar çaðrýlýr, ancak bu sefer anahtarýn negatif deðeri kullanýlarak tersine çevrilmiþ bir iþlem yapýlýr.
void coz(char *metin, int anahtar) {
    // Þifreleme iþlemi ile aynýdýr, ancak anahtarýn negatif deðeri kullanýlýr
    sifrele(metin, -anahtar);
}

