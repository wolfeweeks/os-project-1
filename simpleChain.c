#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> //for pid_t type
#include <sys/wait.h>
// #include <stdio.h>
#include <getopt.h> //for getopt variables (e.g. opterr, optopt, etc.)
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "You must use options. Try running chain -h < textfile.txt for help\n");
    return 1;
  }

  int numOfProcs = 4;  // stores the number of times to fork the program
  int numOfChars = 80; // stores the number of chars to read from the redirected text file
  int sleepTime = 3;   // how long to sleep
  int numOfIterations = 1;

  // generate perror message beginning based off the name of the executable
  char *programName = (char *)malloc(strlen(argv[0]) + 1);
  strcpy(programName, argv[0]);
  char *perrorMessage = programName;
  perrorMessage = (char *)realloc(perrorMessage, (8 + strlen(perrorMessage)) * sizeof(char));
  strcat(perrorMessage, ": Error");

  int options = 0;

  // read through the user's command line options and set any necessary args
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
    else if (childpid == -1) // if the forking process doesn't work, print out an error
    {
      perror(perrorMessage);
    }
  }

  int j;
  for (j = 0; j < numOfIterations; j++)
  {
    sleep(sleepTime);

    int waitError = wait(NULL);             // wait for child proc to die
    if (waitError == -1 && i != numOfProcs) // print any errors unless it's the youngest child
    {
      perror(perrorMessage);
    }

    // print out information for active process
    // fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
    //         i, (long)getpid(), (long)getppid(), (long)childpid);

    fprintf(stderr, "i: %d | ", i);
    fprintf(stderr, "Process ID: %ld | ", (long)getpid());
    fprintf(stderr, "Parent ID: %ld | ", (long)getppid());
    fprintf(stderr, "Child ID: %ld\n", (long)childpid);

    // allocate memory for string of length "numOfChars"
    char *mybuf = (char *)malloc((numOfChars + 1) * sizeof(char));

    // iterate over redirected file for specified num of chars and store each char in mybuf string
    int charIndex;
    for (charIndex = 0; charIndex < numOfChars; charIndex++)
    {
      mybuf[charIndex] = fgetc(stdin);
    }
    mybuf[numOfChars] = '\0';

    // print out mybuf for active process
    fprintf(stderr, "%ld: %s\n", (long)getpid(), mybuf);
  }
  return 0;
}