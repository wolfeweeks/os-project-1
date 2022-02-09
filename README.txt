This program 

To compile and run this project, enter the following commands:
1. make
2. ./chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile
  where:
    -h: help
    -p: number of processes
    -c: number of chars read into the buffer
    -s: time to sleep in each iteration
    -i: number of iterations in the loop
    textfile: a file ending in .textfile
    
Problems Encountered:
  -Not 100% sure where exactly the perror() commands should go
  -It seemed to me like makefile suffixes and paterns were unnecessary

Tasks:
  1. Generally, The processes would print from the oldest to the newest, with
     some slightly out of order.
  2. Not sure how to show this one
  3. In testing, I found roughly 5% of processes were adopted by init
  4. This time, I found roughly 37% of processes were adopted by init
  5. Adding in the iteration loop, I found the output to print out the same info
     k number of times, but were rarely printed in the exact same order.
  6. This time, the output would print the processes in order from youngest to
     oldest, and prints out each processes info k times. Also, the printout took
     m seconds between printing processes.
  7. I was unable to tell which processes generated the separate parts of the
     output. After running the program several times, I did not see any
     differences between them, other than their IDs.
  8. Each process would print out the specified number of chars from the
     redirected input file. I did notice that with any number of iterations,
     the program would continue with the next set of chars from the input file,
     so each iteration of the process would be slightly different.