# RSA Cryptosystem

## Description
This project is a recreation of the RSA Cryptosystem that fits the confines of a class assignment. Done for my university algorithms course.

## Goals & Objectives
**Primary Goal**: uccessfully trace RSA Cryptosystem Execution for a given set of variables.

### Tasks List
- Allow user to enter two prime numbers
- Handle errors (non-prime numbers given)
- Compute n = p * q
- Compute T(n) = (p-1) * (q-1)
- Calculate and present all possible e values such that GCD(e, T(n)) = 1
- Allow user to select e value
- Check that selection is valid and handle errors
- Find d where d * e = 1 mod T(n) && d < T(n)
- Allow user to enter cleartext (m)
- Ensure 0 <= m < n and handle errors
- Run encryption: c = m^e mod n
- Run decryption: m' = c^d mod n
- Use fast divide and conquer modular exponentiation for encryption and decryption
- Print all variables: p,q,n,T(n),e,d,m,c,m'
