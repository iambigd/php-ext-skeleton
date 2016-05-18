/*Hello World program*/
#include <stdio.h>
// #include "hello_world_c.h"
#include "hello_world_c/hello_world_c.h"


int hello_world_c_add(int a,int b){
	int sum = 0;
	printf("hello_world_c_add is coming Orz\n");
	printf("%d\n", a);
	printf("%d\n", b);
	sum = a+b;
	printf("sum=%d\n", sum);
	
	return sum;
}

int main(){
	printf("Hello World C :D");
	printf("sum=%d",hello_world_c_add(10,10));
	return 0;
}