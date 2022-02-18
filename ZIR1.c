// Napisati funkciju unosKonverzija tipa int koja kao parametre prima redom:

// pokazivač na prvi član niza znakova (string) : niz
// pokazivač na objekt tipa int : dulj
// Funkcija unosKonverzija sa standardnog ulaza učitava niz znakova dok se ne unese znak uskličnik (!) koji ne ulazi u učitani niz ili dok duljina učitanog niza nije veća od 10 znakova. Dozvoljen je unos znakova razmaka. Tijekom učitavanja funkcija konvertira sva velika slova u mala i sve znamenke u znak upitnik (?). Konvertirani i ispravno terminirani niz vraća se kao parametar niz, a duljina učitanog niza, bez znaka za kraj niza, kao parametar dulj. Broj konvertiranih znamenki funkcija treba vratiti preko imena u pozivajući program.

// Napomena: potrebno je predati samo izvorni kod funkcije unosKonverzija. Funkcija ništa ne ispisuje.

// Primjeri ispravnih rezultata (unos od korisnika: niz; ispis: konvertiran niz, duljina dulj, rezultat poziva funkcije unosKonverzija). Okomite crte u ispisu samo vizualiziraju početak i kraj konvertiranog niza:

// Unos: 12·34·5·!

// Ispis: |??·??·?·| 8 5

// Unos: 1A··B23·c4!

// Ispis: |?a··b??·c?| 10 4

// Unos: Upro1234567890!

// Ispis: |upro??????| 10 6



// #include <stdio.h>
// #include <string.h>

// int unosKonverzija(char *niz, int *dulj)
// {
//    int duljina = *dulj;
//    int brKonvB = 0;
//    int i = 0;

//    while (*(niz + i) != '\0' && *(niz + i) != '!' && i <= 10)
//    {
//       if (*(niz + i) >= 'A' && *(niz + i) <= 'Z')
//       {
//          *(niz + i) = *(niz + i) + 32;
//       }
//       else if (*(niz + i) >= '0' && *(niz + i) <= '9')
//       {
//          *(niz + i) = '?';
//          brKonvB++;         
//       }
//       i++;      
//    }
//    *(niz + i) = '\0';
//    *dulj = i;

//    return brKonvB;
// }

// int main(void)
// {
//    char niz[12 + 1];
//    printf("Upisite niz > ");
//    fgets(niz, 12 + 1, stdin);

//    int duljina = 0;

//    printf("%s %d %d", niz, duljina, unosKonverzija(niz, &duljina));   

//    return 0;
// }




// Napisati funkciju s prototipom
// void put(int seed, int koraka, struct tocka_s *tocke)
// koja puni polje na čiji prvi član pokazuje pokazivač tocke. Polje se puni na sljedeći način:

// za prvu točku postavi se ishodište
// koordinate sljedećih točaka izračunavaju se tako da se na koordinatu prethodne točke doda slučajno izračunati pomak po X koordinati (nova slučajna vrijednost u rasponu od 0 do 10) i slučajno izračunati pomak po Y koordinati (druga nova slučajna vrijednost u rasponu od 0 do 10).
// Broj seed je inicijalna vrijednost za generator pseudoslučajnih brojeva, a broj koraka predstavlja broj točaka dodanih nakon točke ishodišta (minimalno jednak 1).

// Deklaracija strukture je

// struct tocka_s {
//     int x;
//     int y;
// };
// Važno: za transformaciju pseudoslučajnog broja u broj iz željenog intervala koristiti operator %.

// Primjer 1:
// Za zadano sjeme 500 i broj koraka 2 funkcija će u polje dodati točke (0,0), (10,6) i (14,15) (ako testirate na operacijskom sustavu Windows), odnosno (0,0), (10,3) i (18,6) (ako testirate na operacijskom sustavu Linux ili u sustavu Edgar).

// Primjer 2:
// Za zadano sjeme 1234 i broj koraka 1 funkcija će u polje dodati točke (0,0) i (9,4) (ako testirate na operacijskom sustavu Windows), odnosno (0,0) i (3,7) (ako testirate na operacijskom sustavu Linux ili u sustavu Edgar).

// Predati samo definiciju funkcije, bez naredbi #include, definicije strukture i glavnog programa.




// Načiniti funkciju s prototipom _Bool setQuadrants(char *fileName) koja u binarnoj datoteci zadanog imena svakoj točki ažurira kvadrant u kojem se nalazi. Kvadranti su numerirani od 1 do 4, od "sjeveroistočnog", u pravcu suprotnom kazaljci na satu. Neće se provjeravati rubni uvjeti (u testnim primjerima neće biti točaka na koordinatnim osima). Funkcija treba vratiti 1 ako je obavljena uspješno, a 0 ako nije uspjelo otvaranje toka.

// Zapisi u file su oblika

// struct record_s {
//     int x;
//     int y;
//     int quadrant;
// };
// Važno: Nakon svakog upisivanja, pozvati fflush.

// Napomena: predati samo izvorni kod funkcije, bez deklaracije strukture i naredbi #include. Glavni program, deklaracija strukture i naredbe #include kojima se testira funkcionalnost funkcije već su pripremljeni u Edgaru. U funkciji obvezno zatvoriti tok, jer inače načinjene promjene neće biti spremljene ni vidljive programu koji testira funkciju. Nije dozvoljeno korištenje polja.

// Primjer ulazne datoteke nalazi se u privitku.

// Napisati odsječak programa koji, korištenjem petlje s ispitivanjem uvjeta na kraju, obavlja potpuno istu funkciju kao odsječak programa prikazan dijagramom toka.
// Nije dozvoljeno korištenje pomoćnih varijabli.


// _Bool setQuadrants(char *fileName)
// {
//    _Bool uspjesno = 0;
//    FILE *ulaz = fopen("points.bin", "r+b");

//    struct record_s tocka;

//    while (fread(&tocka, sizeof(tocka), 1, ulaz) == 1)
//    {
//       if (tocka.x > 0 && tocka.y > 0)
//       {
//          tocka.quadrant = 1;
//          fseek(ulaz, -1L * sizeof(tocka), SEEK_CUR);
//          fwrite(&tocka, sizeof(tocka), 1, ulaz);
//       }
//       else if (tocka.x < 0 && tocka.y > 0)
//       {
//          tocka.quadrant = 2;
//          fseek(ulaz, -1L * sizeof(tocka), SEEK_CUR);
//          fwrite(&tocka, sizeof(tocka), 1, ulaz);
//       }
//       else if (tocka.x < 0 && tocka.y < 0)
//       {
//          tocka.quadrant = 3;
//          fseek(ulaz, -1L * sizeof(tocka), SEEK_CUR);
//          fwrite(&tocka, sizeof(tocka), 1, ulaz);
//       }
//       else if (tocka.x > 0 && tocka.y > 0)
//       {
//          tocka.quadrant = 4;
//          fseek(ulaz, -1L * sizeof(tocka), SEEK_CUR);
//          fwrite(&tocka, sizeof(tocka), 1, ulaz);
//       }
      
//       uspjesno = 1;
//    }
//    fflush(ulaz);

//    fclose(ulaz);

//    return uspjesno;
// }



// #include <stdio.h>
// #include <stdlib.h>

// struct tocka_s
// {
//    int x;
//    int y;
// };

// void put(int seed, int koraka, struct tocka_s *tocke)
// {
//    int i, pomakX, pomakY;
//    tocke[0].x = 0;
//    tocke[0].y = 0;

//    for (i = 1; i < koraka; i++)
//    {
//       srand((unsigned int)seed);
//       pomakX = rand() % (10 - 0 + 1) + 0;
//       *(tocke + i)->x += pomakX;

//       // srand((unsigned int)seed);
//       pomakY = rand() % (10 - 0 + 1) + 0;
//       *(tocke + i)->y += pomakY;
//    }

//    return;
// }

// int main(void)
// {
//    int seed, brojKoraka;

//    seed = 500;
//    brojKoraka = 2;

//    struct tocka_s tocke[brojKoraka];

//    put(seed, brojKoraka, &tocke[0]);

//    for (int i = 0; i < brojKoraka; i++)
//    {
//       printf("%d %d", tocke[i].x, tocke[i].y);
//    }

//    return 0;
// }
