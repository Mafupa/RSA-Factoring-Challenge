#include <stdlib.h>
#include <stdio.h>

unsigned int find_factor(unsigned int n)
{
	unsigned int i = 2;

	for (; i < n; i++)
	{
		if (n % i == 0)
			return (i);
	}
	return (-1);
}

int main(int argc, char **argv)
{
	FILE *file;
	char line[1024];

	if (argc != 2)
	{
		perror("Usage: factors <file>");
		return (1);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Error opening this file");
		return (1);
	}
	while (fgets(line, sizeof(line), file))
	{
		unsigned int n = atoi(line);
		unsigned int p = find_factor(n);
		unsigned int q = n / p;
		printf("%u=%u*%u\n", n, q, p);
	}
	fclose(file);
	return (0);
}
