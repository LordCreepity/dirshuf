/* shuffle files in a directory by giving them random names, optionally tacking
   a global file extension to the end. also outputs a shell script that can be
   used to restore the original filenames */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

char *extension;
char *dirname;
char eflg = 0;

char *namegen();

int main(int argc, char **argv){
    DIR *dir;
    struct dirent *fileInDir;
    char *newName;
    FILE *resetfile;

    if (argc < 2){
        fprintf(stderr, "usage: %s <directory> <optional extension>\n",
            argv[0]);
        exit(1);
    }
    if (argv[2] != NULL){
        extension = argv[2];
        eflg++;
    } 
    dirname = argv[1];
    resetfile = fopen("./resetfile", "w");
    if (resetfile == NULL){
        perror("resetfile");
        exit(2);
    }
    dir = opendir(dirname);
    if (dir != NULL){
        while ((fileInDir = readdir(dir)) != NULL){
            if (!strncmp(fileInDir->d_name, "resetfile", 9));
                continue;
            } else {
                newName = namegen();
                fprintf(resetfile, "mv %s %s\n", newName, fileInDir->d_name);
                rename(fileInDir->d_name, newName);
            }
        }
    } else {
        perror(dirname);
        exit(3);
    }
    return 0;
}

/* use tempnam(3) to generate a random filename, append the filename extension
   to it, and check to see if the completed file exists. if it does, generate
   another name */

char *namegen(){
    char *name;
    DIR *dir = opendir(dirname);
    struct dirent *fileInDir;

doOver:
    if (eflg){
        name = strcat(tempnam(dirname, NULL), extension);
    } else {
        name = tempnam(dirname, NULL);
    }
    rewinddir(dir);
    while ((fileInDir = readdir(dir)) != NULL){
        if (!strcmp(name, fileInDir->d_name)){
            goto doOver;
        }
    }
    return name;
}
