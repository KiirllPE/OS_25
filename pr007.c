#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[]) {
	printf("Программа начала работу ...\n");
	pid_t pid, ppid;
	int result;
	pid = getpid();
	ppid = getppid();
	printf("Ид. процесса: %d\n", pid);
	printf("Ид. родительского процесса: %d\n", ppid);
	result = fork();
	if (result > 0) {
		printf ("Родительского процесс ...\n");
		printf("Ид. процесса: %d, Ид. процесса ребенув: %d\n", pid, result);
		printf("Ид. родительского проццесса: %d\n", ppid);
		printf("Родитель завершил работу\n");
	}
	else if (result == 0) {
		printf("Дочерынй процесс ...\n");
		(void) execle("./pr003.out", "./pr003.out", 0, envp);
		printf("Ошибка при выполнение ситемного вызова exec\n");
		exit(-1);		
	}
	else {
		printf("Ошибка при выполнение системного вызова fork\n");
		exit(-1);
	}
	return 0;
}
