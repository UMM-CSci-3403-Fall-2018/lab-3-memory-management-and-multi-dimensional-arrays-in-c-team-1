#include <stdio.h>
#include <stdlib.h>

#include "array_merge.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);
  
  while (getline(&line, &size, stdin) > 0) {
    char* output = disemvowel(line);
    printf("%s\n", output);
    free(output);
  }
  free(line);
}
