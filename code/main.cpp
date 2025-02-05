#include <iostream>
#include <memory>

void SieveOfEratosthenes(int n) {
	if (n < 2) {
		std::cout << "\n\nThe N must be >= 2!\n";
		return;
	}

	int size = (n + 1) / 2;
	std::unique_ptr<bool[]> is_prime = std::make_unique<bool[]>(size);
	for (int i = 0; i < size; ++i) {
		is_prime[i] = true;
	}
	std::cout << "\nPrime numbers up to " << n << ":\n2 ";

	for (int i = 3; i * i <= n; i += 2) {
		if (is_prime[i / 2]) {
			for (int mult = i * i; mult <= n; mult += 2 * i) {
				is_prime[mult / 2] = false;
			}
		}
	}

	for (int i = 1; i < size; ++i) {
		if (is_prime[i]) {
			std::cout << 2 * i + 1 << ' ';
		}
	}
	std::cout << "\n\n";
}

int main() {
	int n;
	std::cout << "Enter N:\n>";
	if (!(std::cin >> n)) {
		std::cerr << "\n\nInvalid input!\nExiting...\n";
		return 1;
	}

	SieveOfEratosthenes(n);

	return 0;
}
