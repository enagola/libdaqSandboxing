// ANCHOR: imports
// We're going to use RLBox in a single-threaded environment.
#define RLBOX_SINGLE_THREADED_INVOCATIONS
// All calls into the sandbox are resolved statically.
#define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol

#include <stdio.h>
#include <cassert>
#include <rlbox/rlbox.hpp>
#include <rlbox/rlbox_noop_sandbox.hpp>

#include "daq.h"
#include "daq_common.h"

using namespace std;
using namespace rlbox;

// my lib should be replaced with the file that has the function definition

// // Declare callback function we're going to call from sandboxed code.
// void hello_cb(rlbox_sandbox_mylib& _, tainted_mylib<const char*> str);

RLBOX_DEFINE_BASE_TYPES_FOR(daq_base, noop); 

int main(int argc, char const *argv[]) {
// ANCHOR_END: imports
// ANCHOR: hello
  // Declare and create a new sandbox
  rlbox_sandbox_daq_base sandbox;
  sandbox.create_sandbox();

  // Call the library hello function:
  auto val = sandbox.invoke_sandbox_function(daq_version_number);
// ANCHOR_END: hello

  printf("the value is %d", val);

  // destroy sandbox
  sandbox.destroy_sandbox();

  return 0;
}
// ANCHOR_END: main-end
