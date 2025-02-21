import java.util.Scanner;

class Sieve {
	private static void SieveOfEratosthenes(int n) {
		if (n < 2) {
			System.out.println("\n\nThe N must be >= 2!\n");
			return;
		}

		int size = (n + 1) / 2;
		boolean[] isPrime = new boolean[size];

		for (int i = 0; i < size; ++i) {
			isPrime[i] = true;
		}

		System.out.print("\nPrime numbers up to " + n + ":\n2 ");

        for (int i = 3; i * i <= n; i += 2) {
			if (isPrime[i / 2]) {
				for (int mult = i * i; mult <= n; mult += 2 * i) {
					isPrime[mult / 2] = false;
				}
			}
        }

		for (int i = 1; i < size; ++i) {
			if (isPrime[i]) {
				System.out.print((2 * i + 1) + " ");
			}
		}
		System.out.println("\n");
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter N:\n> ");

		if (!scanner.hasNextInt()) {
			System.out.println("\n\nInvalid input!\n");
			scanner.close();
			return;
		}

		int n = scanner.nextInt();
		SieveOfEratosthenes(n);

		scanner.close();
	}
}
