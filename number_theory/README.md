# Modular Arithmetic and Bit Operations

## Table of Contents
- [Modular Arithmetic and Bit Operations](#modular-arithmetic-and-bit-operations)
  - [Table of Contents](#table-of-contents)
  - [Modular Arithmetic Formulas](#modular-arithmetic-formulas)
  - [Why Use $10^9 + 7$?](#why-use-109--7)
  - [Modular Multiplicative Inverse (MMI)](#modular-multiplicative-inverse-mmi)
  - [Binary Representation](#binary-representation)
  - [Bitwise Operations](#bitwise-operations)
    - [Truth Table](#truth-table)
    - [Bit Shift Operations](#bit-shift-operations)
  - [Data Types and Bit Limits](#data-types-and-bit-limits)
    - [32-bit Integer Limits](#32-bit-integer-limits)
    - [Bit Terminology](#bit-terminology)
  - [Usage Examples](#usage-examples)
    - [Euler's Totient Function (φ)](#eulers-totient-function-φ)
    - [Euler's Theorem](#eulers-theorem)
    - [Prime Factorization](#prime-factorization)
    - [Total Number of Divisors](#total-number-of-divisors)
    - [Sum of All Divisors](#sum-of-all-divisors)
  - [Fermat's Little Theorem](#fermats-little-theorem)

## Modular Arithmetic Formulas

Basic modular arithmetic operations:

1. **Addition**: $(a + b) \bmod m = ((a \bmod m) + (b \bmod m)) \bmod m$
2. **Subtraction**: $(a - b) \bmod m = ((a \bmod m) - (b \bmod m) + m) \bmod m$
3. **Multiplication**: $(a \cdot b) \bmod m = ((a \bmod m) \cdot (b \bmod m)) \bmod m$
4. **Division**: $\frac{a}{b} \bmod m = a \cdot b^{-1} \bmod m$ 
   
   $b^{-1} \bmod m$ is MMI of $b$

## Why Use $10^9 + 7$?

The value $10^9 + 7$ (1000000007) is commonly used in modular arithmetic for two main reasons:

1. **No Integer Overflow**: It's very close to the maximum value that can be stored in a 32-bit signed integer $(2^{31} - 1 = 2147483647)$, preventing overflow during calculations
2. **Prime Number**: Being prime, it guarantees the existence of modular multiplicative inverse (MMI) for all numbers from $1$ to $M-1$

## Modular Multiplicative Inverse (MMI)

For prime modulus $M$, every number from $1$ to $M-1$ has a unique multiplicative inverse.

## Binary Representation

Decimal to binary conversion examples:

| Decimal | Binary |
| ------- | ------ |
| 0       | 0      |
| 1       | 1      |
| 2       | 10     |
| 3       | 11     |
| 4       | 100    |
| 5       | 101    |
| 7       | 111    |

**Key Observation**: 
- **Odd numbers** have their last bit as `1`
- **Even numbers** have their last bit as `0`

## Bitwise Operations

### Truth Table

| A   | B   | AND (&) | OR (\|) | XOR (^) |
| --- | --- | ------- | ------- | ------- |
| 0   | 0   | 0       | 0       | 0       |
| 0   | 1   | 0       | 1       | 1       |
| 1   | 0   | 0       | 1       | 1       |
| 1   | 1   | 1       | 1       | 0       |

### Bit Shift Operations

- **Left Shift (`<<`)**: Multiplies by $2^n$
- **Right Shift (`>>`)**: Divides by $2^n$ (integer division)

## Data Types and Bit Limits

For $n$ bits, the maximum representable number is $2^n - 1$.

### 32-bit Integer Limits

- **Signed int**: Can store values from $-(2^{31})$ to $2^{31} - 1$
  - Range: -2,147,483,648 to 2,147,483,647
  - One bit reserved for sign (+/-)

- **Unsigned int**: Can store values from $0$ to $2^{32} - 1$
  - Range: 0 to 4,294,967,295
  - All bits used for magnitude

### Bit Terminology

- **Set bit**: Bit value is `1`
- **Unset bit**: Bit value is `0`
- **MSB**: Most Significant Bit (leftmost)
- **LSB**: Least Significant Bit (rightmost)

Example: $1\underbrace{0111011}_{LSB}$
- MSB = 1 (leftmost)
- LSB = 1 (rightmost)

## Usage Examples

```cpp
// Modular arithmetic example
const int MOD = 1000000007;
long long result = ((a % MOD) * (b % MOD)) % MOD;

// Checking if number is odd/even using bitwise AND
bool isOdd = (n & 1);  // Returns true if odd

// Left shift (multiply by 2)
int doubled = n << 1;

// Right shift (divide by 2)
int halved = n >> 1;
```
### Euler's Totient Function (φ)


$$\phi(n) = n \prod_{p \mid n} \left(1 - \frac{1}{p}\right)$$

For prime -

$$\phi(n) = n  \left(1 - \frac{1}{n}\right) = n-1$$

Where:  
- $n$ = Positive integer  
- $p$ $\mid$ $n$ = All distinct prime divisors of $n$

Example - 

$\phi(5) = 5 \left(1 - \frac{1}{5}\right) = 5 \cdot \frac{4}{5} = 4$

$\phi(6) = 6 \left(1 - \frac{1}{2}\right) \left(1 - \frac{1}{3}\right) = 6 \cdot \frac{1}{2} \cdot \frac{2}{3} = 2$

### Euler's Theorem

$$1.a^{b} \equiv a^{b\mod\phi(n)} \mod(n)$$
$$2.(a^{b}\mod n) \equiv (a^{b\mod\phi(n)})\mod n$$ 
 
$$3.(a^{b}\mod M)=(a^{b\mod\phi(M)})\mod M$$

Generalized formula -

$$(a^{b}\mod M) \equiv (a^{b\mod\phi(M)})\mod M  \ (M = Any \ integer)$$

$$(a^{b}\mod M) \equiv (a^{b\mod(M-1)})\mod M  \ (M = Prime \ number)$$




**Where:**  
- $\phi(n)$ is Euler’s Totient Function  
- $\gcd(a, n)$ is the greatest common divisor of $a$ and $n$



### Prime Factorization

For any positive integer $x$, the prime factorization is:
$$x = p_1^{n_1} \cdot p_2^{n_2} \cdot p_3^{n_3} \cdots p_t^{n_t}$$

where $p_1, p_2, p_3, \ldots, p_t$ are distinct prime factors and $n_1, n_2, n_3, \ldots, n_t$ are their respective exponents.

### Total Number of Divisors

The total count of divisors is:
$$(n_1 + 1)(n_2 + 1)(n_3 + 1) \cdots (n_t + 1)$$

**Example:**
$$36 = 2^2 \cdot 3^2$$
Number of divisors = $(2 + 1)(2 + 1) = 3 \cdot 3 = 9$

### Sum of All Divisors

The sum of all divisors is:
$$(1 + p_1 + p_1^2 + p_1^3 + \cdots + p_1^{n_1})(1 + p_2 + p_2^2 + p_2^3 + \cdots + p_2^{n_2}) \cdots$$

Using the geometric series formula, this simplifies to:
$$\frac{p_1^{n_1+1} - 1}{p_1 - 1} \cdot \frac{p_2^{n_2+1} - 1}{p_2 - 1} \cdot \frac{p_3^{n_3+1} - 1}{p_3 - 1} \cdots \frac{p_t^{n_t+1} - 1}{p_t - 1}$$

**Example:**
$$36 = 2^2 \cdot 3^2$$
Sum of divisors = $(1 + 2 + 4)(1 + 3 + 9) = 7 \cdot 13 = 91$

Or using the formula:
$$\frac{2^3 - 1}{2 - 1} \cdot \frac{3^3 - 1}{3 - 1} = \frac{7}{1} \cdot \frac{26}{2} = 7 \cdot 13 = 91$$

## Fermat's Little Theorem

If $p$ is prime and $a$ is not divisible by $p$ (i.e., $\gcd(a, p) = 1$), then:
$$a^{p-1} \equiv 1 \pmod{p}$$

**Alternative form:**
For any integer $a$ and prime $p$:
$$a^p \equiv a \pmod{p}$$
The condition can be stated as either "$a \not\equiv 0 \pmod{p}$" or "$a$ is not a multiple of $p$" or "$\gcd(a, p) = 1$" - they are all equivalent when $p$ is prime.

Note: The condition can be stated as either $a \not\equiv 0 \pmod{p}$ or "$a$ is not a multiple of $p$" or $\gcd(a, p) = 1$ - they are all equivalent when $p$ is prime.


