#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {

	char buf[1024];
	char buf2[2048];
	ssize_t count;

	count = read(3, buf, sizeof(buf));
	sprintf(buf2, "got: %.*s", (int) count, buf);
	lseek(3, 0L, SEEK_SET);
	count = write(3, buf2, strlen(buf2));

	return 0;
}


