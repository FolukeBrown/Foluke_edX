/**
 * op_add -
 * @arg1: First operand
 * @arg2: Second operand
 *
 * Return: Sum of two operands
 */
int op_add(int arg1, int arg2)
{
	return (arg1 + arg2);
}

/**
 * main - Program entry point
 * @ac: Number of arguments
 * @av: Arguments
 */
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	op_add(1, 2);
	return (0);
}
