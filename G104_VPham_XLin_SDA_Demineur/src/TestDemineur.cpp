/**
 * @TestDémineur.cpp
 * Projet SDA, Démmineur
 * @author : Vanessa Pham Xingtong Lin groupe 104
 * @IUT de Paris - Rives de Seine
 * @version 09/01/22
 * @brief Tester le demineur
 */

#include <iostream>
#include <string>
#include <sstream>
#include "DemineurOperations.h"
#include "DemineurSousF.h"
using namespace std;

int main(int argc, char* argv[]) {
	// codeope, lignes, colonnes, nb_mines, <nombre de mines>, nb_pas, <nombre de pas>
	string input;
	getline(cin, input);
	string* input_table = split(input);

	if (input_table[0] == "1") {
		ope1(stoi(input_table[1]), stoi(input_table[2]), stoi(input_table[3]));
	}
	else if (input_table[0] == "2") {
		ope2(input_table);
	}
	else if (input_table[0] == "3") {
		ope3(input_table);
	}
	else if (input_table[0] == "4") {
		ope4(input_table);
	}
	return 0;
}