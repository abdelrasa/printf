#ifndef MAIN_H
#define MAIN_H

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * typedef struct fmt fmt_t - Typedef for struct fmt
 *
 * @fmt: format
 * @fm_t: function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int process_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/**
 * struct fmt - Struct for format and associated function
 *
 * @fmt: format
 * @fn: function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/* tool */
int func_printable(char);
int func_appndhexa(char, char[], int);
int func_dg(char);

long int trnsfrm_sz_nmbr(long int num, int size);
long int trnsfrm_sz_unsgnd(unsigned long int num, int size);

/* fnction print characters and strings */
int funct_char(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int funct_string(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int funct_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/* handler */
int proces_char(char c, char buffer[], int flags,
		int width, int precision, int size);
int proces_number(int is_positive, int ind, char buffer[], int flags,
		int width, int precision, int size);
int proces_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int proces_pntr(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);

int proces_unsigned(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);

/* Functions print no-printable */
int func_non_prntbl(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/* Functions specifiers */
int func_flags(const char *format, int *i);
int func_width(const char *format, int *i, va_list list);
int func_precision(const char *format, int *i, va_list list);
int func_size(const char *format, int *i);

/* Function pointer */
int func_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Function reverse */
int funt_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/* Functions numbers */
int funct_int(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int binary(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int func_printf_unsgnd(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int prinft_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int printf_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int func_printf_hexad_upp(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int prinft_hxd(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/* Function rot 13 */
int func_printf_rot13_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* SIZES */
#define S_LONG 2
#define S_SHORT 1


/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#endif
