/*
  Filename: command_line_example.cpp

  Description: An example of how to grab command-line arguments within any SystemC module.

  Compile (roughly) and run with:
    gcc -std=c++11 -o example.x -L$SYSTEMC/lib -lsystemc -I$SYSTEMC/include command_line_example.cpp
    ./example.x
    ./example.x -debug
    ./example.x -quiet

  or use a properly configured cmake setup

  Dependencies:
  1. A reasonable implementation of C++11 (e.g. recent versions of clang or gcc)
  2. A properly installed version of SystemC 2.3 or later.

*/
#if __cplusplus < 201103L
#  ifdef WIN32
#    pragma message("ERROR: Requires C++11")
#  else
#    error "Requires C++11"
#  endif
#endif

#include <systemc>
#include <string>
using namespace sc_core;
using namespace std;

SC_MODULE(Example) {
  void example_thread( void ) {
    SC_REPORT_INFO( MSGID, "Hello World" );
    SC_REPORT_INFO_VERB( MSGID, "We are debugging this code", SC_DEBUG );
    wait(1,SC_NS);
    SC_REPORT_INFO( MSGID, "Goodbye World" );
    sc_stop();
  }
  SC_CTOR(Example) {
    SC_THREAD(example_thread);
  }
private:
  void end_of_elaboration ( void ) {
    for( int i=1; i<sc_argc(); ++i ) {
      string arg(sc_argv()[i]);
      if( arg == "-debug" ) {
        sc_report_handler::set_verbosity_level(SC_DEBUG);
      } else if (arg == "-quiet" ) {
        sc_report_handler::set_verbosity_level(SC_NONE);
      }
    }
  }
  const char* MSGID{ "/Doulos/Example/Command_line" };
};

int sc_main( int argc, char* argv[] ) {
  Example top("example");
  sc_start();
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
// Copyright 2018 by Doulos. All rights reserved.
// -*- C++ -*- vim:sw=2:tw=0:et
