#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void SieveOfEratosthenes(int n) {
	if (n < 2) {
		printf("\n\nThe N must be >= 2!!!\n");
		return;
	}

	int size = (n + 1) / 2;
	bool *is_prime = (bool*)malloc(size * sizeof(bool));
	if (!is_prime) {
		printf("Memory allocation failed!\n");
		return;
	}

	for (int i = 0; i < size; ++i) {
		is_prime[i] = true;
	}
	printf("\nPrime numbers up to %d:\n2 ", n);

	for (int i = 3; i * i <= n; i += 2) {
		if (is_prime[i / 2]) {
			for (int mult = i * i; mult <= n; mult += 2 * i) {
				is_prime[mult / 2] = false;
			}
		}
	}

	for (int i = 1; i < size; ++i) {
		if (is_prime[i]) {
			printf("%d ", 2 * i + 1);
		}
	}
	printf("\n\n");

	free(is_prime);
}

int main() {
	int n;
	printf("Enter N:\n> ");
	int scan_res = scanf("%d", &n);
	if (scan_res != 1) {
		printf("\n\nInvalid input!\n");
		return 1;
	}

	SieveOfEratosthenes(n);

	return 0;
}
