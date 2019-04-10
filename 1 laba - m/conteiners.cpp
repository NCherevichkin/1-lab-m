#include "conteiner.h"
#include "shape_atd.h"
#include <fstream>

using namespace std;

namespace simple_shapes {
	// Инициализация контейнера
	void Init(container &c) { c.len = 0; }
	// Очистка контейнера от элементов 
	// (освобождение памяти)

	void Clear(container &c) {
		for (int i = 0; i < c.len; i++) {
			delete c.cont[i];
		}
		c.len = 0;
	}
	// Сигнатуры требуемых внешних функций
	shape *In(ifstream &ifdt);

	// Ввод содержимого контейнера из указанного потока
	void In(container &c, ifstream &ifst) {
		while (!ifst.eof())
		{
			if (c.len > 99)
			{
				break;
			}
			else
			{
				if ((c.cont[c.len] = In(ifst)) != 0)
					c.len++;
			}
		}

	}
	// Сигнатуры требуемых внешних функций
	//void Out(shape &s, ofstream &ofst);
	double V(shape &s);

	void Out(shape &s, ofstream &ofst);
	// Вывод содержимого контейнера в указанный поток
	void Out(container &c, ofstream &ofst)
	{
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		for (int i = 0; i < c.len; i++)
		{
			ofst << i << ": ";
			Out(*(c.cont[i]), ofst);
			ofst << "V = "
				<< V(*(c.cont[i])) << endl;
		}
	}
	bool Compare(shape *first, shape *second);
	//-----------------------------------------------------
	// Сортировка содержимого контейнера
	void Sort(container &c) {
		for (int i = 0; i < c.len - 1; i++) {
			for (int j = i + 1; j < c.len; j++) {
				if (Compare(c.cont[i], c.cont[j])) {
					shape *tmp = c.cont[i];
					c.cont[i] = c.cont[j];
					c.cont[j] = tmp;
				}
			}
		}
	}
} // end simple_shapes namespace

