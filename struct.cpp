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

void Dtree::findWall(const string val,  string& type, string& l ) //
{
  int Index = val.find(Dtree::wall,0);

  if(Index == std::string::npos) {cout << "ciao"; return; }

  for( int i = 0; i < Index; i++)
  {
     type.resize(type.size()+1,val.at(i));    // copio in l quello prima del wall
  }
  for(unsigned int i = Index+3; i < val.size(); i++)
  {
    l.resize(l.size()+1,val.at(i));  // copio in l quello dopo del wall
  }
}

// Funzione ausiliaria per la visualizzazione strutturata
void printTreeAUX(const Tree& t, int depth, const unsigned int control) {
    if (isEmpty(t)) return;

    string indent = "--";
// Inserisco indentazione corrispondente alla profondita' raggiunta
    for (int i=0; i<depth; i++)
        cout << indent;

// Visualizzo il contenuto informativo associato a t
    string l, type;
    Dtree::findWall(t->label, type, l);

    if(control == 1)
    cout << type << endl;
    if(control == 0)
    cout << l << endl;
    if(control == 2)
    cout << type << ":" << l << endl;

// Chiamata ricorsiva di printTree su ciascuno dei figli di t (profondita' incrementata di 1)
    Tree auxT = t->firstChild;
    while (!isEmpty(auxT)) {
        printTreeAUX(auxT, depth+1, control);
        auxT = auxT->nextSibling;
    }
}

/*******************************************************************************************************/
// Visualizzazione strutturata: parto dal livello 0
void Dtree::printTree(const tree::Tree& t, const unsigned int control) {     // se button è true mostra il tipo ( num 6)
    printTreeAUX(t, 0, control);                                     // se button è false mostra l'argomento ( num 5 )
}

/*******************************************************************************************************/

void findOperation(const string& val, string& resultOperation, string& resultOperand)
{ int i = 0;
  int z = 0;

  resultOperation = "0";
  resultOperand = "";
  cout << val;
  do{
    switch (val[i]) {

      case '>':  if( i == 0) resultOperation = ">"; break;
      case '<':  if( i == 0) resultOperation = "<"; break;
      case '=':  if( resultOperation[0] == '<' || resultOperation[0] == '>') resultOperation.resize(resultOperation.size()+1, '=');
                 if( resultOperation[0] == '0') resultOperation = '=';

      break;

      default:
          resultOperand.resize(resultOperand.size()+1,val.at(i));// resultOperand[z] = val[i+1]; z++;

          break;
  }
i++;
}while(i != val.size());

cout << endl << "Operando: " << resultOperand << ", Operazione: " << resultOperation << endl;
}

int str2int(const string &s) {
  int n;
  istringstream itmp(s);
  itmp >> n;
  return n;
}


bool isOnlyString( const string val)
{
  for(unsigned int z = 0; z < val.size(); z++){

    for(unsigned int i = 0; i < 10; i++)
    {// cout << "val[" << z <<"] (" << val[z] << ") == " << i << endl;
          if( val[z] == '0' || val[z] == '1' || val[z] == '2' || val[z] == '3' || val[z] == '4' ||
          val[z] == '5' || val[z] == '6' || val[z] == '7' || val[z] == '8' ||  val[z] == '9') // non è vero  mai che la seconda sia rappresentate ma è una semplififcazione
          {
            return false;
          }
        }

  }
  return true;

}

bool comparison (string argIn, string argToCompare)
{ bool isIntegerIn = false;
  bool isIntegerComp = false;


//cout << "Controlli int fatti" << endl;

// CHE PALLE QUEI FOR

  string Operation, Operand;

findOperation(argToCompare, Operation, Operand );

isIntegerIn = (!isOnlyString(argIn));

isIntegerComp = (!isOnlyString(Operand));

cout << "Find operation fatta" << endl;

int numIn = 0, numComp = 0;

if(isIntegerIn) numIn = std::stoi(argIn);
if(isIntegerComp) numComp = std::stoi(Operand);
cout << "IN? " << isIntegerIn <<endl;
cout << "COMP? " << isIntegerComp <<endl <<endl;
cout << "->" << numIn << Operation << numComp << endl;


switch(Operation[0])
{ case '<':
  cout << "Casistica minore";
  if(isIntegerIn && isIntegerComp)
      if (numIn < numComp) return true;
      else return false;
  else if (!(isIntegerIn && isIntegerComp))
      if (argIn < Operand) return true;
      else return false;
  else cout << "Una è una stringa e l'latro un intero" << endl;

  break;

  case '>':
  cout << "Casistica maggiore";
  if(isIntegerIn && isIntegerComp)
      if (numIn > numComp) { cout << "ehehe";return true; }
      else return false;
  else if (!(isIntegerIn && isIntegerComp))
      if (argIn > Operand) return true;
      else return false;
  else cout << "Una è una stringa e l'latro un intero" << endl;

  break;

  case '=':

  cout << "Casistica =";
  if(isIntegerIn && isIntegerComp)
      if (numIn == numComp) return true;
      else return false;
  else if (!(isIntegerIn && isIntegerComp))
      if (argIn == Operand) return true;
      else {cout << "."<<argIn<<"." << "rip."<<argToCompare<<"."; return false; }
  else cout << "Una è una stringa e l'latro un intero" << endl;

  break;

  default: break;
}

return false;

}

void Dtree::prediction ( string& result, const tree::Tree& t)

{// cout << endl << "Partita la funzione prediction su " << t->label << endl;
if(t == nullptr) return;

  string argument, type;
  Tree aux = t; // ausiliaria da spostare

  findWall(aux->label, type, argument);
//  cout << "IL FIGLIO CNTIENE " << t->firstChild->label << endl;
  int val = (t->firstChild->label).find("end"); // se il figlio contiene END
  cout << val;
  if(val!=std::string::npos) { cout << "Albero terminato.." << endl << endl;  result = t->firstChild->label; return;}

  cout << "Inserisci il valore di tipo '" << type << "' da confrontare."<< endl;

  string valIn;

  while(true)
  {
  cout << "Inserisci 0 per abortire." << endl;
  cin >> valIn; // inserisco 50

  if( valIn == "0") return;

  //if(aux->firstChild ==  nullptr) { result = aux->label; return; }

    Tree cur = aux->firstChild;

    type = "";
    argument= ""; //resetto le variabili


    Dtree::findWall(cur->label, type, argument);

    //val inserito e da comparare
    if(comparison (valIn, argument)) {
    //  cout << " Vado al figlio perchè percorso giusto";

      prediction(result, cur); // type ora è il valore in entrata da confrontare
      return;
    }

    else {

      do{
        cur = cur->nextSibling;
    //    cout << endl << "Sto andando al fratello" << endl;

        type = "";
        argument= ""; //resetto le variabili

        Dtree::findWall(cur->label, type, argument); // trovo il nuovo argument


        if(comparison (valIn, argument)) {

          prediction(result, cur); // type ora è il valore in entrata da confrontare
          return;
        }

      }while ( cur->nextSibling != nullptr);

      cout << endl << "Valore inserito non trovato. Riprova."<<endl;
    }

}

    //se sei arrivato sino a qua devi perire?


}

/*******************************************************************************************************/
// trovare il tipo associato al file dentro il txt

void find(string& val, list::List& l)
{
  for(unsigned int i = 0; i < l.size; i++){

  string val2 = list::get(i, l);
  if ( val == val2) { val = val + Dtree::wall + list::get(i+1, l); return; }// val assume il tipo dell'oggetto che mi serve
  }
}
/*******************************************************************************************************/
Tree Dtree::getNode(const Label l, const Tree& t)
{
// se l'albero e' vuoto o l'etichetta e' vuota, restituisco il nodo vuoto
    if (isEmpty(t) || l==emptyLabel)
        { cout << "Errore 1";        return emptyTree; }

// se l'etichetta dell'albero è quella cercata, restituisco t
    if (t->label == l)
        return t;

// Chiamata ricorsiva di getNode su ciascuno dei figli di t, finché una delle chiamate non restituisce un valore diverso da emptyTree
    Tree auxT = t->firstChild;
    Tree resNode;
    while (auxT != emptyTree) {
        resNode = getNode(l, auxT);
        if (resNode == emptyTree) // non ho trovato cercando in questo sottoalbero, devo proseguire la scansione dei fratelli
           auxT = auxT->nextSibling;
        else                      // ho trovato: lo restituisco
           return resNode;
    }
return emptyTree; // se arrivo fino a qui, vuole dire che al termine di una ricerca esaustiva nell'albero il nodo non è stato trovato
}

/*******************************************************************************************************/
void Dtree::modify(string l1, string newType, string newArg, tree::Tree& t){
   removeBlanksAndLower(l1);
   removeBlanksAndLower(newType);
   removeBlanksAndLower(newArg);
   Tree aux = t;
   aux = Dtree::getNode(l1, aux);
   if(aux == emptyTree)  { cout << "File non trovato"; return; }
   aux->label = newType + Dtree::wall + newArg;
 }
/*******************************************************************************************************/

Tree Dtree::readFromStream(istream& str)
{
  list::List listina = list::createEmpty();

    Tree t = createEmpty();
    string line;
    Label rootLabel, fatherLabel, childLabel, childtype;
    getline(str, line);
    istringstream instream;            // uso una variabile di tipo istringstream per poter scandire i pezzi di ogni riga usando >>
    instream.clear();
    instream.str(line);
    instream >> rootLabel;             // il primo elemento che si incontra nel file e' l'etichetta della radice, per convenzione su come deve essere fatto il file

    removeBlanksAndLower(rootLabel);
    list::addBack(rootLabel, listina);

    rootLabel =  rootLabel + Dtree::wall ;

    addElem(emptyLabel, rootLabel, t); // la si inserisce nell'albero vuoto, indicando che il padre non c'e' (primo argomento emptyLabel)
    getline(str, line);                // poi si iniziano a scansionare le righe seguenti
    instream.clear();
    instream.str(line);
    while (!str.eof())
        {

           instream >> fatherLabel; // in ogni riga del file, il primo elemento e' l'etichetta del nodo padre e gli altri sono le etichette dei figli
        removeBlanksAndLower(fatherLabel); // normalizzo l'etichetta del padre
      //  cout << endl << "F: " << (fatherLabel + Dtree::wall) << "R" << rootLabel << endl;

        if( (fatherLabel + Dtree::wall) == rootLabel) fatherLabel = rootLabel;
        else find(fatherLabel, listina);

        while (!instream.eof())            // finche' la riga corrente non e' terminata
            {
            instream >> childtype;              // leggo la prossima etichetta ( il tipo della label)
            instream >> childLabel;              // leggo la prossima etichetta

            removeBlanksAndLower(childtype);    // la normalizzo
            removeBlanksAndLower(childLabel);    // la normalizzo

            list::addBack(childtype, listina);
            list::addBack(childLabel, listina); // aggiungi nella lista di oggetti aggiunti

            string childLabelFINALE = childtype + Dtree::wall + childLabel ;
            cout << childLabelFINALE;
          //  printList(listina);
            if(addElem(fatherLabel, childLabelFINALE, t) == OK) cout<< "Inserimento.."<< endl; // e la attacco al padre

            }

        cout << endl;
        getline(str, line);
        instream.clear();
        instream.str(line);
        }
    str.clear();
    return t;
}



Tree Dtree::readFromFile(string nome_file)
{
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmpty();}
  return readFromStream(ifs);
}
