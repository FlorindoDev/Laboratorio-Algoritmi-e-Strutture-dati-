
#include "./TestFlorindoAFolder/mytest.hpp"
#include "./TestFlorindoAFolder/mytest.cpp"
#include "test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void mytest() {
  cout << endl << "~*~#~*~ Benvenuti nel Test di Florindo Zecconi(N86004544) ~*~#~*~ " << endl;

  uint loctestnum, loctesterr;
  uint stestnum = 0, stesterr = 0;


  //uint ftestnum = 0, ftesterr = 0;

  loctestnum = 0; loctesterr = 0;
  //TestFlorindoA(loctestnum, loctesterr);

  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  //TestFlorindoB(loctestnum, loctesterr);

  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  TestFlorindoC(loctestnum, loctesterr);

  stestnum += loctestnum; stesterr += loctesterr;


  cout << endl << "MyTest (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")"<<"\n";
  //cout << endl << "MyTest (Full Test) (Errors/Tests: " << ftesterr << "/" << ftestnum << ")" << endl;

  cout << endl << "Goodbye!" << endl;
}
