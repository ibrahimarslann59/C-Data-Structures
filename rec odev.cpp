#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//ibrahim arslan 160204025

char dizi[][20] = {"ali","ahmet","selin", "sedat", "dogukan"};   // 5 elemanl� b�r  d�z�s�

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


//lab da yar�m saat sure az geld�g� �c�n yet�st�remed�m.. ancak c�zebildim    
