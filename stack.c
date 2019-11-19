#include <stdio.h>
#include <stdlib.h>

//Global verıables

int *dizi;  //dinamık dızı olusturdugumuzda initialize yapmamız gerekır maınde
int boyut = 0;
int tepe = 0;


int pop() {  // dizinin indisini 1 azaltır

    if(tepe <= 0 || tepe<= boyut/4){
        int *dizi2 = (int*)malloc(sizeof(int)*boyut/2);
        for(int i=0; i<tepe; i++) {
            dizi2[i] = dizi[i];
            free(dizi);
            dizi2 = dizi;
            boyut /= 2;
        }
    }
    return dizi[--tepe];
}

void push(int deger) {                                                    // parametre olarak alınan degerı dızının o ankı ındısıne atar ve ındısı 1 arttırır

    if(tepe >= boyut) {                                                  // C de dizi tanımında degısken kullanamayız!  --> pointer kullanmamız gerekır

        int *dizi2 = (int*)malloc(sizeof(int) * boyut*2);       // boyutun 2 katı kadar yer actık poınterla
        for(int i=0; i<tepe; i++) {
            dizi2[i] = dizi[i];
            free(dizi);
            dizi2 = dizi;
            boyut *= 2;
        }
    }
    dizi[tepe++] =  deger;
}

void bastir() {

    for(int i = 0; i<tepe; i++) {
        printf("%d \n",dizi[i]);
    }
}

int main() {

    dizi = (int*)malloc(sizeof(int) *2);

    push(10);
    push(20);
    bastir();
    printf("popped %d\n", pop());
    //printf("popped %d\n", pop());
    bastir();
}
