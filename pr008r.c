//Программа для чтения информации из в файла в адресное пространство процесса
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
	int fd;
	size_t size;
	char string[20];
	if((fd = open("myfile", O_RDONLY))<0) {
		printf("Ошибка при открытие файла на чтение");
		exit(-1);
	}
	size = read(fd,string,20);
	if(size != 20) {
		printf("не удалось прочитать всю строку");
		exit(-1);
	}
	else 
		printf("Строка прочитана из файла \"myfile\"\n");
	printf("Из  файла с дескриптором %d прочитано %ld байт\n", fd, size);
	printf("Строка: %s\n", string);
	if (close(fd)<0) {
		printf("Не удается закрыть файл с дискриптором %d\n", fd);
		exit(-1);
	}
	return 0;
}
