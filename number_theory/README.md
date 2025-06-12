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
  - [$$(1+2+4)\*(1+3+9)$$](#124139)

## Modular Arithmetic Formulas

Basic modular arithmetic operations:

1. **Addition**: $(a + b) \bmod m = ((a \bmod m) + (b \bmod m)) \bmod m$
2. **Subtraction**: $(a - b) \bmod m = ((a \bmod m) - (b \bmod m) + m) \bmod m$
3. **Multiplication**: $(a \cdot b) \bmod m = ((a \bmod m) \cdot (b \bmod m)) \bmod m$
4. **Division**: $\frac{a}{b} \bmod m = a \cdot b^{-1} \bmod m$

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

$$x=p_{1}^{n_{1}}*p_{2}^{n_{2}}*p_{3}^{n_{3}}\dots*p_{t}^{n_{t}}$$

Total divisors count - 

$$(n_{1}+1)*(n_{2}+1)*(n_{3}+1) \dots*(n_{t}+1)$$

Example -

$$36=2^{2}*3^{2}$$ 

$$(2+1)*(2+1)=9$$

Total sum -

$$(1+p_{1}+p_{1}^2+p_{1}^3\dots+p_{1}^{n1})*(1+p_{2}+p_{2}^2+p_{2}^3\dots+p_{2}^{n2})\\*(1+p_{3}+p_{3}^2+p_{3}^3\dots+p_{3}^{n3})$$

$$=\frac{p_{1}^{n1}-1}{p_{1}-1}*\frac{p_{2}^{n2}-1}{p_{2}-1}*\frac{p_{3}^{n3}-1}{p_{3}-1}\dots*\frac{p_{t}^{nt}-1}{p_{t}-1}$$
Example -

$$36=2^{2}*3^{2}$$ 
$$(1+2+4)*(1+3+9)$$
---

