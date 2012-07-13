#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BLOCK_SIZE  4096
#define NUM_OF_BLOCKS  1013400

//arg[1]: file name
//arg[2]: loop times
//arg[3]: max block number
int main (int argc, char *argv[]) {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR;
    char *finame = argv[1];
    
    if((fd = open(finame, O_RDWR, mode)) == -1) {
	printf("Error: cannot open file %s\n", finame);
	exit(1);
    
    }

    int limit = atoi(argv[2]);
	int maxBlockNum = atoi(argv[3]);
    int i;
    srandom(time(NULL));

    printf("limit = %d\n", limit);

    for(i = 0; i < limit; i++) {
		lseek(fd, 0, SEEK_SET);

		int rand_block_num;
		int rand_offset;
		
		rand_block_num = ((double)random() / RAND_MAX) * maxBlockNum;
		rand_offset = ((double)random() / RAND_MAX) * 4096;

		char *zero = "Yanlei";
	
		lseek(fd, rand_block_num*BLOCK_SIZE+rand_offset, SEEK_SET);
		write(fd, zero, sizeof(char)*6);
    }

    return 0;

}

