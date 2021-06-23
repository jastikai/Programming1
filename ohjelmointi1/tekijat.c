
#include <stdio.h>
#include <math.h>

/* funktioiden prototyypit */
void tekijat(int n);
int haeJakaja(int n);
int parillinen(int n);

int main(void) {
 int luku;

 printf("\nAnna positiivinen kokonaisluku >");
 scanf("%d",&luku);

 /* esitetään luku tekijöidensä tulona */
 tekijat(luku);

 return(0);
}

/* funktio jakaa parametrinaan saamansa luvun alkutekijöihin
   eli alkulukujen muodostamaksi tuloksi */
void tekijat(int n){
 int tekija;
 int luku;

 tekija = haeJakaja(n);
 printf("%d = %d ", n, tekija);

 for(luku = n/tekija; luku >  1; luku = luku/tekija){
  tekija = haeJakaja(luku);
  printf("* %d ", tekija);
 }
 printf("\n\n");
 return;
}

int haeJakaja(int n){

 int jakaja = 0;
 int testi;  /* jakajakokelas */

 /* onko luku n parillinen ? */
 if(parillinen(n)){

   jakaja = 2;

 }else{
   jakaja = 0;
   testi = 3;
 }
/* etsitään jakajaa */
 while(jakaja == 0) {

    /* onko jakaja suurempi kuin luvun n neliöjuuri */
    if(testi > sqrt(n))
    jakaja = n;

    /* meneekö  jako tasan */
    if( n % testi == 0)
    jakaja = testi;

    /* seuraava pariton jakajakokelas */
    testi = testi + 2;
 }

 return(jakaja);
}

int parillinen(int n){
 int tulos;

 tulos = (n % 2) == 0;

 return(tulos);
}