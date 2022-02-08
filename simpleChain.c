#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> //for pid_t type
#include <stdio.h>
#include <getopt.h> //for getopt variables (e.g. opterr, optopt, etc.)

int main(int argc, char *argv[])
{
  int options = 0;

  while (options != -1)
  {
    options = getopt(argc, argv, "hp:c:s:i:");
    switch (options)
    {
    case 'h':
      printf("usage: chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile.txt\n");
      break;
    case 'p':
      printf("-p");
      break;
    case 'c':
      printf("-c");
      break;
    case 's':
      printf("-s");
      break;
    case 'i':
      printf("-i");
      break;
    case ':':
      printf(":");
      break;
    case '?':
      printf("unknown option: %c\n", optopt);
      break;
    default:
      break;
    }
  }

  // pid_t childpid = 0;
  // int i, n;
  // if (argc != 2)
  // {
  //   fprintf(stderr, "Usage: %s processes\n", argv[0]);
  //   return 1;
  // }
  // n = atoi(argv[1]);
  // for (i = 1; i < n; i++)
  //   if (childpid = fork())
  //     break;
  // fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
  //         i, (long)getpid(), (long)getppid(), (long)childpid);
  return 0;
}