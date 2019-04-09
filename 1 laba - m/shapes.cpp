#include <fstream>
#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
  // Сигнатуры требуемых внешних функций 
  void In(box &r, ifstream &ist);
  void In(share  &t, ifstream &ist);
  void In(tetra  &f, ifstream &ist);
  // Ввод параметров обобщенной фигуры из файла
  shape* In(ifstream &ifst)
  {
    shape *sp;
    int k;
    ifst >> k;
    switch(k) {
    case 1:
      sp = new shape;
      sp->k = shape::key::BOX;
      In(sp->r, ifst);
      return sp;
    case 2:
      sp = new shape;
      sp->k = shape::key::SHERE;
      In(sp->t, ifst);
      return sp;
	case 3:
		sp = new shape;
		sp->k = shape::key::TETRA;
		In(sp->f, ifst);
		return sp;
    default:
      return 0;
    }
  }

  void Out(share  &t, ofstream &ofst);
  void Out(box &r, ofstream &ofst);
  void Out(tetra &f, ofstream &ofst);
  double V(share &t);
  double V(box &r);
  double V(tetra &f);

  // Вычисление обьема фигур
  double V(shape &s)
  {
	  switch (s.k) {
	  case shape::key::BOX:
		  return V(s.r);
	  case shape::key::SHERE:
		  return V(s.t);
	  case shape::key::TETRA:
		  return V(s.f);
	 	  default:
		  return -1;
	  }
  }

  // Вывод параметров текущей фигуры в поток
  void Out(shape &s, ofstream &ofst) {
    switch(s.k) {
    case shape::key::BOX:
      Out(s.r, ofst);
      break;
    case shape::key::SHERE:
      Out(s.t, ofst);
      break;
	case shape::key::TETRA:
		Out(s.f, ofst);
		break;
    default:
      ofst << "Incorrect figure!" << endl;
    }
  }
} // end simple_shapes namespace


