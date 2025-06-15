//программа, порождающая дочерный процесс (часть 2). 
//процесс-родитель и процесс ребенок должны выполнять разные действия
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
	pid_t procid, pprocid;
	int a=0, b;
	procid = getpid();
	pprocid = getppid();
	printf("До вызова fork()\n");
	printf("Ид. текущ. процесса: %d\nИд. род. процесса: %d\n", procid, pprocid);
	printf("начальное значение a: %d\n", a);
	b = fork();
	if (b<0) {
		//о время выполнения fork() произошла ошибка. выходим из программы с возвратом кода -1
		printf("Ощибка при выполнении fork()\n");
		exit(-1); //выход из программы
	}
	else if (b==0) {
		printf("\n\nПоявился дочерный процесс получил значение %d\n", b);
		a = a+1; //проверяем изменение значение переменной a
      		procid = getpid();
       		pprocid = getppid();
       		printf("После вызова fork() в процессе-ребенке\n");        
       		printf("Ид. текущ. процесса: %d\nИд. род. процесса: %d\nНовое значенине a: %d\n", procid, pprocid, a);
	}
	else {
		printf("\n\nРодительский процесс после  вызова fork() получил ид.ребенка: %d\n", b);
		a = a+1111; //проверяем изменение значение переменной a
	        procid = getpid();
	   	pprocid = getppid();
		printf("Индентификаторы процесса-родителяе\n");
		printf("Ид. текущ. процесса: %d\nИд. род. процесса: %d\nНовое значенине a: %d\n", procid, pprocid, a);
	}
	return 0;
}
