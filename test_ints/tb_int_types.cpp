#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cassert>

#include <spuc/spuc_int_types.h>
#include "get_type_info.h"

using namespace std;
using namespace SPUC;


int main(int argc, char* argv[]) {

  const int INT_BITS = 6;

  double d;
  spuc_int<INT_BITS> s_a,s_b;
  spuc_int<INT_BITS-1> s_c;

  spuc_uint<INT_BITS> u_a,u_b;
  spuc_uint<INT_BITS-1> u_c;

  spuc_int<2> s_shift  = 1;
  spuc_int<4> s_shift2 = 3;
  spuc_uint<2> u_shift = 1;
  spuc_uint<4> u_shift2 = 3;
  

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

  std::cout << "Shifts with spuc_ints \n";
  SHIFT_TYPES(s_a,s_shift,s_shift2);
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

  std::cout << "Shifts with spuc_uints \n";
  SHIFT_TYPES(u_a,u_shift,u_shift2);
  std::cout << "\n";

  std::cout << "Shifts with ints \n";
  SHIFT_TYPES(u_a,1,8);
  std::cout << "\n";

  ///////
  std::cout << "************* Mixing Signed & Unsigned types ****************\n";

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

  ////////////////////////
  std::cout << "************* Mixing Signed with double ****************\n";
  DMIXED_TYPES(s_a,d,1);
  std::cout << "\n";
  std::cout << "Shifts with doubles \n";
  SHIFT_TYPES(s_a,1.0,8.0);
  std::cout << "\n";

  std::cout << "************* Mixing Unsigned with double ****************\n";
  DMIXED_TYPES(u_a,d,1);
  std::cout << "\n";
  std::cout << "Shifts with doubles \n";
  SHIFT_TYPES(u_a,1.0,8.0);
  std::cout << "\n";

  return(0);
}
