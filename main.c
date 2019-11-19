#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  //scan the comman arguments;
    DIR *dirs;
    if (argc > 1) {
      dirs = opendir(argv[1]);
        if (errno == -1) {
          printf("error: %s", strerror(errno));
            return 0;
        }
    }
    else {
        printf("enter a directory");
        return 0;
    }
    if (errno == -1) {
        printf("error: %s", strerror(errno));
        return 0;
    }
    struct dirent* dir = readdir(dirs);

    //statistics
    printf("statistics for directory\n");
    struct stat n;
    int size;
    while (dir) {
        int error = stat(dir->d_name, &n);
        if (error == -1) {
            printf("error: %s", strerror(errno));
            return 0;
        }
        else {
            size += n.st_size;
        }
        dir = readdir(dirs);
    }
    printf("\ntotal Directory Size: %d Bytes\n", size);

    rewinddir(dirs);
    dir = readdir(dirs);

    printf("\nDirectories:\n");

    while (dir) {
        if(dir->d_type == DT_DIR) {
            printf("\t%s\n", dir->d_name);
        }
        dir = readdir(dirs);
    }
    rewinddir(dirs);
    dir = readdir(dirs);

    printf("\nRegular Files:\n");

    while (dir) {
        if(dir->d_type != DT_DIR) {
            printf("\t%s\n", dir->d_name);
        }
        dir = readdir(dirs);
    }
    closedir(dirs);

    return 0;
}
