#ifndef _DEMINEURSOUSF_H_
#define _DEMINEURSOUSF_H_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * @brief type Booléen, s'assurer que la position d'une mine ne dépasse pas la limite
 * @param[in] int : le probleme
 * @param[in] int : la position de mine
 * @param[in] int : la limite
 * @param[return] : true ou false
 */
bool exists(int probleme[], int position, int max_length);

/**
 * @brief type Booléen, Vérifier si il y a une mine à une position
 * @param[in-out] int* : le probleme
 * @param[in] int : une variable de calcule x
 * @param[in] int : une variable de calcule y
 * @param[return] : true ou false
 */
bool boum(int x, int y, int* probleme);

/**
 * @brief Séparer les int et char d'une entrée en string
 * @param[in] string : input une entrée.
 * @param[return] string : le int OU le char
 */
string* split(string input);

/**
 * @brief Remplir les cases de la grille selon le probleme et l'historique de coup
 * @param[in] int : la position en abscisse x sur la grille
 * @param[in] int : la position en ordonnée y sur la grille
 * @param[return] : un contenue : '.' , ' ' , 'm' , 'x'.
 */
char remplir_case(int x, int y, int* probleme);

/**
 * @brief afficher la structure grille
 * @param[out] char : la structure grille
 * @param[in] int : le nombre de lignes
 * @param[in] int : le nombre de colonnes
 */
void afficher_grille(char** grille, int lignes, int colonnes);

/**
 * @brief Revele la position des mines avec un 'm' sur la grille apres le dernier coup
 * @param[out] char : la structure de la grille : la couche revelé après les coups
 * @param[in] int : le nombre de lignes
 * @param[in] int : le nombre de colonnes
 */
void devoiler_mines(char** grille, int* probleme, int lignes, int colonnes);

/**
 * @brief Initialise une grille
 * @param[in] int : le nombre de lignes
 * @param[in] int : le nombre de colonnes
 */
char** init_grille(int lignes, int colonnes);

#endif 

