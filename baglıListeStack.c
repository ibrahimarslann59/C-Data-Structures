#include <stdio.h>
#include <stdlib.h>

 struct n {
    struct n * next;
    int data;
};
typedef struct n node;

/*
void bastir(node * root) {

    while (root != NULL) {
        printf("%d", root->data);
        root = root->next;
    }
} */

int pop (node *root) {
    if(root == NULL) {
        printf("Stack Bos");
        return  -1;                                          //int tipinde tanımladıgımız ıcın -1 dondurduk
    }

    if(root->next == NULL) {                               //sılınecek sadece 1 eleman kaldıysa bu ozel duruma gırer cunku usttekı whıle da next'inin next'ini bulamayacak
        int poppedData = root->data;
        free(root);
        return poppedData;
    }

    node* iter = root;
    while (iter->next->next != NULL)                   // sondan bır oncekı kutuya gıtmem gerekıyor cunku son elemana kadar gıdersem son elemanı sılemem
        iter = iter->next;

    node* temp = iter->next;                                 // sılınecek olan elemanın konumu
    int poppedData = temp->data;                             // sılınecek olan datayı poppedData da tutuyorum cunku pop ettıkten sonra o datayı dondurecegım
    iter->next = NULL;
    free(temp);
    return poppedData;
}

node* push(node * root, int x) {                              //root'u dondurdugumuz ıcın node* tıpınde olusturduk
    if(root == NULL) {
        root = (node*)malloc(sizeof(node));
        root->data = x;
        root->next = NULL;
        return root;
    }
    node* iter = root;
    while (iter->next != NULL) {                             // en basta root'u gosteren iter NULL dan bır oncekı datayı gıder..
        iter = iter->next;

        node * temp = (node*)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        iter->next = temp;
        return root;
    }
}
int main() {

    node * root = NULL;                        //araya ekleme yaptıktan sonra pop edınce hata veriyor
    root = push(root,10);
    root = push(root, 20);
    root = push(root, 30);
    printf("%d -> ",pop(root));
    root = push(root,70);
    printf("%d -> ",pop(root));
    root = push(root, 80);
    printf("%d ->",pop(root));


    return 0;
}