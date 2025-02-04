#include <stdio.h>
#include <stdlib.h>

void SieveOfEratoshenes(int n) {
	if (n < 2) {
		printf("\n\nThe N must be >= 2!!!\n");
		return;
	}

	int *sieve = (int*)malloc((n + 1) * sizeof(int));
	if (!sieve) {
		printf("Memory allocation failed!\n");
		return;
	}
	sieve[0] = sieve[1] = -1; // 0 & 1 are neither prime nor composite numbers
	for (int i = 2; i  <= n; ++i) {
		sieve[i] = 1; // init any other number as prime
	}

	for (int i = 2; i * i <= n; ++i) {
		if (sieve[i]) {
			for (int mult = i * i; mult <= n; mult += i) {
				sieve[mult] = 0;
			}
		}
	}

	printf("\nPrime numbers up to %d:\n", n);
	for (int i = 2; i <=n; ++i) {
		if (sieve[i]) {
			printf("%d ", i);
		}
	}
	printf("\n\n");

	free(sieve);
}

int main() {
	int n;
	printf("Enter N:\n>");
	int scan_res = scanf("%d", &n);
	if (scan_res != 1) {
		printf("\n\nInvalid input!\n");
		return 0;
	}

	SieveOfEratoshenes(n);

	return 0;
}
