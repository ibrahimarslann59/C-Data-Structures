#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;

};
typedef struct n node;

void bastir(node *r) {

    while (r != NULL) {
        printf("%d\n", r->x);
        r = r->next;

    }
    printf(" \n");

}

void ekle (node *r ,int x) {
    while(r->next != NULL){
        r = r->next;
    }

    r->next = (node*) malloc(sizeof(node));
    r->next->x = x;
    r->next->next = NULL;
}
node* ekleSirali(node *r ,int x) {
    if(r==NULL) { // linklist bos ıse direkt ekle
        r = (node*) malloc(sizeof(node));
        r->next = NULL;
        r->x = x;
        return r; //void i node* a donusturunce deger dondurmesı gerektıgı ıcın return r yaptık.. yanı yenı root u dondur

    }

    if(r->x > x) {  // lınklıst bos değilse ve ilk elemandan kucukse basa ekle ve ROOT değişiyor  (ROOT TAN KUCUK OLDUGU ICIN YENI ROOT BU SAYI OLUR)
        node * temp;
        temp = (node*) malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
        //r = temp;
        return temp; //


    }
    node * iter;
    iter = r;
    while(iter->next != NULL && iter->next->x < x) {  //lınk lıst bos değilse ve null gorene kadar VE benden daha buyuk bır sayı gorene kadar devam et
        iter = iter->next;
    }
    node *temp = (node*) malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = x;
    return r;


}
node * sil(node *r , int x) {

node * temp ;
node * iter = r;
if(r->x == x) {
    temp = r;
    r = r->next;
    free(temp);
    return r;
}

while(iter->next != NULL && iter->next->x != x) {
    iter = iter->next;
}
if(iter->next == NULL) {
    printf("sayi bulunamadi.");
    return r;
}
    temp = iter->next;
     iter->next = iter->next->next;
       free(temp);
return r;

}

int main() {

    node *root;
    root = NULL;
    root =  ekleSirali(root,400);
    root = ekleSirali(root,40);
    root = ekleSirali(root,4);
    root = ekleSirali(root,450);
    root = ekleSirali(root,50);

    bastir(root);
sil(root,400);
bastir(root);
sil(root,450);
bastir(root);

}