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
#include<stdio.h>
#include<unistd.h>
#include "dlog.h"
//\e[display;font-color;backgroud-color	m	string  \e[0m
int main(void)
{
	char buf[32]="buf1buf2";
	int num = 123;


	dlog_warn("buf:%s \t num %d", buf, num);
	dlog_err("buf:%s \t num %d", buf, num);
	dlog_trace();
	dlog_debug("buf:%s \t num %d", buf, num);
	dlog_info("buf:%s \t num %d", buf, num);

#if 0
	printf("[%s %d]" HEAD DISPLAY_BLINK COLOR_BG_NONE COLOR_FT_YELLOW  "print color %s" ENDL, __FILE__, __LINE__, buf);
	printf("[%s %d]" HEAD DISPLAY_BLINK COLOR_BG_NONE COLOR_FT_RED  "print color %s" ENDL, __FILE__, __LINE__, buf);
	printf("[%s %d]" HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_GREEN	"print color %s" ENDL, __FILE__, __LINE__, buf);
	printf("[%s %d]" HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_PURPLE	"print color %s" ENDL, __FILE__, __LINE__, buf);
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

	printf("[%2u]\e[1;31;40m Red \e[0m\n",  __LINE__);

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
#endif
	return 0 ;
}

