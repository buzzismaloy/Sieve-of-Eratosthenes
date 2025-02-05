def sieve_of_eratosthenes(n):
    if n < 2:
        print("The N must be >= 2!\n")
        return

    size = (n + 1) // 2
    is_prime = [True] * size

    print("\nPrime numbers up to {}:\n2".format(n), end=" ")
    for i in range(3, int(n ** 0.5) + 1, 2):
        if is_prime[i // 2]:
            for mult in range(i * i, n + 1, 2 * i):
                is_prime[mult // 2] = False

    for i in range(1, size):
        if is_prime[i]:
            print(2 * i + 1, end=" ")
    print("\n")

if __name__ == "__main__":
    try:
        n = int(input("Enter N:\n> "))
        sieve_of_eratosthenes(n)
    except ValueError:
        print("\n\nInvalid input!\n")

