/* shuffle files in a directory by giving them random names, optionally tacking
   a global file extension to the end */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

char *extension = '\0';
DIR *dir;
struct dirent *fileInDir;
int fileCount = 0;

int main(int argc, char **argv){
    int exponentialchars = 1;

    if (argc < 2){
        fprintf(stderr, "usage: %s <directory> <optional extension>\n",
            argv[0]);
        exit(1);
    }
    if (argv[2] != NULL){
        extension = argv[2];
    }
    dir = opendir(argv[1]);
    if (dir != NULL){
        while ((fileInDir = readdir(dir)) != NULL){
            fileCount++;
        }
    } else {
        perror(argv[1]);
        exit(2);
    }
    while (26**exponentialchars < fileCount){
        exponentialchars++;
    }
    rewinddir(dir);
    while ((fileInDir = readdir(dir)) != NULL){
        
    }
}
