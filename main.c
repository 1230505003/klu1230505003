#include <stdio.h>
#include <string.h>

// Bu sat�rlar, kullan�lacak fonksiyonlar�n prototiplerini tan�mlar. Bu, derleyiciye bu fonksiyonlar�n ne t�r parametreler alaca��n� ve ne t�r bir de�er d�nd�rece�ini bildirir.
void sifrele(char *metin, int anahtar);
void coz(char *metin, int anahtar);
//Bu b�l�m, kullan�c�dan metin ve anahtar de�erini al�r, �ifreleme ve ��zme fonksiyonlar�n� �a��r�r, ard�ndan sonu�lar� ekrana yazd�r�r.
int main() {
    char metin[100];
    int anahtar;

    // Kullan�c�dan metin ve anahtar de�eri al�n�r
    printf("Metni girin: ");
    fgets(metin, sizeof(metin), stdin);

    printf("Anahtar degerini girin: ");
    scanf("%d", &anahtar);

    // Girilen metni �ifrele
    sifrele(metin, anahtar);
    printf("Sifrelenmis metin: %s\n", metin);

    // �ifreli metni ��z
    coz(metin, anahtar);
    printf("Cozulmus metin: %s\n", metin);

    return 0;
}

// Bu fonksiyon, verilen metni �ifrelemek i�in kullan�l�r. Her karakterin ASCII de�erine g�re k���k harf mi yoksa b�y�k harf mi oldu�una bakarak �ifreleme i�lemini ger�ekle�tirir.
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

// Bu fonksiyon, �ifreli metni ��zmek i�in kullan�l�r. �ifreleme fonksiyonu tekrar �a�r�l�r, ancak bu sefer anahtar�n negatif de�eri kullan�larak tersine �evrilmi� bir i�lem yap�l�r.
void coz(char *metin, int anahtar) {
    // �ifreleme i�lemi ile ayn�d�r, ancak anahtar�n negatif de�eri kullan�l�r
    sifrele(metin, -anahtar);
}

