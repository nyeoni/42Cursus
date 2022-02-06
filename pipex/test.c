#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd1 = open("test1", O_RDONLY | O_WRONLY, 0777);
	int fd2 = open("test2", O_RDONLY | O_WRONLY, 0777);

	printf("I'm STDOUT1\n");
	dup2(fd1, STDOUT_FILENO);
	printf("I'm STDOUT2\n");
	dup2(fd2, STDOUT_FILENO);
	printf("I'm STDOUT3\n");
}