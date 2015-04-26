#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char buffer[512];
	int bdisk, fdisk, i, j;
	unsigned char ch;
	
	if(argc<3) {
		printf("\nBoot Writer\n");
		printf("Use: %s <boot_sector> <device> \n\n", argv[0]);
		exit(0);
	}

	printf("\n\n * Abrindo boot sector");
	bdisk = open(argv[1], O_RDONLY);
	printf("\n * OK");
	read(bdisk,buffer,510);
	close(bdisk);

	printf("\n * Setando como boot file");
	buffer[510]=0x55;
	buffer[511]=0xAA;
	printf("\n * Assinatura de boot 0x55AA gravado");
	fdisk = open(argv[2],O_RDWR);
	lseek(fdisk,0,SEEK_SET);
	write(fdisk,buffer,512);
	printf("\n * OK .. Bootsector gravado com sucesso\n\n");
	close(fdisk);
/*
	printf("boot sector in HEX:\n");
	j=0;
	for(i=0; i<512; i++)
	{
		ch=(unsigned char) bufb[i];
		if (j==8) printf(" -");
		if (j==16) 
		{
			printf("\n");
			j=0;
		}
		j++;
		if (ch<0x10) printf(" 0%x",ch);
		else printf(" %2x",ch);
	}

	printf("\n\n");

*/

	}
	

