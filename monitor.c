#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

//argv[1]: file name for xfs_check output
//output 2 if xfs_check outputs nothing
//output 1 if xfs_check writes something to the log
int main (int argc, char *argv[]) {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR;
    char *finame = argv[1];

/*
	if((fd = open(finame, O_RDONLY, mode)) == -1) {
		printf("Error: cannot open file %s\n", finame);
		exit(1);
    }
*/

	int size;

    struct stat st;
    stat(finame, &st);
    size = st.st_size;

    int flag = 2;

    if(size > 10) {
		flag = 4;
    }
    
    printf("%d\n", flag);

    return 0;
    

}
