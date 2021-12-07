# Algorithms

## Sieve of Eratosthenes

In mathematics, the sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.

![sieve](https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif)

### Definition of the algorithm from wikipedia:
A prime number is a natural number that has exactly two distinct natural number divisors: the number 1 and itself.

To find all the prime numbers less than or equal to a given integer n by Eratosthenes' method:

<ol>
<li><p>Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).</p></li>
<li><p>Initially, let p equal 2, the smallest prime number.</p></li>
<li><p>Enumerate the multiples of p by counting in increments of p from 2p to n, and mark them in the list (these will be 2p, 3p, 4p, ...; the p itself should not be marked).</p></li>
<li><p>Find the smallest number in the list greater than p that is not marked. If there was no such number, stop. Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.</p></li>
<li><p>When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.</p></li>
</ol>


[Solution in C](eratosthenes_sieve/eratosthenes_sieve.c)

[Solution in Python](eratosthenes_sieve/eratosthenes_sieve.py)

## Knight's tour

A knight's tour is a sequence of moves of a knight on a chessboard such that the knight visits every square exactly once. If the knight ends on a square that is one knight's move from the beginning square (so that it could tour the board again immediately, following the same path), the tour is closed; otherwise, it is open.

![tour](https://upload.wikimedia.org/wikipedia/commons/c/ca/Knights-Tour-Animation.gif)

### Brute force solution
Brute-force algorithms
A brute-force search for a knight's tour is impractical on all but the smallest boards.[15] For example, there are approximately 4×1051 possible move sequences on an 8 × 8 board,[16] and it is well beyond the capacity of modern computers (or networks of computers) to perform operations on such a large set. However, the size of this number is not indicative of the difficulty of the problem, which can be solved "by using human insight and ingenuity ... without much difficulty.

[Solution in C](knights_tour/knights_tour.c)

[Solution in Python](knights_tour/knights_tour.py)
