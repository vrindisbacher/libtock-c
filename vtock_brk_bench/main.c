/* vim: set sw=2 expandtab tw=80: */

#include <stdio.h>
#include <libtock/tock.h>
#include<math.h>

static int brk_array[10] = {42, 17, 99, 32, 88, 5, 64, 123, 76, 51};

int main(void) {
  int i = 0;
  while (i < 100) {
    int increment = brk_array[i % 10];
    memop_return_t ret = memop(1, 10);
    uint8_t* heap_end  = (uint8_t*) ret.data;
    i += 1;
  }
}
