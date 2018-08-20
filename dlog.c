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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <getopt.h>
#include <arpa/inet.h>

#include "dlog.h"
#include "version.h"
#include "common.h"


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
			"%s Version %s[%s %s], \nCopyright (C) 2016-2025 cqping  Inc.\n"
			"git commit id : %s\n"
			"http://www.cqping.xyz\n", argv0, VERSION, __DATE__, __TIME__, REVISION);
	exit(EXIT_SUCCESS);
}

void print_styles()
{

		char buf[]= "1234567890abcdefg";
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

void delog_demo()
{
	char buf[]= "1234567890abcdefg";
	int num = 99168;
	int *p_int = &num;

	dlog_warn("buf:%s \t num %d", buf, num);
	dlog_err("buf:%s \t num %d", buf, num);
	dlog_trace();
	dlog_debug("buf:%s \t num %d", buf, num);
	dlog_info("buf:%s \t num %d sizeof int :%zu sizeof piont int :%zu ", buf, num, sizeof(int), sizeof(p_int));

}

#define IP_LEN 24
#define	MAX_PATH_LEN	256

static int interval = 10;
static int upgrade_config = 0;
static char authentication[128] = "admin:admin";
static char cpe_ipaddr[IP_LEN] = "192.168.88.254";
static char directory[MAX_PATH_LEN] = "./";
static int retransfer = 10;

int main(int argc, char *argv[])
{
	int ret = 0;
	int c = 0;
	char* const options = "Vhcr:i:d:I:a:p:";
		while((c = getopt (argc, argv, options)) != -1) {
		switch (c) {
			case 'V':
				printf("Version: %s %s [%s %s]\n", VERSION, REVISION, __DATE__, __TIME__);
				exit(EXIT_SUCCESS);
			case 'h':
				usage(argv[0]);
				exit(EXIT_SUCCESS);
			case 'r':
				if (sscanf(optarg, "%d", &retransfer) != 1) {
					fprintf(stderr, "Illegal argument to -r: Should be -r nums\n");
					exit(EXIT_FAILURE);
				}
				printf("%d\n", retransfer);
				break;
			case 'I':
				if (sscanf(optarg, "%d", &interval) != 1) {
					fprintf(stderr, "Illegal argument to -I: Should be -I nums(seconds)\n");
					exit(EXIT_FAILURE);
				}
				break;
			case 'd':
				/* dir permission check*/
				snprintf(directory, sizeof(directory), "%s", optarg);
				if(access(directory, R_OK) < 0) {
					fprintf(stderr, "directory %s permission check Filed!\n", directory);
					exit(EXIT_FAILURE);
				}
				break;
			case 'i':
				/*device cpe ip check*/
				snprintf(cpe_ipaddr, sizeof(cpe_ipaddr), "%s", optarg);
				struct sockaddr_in sa;
				ret = inet_pton(AF_INET, cpe_ipaddr, &(sa.sin_addr));
				if(ret == 0) {
					fprintf(stderr, "Illegal argument to -i: Should be -i IP\n");
					exit(EXIT_FAILURE);
				}
				dlog_debug("cpe_ipaddr: %s \n ", cpe_ipaddr);
				break;
			case 'a':
				/*authentication*/
				snprintf(authentication, sizeof(authentication), "%s", optarg);
				if(strchr(authentication, ':') == NULL) {
					fprintf(stderr, "Illegal argument to -a: Should be -a username:password\n");
					exit(EXIT_FAILURE);
				}
				break;
			case 'c':
				/*upgrade Configuration*/
				upgrade_config = 1;
				printf("upgrade_config Enabled: %d \n", upgrade_config);
				break;
			default:
				usage(argv[0]);
		}
	}

	
	return 0 ;
}

