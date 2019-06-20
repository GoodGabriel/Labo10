// Compilare con g++ -Wall -std=c++11 *.cpp -o tree

#include "struct.h"
/* Miglioramenti:

-Se il file menu.txt non esiste che facco?
-Fare il caso in cui i label della due siano incompleti ( non nella forma label:::type)


*/

using namespace std;
using namespace tree;

void readFromStreamMenu(istream& str, string& Menu)
{ string line;
    while (!str.eof())
        {
        getline(str, line);
        Menu = Menu + "\n" + line;
        }
    str.clear();
}


void readMenu(string &Menu)
{
    ifstream ifs("menu.txt"); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) Menu = "\nErrore apertura file Menu.txt, impossibile caricare il menu\n";
    readFromStreamMenu(ifs, Menu);
}


int main()
{

string Menu = "";
readMenu(Menu);

try {
/*
vector<tree::Tree> v(maxreg);
for (int j=0; j<maxreg; ++j) {v[j] = tree::createEmpty();}

list::List lst;
high_resolution_clock::time_point t1, t2;
int i;
string nome_file,index;
double duration;

char ch;
*/
string nome_file;
char ch;
tree::Label l1, l2, l;

Tree t = createEmpty();; // da inizializzare però


cout << Menu;

while (true)
{
   cout << "\nDigitare p per stampare il menu, q per terminare\n> ";
   cin >> ch;
   cin.ignore();

   if (ch=='q')
      break;

   switch(ch)
   {
   case '1':
   cin >> nome_file;    // acquisisco il nome del file
   if (!cin) throw runtime_error("Errore inserimento nome file\n");

   readFromFile(nome_file); // quale redfromfile?
   break;

   case '2':  //Inserimento di un nodo etichettato labelFiglio attaccato a un padre labelPadre

   cin >> l1 >> l2; // prendo i due label pero come voglio io
   if (!cin) throw runtime_error("Errore inserimento dati\n");
   removeBlanksAndLower(l1);
   removeBlanksAndLower(l2);
   if(tree::addElem(l1, l2, t) == FAIL) cout << "Rincontrolla la validità"; // quale insertEleme? e se il padre non si trova?
   break;

   case '3': //Cancellazione di un nodo dall'albero;

   cin >> l;
   removeBlanksAndLower(l);
   if(tree::deleteElemI(l, t) == FAIL) cout << "Errore";
   break;

   case '4':
   cin >> l1 >> l2;
   removeBlanksAndLower(l1);
   //Tree aux = t;
  // aux = tree::getNode(l1, aux);
  // aux->label = l2;
   break;

   case '5':
   Dtree::printTree(t);
   break;

   case 'p':
   cout << Menu;
   break;

   default:
   cout << "\nOpzione non valida\n";
   }
}
return 0;
}
catch (runtime_error &msg)
   {cerr << "Errore a runtime: " << msg.what() << endl;}
catch (...)
   {cerr << "Eccezione non riconosciuta\n";}
}
