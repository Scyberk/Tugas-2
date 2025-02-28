#include<stdio.h>
int main(){
	int a = 0;
	int b = 0;
	
	scanf("%d %d", &a, &b);
	getchar();
	
	for(int i = 0; i<b; i++)
	{
	printf("%d\n", a++);
	}
	
	return 0;
}
