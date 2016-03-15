/* shuffle files in a directory by giving them random names, optionally tacking
   a global file extension to the end */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char **argv){
    char *extension = '\0';
    DIR *dir = opendir(argv[1]);
    DIR *dir_nameclobber = opendir(argv[1]);
    struct dirent *fileInDir;
    struct dirent *fileInDir_nameclobber;
    int fileCount = 0;
    char *newName;

    if (argc < 2){
        fprintf(stderr, "usage: %s <directory> <optional extension>\n",
            argv[0]);
        exit(1);
    }
    if (argv[2] != NULL){
        extension = argv[2];
    }
    if (dir != NULL){
        while ((fileInDir = readdir(dir)) != NULL){
            newName = tempnam(argv[1], NULL);
            while ((fileInDir_nameclobber = readdir(dir_nameclobber)) != NULL){
                
            }
        }
    } else {
        perror(argv[1])
        exit(2)
    }
}
