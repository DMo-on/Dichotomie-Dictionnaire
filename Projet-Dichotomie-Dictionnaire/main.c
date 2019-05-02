/*
	Nom: DJEBRI MOUNIRA
	Matricule:201500009092
	Section:ISIL B
	Gr:01
	Date: 09/12/16 20:10
	Description: Projet recherche dichotomique dans dico
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>
#include "altconio.h"
#include <string.h>


typedef enum { false, true } bool;
/* ********************************************** */
/*                Variables globales              */
/* ********************************************** */
#define max_mot 15
#define max_def 200
#define max 215
#define dico "dico.txt"
#define file "file.txt"
#define temp "temp.txt"
HANDLE fManip;    // manipuler fenetre console.
/* ********************************************** */
/*                les structures             */
/* ********************************************** */
typedef struct
{
    char mot[max_mot];
    char def[max_def];
}motdico;
typedef struct
{
    char mot[max_mot];
}TabMot;
typedef struct
{
     char l[max];
}ligned;




/* ********************************************** */
/*                Fonctions de gestion           */
/* ********************************************** */
    void MajMin(char mot[])
    {
            char c;
            int taille,i;
            taille=strlen(mot);
            for(i=0;i<taille;i++)
            {
               c=mot[i];
               mot[i]=tolower(c);
            }
    }

int CreerFichierDico (char nomF[],int n)
{
    FILE *pFile;
    int i;
    motdico ligne;
    pFile=fopen(nomF,"wt");
    if(pFile==NULL)
    {
                   setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {

        for(i=0;i<n;i++)
        {
            fflush(stdin);
            printf("\n\t-Veuillez entrer le mot:\n");
            gets(ligne.mot);
            MajMin(ligne.mot);
            printf("\n\t-La definition:\n");
            gets(ligne.def);
            fprintf(pFile,"%-10s:",ligne.mot);
            fprintf(pFile,"%s.\n",ligne.def);
        }

    }
    fclose(pFile);
    return 1;
}

int TrierFichierDico (char nomF[],int n)
{
   ligned *Tab;
   char moti[max_mot];
   char motj[max_mot];
   char buff[max];
   int i,min,j,test;
   FILE *pFile;
   Tab=(ligned *)malloc((n)*sizeof(ligned));
              if(Tab==NULL)
    {

                   setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: pas assez d'espace!!\a");
        return -1;
    }
   pFile=fopen(nomF,"rt");
           if(pFile==NULL)
    {
                   setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }
    i=0;
           while(fgets(buff,max,pFile)!=NULL)
           {
               strcpy(Tab[i].l,buff);
               i++;
           }

    fclose(pFile);


  for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            sscanf(Tab[i].l,"%s",moti);
            sscanf(Tab[j].l,"%s",motj);
            test=strcmp(moti,motj);
            if(test>0)
            {
                min=j;
                strcpy(buff,Tab[i].l);
                strcpy(Tab[i].l,Tab[min].l);
                strcpy(Tab[min].l,buff);
            }

        }

    }
       pFile=fopen(nomF,"wt");
           if(pFile==NULL)
    {

                   setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }
          for(i=0;i<n;i++)
      {
          strcpy(buff,Tab[i].l);
            fprintf(pFile,"%s",buff);
      }

 fclose(pFile);
free(Tab);

  return 0;
}
void LireFichierDico (char nomF[])
{
    char buff[max];
    char c[1];
    int i,j;
    FILE *pFile;
    pFile=fopen(nomF,"rt");
        if(pFile==NULL)
    {
                   setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
    }else
    {
           while(fgets(buff,max,pFile)!=NULL)
           {
               printf("\t-%s",buff);
           }
    }
    fclose(pFile);
    printf("\n\n\n\t-Entrez 1 pour revenir au menu principal:\n");
    scanf("%s",c);
}
int RajouterMotDico (char nomF[],int n,char word[],char definition[])
{
    FILE *pFile;
    FILE *pTemp;
    char c;
    char motd[max_mot];
    int i;
    char buff[max];
    motdico ligne;
    pFile=fopen(nomF,"rt");
    if(pFile==NULL)
    {
                   setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {


    pTemp=fopen("temp.txt","wt");
    if(pFile==NULL)
    {
                   setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {
                   while(fgets(buff,max,pFile)!=NULL)
           {
               sscanf(buff,"%s",motd);
               if(strcmp(motd,word)==0)
               {
                      setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,26,80,9);
                      gotoxy(26, 26);
                      printf("\n\t-LE MOT EXISTE DEJA!!\n\a");
                      fclose(pFile);
                      fclose(pTemp);
                      remove(temp);
                      gotoxy(26, 33);
                      setcolor(WHITE,BLACK);
                      printf("\n\n\n\t-Entrez 1 pour revenir au menu principal:\n");
                       scanf("%c",&c);
                       return -1;

               }else
               {
                 fprintf(pTemp,buff);
               }

           }
           fflush(stdin);
            fprintf(pTemp,"%-10s:",word);
            fprintf(pTemp,"%s.\n",definition);
        fclose(pFile);
        fclose(pTemp);
    }

    }



        pTemp=fopen(temp,"rt");
    if(pTemp==NULL)
    {
                  setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {


    pFile=fopen(nomF,"wt");
    if(pFile==NULL)
    {
                  setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {
                   while(fgets(buff,max,pTemp)!=NULL)
               {
                 fprintf(pFile,"%s",buff);
               }

    }

    fclose(pFile);
    fclose(pTemp);
    remove(temp);
        }


    return 1;
}
int SupprimerMotDico (char nomF[],int n,char word[])
{
    FILE *pFile;
    FILE *pTemp;
    char definition[max_def];
    char motd[max_mot];
    int i;
    char buff[max];
    motdico ligne;
    pFile=fopen(nomF,"rt");
    if(pFile==NULL)
    {
             setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {


    pTemp=fopen("temp.txt","wt");
    if(pTemp==NULL)
    {
        setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {
                   while(fgets(buff,max,pFile)!=NULL)
           {
               sscanf(buff,"%s",motd);
               if(strcmp(motd,word)!=0)
               {
                 fprintf(pTemp,buff);
                 i++;
               }

           }
           if(i==n)
           {
               printf("Le mot a supprimer n'existe pas\n\a");

                       fclose(pFile);
        fclose(pTemp);
        remove(temp);
        return -1;
           }

        fclose(pFile);
        fclose(pTemp);
    }

    }


        pTemp=fopen(temp,"rt");
    if(pTemp==NULL)
    {
        setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {


    pFile=fopen(nomF,"wt");
    if(pFile==NULL)
    {
          setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {
                   while(fgets(buff,max,pTemp)!=NULL)
               {
                 fprintf(pFile,"%s",buff);
               }

    }

    fclose(pFile);
    fclose(pTemp);
    remove(temp);
        }


    return 1;
}

int CreerFichierFile (char nomF[],int n)
{
    FILE *pFile;
    int i,z,y;
    char mot[max_mot];
    char buff[max_mot];
    pFile=fopen(nomF,"wt");
    if(pFile==NULL)
    {
        setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {
        z=17;
        y=30;
        for(i=0;i<n;i++)
        {
            gotoxy(z,y);
            printf("\t\n-ENTREZ LE MOT:\n");
            gotoxy(z+15,y+1);
            scanf("%s",mot);
            MajMin(mot);
            sprintf(buff,"%s \n",mot);
            fputs(buff,pFile);
            y++;
        }

    }
    fclose(pFile);
    return 1;
}
void LireFichierFile (char nomF[])
{
    FILE *pFile;
    char c[1];
    char mot[max_mot];
    pFile=fopen(nomF,"rt");
    if(pFile==NULL)
    {
          setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");

        exit(-1);
    }else
    {
        while(fgets(mot,max_mot,pFile)!=NULL)
        {
            printf("\t\t-%s\n",mot);
        }

    }
    fclose(pFile);
    printf("\n\n\n\t-Entrez 1 pour revenir au menu principal:\n");
    scanf("%s",c);

}
int half(char nomF[],int begin,int end)
{
    int pos;
       pos=((begin+end)/2);
  return pos;
}
char *Deplacement(char nomF[],int n,int pos)
{
    char *mot;
    mot=(char *)malloc(max_mot*sizeof(char));
         FILE *pFile;
     char buff[max];
     int i;
       pFile=fopen(nomF,"rt");
           if(pFile==NULL)
    {                      setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        exit(-1);
    }else
    {
        for(i=0;i<=pos;i++)
        {
            fflush(stdin);
            fgets(buff,max,pFile);
            sscanf(buff,"%s",mot);
        }
        fclose(pFile);
    }
    return mot;
}
void AfficherLigne(char nomF[],int n,int pos)
{
        FILE *pFile;
    int i;
    char buff[max];
    pFile=fopen(nomF,"rt");
    if(pFile==NULL)
    {                      setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        exit(-1);
    }else
    {
        rewind(pFile);
        fflush(stdin);
        for(i=0;i<=pos;i++)
        {
            fgets(buff,max,pFile);
        }

        gotoxy(17, 28);
        printf("\n\t-LE MOT EXISTE.\n\n\t\tVOICI SA DEFINITION:\n\t\t\t-%s\n",buff);
        fclose(pFile);
    }
}
int RechercheDichotomique (char nomD[],int n,char mot[],int begin,int end)
{
     FILE *dFile;
     int pos;
     char *motd;
     motd=(char *)malloc(max_mot*sizeof(char));
     char buff[max];
       dFile=fopen(nomD,"rt");
           if(dFile==NULL)
    {

                      setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
    }else
    {
         begin=0;
         end=n;

         while (end>=begin)
    {
        rewind(dFile);
        pos=half(nomD,begin,end);
        motd=Deplacement(nomD,n,pos);

        if(strcmp(motd,mot)==0)
        {
          AfficherLigne(nomD,n,pos);
           fclose(dFile);
           return pos;
        }

        if(strcmp(motd,mot)<0)
        {
            begin=pos+1;

        }else
        {
            end=pos-1;
        }

    }

        printf("\n\t-%s: N'EXISTE PAS DANS DICO\n",mot);
        fclose(dFile);
        return -1;
    }

}

int RechercheDicho(char nomD[],int n,char mot[])
{
    int pos,i,begin,end;
     FILE *dFile;
     char *motd;
     motd=(char *)malloc(max_mot*sizeof(char));
     char buff[max];
         begin=0;
         end=n;

         while (end>=begin)
    {
        pos=(begin+end)/2;
        dFile=fopen(nomD,"r");
        if(dFile==NULL)
        {
            setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
        return -1;
        }
         for(i=0;i<=pos;i++)
        {
            fflush(stdin);
            fgets(buff,max,dFile);
            }
        sscanf(buff,"%s",motd);
        fclose(dFile);

        if(strcmp(motd,mot)==0)
        {
          printf("\n\t-%s :EXISTE DANS DICO.\n\n\tVOICI SA DEFINITION :\n\t-%s",mot,buff);

           return pos;
        }

        if(strcmp(motd,mot)<0)
        {
            begin=pos+1;

        }else
        {
            end=pos-1;
        }

    }

        printf("\n\t-%s: N'EXISTE PAS DANS DICO\n",mot);
        fclose(dFile);
        return -1;


}
void MotFileDansDico(char nomD[],int n,char nomF[],int m)
{

    FILE *fFile;
    char c[1];
    int position;
    char motf[max_mot];
    fFile=fopen(nomF,"rt");
    if(fFile==NULL)
    {
            setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
    }else
    {
        fflush(stdin);
        while(fgets(motf,max_mot,fFile)!=NULL)
        {
            sscanf(motf,"%s",motf);
            position=RechercheDicho(nomD,n,motf);
        }
        fclose(fFile);
        printf("\n\n\n\t-Entrez 1 pour revenir au menu principal:\n");
        scanf("%s",c);
    }

}
/* ********************************************** */
/*                Fonctions d'interface           */
/* ********************************************** */
/*
 * cette fonction dessine un cadre allant
 * des coordonnees x et y en haut a gauche de la console
 * d'une taille largeur * hauteur et nettoie
 * son contenu
 */
void dessinCadre(int debx,int deby,int largeur,int hauteur)

{
    int compteur,i,j;
    int actuelX=getx();
    int actuelY=gety();//recupere les position actuelles de x et y voir altconio.h version modifiée de conio.h
/*-------ligne horizontale du haut------*/
    gotoxy(debx,deby);
    printf("%c",201);
    for(compteur=1;compteur<=largeur-2;compteur++)
        printf("%c",205);
    printf("%c",187);

/*-------ligne verticale gauche-------*/
    gotoxy(debx,deby+1);
    for(compteur=1;compteur<=hauteur-2;compteur++)
    {   printf("%c",186);
        gotoxy(debx,deby+1+compteur);
    }

/*-------ligne verticale droite------*/
    gotoxy(debx+largeur-1,deby+1);
    for(compteur=1;compteur<=hauteur-2;compteur++)
    {   printf("%c",186);
        gotoxy(debx+largeur-1,deby+1+compteur);
    }

/*-------ligne horizontale du bas----*/
    gotoxy(debx,deby+hauteur-1);
    printf("%c",200);
    for(compteur=1;compteur<=largeur-2;compteur++)
        printf("%c",205);
    printf("%c",188);

/*-------nettoyage du cadre---*/
    for(i=1;i<=hauteur-2;i++)
    {
        gotoxy(debx+1,deby+i);
        for(j=1;j<=largeur-2;j++)
            printf(" ");
    }
    gotoxy(actuelX,actuelY);    //actualiser les positions
}

/*
 * cette fonction dessine une double ligne horizontale
*/
void dessinDoubleLigne(int x,int y, int longueur)
{
    int compteur;
    int actuelX=getx();   //recupere les position actuelles de x et y voir altconio.h version modifiée de conio.h
    int actuelY=gety();
    gotoxy(x,y);
    for(compteur=0;compteur<longueur;compteur++)
        printf("%c",205);
    gotoxy(actuelX,actuelY);    //actualier les positions
}
/*
 * cette fonction dessine une  ligne horizontale tiret
*/
void dessinLigneT(int x,int y, int longueur)
{
    int compteur;
    int actuelX=getx();   //recupere les position actuelles de x et y voir altconio.h version modifiée de conio.h
    int actuelY=gety();
    gotoxy(x,y);
    for(compteur=0;compteur<longueur;compteur++)
        printf("%c",249);
    gotoxy(actuelX,actuelY);    //actualier les positions
}
/*
 * cette fonction genere le menu principal
*/
int afficherMenuPrincipal()
{
    system("cls");// netoyer la console

    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");
    gotoxy(10, 20 );
    printf("MENU PRINCIPAL:");
    dessinDoubleLigne(10,21, 80);
    gotoxy(40, 24);
    printf("1. GESTION DU DICTIONNAIRE.");
    gotoxy(40, 26);
    printf("2. GESTION DU FICHIER.");
    gotoxy(40, 28);
    printf("3. QUITTER.");
    dessinDoubleLigne(10,33, 80);
    gotoxy(10, 34);
    printf("Entrez votre choix:");
    gotoxy(29, 34);
    setcolor(BLACK,LIGHTGRAY);
    int choix = -1;
    scanf("%d", &choix);
    gotoxy(29, 36);
    setcolor(WHITE,BLACK);
    return choix;
}
/*
 * cette fonction genere le menu dico
*/
int afficherMenuDico()
{
    system("cls");// netoyer la console

    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");
    gotoxy(10, 20 );
    printf("MENU GESTION DU DICTIONNAIRE:");
    dessinDoubleLigne(10,21, 80);
    gotoxy(30, 24);
    printf("1. AJOUTER UN MOT.");
    gotoxy(30, 26);
    printf("2. SUPPRIMER UN MOT.");
    gotoxy(30, 28);
    printf("3. VOIR CONTENU DU DICTIONNAIRE.");
    gotoxy(30, 30);
    printf("4. VERIFIER SI UN MOT EXISTE.");
    gotoxy(30, 32);
    printf("5. REVENIR AU MENU PRINCIPAL.");

    dessinDoubleLigne(10,33, 80);
    gotoxy(10, 34);
    printf("Entrez votre choix:");
    gotoxy(29, 34);
    setcolor(BLACK,LIGHTGRAY);
    int choix = -1;
    scanf("%*c%d", &choix);
    gotoxy(29, 36);
    setcolor(WHITE,BLACK);
    return choix;
}
/*
 * cette fonction genere le menu file
*/
int afficherMenuFile()
{
    system("cls");// netoyer la console

    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");
    gotoxy(10, 20 );
    printf("MENU GESTION DU FICHIER:");
    dessinDoubleLigne(10,21, 80);
    gotoxy(30, 24);
    printf("1. REMPLIR LE FICHIER.");
    gotoxy(30, 26);
    printf("2. CHERCHER LES MOTS DU FICHIER DANS DICO.");
    gotoxy(30, 28);
    printf("3. VOIR LE CONTENU DU FICHIER.");
    gotoxy(30, 30);
    printf("4. REVENIR AU MENU PRINCIPAL.");

    dessinDoubleLigne(10,33, 80);
    gotoxy(10, 34);
    printf("Entrez votre choix:");
    gotoxy(29, 34);
    setcolor(BLACK,LIGHTGRAY);
    int choix = -1;
    scanf("%*c%d", &choix);
    gotoxy(29, 36);
    setcolor(WHITE,BLACK);
    return choix;
}
int AfficheRajoutMot(int n)
{
 int ret;
 char word[max_mot];
 char definition[max_def];
 char c[1];
    system("cls");// netoyer la console
    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");

    dessinLigneT(16,19, 70);
    gotoxy(17, 21);
    printf("\n\t\t-QUEL EST LE MOT QUE VOUS DESIREZ RAJOUTER ?\n");
    gotoxy(17, 26);
    printf("Mot: ");
    gotoxy(17, 31);
    printf("Definition: ");
    dessinLigneT(16,33, 70);
    gets(word);
    gotoxy(30,26);
    gets(word);
    MajMin(word);
    gotoxy(30,31);
    gets(definition);
    ret=RajouterMotDico(dico,n,word,definition);

    if(ret==-1)
            {
                      setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
                      return -1;
            }else
            {
               n++;
            }
    ret=TrierFichierDico(dico,n);
    if(ret==-1)
            {
                      setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
                      return -1;
            }
   printf("\n\n\n\t-Entrez 1 pour revenir au menu principal:\n");
    scanf("%s",c);

}
int AfficheSupprimeMot(int n)
{
 int ret;
 char word[max_mot];
 char definition[max_def];
 char c[1];
    system("cls");// netoyer la console
    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");

    dessinLigneT(16,19, 70);
    gotoxy(17, 21);
    printf("\n\t\t-QUEL EST LE MOT QUE VOUS DESIREZ RAJOUTER ?\n");
    gotoxy(17, 26);
    printf("Mot: ");
    dessinLigneT(16,33, 70);
    gets(word);
    gotoxy(30,26);
    gets(word);
    MajMin(word);
    ret=SupprimerMotDico(dico,n,word);

    if(ret==-1)
            {
                      setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR: probleme lors de l'ouverture du fichier!!\a");
                      return -1;
            }else
            {
               n--;
            }
   printf("\n\n\n\t-Entrez 1 pour revenir au menu principal:\n");
    scanf("%s",c);

}

void AffichecontenuDico()
{
    system("cls");// netoyer la console
    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");
    gotoxy(16,14);
    printf("\n\t\t-VOICI LE CONTENU DU DICTIONNAIRE:\n\n\n");
    dessinLigneT(10,16,70);
    LireFichierDico(dico);

}

void AffichecontenuFile()
{
    system("cls");// netoyer la console
    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");
    gotoxy(16,14);
    printf("\n\t\t-VOICI LE CONTENU DU FICHIER:\n\n\n");
    dessinLigneT(10,16,70);
    LireFichierFile(file);

}

int AfficheCreerFile()
{
    int m,ret;
    char c[1];
    system("cls");// netoyer la console
    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");

    dessinLigneT(16,19, 70);
    gotoxy(17, 21);
    printf("\n\t\t-QUELLE EST LE NOMBRE DE MOT QUE CONTIENT VOTRE FICHIER:\n");
    gotoxy(17, 26);
    printf("La taille: ");
    gotoxy(30,26);
    scanf("%d",&m);
    dessinLigneT(16,28,70);
    if(m<1 || m>100)
    {
                     setcolor(RED,LIGHTGRAY);
                      dessinCadre(10,23,80,9);
                      gotoxy(26, 25);
                      printf("ERREUR!!");
                      setcolor(WHITE,BLACK);
                      gotoxy(26,33);
                      printf("\n\n\n\t-Entrez 1 pour revenir au menu principal:\n");
                      scanf("%s",c);
     }
    ret=CreerFichierFile(file,m);

}
void AfficheMotFileDansDico(n,m)
{
    system("cls");// netoyer la console
    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");

    dessinLigneT(16,19, 70);
    gotoxy(17, 21);
    printf("VOICI LES MOTS DE FILE QUI EXISTENT DANS DICO:\n");
    MotFileDansDico(dico,n,file,m);
}
void AfficherRechercheDico(n)
{
    int begin,end,ret;
    char word[max_mot];
    char c[1];
    system("cls");// netoyer la console
    dessinCadre(10,4,80,10);
    dessinCadre(11,5,78,8);
    gotoxy(32, 9);
    printf("DJEBRI - DICTIONNAIRE :");

    dessinLigneT(16,19, 70);
    gotoxy(17, 21);
    printf("\t\t-ENTREZ LE MOT QUE VOUS VOULEZ CHERCHER:\n");
    gotoxy(17, 26);
    printf("Mot: ");
    dessinLigneT(16,36, 70);
    gets(word);
    gotoxy(30,26);
    gets( word);
    MajMin(word);
    ret=RechercheDichotomique(dico,n,word,begin,end);
    printf("\n\n\n\t-Entrez 1 pour revenir au menu principal:\n");
    scanf("%s",c);
}

/* ********************************************** */
/*                Fonction principale             */
/* ********************************************** */

int main()
{
    int choix1,choix2;
    int ret,n,m,pos;
    n=10;
    m=3;
    char c=' ';
    TabMot *existe;
    int begin,end;
    char word[max_mot];
    // Titre de la fenetre
    SetConsoleTitle("Universite des sciences et de la technologie Houari-Boumediene - Recherche Dichotomique dans un dictionnaire");
    // fixer la taille de la fenetre console:
    fManip = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT fTaille = {0, 0, 100, 50};
    SetConsoleWindowInfo(fManip, 1, &fTaille);


    while(1)
    {
        setcolor(WHITE,BLACK);

        choix1= afficherMenuPrincipal();
        switch(choix1)
        {
        case 1:
            choix2=afficherMenuDico();
            switch(choix2)
            {
            case 1:
                ret=AfficheRajoutMot(n);
                break;
            case 2:
                ret=AfficheSupprimeMot(n);
                break;
            case 3:
                AffichecontenuDico();
                break;
            case 4:
                AfficherRechercheDico(n);
                break;
            case 5:
                choix1= afficherMenuPrincipal();
                break;
            }
            break;
        case 2:
            choix2=afficherMenuFile();
             switch(choix2)
            {
            case 1:
                AfficheCreerFile();
                break;
            case 2:
                AfficheMotFileDansDico(n,m);
                break;
            case 3:
                    AffichecontenuFile();
                    break;
            case 4:
               choix1= afficherMenuPrincipal();
                break;
            }
            break;
        case 3:
            exit(-1);

        }
    }
    return 0;
}
