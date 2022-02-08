#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> //for pid_t type
#include <sys/wait.h>
// #include <stdio.h>
#include <getopt.h> //for getopt variables (e.g. opterr, optopt, etc.)

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "You must use options. Try running chain -h < textfile.txt for help\n");
    return 1;
  }

  int numOfProcs = 4;
  int numOfChars = 80;
  int sleepTime = 3;
  int numOfIterations = 1;

  int options = 0;

  while (options != -1)
  {
    options = getopt(argc, argv, "hp:c:s:i:");
    switch (options)
    {
    case 'h':
      printf("usage: chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile.txt\n");
      return 0;
    case 'p':
      numOfProcs = atoi(optarg);
      break;
    case 'c':
      numOfChars = atoi(optarg);
      break;
    case 's':
      sleepTime = atoi(optarg);
      break;
    case 'i':
      numOfIterations = atoi(optarg);
      break;
    case ':':
      printf("Option needs a value\n");
      return 1;
    case '?':
      printf("%c is not an option\n", optopt);
      return 1;
    default:
      break;
    }
  }

  pid_t childpid = 0;
  int i;
  for (i = 1; i < numOfProcs; i++)
  {
    if (childpid = fork())
    {
      break;
    }
  }

  int j;
  for (j = 0; j < numOfIterations; j++)
  {
    sleep(sleepTime);
    wait(NULL);

    fprintf(stderr, "i: %d | ", i);
    fprintf(stderr, "Process ID: %ld | ", (long)getpid());
    fprintf(stderr, "Parent ID: %ld | ", (long)getppid());
    fprintf(stderr, "Child ID: %ld\n", (long)childpid);
  }
  return 0;
}