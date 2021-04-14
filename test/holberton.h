#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
/**
 * struct char_funcs - Struct to find function based on char
 * @c: char to check as key
 * @f: Pointer to function to call
 */
typedef struct char_funcs
{
	char *c;
	int (*f)();
} char_funcs_t;

#define SPECIAL_CHAR '%'

void write_buffer(char buffer[], int *buflen, int *bufpos);
void initialize_buffer(char buffer[]);
int _printf(const char *format, ...);
int printfHex(const char *format, ...);
int print_c(va_list args, char buffer[], int *buflen, int *bufpos);
int print_s(va_list args, char buffer[], int *buflen, int *bufpos);
int print_number(int n, char buffer[], int *buflen, int *bufpos);
int print_int_buff(va_list args, char buffer[], int *buflen, int *bufpos);
int print_string(va_list arg);
int print_int(va_list arg);
void print_int_B(int n);
char *binConverter(unsigned int n);
char *octConverter(unsigned int n);
char *hexConverter(char type, unsigned int n);
char *size_tHex(char type, size_t n);
int print_Unum(unsigned int n, char buffer[], int *buflen, int *bufpos);
int print_u(va_list args, char buffer[], int *buflen, int *bufpos);
int print_o(va_list args, char buffer[], int *buflen, int *bufpos);
int print_hex(va_list args, char buffer[], int *buflen, int *bufpos);
int print_heX(va_list args, char buffer[], int *buflen, int *bufpos);
int print_b(va_list args, char buffer[], int *buflen, int *bufpos);
int print_S(va_list args, char buffer[], int *buflen, int *bufpos);
int print_r(va_list args, char buffer[], int *buflen, int *bufpos);
int print_R(va_list args, char buffer[], int *buflen, int *bufpos);
int print_p(va_list args, char buffer[], int *buflen, int *bufpos);
char *convert(unsigned int num, int base);
char *itoa(int num, char *s, int base);
int _puts(char const *s);
long int print_dec(va_list arg);
int print_char(va_list arg);
#endif

