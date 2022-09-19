#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  const size_t BUF_SIZE = 1024;
  char buf[BUF_SIZE];
  buf[0] = '\0';

  if (argc != 2) {
    printf("supply a file to read\n");
    exit(1);
  }

  strcat(buf, "/usr/bin/cat ");
  strcat(buf, argv[1]);

  system(buf);
  return 0;
}