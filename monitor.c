#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

//argv[1]: file name for xfs_check output
//argv[2]: file name for # of failures log
int main (int argc, char *argv[]) {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR;
    char *finame = argv[1];
    char *finame2 = argv[2];
    
    if((fd = open(finame, O_RDONLY, mode)) == -1) {
	printf("Error: cannot open file %s\n", finame);
	exit(1);

    }

    struct stat *st;
    stat(finame, st);
    int size;
    size = st -> st_size;
    
    close(fd);

    int flag = 2;

    if(size != 0) {
	flag = 1;
    }
    
    printf("%d", flag);

    return 0;
    

}
