#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char **argv)
{	
	int my;
	int real;
	int jeanne;
	
	jeanne =argc;
	if(strcmp(argv[1],"p") == 0)
	{
		int test = 21474;
		int hexa = 15;
	
		my = ft_printf("p: %p address : %d  d: %d x: %x X: %X\n",NULL,(void *)-1,test,-5,hexa);
		real = printf("p: %p address : %d  d: %d x: %x X: %X\n",NULL,(void *)-1,test,-5,hexa);
		printf("my : %d real : %d",my,real);
	}
	if(strcmp(argv[1],"s") == 0)
	{
		char *teststr = argv[2];
		
		my = ft_printf("%s\n",teststr);
		real = printf("%s\n",teststr);
		printf("my : %d real : %d",my,real);
	}
	if(strcmp(argv[1],"c") == 0)
	{
		char testc = argv[2][0];

		my = ft_printf("%c%c\n",testc,NULL);
		real = printf("%c%c\n",testc,NULL);
		printf("my : %d real : %d",my,real);
	}
	if(strcmp(argv[1],"u") == 0)
	{
		my = ft_printf("%u,%u,%u,%u,%u,%u,%u\n",0,-1,NULL,2147483647,-2147483648,-247483649,2147483648);
		real = printf("%u,%u,%u,%u,%u,%u,%u\n",0,-1,NULL,2147483647,-2147483648,-247483649,2147483648);
		printf("my : %d real : %d",my,real);
	}
	if(strcmp(argv[1],"d") == 0)
	{
		

		my = ft_printf("%d,%d,%d,%d,%d,%d,%d,%d\n",0,-1,1,2147483647,-2147483648,-247483649,2147483648,NULL);
		real = printf("%d,%d,%d,%d,%d,%d,%d,%d\n",0,-1,1,2147483647,-2147483648,-247483649,2147483648,NULL);
		printf("my : %d real : %d",my,real);
	}
	if(strcmp(argv[1],"i") == 0)
	{	
		my = ft_printf("%i,%i,%i,%i,%i,%i,%i,%i\n",0,-1,1,2147483647,-2147483648,-247483649,2147483648,NULL);
		real = printf("%i,%i,%i,%i,%i,%i,%i,%i\n",0,-1,1,2147483647,-2147483648,-247483649,2147483648,NULL);
	
		printf("my : %d real : %d",my,real);
	}
	if(strcmp(argv[1],"x") == 0)
	{
		
		my = ft_printf("");
		real = printf("");
		printf("my : %d real : %d",my,real);
	}
	if(strcmp(argv[1],"percent") == 0)
	{
		my = ft_printf("%%");
		real = printf("%%");
		printf("my : %d real : %d",my,real);
	}
	
}
/*
int main()
{
	ft_printf("%5%");write(1,":",1);
	printf("%5%");

}*/	
