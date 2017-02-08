#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10000 
#define TAILLE 500 

typedef struct S_s
{
  int * tab_int[TAILLE] ; 
  char tab_char[TAILLE] ; 
} S_t ; 


char f3()  
{
  char c = 'a' + (rand() % ('z'+1)) ;
  return( c ) ;
}


int * f2() 
{

	int *i =malloc(sizeof(int));
	//La variable locale exist que quand le fonction s'exécute, après il n'exist plus. Il faut utiliser malloc pour créer un pointeur dynamique
	  *i = rand() ;//il faut utiliser *i pour changer le contenu pointé
  return( i ) ;//i est un pointeur donc j'enleve le &
}


S_t * f1() 
{
  int i , j ; 
  S_t *tab=malloc(sizeof(S_t)*N) ;
	//La variable locale exist que quand le fonction s'exécute, après il n'exist plus. Il faut utiliser malloc pour créer un pointeur dynamique
	//pour envoyer le tableau de taille N on crée un pointeur pointe sur une partie de taille N fois la taille de S_t
  for( i=0 ; i<N ; i++ )
    {
      for( j=0 ; j<TAILLE ; j++ ) 
	{
	  tab[i].tab_int[j] = f2()  ;
	  tab[i].tab_char[j] = f3() ; 
	}
    }

  return(tab) ; 
}



int main()
{
  S_t * tab ; 

  printf("Debut du programme\n"); 

  srand(getpid());

  printf("Appel de f1\n"); 
  tab = f1() ; 
  printf( "Retour de f1\n") ; 
  
  printf("Fin normale du programme\n"); 
  
  return(0); 
}
