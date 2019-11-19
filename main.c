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
    DIR *dir;
    if (argc > 1) {
      dir = opendir(argv[1]);
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

    return 0;
}
