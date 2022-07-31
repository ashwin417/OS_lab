#include<stdio.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<stdlib.h> 
  
int main() 
{ 
    char c; 
    int fd1 = open("sample.txt", O_RDONLY, 0); 
    read(fd1, &c, 1); 
    printf("%c\n", c); 
} 
