/**
 * @DémineurOperations.cpp
 * Projet SDA, Démmineur
 * @author : Vanessa Pham Xingtong Lin groupe 104
 * @IUT de Paris - Rives de Seine
 * @version 09/01/22
 * @brief les Operations du demineur
 */

#include <iostream>
#include <string>
#include <sstream>
#include "DemineurOperations.h"
#include "DemineurSousF.h"
using namespace std;

//OPERATION 1
int* ope1(int lignes, int colonnes, int mines) {
	int* probleme = new int[mines + 3];
	probleme[0] = lignes;
	probleme[1] = colonnes;
	probleme[2] = mines;
	int tmp;//random les mines
	for (int i = 3; i < mines + 3; i++) {
		tmp = (rand() % (lignes * colonnes) + 1);
		while (exists(probleme, tmp, lignes * colonnes)) {
			tmp = (rand() % (lignes * colonnes));
		}
		probleme[i] = tmp;
	};
	string c = "";
	c += to_string(lignes) + " " + to_string(colonnes) + " " + to_string(mines) + " ";
	for (int i = 3; i < mines + 3; i++) {
		c += to_string(probleme[i]) + " ";
	}
	cout << c << endl;
	return probleme;
}

//OPERATION 2
void ope2(string* input_table) {
	int ope = stoi(input_table[0]);//transforme string en int
	int lignes = stoi(input_table[1]);
	int colonnes = stoi(input_table[2]);
	int mines = stoi(input_table[3]);
	int* probleme = new int[3 + mines];
	for (int i = 1; i <= (mines + 3); i++) {
		probleme[i - 1] = stoi(input_table[i]);
	}
	int pas = stoi(input_table[3 + mines + 1]);

	int index_move = 3 + mines + 1 + 1;
	int max_index_move = 3 + mines + 1 + pas;
	// Initialisation de la grille
	char** grille = init_grille(lignes, colonnes);
	char** grille_modele = init_grille(lignes, colonnes);
	// Construction de la grille
	for (int x = 0; x < colonnes; x++) {
		for (int y = 0; y < lignes; y++) {
			grille_modele[x][y] = remplir_case(x, y, probleme);
			grille[x][y] = '.';
		}
	}

	while (index_move <= max_index_move) {
		string move = input_table[index_move];
		char action = move[0];
		int index = stoi(move.substr(1, move.length() - 1));
		int move_y = index / colonnes;
		int move_x = index % colonnes;
		int result = play2(grille, grille_modele, probleme, action, move_x, move_y);
		index_move++;
	}afficher_grille(grille, lignes, colonnes);
	cout << endl;
}

//OPERATION 3
void ope3(string* input_table) {
	int ope = stoi(input_table[0]);
	int lignes = stoi(input_table[1]);
	int colonnes = stoi(input_table[2]);
	int mines = stoi(input_table[3]);
	int* probleme = new int[3 + mines];
	for (int i = 1; i <= (mines + 3); i++) {
		probleme[i - 1] = stoi(input_table[i]);
	}
	int pas = stoi(input_table[3 + mines + 1]);

	int index_move = 3 + mines + 1 + 1;
	int max_index_move = 3 + mines + 1 + pas;
	// Initialisation de la grille
	char** grille = init_grille(lignes, colonnes);
	char** grille_modele = init_grille(lignes, colonnes);
	// Construction de la grille
	for (int x = 0; x < colonnes; x++) {
		for (int y = 0; y < lignes; y++) {
			grille_modele[x][y] = remplir_case(x, y, probleme);
			grille[x][y] = '.';
		}
	}

	while (index_move <= max_index_move) {
		string move = input_table[index_move];
		char action = move[0];
		int index = stoi(move.substr(1, move.length() - 1));
		int move_y = index / colonnes;
		int move_x = index % colonnes;
		int result = play3(grille, grille_modele, probleme, action, move_x, move_y);
		index_move++;
	}
}

//OPERATION 4
void ope4(string* input_table) {
	int ope = stoi(input_table[0]);
	int lignes = stoi(input_table[1]);
	int colonnes = stoi(input_table[2]);
	int mines = stoi(input_table[3]);
	int* probleme = new int[3 + mines];
	for (int i = 1; i <= (mines + 3); i++) {
		probleme[i - 1] = stoi(input_table[i]);
	}
	int pas = stoi(input_table[3 + mines + 1]);

	int index_move = 3 + mines + 1 + 1;
	int max_index_move = 3 + mines + 1 + pas;
	// Initialisation de la grille
	char** grille = init_grille(lignes, colonnes);
	char** grille_modele = init_grille(lignes, colonnes);
	// Construction de la grille
	for (int x = 0; x < colonnes; x++) {
		for (int y = 0; y < lignes; y++) {
			grille_modele[x][y] = remplir_case(x, y, probleme);
			grille[x][y] = '.';
		}
	}

	while (index_move <= max_index_move) {
		string move = input_table[index_move];
		char action = move[0];
		int index = stoi(move.substr(1, move.length() - 1));
		int move_y = index / colonnes;
		int move_x = index % colonnes;
		int result = play4(grille, grille_modele, probleme, action, move_x, move_y);
		index_move++;
	}
}

//play2 pour l'OPERATION 2
int play2(char** grille, char** grille_modele, int* probleme, char action, int x, int y) {
	int lignes = probleme[0];
	int colonnes = probleme[1];
	int mines = probleme[2];
	if (action == 'D') {
		if (boum(x, y, probleme)) {
			devoiler_mines(grille, probleme, lignes, colonnes);
			return 0;
		}
		else if (grille_modele[x][y] >= '1' && grille_modele[x][y] <= '8' && grille[x][y] == '.') {
			grille[x][y] = grille_modele[x][y];
		}
		// récursif
		else if (grille_modele[x][y] == ' ' && grille[x][y] == '.') {
			grille[x][y] = ' ';
			if (x > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play2(grille, grille_modele, probleme, action, x - 1, y);
			}
			if (x < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play2(grille, grille_modele, probleme, action, x + 1, y);
			}
			if (y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play2(grille, grille_modele, probleme, action, x, y - 1);
			}
			if (y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play2(grille, grille_modele, probleme, action, x, y + 1);
			}
			if (x > 0 && y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play2(grille, grille_modele, probleme, action, x - 1, y - 1);
			}
			if (x > 0 && y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play2(grille, grille_modele, probleme, action, x - 1, y + 1);
			}
			if (x < colonnes - 1 && y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play2(grille, grille_modele, probleme, action, x + 1, y - 1);
			}
			if (x < colonnes - 1 && y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play2(grille, grille_modele, probleme, action, x + 1, y + 1);
			}
		}
	}
	else if (action == 'M') {
		if (grille_modele[x][y] != 'm' && grille[x][y] == '.') {
			grille[x][y] = 'x';
			devoiler_mines(grille, probleme, lignes, colonnes);
			return 0;
		}
		else if (grille[x][y] == '.') {
			grille[x][y] = 'x';
		}
	}
	return 1;
}

//play3 pour l'OPERATION 3
int play3(char** grille, char** grille_modele, int* probleme, char action, int x, int y) {
	int lignes = probleme[0];
	int colonnes = probleme[1];
	int mines = probleme[2];
	if (action == 'D') {
		if (boum(x, y, probleme)) {
			devoiler_mines(grille, probleme, lignes, colonnes);
			cout << "Game not won" << endl;
			return 0;
		}
		else if (grille_modele[x][y] >= '1' && grille_modele[x][y] <= '8' && grille[x][y] == '.') {
			grille[x][y] = grille_modele[x][y];
		}
		// récursif
		else if (grille_modele[x][y] == ' ' && grille[x][y] == '.') {
			grille[x][y] = ' ';
			if (x > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play3(grille, grille_modele, probleme, action, x - 1, y);
			}
			if (x < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play3(grille, grille_modele, probleme, action, x + 1, y);
			}
			if (y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play3(grille, grille_modele, probleme, action, x, y - 1);
			}
			if (y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play3(grille, grille_modele, probleme, action, x, y + 1);
			}
			if (x > 0 && y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play3(grille, grille_modele, probleme, action, x - 1, y - 1);
			}
			if (x > 0 && y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play3(grille, grille_modele, probleme, action, x - 1, y + 1);
			}
			if (x < colonnes - 1 && y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play3(grille, grille_modele, probleme, action, x + 1, y - 1);
			}
			if (x < colonnes - 1 && y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play3(grille, grille_modele, probleme, action, x + 1, y + 1);
			}
		}
	}
	else if (action == 'M') {
		if (grille_modele[x][y] != 'm' && grille[x][y] == '.') {
			grille[x][y] = 'x';
			devoiler_mines(grille, probleme, lignes, colonnes);
			cout << "Game not won" << endl;
			return 0;
		}
		else if (boum(x, y, probleme)) {
			devoiler_mines(grille, probleme, lignes, colonnes);
			cout << "Game not won" << endl;
			return 0;
		}
		else if (grille[x][y] == '.') {
			grille[x][y] = 'x';
		}
	}
	int minefind = 0;
	for (int x = 0; x < colonnes; x++) {
		for (int y = 0; y < lignes; y++) {
			if ((grille[x][y] == '.') || (grille[x][y] == 'x' && grille_modele[x][y] == 'm')) {
				grille_modele[x][y] = remplir_case(x, y, probleme);
				minefind++;
			}
		}
	}
	if (minefind == mines) {
		cout << "Game Won" << endl;
	}

	return 1;
}

//play4 pour l'OPERATION 4
int play4(char** grille, char** grille_modele, int* probleme, char action, int x, int y) {
	int lignes = probleme[0];
	int colonnes = probleme[1];
	int mines = probleme[2];
	if (action == 'D') {
		if (boum(x, y, probleme) == true) {
			devoiler_mines(grille, probleme, lignes, colonnes);
			cout << "Game lost" << endl;
			return 0;
		}
		else if (boum(x, y, probleme) == false) {
			cout << "Game not lost" << endl;
		}
		else if (grille_modele[x][y] >= '1' && grille_modele[x][y] <= '8' && grille[x][y] == '.') {
			grille[x][y] = grille_modele[x][y];
		}
		// récursif
		else if (grille_modele[x][y] == ' ' && grille[x][y] == '.') {
			grille[x][y] = ' ';
			if (x > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play4(grille, grille_modele, probleme, action, x - 1, y);
			}
			if (x < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play4(grille, grille_modele, probleme, action, x + 1, y);
			}
			if (y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play4(grille, grille_modele, probleme, action, x, y - 1);
			}
			if (y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play4(grille, grille_modele, probleme, action, x, y + 1);
			}
			if (x > 0 && y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play4(grille, grille_modele, probleme, action, x - 1, y - 1);
			}
			if (x > 0 && y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play4(grille, grille_modele, probleme, action, x - 1, y + 1);
			}
			if (x < colonnes - 1 && y > 0) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play4(grille, grille_modele, probleme, action, x + 1, y - 1);
			}
			if (x < colonnes - 1 && y < colonnes - 1) {//eviter les erreur de depassement; pas soyez plus grand que grille
				play4(grille, grille_modele, probleme, action, x + 1, y + 1);
			}
		}
	}
	else if (action == 'M') {
		if (grille_modele[x][y] != 'm' && grille[x][y] == '.') {
			grille[x][y] = 'x';
			devoiler_mines(grille, probleme, lignes, colonnes);
			if (grille_modele[x][y] = 'm' && grille[x][y] == 'x')
				cout << "Game lost" << endl;
			return 0;
		}
		else if (grille[x][y] == '.') {
			grille[x][y] = 'x';
		}
	}

	int minefind = 0;
	for (int x = 0; x < colonnes; x++) {
		for (int y = 0; y < lignes; y++) {
			if ((grille[x][y] == '.') || (grille[x][y] == 'x' && grille_modele[x][y] == 'm')) {
				grille_modele[x][y] = remplir_case(x, y, probleme);
				minefind++;
			}
		}
	}
	if (minefind == mines) {
		cout << "Game not lost" << endl;
	}

	return 1;
}