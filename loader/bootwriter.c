#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char bufb[512];
	int fdisk;
	
	if(argc<3) {
		printf("\nBoot Writer\n");
		printf("Use: %s <boot_sector> <device> \n\n", argv[0]);
		exit(0);
	}

	printf("\n\n * Abrindo boot sector");
	bdisk = open(argv[1], O_RDONLY);
	printf("\n * OK");
	read(bdisk,bufb,510);
	close(bdisk);

	printf("\n * Setando como boot file");
	bufb[510]=0x55;
	bufb[511]=0xAA;
	printf("\n * Assinatura de boot 0x55AA gravado...");
	fdisk = open(argv[2],O_RDWR);
	lseek(fdisk,0,SEEK_SET);
	write(fdisk,bufb,512);
	printf("\n * OK .. Bootsector gravado com sucesso...\n\n");
	close(fdisk);
}
	

