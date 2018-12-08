#include <stdio.h>
#include<stdlib.h>


struct n{
   struct  n* sag;
    struct n* sol;
    int data;
}; typedef struct n node;
int dizi[8];
int i=0;

node* ekle(node*,int);
void yazdir(node*);

node* ekle(node* agac,int x){
    if(agac==NULL){

        node* root = (node*)malloc(sizeof(node));
        root->sag = NULL;
        root->sol = NULL;
        root->data = x;
        return  root;
    }

    if(agac->data <x){
        agac->sag = ekle(agac->sag,x);
        return agac;
    }
    agac->sol = ekle(agac->sol,x);
    return agac;

}
void yazdir(node* agac){
    if(agac==NULL){
        return;
    }
    yazdir(agac->sol);
    printf(" %d ,",agac->data);  // sıralanmıs agacı  sırasıyla bir diziye atar
dizi[i++] = (agac->data);

    yazdir(agac->sag);


}

int main() {
    node *agac = NULL;
    int benzerlik =0;

    agac = ekle(agac, 5);
    agac = ekle(agac, 8);
    agac = ekle(agac, 2);
    agac = ekle(agac, 1);
    agac = ekle(agac, 9);
    agac = ekle(agac, 7);
    agac = ekle(agac, 6);
    agac = ekle(agac, 3);

    int tam_dizi[] = {5, 8, 2, 1, 9, 7, 6, 3};
    yazdir(agac);

    for (int j = 0; j < 8; j++) {
        if (dizi[j] == tam_dizi[j]) {
            benzerlik++;

        }

    }
    for (int k = 0; k < 8; k++) {

printf("\n");
        printf("\ntam agac dizi: %d", tam_dizi[k]);
    }
    printf("\n\n*********");
    printf("\nbenzerlik: %d", benzerlik);
    printf("\n\n*********");

}
