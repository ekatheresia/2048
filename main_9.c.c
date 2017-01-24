/* Nomor Kelompok	: 9 				*/
/* Nama File		: main_9.c 			*/
/* Deskripsi		: Driver Game 2048  */

#include "ADT2048.c"

int main ()
{
	// KAMUS GLOBAL
	int pil;
	char nama[20];

	// ALGORITMA
		setlayar();
		awal();
		system("cls");
		gotoxy(55,20);
		printf("Please enter you name below :\n");
		gotoxy(60,23);
		scanf("%s", &nama);
		menu(nama);
        pil5();
    return(0);
}
