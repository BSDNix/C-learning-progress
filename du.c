// work in progress, but it actually tries doing stuff now.

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <getopt.h> // love using this lib

void(Usage) 

int main(int argc, char **argv)
 struct stat file_stats;
    DIR *dirp;
    struct dirent* dent;

    dirp=opendir("."); // use current dir for testing
    do {
        dent = readdir(dirp);
        if (dent)
        {
            printf("%s  --  ", dent->d_name);
            if (!stat(dent->d_name, &file_stats))
            {
                printf("%u bytes\n", (unsigned int)file_stats.st_size);
            }
            else
            {
                printf("(stat() failed for this file)\n");
            }
        }
    } while (dent);
    closedir(dirp);
}
