# Sieve of Eratosthenes

## About

The sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.

## Algorithm

1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
2. Initially, let p equal 2, the smallest prime number.
3. Enumerate the multiples of p by counting in increments of p from 2p to n, and mark them in the list (these will be 2p, 3p, 4p, ...; the p itself should not be marked).
4. Find the smallest number in the list greater than p that is not marked. If there was no such number, stop. Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
5. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.

## Run program

1. Clone git repository:
```bash
https://github.com/buzzismaloy/Sieve-of-Eratosthenes.git
```
2. Go to the directory:
```bash
cd Sieve-of-Eratosthenes/code
```
3. Compile and run:

* C:

```bash
gcc main.c -o main
./main
```
* C++:

```bash
g++ main.cpp -o main
./main
```
* Java:

```bash
javac Sieve.java
java Sieve
```
* Python:

```bash
python3 main.py
```

## See also

* [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
