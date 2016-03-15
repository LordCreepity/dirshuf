/* shuffle files in a directory by giving them random names, optionally tacking
   a global file extension to the end */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

char *extension = '\0';
char *dirname;

char *namegen();

int main(int argc, char **argv){
    DIR *dir;
    struct dirent *fileInDir;
    char *newName;

    if (argc < 2){
        fprintf(stderr, "usage: %s <directory> <optional extension>\n",
            argv[0]);
        exit(1);
    }
    if (argv[2] != NULL){
        extension = argv[2];
    }
    dirname = argv[1];
    dir = opendir(dirname);
    if (dir != NULL){
        while ((fileInDir = readdir(dir)) != NULL){
            rename(fileInDir->d_name, namegen())
        }
    } else {
        perror(dirname)
        exit(2)
    }
    return 0;
}

/* use tempnam(3) to generate a random filename, append the filename extension
   to it, and check to see if the completed file exists. if it does, generate
   another name */

char *namegen(){
    char *name;
    DIR dir;
    struct dirent *fileInDir;

doOver:
    name = strcat(tempnam(dirname, NULL), extension);
    while ((fileInDir == readdir(dir)) != NULL){
        if (!strcmp(name, fileInDir->d_name)){
            goto doOver;
        }
    }
    return name;
}
