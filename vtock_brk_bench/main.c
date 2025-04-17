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


  ret = memop(2, 0); // start
  if (ret.status != TOCK_STATUSCODE_SUCCESS) {
    return 1;
  }
  int mem_start = ret.data;

  ret = memop(1, 0); // heap end
  if (ret.status != TOCK_STATUSCODE_SUCCESS) {
    return 1;
  }
  int heap_end = ret.data;

  ret = memop(6, 0); // grant region begin
  if (ret.status != TOCK_STATUSCODE_SUCCESS) {
    return 1;
  }
  int grant_end = ret.data;

  ret = memop(3, 0); // memory end
  if (ret.status != TOCK_STATUSCODE_SUCCESS) {
    return 1;
  }
  int mem_end = ret.data;

  printf("Failed after %d invocations of brk\n", counter);
  printf("The process accessible ram size is %d\n", heap_end - mem_start);
  printf("The total process size is %d\n", mem_end - mem_start);
  printf("The amount of memory unused is: %d", grant_end - heap_end);
}
