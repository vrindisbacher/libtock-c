/* vim: set sw=2 expandtab tw=80: */

#include <stdio.h>
#include <sys/types.h>
#include <libtock/tock.h>
#include<math.h>

int main(void) {
  memop_return_t ret = memop(1, 0);
  if (ret.status != TOCK_STATUSCODE_SUCCESS) {
    return 1;
  }
  caddr_t original_heap_end = (caddr_t) ret.data;

  int counter = 1;
  while (true) {
    // increment heap with brk 1
    memop_return_t ret = memop(0, (int) original_heap_end);
    if (ret.status != TOCK_STATUSCODE_SUCCESS) {
      break;
    }
    original_heap_end += 1;
    counter += 1;
  }
  printf("Failed after %d invocations of brk", counter);
}
