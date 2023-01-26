#include "main.h"
/**
 * print_unsigned - prints unsigned number
 * @types: lists of args
 * @buffer: buffer arr to handle print
 * @flags: calc active flags
 * @width: get width
 * @precision: precision spec
 * @size: size specifier
 * Return: 0 Success
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - prints unsigned number in hexa notation
 * @types: list of args
 * @buffer: buffer arr to handle print
 * @flags: calc avtive flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: 0 Success
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}
/**
 * print_hexa - prints a hexadecimal number in lower or upper
 * @types: lists of args
 * @map_to: Arr of values to map numbers to
 * @buffer: buffer arr to handle print
 * @flags: calc active flags
 * @flag_ch: calc active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: 0 Success
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
