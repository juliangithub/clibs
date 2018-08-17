/*===============================================================
*	Copyright (C) 2018 All rights reserved.
*	
*	Filename：dlog.h
*	Author：julian
*	Date：2018-08-05
*	Discription:
*	
*	release notes：
*
================================================================*/
#ifndef _DLOG_H
#define _DLOG_H
#if 1
#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"
 
#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
#define CLEAR                "\e[2J"
#define CLRLINE              "\r\e[K" //or "\e[1K\r"
#endif

#define HEAD				"\e["// or "\033["
#define DISPLAY_DEF			"0"
#define DISPLAY_BOLD		"1"
#define DISPLAY_BLINK		"5"
#define DISPLAY_UNLINE		"24"

#define COLOR_FT_BLACK			";30m"
#define COLOR_FT_RED			";31m"
#define COLOR_FT_GREEN			";32m"
#define COLOR_FT_YELLOW			";33m"
#define COLOR_FT_BLUE			";34m"
#define COLOR_FT_PURPLE			";35m"
#define COLOR_FT_CYAN			";36m"
#define COLOR_FT_WHITE			";37m"

#define COLOR_BG_NONE			""
#define COLOR_BG_BLACK			";40"
#define COLOR_BG_RED			";41"
#define COLOR_BG_GREEN			";42"
#define COLOR_BG_YELLOW			";43"
#define COLOR_BG_BLUE			";44"
#define COLOR_BG_PURPLE			";45"
#define COLOR_BG_CYAN			";46"
#define COLOR_BG_WHITE			";47"

#define ENDL                 "\e[0m\n"


#define DLOG_EN

#define dlog_warn(format, ...)   printf(HEAD DISPLAY_BLINK COLOR_BG_NONE COLOR_FT_YELLOW"Warning(%s %d )"format ENDL, __FILE__, __LINE__,##__VA_ARGS__)
#define dlog_err(format, ...)   printf(HEAD DISPLAY_BLINK COLOR_BG_NONE COLOR_FT_RED"Error(%s %d )"format ENDL, __FILE__, __LINE__,##__VA_ARGS__)
#ifdef DLOG_EN
    #define dlog_trace()                  printf(HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_BLUE"(%s %s %d )" ENDL, __FILE__, __FUNCTION__, __LINE__)
    #define dlog_debug(format, ...)   printf(HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_PURPLE"(%s %d )"format ENDL, __FILE__, __LINE__,##__VA_ARGS__)
    #define dlog_info(format, ...)   printf(HEAD DISPLAY_DEF COLOR_BG_NONE COLOR_FT_GREEN"Info:(%s %d )"format ENDL, __FILE__, __LINE__,##__VA_ARGS__)
#else
    #define dlog_trace()
    #define dlog_debug(format, ...)
    #define dlog_info(format, ...)
#endif

#endif //DLOG_H
