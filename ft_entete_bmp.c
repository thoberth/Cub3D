/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:55:27 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/07 16:45:15 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct entete_struct {  //structure (globale) ou seront stockées les infos de l'entete
	char signature[2];
	int taille;
	int offset;
	int taille_entete;
	int largeur;
	int longueur;
	int plans;
	int bpp;
	int compression;
	int taille_image;
	int Hresolution;
	int Vresolution;
	int nbr_couleur;
	int nbr_couleur_importante;
}entete;

int hex2dec (unsigned char hex[4],int nombre) //Fonction permettant de convertir un nombre hexa
{					      //en décimal (plus facile à lire)
	int resultat = 0;
	int i;

	for (i = nombre - 1; i >= 0; i--)
	{
		resultat = resultat * 256 + hex[i];
	}
	return resultat;
}

void lire_fichier (char nom[255])
{
	unsigned char temp[4]; //Zone mémoire temporaire où on stoque ce qui est lu dans le fichier avant
	FILE * fichier;        //de le traiter.

	fichier = fopen (nom,"r");

	fread (&entete.signature,2,1,fichier); //signature codée sur 2 octets
	fread (&temp,4,1,fichier);
	entete.taille = hex2dec (temp,4); //taille totale du fichier, 4 octets
	fread (&temp,4,1,fichier); //reservé
	fread (&temp,4,1,fichier); //Offset de début de l'image, 4 octets
	entete.offset = hex2dec (temp,4);
	fread (&temp,4,1,fichier); //Taille de l'entete, 4 octets
	entete.taille_entete = hex2dec (temp,4);
	fread (&temp,4,1,fichier); //Largeur, 4 octets
	entete.largeur = hex2dec(temp,4);
	fread (&temp,4,1,fichier); //Longueur, 4 octets
	entete.longueur = hex2dec(temp,4);
	fread (&temp,2,1,fichier); //Nombre de plans ( 1 ), 2 octets
	entete.plans = hex2dec (temp,2);
	fread (&temp,2,1,fichier); //Nbre de bit par pixels, 2 octets
	entete.bpp = hex2dec (temp,2);
	fread (&temp,4,1,fichier); //Compression, 0 = rien, 4 octets
	entete.compression = hex2dec (temp,4);
	fread (&temp,4,1,fichier); //Taille de l'image, 4 octets
	entete.taille_image = hex2dec (temp,4);
	fread (&temp,4,1,fichier); //Resolution horizotale en pixels par mètre, 4octets
	entete.Hresolution = hex2dec (temp,4);
	fread (&temp,4,1,fichier); //Resolution verticale, en ixels par mètre, 4 octets
	entete.Vresolution = hex2dec (temp,4);
	fread (&temp,4,1,fichier); //Nombre de couleur utilisées, 0 = toutes, 4 octets
	entete.nbr_couleur = hex2dec (temp,4);
	fread (&temp,4,1,fichier); //Nombre de couleurs importantes, 0 = toues, 4 octets
	entete.nbr_couleur_importante = hex2dec (temp,4);

	//Si c'est un image 8 bit, cette entête est suivie de la palette.
        //Après la palette, ce sont les données de l'image
	
	fclose (fichier);
}

main ()
{
	lire_fichier ("img.bmp"); //remplacez ici par le fichier, ou par un scanf ;-)

	printf ("Signature : %s\n",entete.signature);
	printf ("Taille du fichier : %d\n",entete.taille);
	printf ("Offset de début de l'image : %d\n",entete.offset);
	printf ("Taille du Bitmap Info : %d\n",entete.taille_entete);
	printf ("Largeur : %d\n",entete.largeur);
	printf ("Longueur : %d\n",entete.longueur);
	printf ("Nombre de plans : %d\n",entete.plans);
	printf ("Bits par pixels : %d\n",entete.bpp);
	printf ("Schéma de compression : %d\n",entete.compression);
	printf ("Taille de l'image : %d\n",entete.taille_image);
	printf ("Résolution verticale : %d\n",entete.Vresolution);
	printf ("Résolution horizontale : %d\n",entete.Hresolution);
	printf ("Nombre de couleurs (0 = toutes) : %d\n",entete.nbr_couleur);
	printf ("Nombre de couleurs importantes (0 = toutes) : %d\n",entete.nbr_couleur_importante);
	
}