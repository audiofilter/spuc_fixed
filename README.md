
C++ Fixed Point types
================================

### Build status - Mac Os X, clang 
[![Build Status](https://travis-ci.org/audiofilter/spuc_fixed.png)](https://travis-ci.org/audiofilter/spuc_fixed)


A C++ library of (largely) SystemC compatible compile time fixed point data types for fast simulation 

The objective of this library is to provide classes to use instead of

- sc_fixed
- sc_ufixed
- sc_int
- sc_uint

that are

- a) much faster for simulation than the current equivalent SystemC types
- b) potentially synthesisable using current high-level synthesis tools
- c) have more intuitive return types for various math operations such as addition,subtraction, multiplication, etc
- d) Useful for spuc library

Expected speedup vs SystemC can be as much as 300 times faster


Supported Saturation / Rounding modes:

- Saturation modes based on : SC\_WRAP, SC_SAT, SC_SAT_SYM
and
- Rounding modes based on : SC\_RND, SC_TRN

These types will exist in the namespace *SPUC* 

To see the fixed-point type semantics for the integer types, please look at file test_ints/Type_Info.txt
This is an example of the output of the test run in the speed_test directory.

Starting Loops with Loops = 2097152

       double    Time elapsed = 0.117503  Factor = 1
       SPUC      Time elapsed = 0.0962961  Factor = 0.819519
