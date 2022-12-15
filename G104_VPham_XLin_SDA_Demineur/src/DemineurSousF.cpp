/**
 * @DémineurSousF.cpp
 * Projet SDA, Démmineur
 * @author : Vanessa Pham Xingtong Lin groupe 104
 * @IUT de Paris - Rives de Seine
 * @version 09/01/22
 * @brief les Sous Fonctions utlisés par les Operations du demineur
 */

#include <iostream>
#include <string>
#include <sstream>
#include "DemineurOperations.h"
#include "DemineurSousF.h"
using namespace std;


//éviter depassement de grille
bool exists(int probleme[], int position, int max_length) {
	for (int i = 3; i < max_length; i++) {
		if (probleme[i] == position) {
			return true;
		}
	}
	return false;
}

// Vérifier si c'est la position de la mine
bool boum(int x, int y, int* probleme) {
	int colonnes = probleme[1];
	int mines = probleme[2];
	for (int i = 3; i < (mines + 3); i++) {
		if ((y * colonnes + x) == probleme[i])
			return true;
	}
	return false;
}

// split pour separer le cin(entree) type string
string* split(string input) {
	int nb_parameters = 1;
	for (int i = 0; input[i]; i++)
		if (input[i] == ' ')
			nb_parameters++;
	string* result = new string[nb_parameters];
	stringstream ssin(input);
	int i = 0;
	while (ssin.good() && i < nb_parameters) {
		ssin >> result[i];
		i++;
	}
	return result;
}

// Remplir une case de la grille
char remplir_case(int x, int y, int* probleme) {
	if (boum(x, y, probleme)) { return 'm'; }
	int index_max_lignes = probleme[0] - 1;
	int index_max_colonnes = probleme[1] - 1;
	int somme = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!((x + i) < 0 || (y + j) < 0 || (x + i) > index_max_colonnes || (y + j) > index_max_lignes || (i == 0 && j == 0)))
				if (boum(x + i, y + j, probleme))
					somme++;
		}
	}
	if (somme > 0) {
		char chiffre = '0' + somme;//les chiffres sont affichés en char
		return chiffre;
	}
	else {
		return ' ';//si autour de lui il y a pas de mine, afficher ' '
	}
}


//affiche grille
void afficher_grille(char** grille, int lignes, int colonnes) {
	cout << to_string(lignes) + " " << to_string(colonnes) << endl;
	for (int x = 0; x < colonnes; x++) {
		cout << " ---";
	}
	cout << endl;
	for (int y = 0; y < lignes; y++) {
		for (int x = 0; x < colonnes; x++) {
			cout << "|" << " " << grille[x][y] << " ";
		}
		cout << '|' << endl;
		for (int x = 0; x < colonnes; x++) {
			cout << " ---";
		}
		cout << endl;
	}
}

//si la case a mine affiche m
void devoiler_mines(char** grille, int* probleme, int lignes, int colonnes) {
	for (int x = 0; x < colonnes; x++) {
		for (int y = 0; y < lignes; y++) {
			if (boum(x, y, probleme)) {
				grille[x][y] = 'm';
			}
		}
	}
}

//initialiser grille
char** init_grille(int lignes, int colonnes) {
	char** grille = new char* [colonnes];
	for (int x = 0; x < colonnes; x++) {
		grille[x] = new char[lignes];
	}
	return grille;
}
