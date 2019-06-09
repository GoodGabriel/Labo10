
enum TypeofCell {age, category, risc, end };

typedef string Label;

namespace Tree {
struct treeNode {
  nodeArch * rightChild;  //puntatore al figlio di sinistra
  nodeArch * leftChild;
  TypeofCell type; // si potrebbe fare un puntatore ad un array con i valori ma non credo sia così utile
};

struct nodeArch {
  Label label;  //valore immagazinato
  treeNode * ptrCell; //puntatore al figlio
};

typedef Cell* Tree; // la radice

CreateEmpty(Tree&);
isEmpty(const &Tree);
insert(); // ancora da definire questa







}
