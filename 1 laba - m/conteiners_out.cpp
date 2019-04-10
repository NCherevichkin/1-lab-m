#include "conteiner.h"
#include "shape_atd.h"
#include <fstream>

using namespace std;
namespace simple_shapes {
	void Out(shape &s, ofstream &ofst);
	double V(shape &s);

	//-----------------------------------------------------
	// ����� ������ ���������������
	void OutBox(container &c, ofstream &ofst) {
		ofst << "Only box." << endl;
		for (int i = 0; i < c.len; i++) {
			ofst << i << ": ";
			if (c.cont[i]->k == shape::BOX)
			{
				Out(*(c.cont[i]), ofst);
				ofst << "V = "
					<< V(*(c.cont[i])) << endl;
			}
			else
				ofst << endl;
		}
	}
}