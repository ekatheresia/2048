/* Nomor Kelompok	: 9 				*/
/* Nama File		: ADT2048.c 		*/
/* Deskripsi		: File berisi realisasi ADT yang digunakan pada Game 2048 */

#include "ADT2048.h"

address Alokasi (infotype X) {
     address P;

     P = (address) malloc (sizeof(ElmtList));		//menyediakan alokasi memori
     if (P != Nil)									//Alokasi berhasil
     {
         value(P) = X;
         right(P) = Nil;
         below(P) = Nil;
         found(P) = false;
     }
     return(P);
}

void InitList(Mtrks *L) {
    First(*L) = Nil;
}

address GetElmt (Mtrks L, int i, int j)
{
	//Kamus
    int a; int b;
    address c;

	//Algoritma
    c = First(L);
    if ((i == 1)&&(j==1)) {
        return(First(L));
    } else {
    a = 1;
    b = 1;
    while (a < i) {
        c = below(c);
        a = a + 1;
    }

    while (b < j) {
        c = right(c);
        b = b + 1;
    }
    return (c);
    }
}

void SetElmt(Mtrks *L, int i, int j, int X)
{
    //Kamus
	address c;

	//Algoritma
    c = GetElmt(*L, i, j);
    (*c).value = X;
}

void Rndminsert (Mtrks *M) 
{
	//Kamus
	int ri;
	int rj;
	int randomer;
	int randnumb;
	bool done;

	//Algoritma 
   	done = false;
   	while (!(done)) {
   		ri = rand() % 4 + 1;
   		rj = rand() % 4 + 1;
   		randomer = rand() %9;
   		if (randomer <= 4) {
    		randnumb = 2;
   		}
		else {
        	randnumb = 4;
     	}
   		if ((*GetElmt(*M, ri,rj)).value == 0) {
      		(*GetElmt(*M, ri,rj)).value = randnumb;
      		done = true;
   		}
   }
}

void TulisMatriks (Mtrks M)
{
	//Kamus Lokal
    int a;
    int b;
    int c;
    
    //Algoritma
    printf ("\n\n\n\n\n\n\n");
    printf ("          ++++++++++++++++++++ P L A Y +++++++++++++++++\n\n\n");
    a = 1;
    while (a <= 4) {
        b = 1;
        while (b <= 4) {
            printf ("          %d", (*GetElmt(M,a,b)).value);
            c = (*GetElmt(M,a,b)).value;
            if (c > 999) {
                printf(" ");
            } else if (c > 99) {
                 printf("  ");
              } else if (c > 9) {
                  printf("   ");
                } else {
                    printf("    ");
                }
            b = b + 1;
        }
        printf ("\n\n");
        a = a + 1;
    }
    printf ("\n");
}

void MoveMatriks (Mtrks *M, char x, int *cnt)
{
	//Kamus Lokal
		int i;
		int j;
		int s;
		int q;
		int temp;

	//Algoritma
	temp = *cnt;
   	i = 1;
   	while (i <= 4) {
      j = 1;
      while (j <= 4) {
        (*GetElmt(*M, i, j)).found = false;
        j = j + 1;
      }
      i = i + 1;
	//Menginisialisasi status semua cell
   }
	switch(x) {
	   case 'W' :					//Pergeseran ke atas
	       {
	           j = 1;
	           while (j <= 4) {
	                i = 2;
	
	                while (i <= 4) {
	
	                    if ((*GetElmt(*M, i, j)).value == 0) {
	
	                        (*GetElmt(*M, i, j)).value = (*GetElmt(*M, i, j)).value;
	
	                    } else {
	
	                        s = i - 1;
	                        q = i;
	
	                        while (s >= 1) {
	                            if ((*GetElmt(*M, s, j)).value == 0) {
	                                (*GetElmt(*M, s, j)).value = (*GetElmt(*M, q, j)).value;
	                                (*GetElmt(*M, q, j)).value = 0;
	                                 temp = temp + 1;
	                            } else if ((!((*GetElmt(*M, s, j)).found))&&(!((*GetElmt(*M, q, j)).found))) {
	
	                                if ((*GetElmt(*M, q, j)).value == (*GetElmt(*M,s,j)).value) {
	                                    (*GetElmt(*M,s,j)).value = (*GetElmt(*M,s,j)).value * 2;
	                                    (*GetElmt(*M,s,j)).found = true;
	                                    (*GetElmt(*M, q, j)).value = 0;
	                                    temp = temp + 1;
	                                }
	
	                              } else {
	                                         (*GetElmt(*M, q, j)).value = (*GetElmt(*M, q, j)).value;
	                                     }
	                              s = s - 1;
	                              q = q - 1;
	                            }
	                        }
	                    i = i + 1;
	                    }
	                j = j + 1;
	                }
	                break;
	           }
	   case 'S' :				//Pergeseran ke bawah
	       {
	           j = 1;
	           while (j <= 4) {
	                i = 3;
	
	                while (i >=1) {
	
	                    if ((*GetElmt(*M,i,j)).value == 0) {
	
	                        (*GetElmt(*M,i,j)).value = (*GetElmt(*M,i,j)).value;
	
	                    } else {
	
	                        s = i + 1;
	                        q = i;
	
	                        while (s <= 4) {
	                            if ((*GetElmt(*M,s,j)).value == 0) {
	                                (*GetElmt(*M,s,j)).value = (*GetElmt(*M, q, j)).value;
	                                (*GetElmt(*M, q, j)).value = 0;
	                                 temp = temp + 1;
	
	                            } else if ((!((*GetElmt(*M,s,j)).found))&&(!((*GetElmt(*M, q, j)).found))) {
	
	                                if ((*GetElmt(*M, q, j)).value == (*GetElmt(*M,s,j)).value) {
	                                    (*GetElmt(*M,s,j)).value = (*GetElmt(*M,s,j)).value * 2;
	                                    (*GetElmt(*M,s,j)).found = true;
	                                    (*GetElmt(*M, q, j)).value = 0;
	                                    temp = temp + 1;
	                                }
	
	                              } else {
	                                         (*GetElmt(*M, q, j)).value = (*GetElmt(*M, q, j)).value;
	                                     }
	                              s = s + 1;
	                              q = q + 1;
	                            }
	                        }
	                    i = i - 1;
	                    }
	                j = j + 1;
	                }
	                break;
	       }
	
	   case 'A' :					//Pergeseran ke kiri
	       {
	           i = 1;
	           while (i <= 4) {
	                j = 2;
	
	                while (j <= 4) {
	
	                    if ((*GetElmt(*M,i,j)).value == 0) {
	
	                        (*GetElmt(*M,i,j)).value = (*GetElmt(*M,i,j)).value;
	
	                    } else {
	
	                        s = j - 1;
	                        q = j;
	
	                        while (s >= 1) {
	                            if ((*GetElmt(*M,i,s)).value == 0) {
	                                (*GetElmt(*M,i,s)).value = (*GetElmt(*M,i,q)).value;
	                                (*GetElmt(*M,i,q)).value = 0;
	                                 temp = temp + 1;
	
	                            } else if ((!((*GetElmt(*M,i,s)).found)&&(!((*GetElmt(*M,i,q)).found)))) {
	
	                                if ((*GetElmt(*M,i,q)).value == (*GetElmt(*M,i,s)).value) {
	                                    (*GetElmt(*M,i,s)).value = (*GetElmt(*M,i,s)).value * 2;
	                                    (*GetElmt(*M,i,s)).found = true;
	                                    (*GetElmt(*M,i,q)).value = 0;
	                                    temp = temp + 1;
	                                }
	
	                              } else {
	                                         (*GetElmt(*M,i,q)).value = (*GetElmt(*M,i,q)).value;
	                                     }
	                              s = s - 1;
	                              q = q - 1;
	                            }
	                        }
	                    j = j + 1;
	                    }
	                i = i + 1;
	                }
	                break;
	       }
	
	   case 'D' :					//Pergeseran ke kanan
	      {
	          i = 1;
	           while (i <= 4) {
	                j = 3;
	
	                while (j >= 1) {
	
	                    if ((*GetElmt(*M,i,j)).value == 0) {
	
	                        (*GetElmt(*M,i,j)).value = (*GetElmt(*M,i,j)).value;
	
	                    } else {
	
	                        s = j + 1;
	                        q = j;
	
	                        while (s <= 4) {
	                            if ((*GetElmt(*M,i,s)).value == 0) {
	                                (*GetElmt(*M,i,s)).value = (*GetElmt(*M,i,q)).value;
	                                (*GetElmt(*M,i,q)).value = 0;
	                                 temp = temp + 1;
	
	                            } else if ((!((*GetElmt(*M,i,s)).found))&&(!((*GetElmt(*M,i,q)).found))) {
	
	                                if ((*GetElmt(*M,i,q)).value == (*GetElmt(*M,i,s)).value) {
	                                    (*GetElmt(*M,i,s)).value = (*GetElmt(*M,i,s)).value * 2;
	                                    (*GetElmt(*M,i,q)).value = 0;
	                                    (*GetElmt(*M,i,s)).found = true;
	                                    temp = temp + 1;
	                                }
	
	                              } else {
	                                         (*GetElmt(*M,i,q)).value = (*GetElmt(*M,i,q)).value;
	                                     }
	                              s = s + 1;
	                              q = q + 1;
	                            }
	                        }
	                    j = j - 1;
	                    }
	                i = i + 1;
	                }
	                break;
	      }
	
	   case 'C' :				//Menyimpan permainan
	        {
	            SaveGame(*M);
	        }
	
	   default :
	      printf("                                  Pilihan salah. \n");		//Pesan Kesalahan
	      break;
	       }
	*cnt = temp;	
}

bool CekIsDed (Mtrks M)
{
    //Kamus
	int i;
    int j;
    int cek;

	//Algoritma
    cek = 0;
    i = 1;
    while (i < 4) {
        j = 1;
        while (j < 4) {
            cek = cek + CekSamping(M, i, j);
            cek = cek + CekBawah(M,i,j);
            j = j + 1;
        } //berhenti di j = 4
        cek = cek + CekBawah(M, i, j);
        i = i + 1;
    } //berhenti di 3, 4

    j = 1;
    while (j < 4) {
        cek = cek + CekSamping(M, i, j);
        j = j + 1;
    }
    return (cek == 0);
}

bool Cek2048 (Mtrks M)
{
	//Kamus Lokal
    int i;
    int j;
    bool cek;

	//Algoritma
    cek = false;
    i = 1;
    while (i <= 4) {
        j = 1;
        while (j <= 4) {
            if ((*(GetElmt(M, i, j))).value == 2048 ) {
                cek = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return (cek);
}

int CekSamping (Mtrks M, int i, int j)
{
	//Kamus Lokal
    int q;

	//Algoritma
    q = j + 1;
    if(((*GetElmt(M,i,j)).value == (*GetElmt(M,i,q)).value) || ((*GetElmt(M,i,q)).value == 0) || ((*GetElmt(M,i,j)).value == 0)) {
        return (1);
    } else {
        return (0);
    }
}

int CekBawah (Mtrks M, int i, int j)
{
	//Kamus Lokal
    int p;

	//Algoritma
    p = i + 1;
    if(((*GetElmt(M,i,j)).value== (*GetElmt(M,p,j)).value) || ((*GetElmt(M,p,j)).value == 0) || ((*GetElmt(M,i,j)).value == 0)) {
        return (1);
    } else {
        return (0);
        }
}

int GetHighScore (Mtrks M)
{
	// Kamus Lokal
    int i;
    int j;
    int max;

	//Algoritma
    max = (*(GetElmt(M, 1, 1))).value;
    i = 1;
    while (i <= 4) {
        j = 1;
        while (j <= 4) {
            if ((*(GetElmt(M, i, j))).value >= max ) {
                max = ((*(GetElmt(M, i, j))).value);
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return (max);
}

void SaveHighScore(TabInt T)
{
    /* Kamus Lokal */
    FILE *fc;
	int i;
	char nama[20], nilai[5];

	/* Algoritma */
	i=0;
	fc = fopen("HighScore.txt", "w+");
	sprintf(nama, "%s",T.TNama[i]);
    fputs(nama,fc);
    fputs(" ", fc);
    printf("%d",T.THS[i]);
    sprintf(nilai,"%d",T.THS[i]);
    fputs(nilai,fc);

    i++;
    printf("%d",i);
	while (i<=T.NbElmt)
    {
        fputs("\n",fc);
        sprintf(nama, "%s",T.TNama[i]);
        fputs(nama,fc);
        fputs(" ", fc);
        sprintf(nilai, "%d", T.THS[i]);
        fputs(nilai,fc);
        i++;
    }
	fclose(fc);
}

void LoadHighScore(TabInt *T)
{
    /* Kamus Lokal */
    FILE *fc;
    int i,k, sum;
    char Ckata[20];
    char c,r;

    fc = fopen("HighScore.txt","r");
    if (fc)
    {
        i=0;
        (*T).NbElmt=0;

        c = fscanf(fc, "%s", Ckata);
        do{
            r = getc(fc);
            if (Ckata[0]>48 && Ckata[0]<58)
            {
                k=0; sum = 0;
                while (Ckata[k]>48 && Ckata[k]<58)
                {
                    if (k > 0)
                    {
                        sum = sum * 10;
                    }
                    sum = sum + (Ckata[k] - '0');
                    k++;
                }
                (*T).THS[i] = sum;
            }
            else if ((Ckata[0]>64 && Ckata[0]<91) || (Ckata[0]>96 && Ckata[0]<123))		//Mengecek jika karakter merupakan integer
            {
                strcpy((*T).TNama[i], Ckata);
            }
            //Membaca kembali string berikutnya
            c = fscanf(fc, "%s", Ckata);

            //Menghitung baris pada file dan memulai matriks baris baru
            if (r == '\n')
            {
                i++;
                (*T).NbElmt++;
            }
        }while(c != EOF);
    }
}

void SortHighScore(TabInt *T)
{
    //Kamus Lokal
    int temp;
    int i,j;
    char tempkata[20];

    //Algoritma
    for(i=0;i<(*T).NbElmt;i++) {
        {
            for (j=i+1; j<=(*T).NbElmt;j++)
            {
                if((*T).THS[j] > (*T).THS[i]) {
                    temp = (*T).THS[j];
                    (*T).THS[j] = (*T).THS[i];
                    (*T).THS[i] = temp;
                    strcpy(tempkata, (*T).TNama[j]);
                    strcpy((*T).TNama[j],(*T).TNama[i]);
                    strcpy((*T).TNama[i],tempkata);

                }
            }
        }
    }
}

void menu(char nama[20])
{
	//Kamus Lokal
	int pil,n,y;
	TabInt T;
	int ans;
	
	//Algoritma
		do {
		system ("cls");
		gotoxy (55,20);
		printf ("Welcome!");
		gotoxy (55,21);
		printf ("Please choose the menu below!");
		gotoxy (55,22);
		printf ("1. Play");
		gotoxy (55,23);
		printf ("2. High Score");
		gotoxy (55,24);
		printf ("3. How to play");
		gotoxy (55,25);
		printf ("4. About");
		gotoxy (55,26);
		printf ("5. Quit");
		gotoxy (55,27);
		printf ("Your choice : ");
		scanf  ("%i", &pil);
		switch (pil)
		{
			case 1 :
					{
						system("cls");
						Play(nama);
						getch();
						break;
					}

			case 2 :
					{
						system("cls");
						gotoxy (45,20);
						printf ("+++++++++++++++ HIGH SCORES +++++++++++++++");
						LoadHighScore(&T);
						SortHighScore(&T);
						y=23;
						for (n=0;n<=T.NbElmt;n++)
						{
							gotoxy(45,y);
					        printf("|  %s ", T.TNama[n]);
					        gotoxy(80, y);
					        printf("  %d |\n", T.THS[n]);
					        y++;
    					}
    					gotoxy(45,y+1);
    					printf ("___________________________________________");
    					gotoxy(50,y+7);
    					printf("Press anywhere to back to menu\n");
    					getch();
						break;
					}
			case 3 :
					{
						pil3();
						break;
					}

			case 4 :
					{
						pil4();
						break;
					}
		}
} while (pil != 5);
}

void pil3 ()
{
	system ("cls");
	gotoxy (40,20);
	printf ("++++++++++++++++++++++  H O W   T O   P L A Y  ++++++++++++++++++++++");
	gotoxy (40,23);
	printf ("|         To play this game, the only thing you have to do is       |");
	gotoxy (40,24);
	printf ("|          press the 'W', 'A', 'S', 'D' key on your keyboard.       |");
	gotoxy (40,25);
	printf ("|        W is to move up, A is to move left, S is to move down      |");
	gotoxy (40,26);
	printf ("|                       D is to move right                          |");
	gotoxy (40,27);
	printf ("|                         Enjoy the game!                           |");
	gotoxy (40,28);
	printf ("_____________________________________________________________________");
	gotoxy (40,30);
	printf ("                  Press anywhere to back to menu                     ");
	getch();
}

void pil4()
{
	system ("cls");
	gotoxy(45,20);
	printf ("+++++++++++++++++++++ A B O U T  +++++++++++++++++++++");
	gotoxy(45,23);
	printf ("|  2048 COPYRIGHT DECEMBER 2015                      |");
	gotoxy(45,24);
	printf ("|                                                    |");
	gotoxy(45,25);
	printf ("|  BY SYNTAX AI'NT ERROR                             |");
	gotoxy(45,26);
	printf ("|  18214011 ---- ABDUL HAKIM                         |");
	gotoxy(45,27);
	printf ("|  18214012 ---- EKA THERESIA                        |");
	gotoxy(45,28);
	printf ("|  18214024 ---- CHRISTIAN ALEXANDER                 |");
	gotoxy(45,29);
	printf ("|  18214055 ---- TIRZA FIDELA                        |");
	gotoxy(45,30);
	printf ("______________________________________________________");
	gotoxy(45,32);
	printf ("          Press anywhere to back to menu              ");
	getch();
}

void pil5()
{
    system("cls");
    gotoxy(45,20);
	printf ("Thank you for playing this game! Come back soon!^^\n\n\n\n\n\n\n");
    getch();
}

void awal ()
{
	system ("cls");
	system ("COLOR 17");
	printf ("\n\n\n\n\n\n");
	printf ("                              xxxxxxxxxxxxxxxxxxx        xxxxxxxxxx                     xxxxxxxx        xxxxxxxxx   \n");
	printf ("                              xxxxxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxx                  xxxxxxxxx       xxxxxxxxxxx  \n");
	printf ("                                           xxxxxxx    xxxxxxxxxxxxxxxx               xxxxxxxxxxx      xxxxxxxxxxxxx \n");
	printf ("                                          xxxxxxx     xxxxxxxxxxxxxxxx             xxxxxxxxxxxxx     xxxx       xxxx\n");
	printf ("                                         xxxxxxx      xxxx        xxxx            xxx       xxxx     xxxx       xxxx\n");
	printf ("                                       xxxxxxx        xxxx        xxxx           xxxx       xxxx     xxxx       xxxx\n");
	printf ("                                     xxxxxxx          xxxx        xxxx          xxxxx       xxxx     xxxx       xxxx\n");
	printf ("                                    xxxxxxx           xxxx        xxxx         xxxxxx       xxxx     xxxxxxxxxxxxxxx\n");
	printf ("                                  xxxxxxx             xxxx        xxxx        xxxxxxx       xxxx     xxxxxxxxxxxxxxx\n");
	printf ("                                 xxxxxxx              xxxx        xxxx       xxxxxxxxxxxxxxxxxxx     xxxx       xxxx\n");
	printf ("                                xxxxxxx               xxxx        xxxx      xxxxxxxxxxxxxxxxxxxx     xxxx       xxxx\n");
	printf ("                               xxxxxxx                xxxxxxxxxxxxxxxx                      xxxx     xxxx       xxxx\n");
	printf ("                              xxxxxxx                 xxxxxxxxxxxxxxxx                      xxxx     xxxx       xxxx\n");
	printf ("                              xxxxxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxx                       xxxx     xxxxxxxxxxxxxxx\n");
	printf ("                              xxxxxxxxxxxxxxxxxxxx       xxxxxxxxxx                         xxxx      xxxxxxxxxxxxx \n");
	printf ("\n\n\n\n\n\n");
	printf ("                                                            Press anywhere to continue                                ");
	getch();
	system ("COLOR F1");
	getch();
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void setlayar()
{
    HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Coordinates = {20, 20};
    SetConsoleScreenBufferSize(Output, Coordinates);
    SMALL_RECT Coordinates2 = {20, 18, 70, 90};
    SetConsoleWindowInfo(Output, TRUE, &Coordinates2);
}


void Play(char Player[20])
{
	/* Kamus */
	    bool GameOver;
	    int i,j,HS;
	    int countwin, cnt;
	    char mv;
	    Mtrks M;
	    address P, UpperRow, prevInput;
	    TabInt T;
	    bool found;

	/* Algoritma */
    i = 1;
    GameOver = false;
    countwin = 1;
        while (i <= 4) {
            j = 1;
            while (j <= 4) {
                P = Alokasi(0);

                if ((i == 1)&&(j ==1)) {
                    First(M) = P;
                    UpperRow = P;
                }
                else if (i == 1) {
                    right(prevInput) = P;
                }
                else if (j == 1) {
                    below(UpperRow) = P;
                    UpperRow = right(UpperRow);
                } else {
                    right(prevInput) = P;
                    below(UpperRow) = P;
                    UpperRow = right(UpperRow);
                }


                SetElmt(&M, i, j, 0);
                if (j == 4) {
                    UpperRow = GetElmt(M, i, 1);
                }
                prevInput = P;
                j = j + 1;
            }
            i = i + 1;
        }
    srand(time(NULL));
    Rndminsert(&M);
    Rndminsert(&M);
    TulisMatriks(M);

    while (!(GameOver)) {
        printf("          Pergerakan : ");
        scanf (" %c", &mv);
        system("cls");

        cnt = 0;
        MoveMatriks (&M, mv, &cnt);
        if (cnt > 0) {
        Rndminsert(&M);
        }
        TulisMatriks(M);
        if ((Cek2048(M))&&(countwin==1)) {
            printf("Anda sudah mencapai 2048, silakan melanjutkan.\n");
            countwin = countwin + 1;
        }
        GameOver = CekIsDed(M);
        if (GameOver == true)
        {
            HS = GetHighScore(M);
            printf("Score Akhir anda = %d\n", HS);
            LoadHighScore(&T);
            if(T.NbElmt<9)
                T.NbElmt++;
            strcpy(T.TNama[T.NbElmt],Player);
            T.THS[T.NbElmt]=HS;
            SortHighScore(&T);
            SaveHighScore(T);
            printf ("Anda kalah! \n");
            getchar();
        }
    }
}

void SaveGame(Mtrks M)
{
    address c;
	int i,j,x;
	FILE *f = fopen("SaveGame.txt","w");
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
		    c = GetElmt(M,i,j);
		    x = (*c).value;
		    fprintf(f,"%d\n",x);
		}
	}
	fclose(f);
}

void LoadGame(Mtrks *M)
{
	int x,i,j;
	FILE *f = fopen("SaveGame.txt", "r");
	if (f == NULL) {
		printf("File tidak berhasil diload.\n");
	}
	else
	{
		for(i=1;i<=4;i++)
		{
			for(j=1;j<=4;j++);
			{
				fscanf(f,"%d",&x);
				printf("%d",x);
				SetElmt(M,i,j,x);
			}
		}
    }
    fclose(f);
}

