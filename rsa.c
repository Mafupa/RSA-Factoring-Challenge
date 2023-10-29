#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ll unsigned long long

ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		ll temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

ll find_factor(ll n)
{
	ll x = 2, y = 2, d = 1, c;

	while (d == 1)
	{
		x = (x * x + 1) % n;
		y = (y * y + 1) % n;
		y = (y * y + 1) % n;
		c = (x > y) ? x - y : y - x;
		d = gcd(c, n);
	}
	return (d);
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
		ll n = strtoull(line, NULL, 10);
		ll p = find_factor(n);
		ll q = n / p;
		printf("%llu=%llu*%llu\n", n, q, p);
	}
	fclose(file);
	return (0);
}
