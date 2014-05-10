#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cassert>

#include "get_type_info.h"

using namespace std;
using namespace fp_dt;


int main(int argc, char* argv[]) {

  const int INT_BITS = 6;

  double d;
  fp_int<INT_BITS> s_a,s_b;
  fp_int<INT_BITS-1> s_c;

  fp_uint<INT_BITS> u_a,u_b;
  fp_uint<INT_BITS-1> u_c;

  s_a = 1;
  s_b = 1;
  s_c = 1;
  u_a = 1;
  u_b = 1;
  u_c = 1;

  int status;

  std::cout << "************* Signed types ****************\n";

  std::cout << "Same type \n";
  MIXED_TYPES(s_a,s_b,1);
  std::cout << "\n";
  std::cout << "Same type different sizes \n";
  DMIXED_TYPES(s_a,s_c,1);
  std::cout << "\n";
  std::cout << "Same type different sizes \n";
  DMIXED_LOGIC_TYPES(s_a,s_c,1);
  std::cout << "\n";

  UNARY_TYPES(s_a);
  std::cout << "\n";

  std::cout << "Shifts with ints \n";
  SHIFT_TYPES(s_a,1,8);
  std::cout << "\n";

  TO_INT_TYPES(s_a);
  std::cout << "\n";



  std::cout << "************* Unsigned types ****************\n";

  std::cout << "Same type \n";
  MIXED_TYPES(u_a,u_b,1);
  std::cout << "\n";
  std::cout << "Same type different sizes \n";
  MIXED_TYPES(u_a,u_c,1);
  std::cout << "\n";
  std::cout << "Same type different sizes \n";
  DMIXED_LOGIC_TYPES(u_a,u_c,1);
  std::cout << "\n";

  UNARY_TYPES(u_a);
  std::cout << "\n";

  std::cout << "Shifts with ints \n";
  SHIFT_TYPES(u_a,1,8);
  std::cout << "\n";

  ///////
  std::cout << "************* Mixing Signed & Unsigned types ****************\n";
  s_a = 1;
  u_b = 1;
  u_c = 1;

  std::cout << "Same size signed + unsigned\n";
  MIXED_TYPES(s_a,u_b,1);
  std::cout << "\n";
  std::cout << "Different type different sizes \n";
  DMIXED_TYPES(s_a,u_c,1);
  std::cout << "\n";
  std::cout << "Different type different sizes \n";
  DMIXED_LOGIC_TYPES(s_a,u_c,1);
  std::cout << "\n";

  std::cout << "************* Unsigned types ****************\n";

  std::cout << "Same size signed + unsigned \n";
  MIXED_TYPES(u_a,s_b,1);
  std::cout << "\n";
  std::cout << "Different type different sizes \n";
  MIXED_TYPES(u_a,s_c,1);
  std::cout << "\n";
  std::cout << "Different type different sizes \n";
  DMIXED_LOGIC_TYPES(u_a,s_c,1);
  std::cout << "\n";

  return(0);
}
