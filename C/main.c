#include <string.h>
#include <stdio.h>
#include "hexdump.h"
int main() {
  char buffer[] = "This is a random buffer to demonstrate hexDump()...";
  hexDump((unsigned char *)buffer, strlen(buffer) + 1);
  return 0;
}
