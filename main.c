#include <stdio.h>
#include <stdlib.h>
#define maxelem 100

typedef struct tb
{
    int tabint[maxelem];
    int nbrelem;
}tliste;//structure pour remplaire un tableau
///fonction pour allouer un espace memoire

tliste *allouer_tliste()
{
    tliste * tableau;
    //allouer l'espace memoire
    tableau = (tliste*)malloc(sizeof(tliste));
    if(!(tableau))//tester si l'allocation passe bien
    {
        printf("\n erreur de location de la memoire");
        exit(-1);
    }
    return ((tliste*)tableau);
}
/* ----------------------------------------------------------------*/
///fonction d'initialisation
tliste *initialiser_tliste(tliste *table)
{
    if(!(table))//tester que l'allocation passer bien
    {
      printf("\n erreur de l'allocation de la memoire");
      exit(-1);
    }
    table->nbrelem=0;//initialiser le nbr element
    return ((tliste*)table);
}
/* ----------------------------------------------------------------*/
///fonction verification liste vide
int estvide_tliste(tliste tableau)
{
    //return 1 si le tableau est vide et 0 sinon
    return (tableau.nbrelem==0);
}
/* ----------------------------------------------------------------*/
///fonction verification liste saturee
int estpleine_tliste(tliste tableau)
{
    //return 1 si le tableau est saturer et 0 sinon
    return (tableau.nbrelem==maxelem);
}
/* ----------------------------------------------------------------*/
///fonction d'insertion (fin)
int inserer_fin_tliste(tliste *TAB,int elem)
{
  if(!(TAB))//tester que si l'occation passer mal
    {
        printf("erreur de location de la memoire");
        exit(-1);
    }
    if(estpleine_tliste(*TAB))//tester si le tableau est vide
    {
        printf("le tableau est pleine");
        return 0;
    }
    // inserer l'element et augmenter le nbr element
    TAB->tabint[TAB->nbrelem++]=elem;
    return 1;
}
/* ----------------------------------------------------------------*/
//fonction d'insertion (position donnee)
int insertion_pos_tliste(tliste *table,int elem,int ind)
{

    if(!(table))//tester si l'allocation passe bien
    {
        printf("erreur de location de la memoire");
        exit(-1);
    }
    if(estpleine_tliste(*table))//tester si le tableau est saturer
    {
        printf("le tableau est pleine");
        exit(-1);
    }
    //tester si l'indece pas valide
    if((ind <= 0 )|| ( table->nbrelem < ind))
    {
        printf("\n l'indece pas valide");
    }
    else
       {
           //boucle pour tasser les element de tableau
           for(int i = table->nbrelem;i>ind;i--)
                  table->tabint[i] = table->tabint[i-1];
           table->tabint[ind] = elem;//inserer l'element
           table->nbrelem++;//incrementation de nbr element
        }
}
/* ----------------------------------------------------------------*/
///fonction pour la suppression
int supp_tliste(tliste *tb,int ind)
{
    if(!(tb))//tester si l'allocation passe bien
    {
        printf("erreur de l'allocation de la memoire");
        return ((int)-2);
    }
    if(estvide_tliste(*tb))//tester si le tableau est vide
    {
        printf("le tableau est vide");
        return ((int)-1);
    }
    //tester si la position n'est pas valide
    if((ind<0) || (tb->nbrelem <ind))
    {
        printf("\n l'indece pas valide");
        return ((int)0);
    }
    //boucle pour tasser les element de tableau
    for(int i=ind; i<tb->nbrelem;i++)
        tb->tabint[i]=tb->tabint[i+1];
    tb->nbrelem--;//dicrementation de nbr element
    return ((int)1);
}
/* ----------------------------------------------------------------*/
///fonction pour la suppression (1ere occurence)
int supp_1occ(tliste *TAB,int elem)
{

    if(!(TAB))//tester si l'allocation passe bien
    {
        printf("erreur de location de la memoire");
        exit(-1);
    }
    if(estvide_tliste(*TAB))//tester si le tableau est vide
    {
        printf("le tableau est vide");
        exit(-2);
    }
    //boucle pour chercher la pre
    for(int i=0;i<TAB->nbrelem;i++)
    {
        //tester si l'element est trouvee

        if(TAB->tabint[i]==elem)
        {
          //supprimer l'element
          if(supp_tliste(TAB,i));
          return(int) 1;
        }
    }
    return(int) 0;
}
/* ----------------------------------------------------------------*/
///fonction pour la suppression (toutes occurences)
int supp_tout_occur(tliste *tableau,int elem)
{
    if(!(tableau))//tester que l'allocation passer bien
    {

        printf("erreur de location de la memoire");
        return((int)-1);
    }
    if(estvide_tliste(*tableau))//tester si le tableau est vide
    {
        printf("le tableau est vide");
        return((int)0);
    }
    //supprimer toutes les occurences
    while(supp_1occ(tableau,elem));
    return((int)1);
}
/* ----------------------------------------------------------------*/
///fonction pour afficher les element de tliste
void afficher(tliste table)
{
    printf("\n l'affichage de tableau est :");
    //boucle d'affichage
    for(int i=0;i<table.nbrelem;i++)
        printf("\n tab[%d]=%d ",i,table.tabint[i]);
}
/* ----------------------------------------------------------------*/
/* ----------------------------------------------------------------*/
void main()
{
    tliste *table;
    int i,elem,h;
    table=allouer_tliste();
    table=initialiser_tliste(table);
    printf("entrer le nbr des element");
    scanf("%d",&h);
    for(i=0;i<h;i++)
    {
       printf("\n entrer l'element %d : ",i+1);
       scanf("%d",&elem);
       inserer_fin_tliste(table,elem);
    }
    afficher(*table);
    printf("\n/* ----------------------------------------------------------------*/");
    insertion_pos_tliste(table,20,4);
    afficher(*table);
    printf("\n/* ----------------------------------------------------------------*/");
    insertion_pos_tliste(table,100,50);
    printf("\n/* ----------------------------------------------------------------*/");
    supp_1occ(table,3);
    afficher(*table);
    printf("\n/* ----------------------------------------------------------------*/");
    supp_1occ(table,3);
    afficher(*table);
    printf("\n /* ----------------------------------------------------------------*/");
    if(supp_tout_occur(table,2));
    afficher(*table);
    printf("\n/* ----------------------------------------------------------------*/");




}
