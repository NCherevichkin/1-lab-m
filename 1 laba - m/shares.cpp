#include <fstream>
#include "share_atd.h"

using namespace std;

namespace simple_shapes {
  // ¬вод параметра шара из потока
  void In(share &t, ifstream &ifst) 
  {
    ifst >> t.rad;
  }
  void Out(share &t, ofstream &ofst)
  {
    ofst << "It is Sphere: r = " 
      << t.rad << endl;
  }
  // ќбьем 
  double V(share &t)
  {
	  return ((t.rad * t.rad * t.rad * 3.14 * 4) / 3);
  }
} // end simple_shapes namespace

