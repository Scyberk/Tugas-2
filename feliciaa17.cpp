#include <stdio.h>

int main(){

/*problem N: skydiving	
	char nama1[105];
	double tinggi1;
	int umur1;
	
	char nama2[105];
	double tinggi2;
	int umur2;
	
	scanf("%s %lf %d %s %lf %d", nama1, &tinggi1, &umur1, nama2, &tinggi2, &umur2);
	
	printf("Name 1: %s\n", nama1);
	printf("Height 1: %.2lf\n", tinggi1);
	printf("Age 1: %d\n", umur1);
	printf("Name 2: %s\n", nama2);
	printf("Height 2: %.2lf\n", tinggi2);
	printf("Age 2: %d\n", umur2);
*/
 
/* problem r : the registration begins
    char id[15];
    char nama[105];
    char kelas;
    int num;
    
    scanf("%s %[^\n] %c %d", id, nama, &kelas, &num);
    
    printf("Id    : %s\n", id);
    printf("Name  : %s\n", nama);
    printf("Class : %c\n", kelas);
    printf("Num   : %d\n", num);
*/

 /* hexadesimal, oktal
    int N;
	scanf("%d", &N);
	
	printf("%x\n", N);	-> heksadesimal
	printf("%o\n", N);	-> oktal
*/

/* problem r: reversing
    char a[30];
    char b[30];
    char c[30];
    
    scanf("%s %s %s", a,b,c);
    
    printf("%s %s %s\n", c,b,a);
*/

	char string[105];
	scanf("%[^\n]", string);
	
	printf("#include <stdio.h>\n");
	printf("int main()\n");
	printf("{\n");
	printf("    printf(\"%%s\\n\",\"%s\");\n", string);
	printf("    return 0;\n");
	printf("}\n");
	
			
	return 0;
}
