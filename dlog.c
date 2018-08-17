/*===============================================================
 *	Copyright (C) 2018 All rights reserved.
 *	
 *	Filename：dlog.c
 *	Author：julian
 *	Date：2018-08-05
 *	Discription:
 *	
 *	release notes：
 *
 ================================================================*/
//#include<stdio.h>
//#include<unistd.h>
//#include<string.h>
#include "dlog.h"
#include "version.h"
#include "common.h"
//\e[display;font-color;backgroud-color	m	string  \e[0m

void print_hex(unsigned char*buf, size_t len)
{
	int i =0;
	unsigned char *cousor = buf;
	for(i=0; i<len ;cousor++, i++)
	{
		printf("i:%d %x \t %x\n ",i,  cousor, *cousor);
	}

}

void
usage(char const *argv0)
{
	// "   -f config file -- Set tool config file .\n"
	fprintf(stderr, "Usage: %s [options]\n", argv0);
	fprintf(stderr, "Options:\n");

	fprintf(stderr,
			"   -V             -- Print version and exit.\n"
			"   -h             -- Print usage information.\n\n"
			"   -r times       -- set network retransfer max times.\n"
			"   -I interval    -- Set the interval of cpe info query.\n"
			"   -d name        -- Set firmware and configure file directory ename.\n"
			"   -i CPEIP       -- Set upgrade push forward device's ipaddress.\n"
			"   -p CPE port    -- Set upgrade push forward device's webserver port.\n"
			"   -a auth string -- Set the authentication.\n"
			"   -c             -- upgrade device Configuration .\n"
			"demo Version %s %s [%s %s], \nCopyright (C) 2016-2025 cqping  Inc.\n"
			"http://www.cqping.xyz\n", VERSION, _REVISION, __DATE__, __TIME__);
	exit(EXIT_SUCCESS);
}

void print_styles()
{

		printf("[%s %d]" HEAD DISPLAY_BLINK COLOR_BG_NONE COLOR_FT_YELLOW  "print color %s" ENDL, __FILE__, __LINE__, buf);
		printf("[%s %d]" HEAD DISPLAY_BLINK COLOR_BG_NONE COLOR_FT_RED	"print color %s" ENDL, __FILE__, __LINE__, buf);
		printf("[%s %d]" HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_GREEN	"print color %s" ENDL, __FILE__, __LINE__, buf);
		printf("[%s %d]" HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_PURPLE "print color %s" ENDL, __FILE__, __LINE__, buf);
		printf("[%s %d]" HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_BLUE "print color %s" ENDL, __FILE__, __LINE__, buf);
		printf("[%s %d]" HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_WHITE "print color %s" ENDL, __FILE__, __LINE__, buf);
	
		printf("This is a character control test!\n" );
		sleep(3);
		printf("[%2u]" CLEAR "CLEAR\n" NONE, __LINE__);
	
		printf("[%2u]" BLACK "BLACK " L_BLACK "L_BLACK\n" NONE, __LINE__);
		printf("[%2u]" RED "RED " L_RED "L_RED\n" NONE, __LINE__);
		printf("[%2u]" GREEN "GREEN " L_GREEN "L_GREEN\n" NONE, __LINE__);
		printf("[%2u]" BROWN "BROWN " YELLOW "YELLOW\n" NONE, __LINE__);
		printf("[%2u]" BLUE "BLUE " L_BLUE "L_BLUE\n" NONE, __LINE__);
		printf("[%2u]" PURPLE "PURPLE " L_PURPLE "L_PURPLE\n" NONE, __LINE__);
		printf("[%2u]" CYAN "CYAN " L_CYAN "L_CYAN\n" NONE, __LINE__);
		printf("[%2u]" GRAY "GRAY " WHITE "WHITE\n" NONE, __LINE__);
	
		printf("[%2u]\e[1;31;40m Red \e[0m\n",	__LINE__);
	
		printf("[%2u]" BOLD "BOLD\n" NONE, __LINE__);
		printf("[%2u]" UNDERLINE "UNDERLINE\n" NONE, __LINE__);
		printf("[%2u]" BLINK "BLINK\n" NONE, __LINE__);
		printf("[%2u]" REVERSE "REVERSE\n" NONE, __LINE__);
		printf("[%2u]" HIDE "HIDE\n" NONE, __LINE__);
	
		printf("Cursor test begins!\n" );
		printf("=======!\n" );
		sleep(10);
		printf("[%2u]" "\e[2ACursor up 2 lines\n" NONE, __LINE__);
		sleep(10);
		printf("[%2u]" "\e[2BCursor down 2 lines\n" NONE, __LINE__);
		sleep(5);
		printf("[%2u]" "\e[?25lCursor hide\n" NONE, __LINE__);
		sleep(5);
		printf("[%2u]" "\e[?25hCursor display\n" NONE, __LINE__);
		sleep(5);
		printf("Test ends!\n" );
		sleep(3);
		printf("[%2u]" "\e[2ACursor up 2 lines\n" NONE, __LINE__);
		sleep(5);
		printf("[%2u]" "\e[KClear from cursor downward\n" NONE, __LINE__);
		
}

int main(int argc, char *argv[])
{
	char buf[32]="buf1buf2";
	int sk_hostuniq[3]={0x0};
	int num = 123;
	int *p_int = &num;
	unsigned long long llnum = 1234567898765432123;

	char* const options = "Vhcr:i:d:I:a:p:";
		while((c = getopt (argc, argv, options)) != -1) {
		switch (c) {
			case 'V':
				printf("Skyworth Curl upgrade push tool Version: %s%lu [%s %s]\n", VERSION, (long unsigned int) REVISION, __DATE__, __TIME__);
				exit(EXIT_SUCCESS);
						default:
				usage(argv[0]);
		}
	}

	dlog_warn("buf:%s \t num %d", buf, num);
	dlog_err("buf:%s \t num %d", buf, num);
	dlog_trace();
	dlog_debug("buf:%s \t num %d", buf, num);
	dlog_info("buf:%s \t num %d sizeof int :%zu sizeof piont int :%zu ", buf, num, sizeof(int), sizeof(p_int));
	printf("%llu \t  %llx sizeof sk_hostuniq: %zu\n", llnum, llnum, sizeof(sk_hostuniq));
	sk_hostuniq[0] += 16;
	sk_hostuniq[2] += 32;
	
	printf("sk_hostuniq: %x  %d\n", sk_hostuniq, *sk_hostuniq);
	unsigned char pkt[12]={0x0};
	memcpy(pkt, sk_hostuniq, sizeof(pkt));
	print_hex(pkt, sizeof(pkt));
	
	return 0 ;
}

