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
		switch (k) {
		case 1:
			sp = new shape;
			sp->k = shape::key::BOX;
			In(sp->r, ifst);
			break;
		case 2:
			sp = new shape;
			sp->k = shape::key::SHERE;
			In(sp->t, ifst);
			break;
		case 3:
			sp = new shape;
			sp->k = shape::key::TETRA;
			In(sp->f, ifst);
			break;
		default:
			return 0;
		}
		ifst >> sp->temp;
		return sp;
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
	// Cравнение ключей двух программных объектов
	// Сигнатуры требуемых функций
	double V(shape &s);
	//-----------------------------------------------------
	bool Compare(shape *first, shape *second) {
		return V(*first) < V(*second);
	}



	// Вывод параметров текущей фигуры в поток
	void Out(shape &s, ofstream &ofst) {
		switch (s.k) {
		case shape::key::BOX:
			Out(s.r, ofst);
			break;
		case shape::key::SHERE:
			Out(s.t, ofst);
			break;
		default:
		case shape::key::TETRA:
			Out(s.f, ofst);
			break;
			ofst << "Incorrect figure!" << endl;
		}
		ofst << "Melting point = " << s.temp << " °C " << endl;
	}

} // end simple_shapes namespace

