//Программа, анализирующая аргументы командной строки
#include <stdio.h>
int main(int argc, char* argv[], char* envp[]) {
	//Количество аргументов переданной программе - argc 
	printf("Программе передано %d аргументов\n\n", argc);

	//Список значение аргументов (массив argv)
	for (int i=0; i<argc; i++)
		printf("Аргумент [%d]: %s\n", i, argv[i]);
	printf("\n");
}
