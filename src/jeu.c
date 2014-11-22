/**
@brief jeu.c a le code des fonctions pour le module jeu.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/jeu.c
@version 1.0
@date 2012/06/07
*/

#include <stdio.h>
#include <stdlib.h>

#include "jeu.h"
#include "snake.h"
#include "terrain.h"
#include "nourriture.h"

void jeuGetScore (const char * monFic, Jeu *pJeu);

void jeuInstruction(const char * monFic,Jeu *pJeu);

/*Initialise le jeu, en initialisant le snake et le terrain*/
void jeuInit(Jeu *pJeu)
{
	snkInit(&(pJeu->snk));
	terAfficheDepuisFichier("data/snkLevel1.txt",&(pJeu->ter));
	snkCreation(&(pJeu->snk));
	nourPosition(&(pJeu->ter),&(pJeu->nour));
	pJeu->niveau=1;
	jeuGetScore("data/max_score.txt",pJeu);
}

/*Libere la place allouée par les composantes du jeu*/
void jeuLibere(Jeu *pJeu)
{
    snkLibere(&(pJeu->snk));
    terLibere(&(pJeu->ter));
    pJeu->niveau=0;
}

/*Renvoie un pointeur sur le terrain*/
Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->ter);
}

/*Renvoie un pointeur sur le snake*/
Snake *jeuGetSnakePtr(Jeu *pJeu)
{
	return &(pJeu->snk);
}

/*Renvoie un pointeur sur la nourriture*/
Nourriture *jeuGetNourPtr(Jeu *pJeu)
{
    return &(pJeu->nour);
}

/*Renvoie un pointeur sur le terrain sans le modifier*/
const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{
	return &(pJeu->ter);
}

/*Renvoie un pointeur sur le snake sans le modifier*/
const Snake *jeuGetConstSnakePtr(const Jeu *pJeu)
{
	return &(pJeu->snk);
}

/* Renvoie un pointeur sur la nourriture sans la modifier*/
const Nourriture *jeuGetConstNourPtr(const Jeu *pJeu)
{
    return &(pJeu->nour);
}

/*Renvoie le niveau du jeu*/
const int jeuGetNiveau (const Jeu *pJeu)
{
    return pJeu->niveau;
}

/*Change le niveau du jeu a celui passé en paramètre*/
void jeuSetNiveau (Jeu *pJeu,const int n)
{
    pJeu->niveau = n;
}

/*Change de niveau après un certain score*/
void jeuChangeNiveau(Jeu *pJeu)
{
    if(snkGetScore(&(pJeu->snk)) > 100 && jeuGetNiveau(pJeu)==1)
    {
        terLibere(&(pJeu->ter));
        terAfficheDepuisFichier("data/snkLevel2.txt",&(pJeu->ter));
        pJeu->snk.vies++;
        snkInitPerdu(&(pJeu->snk));
        nourPosition(&(pJeu->ter),&(pJeu->nour));
        jeuSetNiveau(pJeu,2);
    }
    if(snkGetScore(&(pJeu->snk)) > 200 && jeuGetNiveau(pJeu)==2)
    {
        terLibere(&(pJeu->ter));
        terAfficheDepuisFichier("data/snkLevel3.txt",&(pJeu->ter));
        pJeu->snk.vies++;
        snkInitPerdu(&(pJeu->snk));
        nourPosition(&(pJeu->ter),&(pJeu->nour));
        jeuSetNiveau(pJeu,3);
    }
    if(snkGetScore(&(pJeu->snk)) > 300 && jeuGetNiveau(pJeu)==3)
    {
        terLibere(&(pJeu->ter));
        terAfficheDepuisFichier("data/snkLevel4.txt",&(pJeu->ter));
        pJeu->snk.vies++;
        snkInitPerdu(&(pJeu->snk));
        nourPosition(&(pJeu->ter),&(pJeu->nour));
        jeuSetNiveau(pJeu,4);
    }
    if(snkGetScore(&(pJeu->snk)) > 400 && jeuGetNiveau(pJeu)==4)
    {
        terLibere(&(pJeu->ter));
        terAfficheDepuisFichier("data/snkLevel5.txt",&(pJeu->ter));
        pJeu->snk.vies++;
        snkInitPerdu(&(pJeu->snk));
        nourPosition(&(pJeu->ter),&(pJeu->nour));
        jeuSetNiveau(pJeu,5);
    }
    if(snkGetScore(&(pJeu->snk)) > 500 && jeuGetNiveau(pJeu)==5)
    {
        terLibere(&(pJeu->ter));
        terAfficheDepuisFichier("data/snkLevel6.txt",&(pJeu->ter));
        pJeu->snk.vies++;
        snkInitPerdu(&(pJeu->snk));
        nourPosition(&(pJeu->ter),&(pJeu->nour));
        jeuSetNiveau(pJeu,6);
    }
}

/*Teste le nombre de vie du jouer et reinitialise tout si le jouer a perdu*/
int jeuPerdre (Jeu *pJeu)
{
    if(snkGetVies(&(pJeu->snk))<0)
    {
        return 1;
    }
    return 0;
}

/*Récupère l'action du clavier de l'utilisateur*/
void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' :
				if (snkGetDir(&(pJeu->snk))=='h' || snkGetDir(&(pJeu->snk))=='b')
				{
				    snkGauche(&(pJeu->snk), &(pJeu->ter), &(pJeu->nour));
                    jeuChangeNiveau(pJeu); jeuPerdre(pJeu);
				}
				break;
		case 'd' :
                if (snkGetDir(&(pJeu->snk))=='h' || snkGetDir(&(pJeu->snk))=='b' || snkGetDir(&(pJeu->snk))=='n')
                {
                    snkDroite(&(pJeu->snk), &(pJeu->ter), &(pJeu->nour));
                    jeuChangeNiveau(pJeu); jeuPerdre(pJeu);
                }
				break;
		case 'h' :
                if (snkGetDir(&(pJeu->snk))=='g' || snkGetDir(&(pJeu->snk))=='d' || snkGetDir(&(pJeu->snk))=='n')
                {
                    snkHaut(&(pJeu->snk), &(pJeu->ter), &(pJeu->nour));
                    jeuChangeNiveau(pJeu); jeuPerdre(pJeu);
                }
				break;
		case 'b' :
				if (snkGetDir(&(pJeu->snk))=='g' || snkGetDir(&(pJeu->snk))=='d' || snkGetDir(&(pJeu->snk))=='n')
				{
				    snkBas(&(pJeu->snk), &(pJeu->ter), &(pJeu->nour));
                    jeuChangeNiveau(pJeu); jeuPerdre(pJeu);
				}
				break;
	}
}

/*Fait avancer le snake automatiquement a partir de la direction donnee*/
void jeuAvance(Jeu *pJeu)
{
        if (snkGetDir(&(pJeu->snk))=='g')
        {
            snkGauche(&(pJeu->snk), &(pJeu->ter), &(pJeu->nour));
            jeuChangeNiveau(pJeu); jeuPerdre(pJeu);
        }
        if (snkGetDir(&(pJeu->snk))=='d')
        {
            snkDroite(&(pJeu->snk), &(pJeu->ter), &(pJeu->nour));
            jeuChangeNiveau(pJeu); jeuPerdre(pJeu);
        }
        if (snkGetDir(&(pJeu->snk))=='h')
        {
            snkHaut(&(pJeu->snk), &(pJeu->ter), &(pJeu->nour));
            jeuChangeNiveau(pJeu); jeuPerdre(pJeu);
        }
        if (snkGetDir(&(pJeu->snk))=='b')
        {
            snkBas(&(pJeu->snk), &(pJeu->ter), &(pJeu->nour));
            jeuChangeNiveau(pJeu); jeuPerdre(pJeu);
        }
}

/*On remplit le tableau de caractere score a partir d'un fichier*/
void jeuGetScore (const char * monFic, Jeu *pJeu)
{
    int i;
    char monFic2[64];
    FILE * FicA;
    FicA = fopen (monFic,"r");
    if(FicA == NULL)
    {
        sprintf( monFic2, "../%s", monFic);
        FicA = fopen (monFic2,"r");
    }
    if(FicA == NULL)
    {
        printf("Jeu: Impossible d'ouvrir le fichier \n");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<=6;i++)
    {
        fscanf(FicA,"%c",&pJeu->max_score[i]);
    }
    pJeu->max_score[7]='\0';
    if(feof(FicA))
    {
        printf("Jeu: Fin de fichier \n");
    }
    else
    {
        printf("Jeu: Pas de probleme \n");
    }
}

/*On met le nouveau score dans le fichier*/
void jeuSetScore(char * monFic, const Jeu *pJeu)
{
    char monFic2[64];
    FILE * FicA;
    char n_score[7];
    int i,j=1,acc=0, acc1=0;
    FicA = fopen (monFic,"w");

    /*Pour changer un caractère dans un entier*/
    for(i=6;i>=0;i--)
    {
        acc= acc + (pJeu->max_score[i]-'0')*j;
        j*=10;
    }

    acc1=pJeu->snk.score;

    /*Différents calculs pour changer un caractère dans un entier*/
    if(acc1 > acc)
    {
        i=6;
        n_score[7]='\0';

        while(acc1!=0)
        {
            n_score[i]=(char)(acc1%10+'0');
            acc1=acc1/10;
            i--;
        }
        if(i!=0)
        {
            while(i!=0)
            {
                n_score[i]=(char)(0+'0');
                i--;
            }
            n_score[0]=(char)(0+'0');
        }

        /*Ecriture du fichier avec le nouveau score*/
        if(FicA == NULL)
        {
            sprintf( monFic2, "../%s", monFic);
            FicA = fopen (monFic2,"r");
        }
        if(FicA == NULL)
        {
            printf("Impossible d'ouvrir le fichier \n");
            exit(EXIT_FAILURE);
        }

        for(i=0;i<7;i++)
        {
            fprintf(FicA,"%c",n_score[i]);
        }
    }
}

/*On remplit le tableau des instructions du jeu a partir d'un fichier*/
void jeuInstruction(const char * monFic,Jeu *pJeu)
{
    int i=0;
    char monFic2[60];
    FILE * FicA;
    FicA = fopen (monFic,"r");
    if(FicA == NULL)
    {
        sprintf( monFic2, "../%s", monFic);
        FicA = fopen (monFic2,"r");
    }
    if(FicA == NULL)
    {
        printf("Impossible d'ouvrir le fichier \n");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<60;i++)
    {
        fscanf(FicA,"%c",&pJeu->instruction[i]);
    }
    pJeu->instruction[i] = '\0';
    if(feof(FicA))
    {
        printf("Fin de fichier \n");
    }
    else
    {
        printf("Pas de probleme \n");
    }
}
