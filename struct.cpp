#include <string>
#include <iostream>
#include "struct.h"
#include <string.h>

using namespace std;
using namespace tree;

struct tree::treeNode {   // copiato direttamente da tree cazzi in culo
    Label label;
    treeNode *firstChild;
    treeNode *nextSibling;
};


void Dtree::findWall(const string val, string& type, string& l)
{
  int Index = val.find(Dtree::wall,0);

  if(Index == val.size()) return;

  for( int i = 0; i < Index; i++)
  {
     l.resize(l.size()+1,val.at(i));    // copio in l quello prima del wall
  }
  for(unsigned int i = Index+3; i < val.size(); i++)
  {
    type.resize(type.size()+1,val.at(i));  // copio in l quello dopo del wall
  }
  cout << l << type;
}


// Funzione ausiliaria per la visualizzazione strutturata
void printTreeAUX(const Tree& t, int depth) {
    if (isEmpty(t)) return;

    string indent = "--";
// Inserisco indentazione corrispondente alla profondita' raggiunta
    for (int i=0; i<depth; i++)
        cout << indent;

// Visualizzo il contenuto informativo associato a t
    string l, type;
    Dtree::findWall(t->label, type, l);

    cout << l << endl;

// Chiamata ricorsiva di printTree su ciascuno dei figli di t (profondita' incrementata di 1)
    Tree auxT = t->firstChild;
    while (!isEmpty(auxT)) {
        printTreeAUX(auxT, depth+1);
        auxT = auxT->nextSibling;
    }
}



/*******************************************************************************************************/
// Visualizzazione strutturata: parto dal livello 0
void Dtree::printTree(const tree::Tree& t) {
    printTreeAUX(t, 0);
}
