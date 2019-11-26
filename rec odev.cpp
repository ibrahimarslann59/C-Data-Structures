#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//ibrahim arslan 160204025

char dizi[][20] = {"ali","ahmet","selin", "sedat", "dogukan"};   // 5 elemanlý býr  dýzýsý

int uzunluk = 0;
int boyut = 0;



char recursive(char kelime[]) {
	if(boyut == 5) {
		return -1;
	}
	int temp = strlen(kelime);
	if(temp == uzunluk) {
	 printf("%s\n", kelime);
	}
		boyut++;
	return recursive(dizi[boyut]);
}  
 
int main(){
	
	printf("Kac karakterli bir string aratmak istiyorsunuz: ");
	scanf("%d", &uzunluk);
	
	recursive(dizi[boyut]);

}	


//lab da yarým saat sure az geldýgý ýcýn yetýstýremedým.. ancak cözebildim    
