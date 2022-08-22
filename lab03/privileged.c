#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void main() {
  int fd;

  /* Assume that /etc/zzz is an important system file,
   * and it is owned by root with permission 0644.
   * Before running this program, you should create
   * the file /etc/zzz first. */
  uid_t spot1_ruid = getuid();
  uid_t spot1_euid = geteuid();
  printf("at spot1: ruid is: %d\n", spot1_ruid);
  printf("at spot1: euid is: %d\n", spot1_euid);
  fd = open("/etc/zzz", O_RDWR | O_APPEND);
  if (fd == -1) {
     printf("Cannot open /etc/zzz\n");
     exit(0);
  }

  /* Simulate the tasks conducted by the program */
  sleep(1);

  /* After the task, the root privileges are no longer needed,
     it's time to relinquish the root privileges permanently. */
  setuid(getuid());  /* getuid() returns the real uid */
  uid_t spot2_ruid = getuid();
  uid_t spot2_euid = geteuid();
  printf("at spot2: ruid is: %d\n", spot2_ruid);
  printf("at spot2: euid is: %d\n", spot2_euid);
    
  if (fork()) { /* In the parent process */
    uid_t spot3_ruid = getuid();
    uid_t spot3_euid = geteuid();
    printf("at parent process: ruid is: %d\n", spot3_ruid);
    printf("at parent process: euid is: %d\n", spot3_euid);
    //close (fd);
    exit(0);
  } else { /* in the child process */
    /* Now, assume that the child process is compromised, malicious
       attackers have injected the following statements
       into this process */
    uid_t spot4_ruid = getuid();
    uid_t spot4_euid = geteuid();
    printf("at child process: ruid is: %d\n", spot4_ruid);
    printf("at child process: euid is: %d\n", spot4_euid);
    write (fd, "Malicious Data\n", 15);
    close (fd);
  }
}