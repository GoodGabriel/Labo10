
/*
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
*/
#include "tree-chsib.h"

using namespace std;

namespace Dtree{

typedef string Label;

const string wall = ":::";


/* Funzioni che non caratterizzano il TDD Tree, ma che servono per input/output */
tree::Tree readFromFile(string);
tree::Tree readFromStream(istream&);
void printTree(const tree::Tree&, const unsigned int);
void modify(string, string, string, tree::Tree&);
tree::Tree getNode(const Label, const tree::Tree&);
void prediction ( string&, const tree::Tree&);
void findWall(const string, string&, string&); //ritorna il valore dell'espressione utile per le operazioni, il tipo di valore verrà inserito nella variabile&
//funzioni inserite nel DecisionTree perchè utili solo con esso


}
