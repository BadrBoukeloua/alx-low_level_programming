#ifndef MAIN_H
#define MAIN_H

unsigned int binary_to_uint(const char *binary);
void print_binary(unsigned long int number);
int get_bit(unsigned long int number, unsigned int index);
int set_bit(unsigned long int *number, unsigned int index);
int clear_bit(unsigned long int *number, unsigned int index);
unsigned int flip_bits(unsigned long int number1, unsigned long int number2);
int _atoi(const char *str);
int _putchar(char character);
int get_endianness(void);

#endif

