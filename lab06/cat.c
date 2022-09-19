#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char ** argv) {
  uid_t euid = geteuid();

  printf("DOING SOMETHING MALICIOUS, with effective user ID %d\n", euid);
}