#include <stdio.h>
#include <dirent.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int l = 0;
    int which = -1;
    struct stat sb;
    char dir[] = ".";
    if (argc == 3) {
        if (strcmp(argv[2], "-l") == 0) {
            l = 1;
            which = 0;
        }
        if (strcmp(argv[1], "-l") == 0) {
            l = 1;
            which = 1;
        }
    }
    if (argc >= 2) {
        //assign arv[1] to dir
        strcpy(dir, argv[which + 1]);
    }
    //make it so passing -l as an argument will print out the long listing of the files

    // if (opendir(argv[1]) == -1) {
    //     perror("opendir");
    //     exit(EXIT_FAILURE);
    // }

    DIR *dp = opendir(dir);
    assert(dp != NULL);
    struct dirent *d;
    while ((d = readdir(dp)) != NULL) {
    printf("%lu %s\n", (unsigned long) d->d_ino,
    d->d_name);
    if(l){
        lstat(d->d_name, &sb);
        printf("ID of containing device:  [%x,%x]\n",
                  major(sb.st_dev),
                  minor(sb.st_dev));

           printf("File type:                ");

           switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

           printf("I-node number:            %ju\n", (uintmax_t) sb.st_ino);

           printf("Mode:                     %jo (octal)\n",
                  (uintmax_t) sb.st_mode);

           printf("Link count:               %ju\n", (uintmax_t) sb.st_nlink);
           printf("Ownership:                UID=%ju   GID=%ju\n",
                  (uintmax_t) sb.st_uid, (uintmax_t) sb.st_gid);

           printf("Preferred I/O block size: %jd bytes\n",
                  (intmax_t) sb.st_blksize);
           printf("File size:                %jd bytes\n",
                  (intmax_t) sb.st_size);
           printf("Blocks allocated:         %jd\n",
                  (intmax_t) sb.st_blocks);

           printf("Last status change:       %s", ctime(&sb.st_ctime));
           printf("Last file access:         %s", ctime(&sb.st_atime));
           printf("Last file modification:   %s", ctime(&sb.st_mtime));
    }
    }
    closedir(dp);
    return 0;
}