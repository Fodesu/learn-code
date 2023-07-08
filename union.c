#include <stdio.h>
union test
{
int a;
char b;
};

int main() {
union test k;
k.a = 0xff;
if(k.b == 0xff)
	printf("little\n");
else if(k.b == 0x00) 
	printf("big\n");
else 
	printf("error\n");
printf("%d\n", k.b);
}
