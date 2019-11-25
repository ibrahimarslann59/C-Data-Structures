#include <stdio.h>
#include <stdlib.h>

int * dizi = NULL;
int sira = 0;
int sirabasi = 0;
int boyut = 2;

void temizle() {
    if(sirabasi == 0)
        return ;

    for (int i = 0; i<boyut; i++) {                       //sira-1   ??
        dizi[i] = dizi[i+sirabasi];
    }
    sira -= sirabasi;                              // orn sıra 3. ındıste ıse sırayı en basa almak ıcın 3 bırım hareket edecegı ıcın sira da 3 birim gerıye gelecektir
    sirabasi = 0;                                      // en basa geldıgı ıcın sırabasi ni 0 yapmamız gerekır
}

void enque(int a ) {  // Dizi bos ise bır yer ac
    if(dizi == NULL) {
        dizi = (int*)malloc(sizeof(int)*2);                         // 2 bırımlık yer acildi
    }
    if(sira >= boyut) {
        boyut *= 2;
        int * dizi2 = (int*)malloc(sizeof(int)*boyut);             // boyutun 2 katı yenı bır dızı olustur
        for(int i = 0; i<boyut/2; i++) {
            dizi2[i] = dizi[i];
            free (dizi);
            dizi = dizi2;                                                   //  yeni dizi2 yi dizi de gostersin cunku dıger yerlerde de aynı dızıyı kullanıyoruz
        }
    }
    dizi[sira++] = a;                                                 // sıranın bulundugu ındıse koy ve sirayı 1 arttır
}


int deque() {
    if(sira == sirabasi) {
        printf("Sira Bos.");
        return -1;
    }

    if(sira-sirabasi <= boyut/4) {                                         //sira-sirabasi = dizideki eleman sayısı
            int * dizi2 = (int*)malloc(sizeof(int)*boyut/2);            // boyutun yarısı kadar bır dızı ac hafızada
            for(int i = 0; i<sira-sirabasi; i++) {
                dizi2[i] = dizi[sirabasi+i];                                // 0. ındıse kacıncı ındıste eleman var ıse ordan basla kopyalamaya
            }
            sira -= sirabasi;                                              // sira yi en basta kac bos yer varsa o kadar azaltıyoruz (sirabasi)
            sirabasi = 0;
            free (dizi);
            boyut /=2;
            dizi = dizi2;
    }
    return dizi[sirabasi++];
}

int main(){
    for (int i = 0; i < 20 ; ++i) {
        enque(i*10);
    }

    for (int i = 0; i <13 ; ++i) {
        printf("%d", deque());
    }

}
