/* Nomor Kelompok	: 9 				*/
/* Nama File		: ADT2048.h 		*/
/* Deskripsi		: File berisi definisi ADT yang digunakan pada Game 2048 */

#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#define found(P) (P)->found
#define value(P) (P)->value
#define right(P) (P)->right
#define below(P) (P)->below
#define First(L) ((L).First)
#define Nil NULL

typedef int infotype;
typedef struct tElmtList *address;

typedef struct tElmtList {
    infotype value;
    bool found;
    address right;
    address below;
} ElmtList;

typedef struct {
address First;
} Mtrks;

typedef struct {
    char TNama[10][20];
    int  THS[10];
    int NbElmt;
} TabInt;

address Alokasi (infotype X);
//I.S : Sembarang
//F.S : Memori berhasil dialokasikan untuk menyimpan X

void InitList(Mtrks *L);
//I.S : Sembarang
//F.S : Matriks berhasil diinisialisasi

address GetElmt (Mtrks L, int i, int j);
//I.S : Matriks L terdefinisi, i dan j terdefinisi
//F.S : Mengembalikan alamat sebuah list dengan indeks (i,j)

void SetElmt(Mtrks *L, int i, int j, int X);
//I.S : Matriks terdefinisi. indeks i dan j terdefinisi. X terdefinisi
//F.S : X berhasil dimasukkan menjadi value pada Matriks dengan indeks (i,j)

void Rndminsert (Mtrks *M);
//I.S : Matriks M terdefinisi
//F.S : Matriks M terupdate elemennya. Elemen pada indeks random yang awalnya 0 berubah menjadi angka 2 atau 4.

void TulisMatriks (Mtrks M);
//I.S : Matriks M terdefinisi
//F.S : Matriks M tercetak di layar

void MoveMatriks (Mtrks *M, char x, int *cnt);
//I.S : Matriks M terdefinisi. X terdefinisi.
//F.S : Matriks M berhasil diupdate berdasarkan masukan pergeseran x.
//		Jika masukan W: Matriks bergeser ke atas, angka yang sama akan dijumlahkan
//		Jika masukan A: Matriks bergeser ke kiri, angka yang sama akan dijumlahkan
// 		Jika masukan S: Matriks bergeser ke bawah, angka yang sama akan dijumlahkan
//		Jika masukan D: Matriks bergeser ke kanan, angka yang sama akan dijumlahkan

bool CekIsDed (Mtrks M);
//I.S : Matriks M terdefinisi
//F.S : Mengembalikan true jika kondisi Matriks penuh dan pergerakan tidak bisa dilakukan

bool Cek2048 (Mtrks M);
//I.S : Matriks M terdefinisi
//F.S : Mengembalikan true jika ada elemen matriks yang bernilai 2048

int CekSamping (Mtrks M, int i, int j);
//I.S : M terdefinisi. i dan j terdefinisi.
//F.S : Melakukan pengecekan ke samping. Mengembalikan indeks baris yang berisi angka bukan 0

int CekBawah (Mtrks M, int i, int j);
//I.S : M terdefinisi. i dan j terdefinisi.
//F.S : Melakukan pengecekan ke bawah. Mengembalikan indeks baris yang berisi angka bukan 0

/* ADT HighScore */
int GetHighScore (Mtrks M);
//I.S : Matriks M terdefinisi
//F.S : Mengembalikan elemen matriks dengan nilai maksimum untuk menjadi High Score

void SaveHighScore(TabInt T);
//I.S : Tabel T terdefinisi 
//F.S : Menyimpan isi tabel ke file eksternal

void InisiasiTabel(TabInt *T);
//I.S : Sembarang
//F.S : Tabel T berhasil diinisialisasi

void LoadHighScore(TabInt *T);
//I.S : T terdefinisi
//F.S : High Score beserta nama pemain dari file eksternal disimpan ke tabel

void SortHighScore(TabInt *T);
//I.S : T terdefinisi
//F.S : Tabel T berisi data yang terurut dari skor yang paling besar hingga paling kecil

/* ADT Menu Utama Permainan*/
void awal ();
//I.S : Sembarang
//F.S : Tulisan 2048 ditampilkan pada layar

void menu(char nama[20]);
//I.S : Nama terdefinisi
//F.S : Menampilkan pilihan menu ke layar

void pil4();
//Menampilkan keluaran jika user memilih pilihan 4 (About)

void pil3 ();
//Menampilkan keluaran jika user memilih pilihan 3 (How To Play)

void pil5();
// menampilkan pesan selamat tinggal

void setlayar();
// mengatur ukuran layar

void gotoxy(int x, int y);
//I.S : x dan y terdefinisi
//F.S : Mengatur posisi output an kursor pada layar sesuai dengan koordinat x-y

/* Prosedur dan Fungsi untuk Save dan Load Game */
void SaveGame(Mtrks M);
//I.S : M terdefinisi
//F.S : Isi matriks disimpan ke sebuah file eksternal

void LoadGame(Mtrks *M);
//I.S : M terdefinisi
//F.S : Data dari file eksternal disimpan ke list M

void Play(char nama[20]);
//I.S : Nama pemain terdefinisi.
//F.S : Permainan 2048 dijalankan. Permainan berhenti ketika mencapai kondisi menang atau kalah. Skor ditampilkan ke layar
