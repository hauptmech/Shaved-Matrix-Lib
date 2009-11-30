#include <iostream>
#include <fstream>
#include "Matr.h"

using namespace std;
int main()
{
 cout << "bubba\n";
 Vect3 a = Vect3(2,3,4);
 Vect3 b = Vect3(1,1,1);
 Vect3 c = Vect3(0,0,0);
 
 b[2]=5; 

 c = a*2;
 c = a^a;
 c = !a;
 double d = ~a;
 c = a-a;
 c = -a;
 c = -a-a;
 d = a*a;

 cout << c[0] << " " << c.q[1] << " " << c.q[2] << "\n";
 


  return 0;
}
