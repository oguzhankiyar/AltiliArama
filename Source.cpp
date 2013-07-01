#include <stdio.h>
#define elemanSayisi 15

int altiliArama(int, int);
int dizi[] = {1, 5, 9, 15, 33, 45, 49, 52, 55, 61, 69, 78, 86, 92, 97};
int arananSayi;

void main(){
	printf("Islem yapilacak dizi:\n");
	int i;
	for (i=0;i<elemanSayisi;i++)
		printf("%d ", dizi[i]);
	printf("\n");
	do{
		printf("\nAranacak sayiyi giriniz(Cikis icin -1): ");
		scanf("%d", &arananSayi);
		if (arananSayi != -1){
			int sonuc = altiliArama(0, elemanSayisi - 1);
			if (sonuc == -1)
				printf("Aradiginiz sayi bulunamadi!\n");
			else
				printf("Aradiginiz sayi dizinin %d. elamanidir.\n", sonuc + 1);
		}
	} while(arananSayi != -1);
}
int altiliArama(int ilkIndis, int sonIndis){
	int ortaIndis[5];
	ortaIndis[2] = (ilkIndis + sonIndis) / 2;
	ortaIndis[0] = ((ilkIndis + ortaIndis[2]) / 2 + ilkIndis) / 2;
	ortaIndis[1] = ((ilkIndis + ortaIndis[2]) / 2 + ortaIndis[0]) / 2;
	ortaIndis[3] = ((ortaIndis[2] + sonIndis) / 2 + ortaIndis[2]) / 2;
	ortaIndis[4] = ((ortaIndis[2] + sonIndis) / 2 + sonIndis) / 2;
	if (dizi[ilkIndis] == arananSayi)
		return ilkIndis;
	else if (dizi[sonIndis] == arananSayi)
		return sonIndis;
	else if (dizi[ilkIndis] < arananSayi && dizi[ortaIndis[0]] >= arananSayi)
		return altiliArama(ilkIndis, ortaIndis[0]);
	else if (dizi[ortaIndis[0]] < arananSayi && dizi[ortaIndis[1]] >= arananSayi)
		return altiliArama(ortaIndis[0], ortaIndis[1]);
	else if (dizi[ortaIndis[1]] < arananSayi && dizi[ortaIndis[2]] >= arananSayi)
		return altiliArama(ortaIndis[1], ortaIndis[2]);
	else if (dizi[ortaIndis[2]] < arananSayi && dizi[ortaIndis[3]] >= arananSayi)
		return altiliArama(ortaIndis[2], ortaIndis[3]);
	else if (dizi[ortaIndis[3]] < arananSayi && dizi[ortaIndis[4]] >= arananSayi)
		return altiliArama(ortaIndis[3], ortaIndis[4]);
    else if (dizi[ortaIndis[4]] < arananSayi && dizi[sonIndis] > arananSayi)
        return altiliArama(ortaIndis[4], sonIndis);
	else
		return -1;
}