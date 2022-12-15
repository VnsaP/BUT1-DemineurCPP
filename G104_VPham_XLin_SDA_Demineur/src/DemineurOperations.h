#ifndef _DEMINEURFONCTIONS_H_
#define _DEMINEURFONCTIONS_H_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * OPERATION 1
 * @brief Rentrer et afficher un probleme
 * @param[in] int : le nombre de lignes.
 * @param[in] int : le nombre de colonnes.
 * @param[in] int : le nombre de mines.
 * @param[out] int : la liste des positions des mines donnés aléatoirement.
 * @pre le nombre de mines doit être entre lignes*colonnes.
 */
int* ope1(int lignes, int colonnes, int mines);

/**
 * OPERATION 2
 * @brief Rentrer un probleme, la position des mines,
 * @brief rentrer un historique de coup
 * @brief créer et affiche une grille selon le probleme et l'historique de coup.
 * @param[in] string : le probleme, les positions des mines, les coups.
 * @param[out] string : Le nombre de colonnes et lignes.
 * @param[out] string : une grille.
 */
void ope2(string* input_table);

/**
 * OPERATION 3
 * @brief similaire à l'opération 2 MAIS n'affiche QUE le resultat
 * @param[in] string : le probleme, les positions des mines, les coups.
 * @param[out] string : Resulat : "Game won" ou "Game not won"
 */
void ope3(string* input_table);

/**
 * OPERATION 4
 * @brief similaire à l'opération 2 MAIS n'affiche QUE le resultat
 * @param[in] string : le probleme, les positions des mines, les coups.
 * @param[out] string : Resulat : "Game lost" ou "Game not lost"
 */
void ope4(string* input_table);

/**
 * "PLAY2" pour l'OPERATION 2
 * @brief Est appellé par l'ope2
 * @brief remplie la grille selon le probleme et l'historique de coup
 * @param[in-out] char** : grille : la 1ere couche visible
 * @param[in-out] char** : grille_modele : la couche revelé après les coups
 * @param[in-out] int* : le probleme
 * @param[in] char : l'action: les coups joués
 * @param[in] int : la position sur la grille en abscisse x
 * @param[in] int : la position sur la grille en ordonnée y
 */
int play2(char** grille, char** grille_modele, int* probleme, char action, int x, int y);

/**
 * "PLAY3" pour l'OPERATION 3
 * @brief Est appellé par l'ope3
 * @brief remplie la grille selon le probleme et l'historique de coup
 * @brief calcule le résultat "Game won" ou "Game not won"
 * @param[in-out] char** : grille : la 1ere couche visible
 * @param[in-out] char** : grille_modele : la couche revelé après les coups
 * @param[in-out] int* : le probleme
 * @param[in] char : l'action: les coups joués
 * @param[in] int : la position sur la grille en abscisse x
 * @param[in] int : la position sur la grille en ordonnée y
 */
int play3(char** grille, char** grille_modele, int* probleme, char action, int x, int y);

/**
 * "PLAY4" pour l'OPERATION 4
 * @brief Est appellé par l'ope4
 * @brief remplie la grille selon le probleme et l'historique de coup
 * @brief calcule le résultat "Game lost" ou "Game not lost"
 * @param[in-out] char** : grille : la 1ere couche visible
 * @param[in-out] char** : grille_modele : la couche revelé après les coups
 * @param[in-out] int* : le probleme
 * @param[in] char : l'action: les coups joués
 * @param[in] int : la position sur la grille en abscisse x
 * @param[in] int : la position sur la grille en ordonnée y
 */
int play4(char** grille, char** grille_modele, int* probleme, char action, int x, int y);

#endif
