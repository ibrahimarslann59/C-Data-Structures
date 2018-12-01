#include <stdio.h>
#include <stdlib.h>

struct n{
   struct  n* next;
    int x;
};
typedef struct n node;

node* sirali_ekle(node*,int);
node* asalCarpanlariBul(int,node*);
void yazdir(node*);
node* kKatiYazdir(node*,node*,int);
void sonuc(node*,int);

int main() {
    node* root;  node* carpan;
    root = NULL;  carpan = NULL;

    FILE *hedef_dosya = fopen("input.txt","r+");
    int sayi;
    if(hedef_dosya==NULL){
        printf("Dosya bulunamadı");
    }
    else{
        for(int i=1;i<=40;i++){
            fscanf(hedef_dosya,"%d",&sayi);
            if(sayi==1 && i!=1){
                carpan = asalCarpanlariBul(i,carpan);


            }


        }
    }
    fclose(hedef_dosya);

    int k;
    printf("bir k sayisi gırınız:");                scanf("%d",&k);

    printf("girilen duğmelerın asal carpanları:");         yazdir(carpan);
    printf("\n******SONUCLAR*******");
    kKatiYazdir(carpan,root,k);
    printf("\n");
    sonuc(root,k);



}

node* sirali_ekle(node* rootf,int xf) {
    node* iterf = rootf;
    while(iterf!=NULL){

        if(iterf->x == xf){
            return rootf;

        }
        iterf = iterf->next;
    }
    if(rootf==NULL){
        rootf = (node*)malloc(sizeof(node));
        rootf->x = xf;
        rootf->next = NULL;
        return rootf;
    }
    if(rootf->x>xf){
        node* tempf = (node*)malloc(sizeof(node));
        tempf->x = xf;
        tempf->next = rootf;
        return tempf;                  //rootf=tempf yapıp sonra da return rootf;  yapsak ne degısırdı?

    }
    iterf = rootf;

while(iterf->next!=NULL && iterf->next->x <xf){
   iterf = iterf->next;

}
         node* temp = (node*)malloc(sizeof(node));
           temp->x = xf;
           temp->next = iterf->next;
           iterf->next = temp;
    return rootf; // root değişseydi yeni rootu dondurucektık


}

node* asalCarpanlariBul(int sayi,node* ptr ){

    for(int i=2;sayi>1;i++){
        while(sayi%i==0){
            ptr = sirali_ekle(ptr,i);
                    sayi = sayi/i;
        }
}
    return ptr;

}
void yazdir(node* carp){
    while(carp!=NULL){
        printf("%d",carp->x);
        carp = carp->next;

    }
}
node* kKatiYazdir(node* rootf ,node* root,int k) {

    while (rootf != NULL) {
        for (int i = 1; i <= k; i++) {
            root = sirali_ekle(rootf, (rootf->x * i));

        }
        rootf = rootf->next;
    }
    return root;

}

void sonuc(node* root,int k){
    int i=0;
    while(i<k){
        root = root->next;
        i++;
    }
    printf("K: %d sayisinin denk geldiği indis: %d",k,root->x);

}