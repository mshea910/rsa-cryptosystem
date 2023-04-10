//
// Created by Michael Shea on 4/10/23.
//

#include "CryptoSystem.h"

CryptoSystem::CryptoSystem(int primeA, int primeB) {
    this->p = primeA;
    this->q = primeB;

    computeN();
    computeTn();
    computeEValues();
}

// Compute n = p * q
void CryptoSystem::computeN() {
    this->n = this->p * this->q;
}

// Compute T(n) = (p-1) * (q-1)
void CryptoSystem::computeTn() {
    this->Tn = (this->p - 1) * (this->q - 1);
}

// Compute All e Values Where GCD(e,T(n)) = 1
void CryptoSystem::computeEValues() {
    int val;
    // While i < T(n)
    for(int i = 1; i <= this->Tn; i++){
        // GCD Function
        val = gcd(i, this->Tn);
        if(val == 1){
            //If GCD Result Equals 1, Add i to List
            this->eList.push_back(i);
        }
    }
}

// GCD Function
int CryptoSystem::gcd(int n1, int n2) {
    int num = 0;
    // While i < T(n)
    for(int i = 1; i <= n2; i++){
        // Check If Both Numbers Are Divisible by i and Set num Accordingly
        if(n1 % i == 0 && n2 % i == 0){
            num = i;
        }
    }
    // Return
    return num;
}

// Run Through eList Vector and Print Values
void CryptoSystem::printList() {
    std::cout << "(";

    for(int i = 0; i < this->eList.size(); i++){
        if(i == this->eList.size() - 1){
            std::cout << eList[i] << ")";
        } else {
            std::cout << eList[i] << ", ";
        }
    }

    std::cout << std::endl;
}

// Verify num is in eList Vector and Return Bool Accordingly
bool CryptoSystem::checkEValue(int num) {
    for(int i : this->eList){
        if(num == i){
            return true;
        } else if(i == this->eList.back()){
            return false;
        }
    }
}

// Set e Variable and Run computeD Function
void CryptoSystem::setEValue(int num) {
    this->e = num;
    computeD();
}

// Find d where d * e = 1 mod T(n) and d < T(n)
void CryptoSystem::computeD() {
    for(int i = 1; i < this->Tn ; i++){
        if((i*this->e) % this->Tn == 1){
            this->d = i;
        }
    }
}

// Verify num < n and num >= 0
bool CryptoSystem::checkMValue(int num) {
    if(num < this->n && num >= 0){
        return true;
    }

    return false;
}

// Set m Variable and run ComputeC and ComputemP
void CryptoSystem::setMValue(int num) {
    this->m = num;
    computeC();
    computemP();
}

// Perform Fast Modular Exponentiation
int CryptoSystem::fastModExp(int a, int b, int n) {
    int x, prod = 1;

    // Set x = a % n
    x = a % n;

    // While b Is Greater Than 0 ...
    while(b > 0) {
        // If b is Non-Prime
        if((b % 2) > 0) {
            // Set prod Equals prod * x mod n
            prod = (prod * x) % n;
        }
        // Set x = x^2 mod n
        x = (x * x) % n;
        // If Odd, Round Down
        b = floor(b/2);
    }

    return prod;
}

// Compute c = m^e mod n Using Fast Modular Exponentiation
void CryptoSystem::computeC() {
    this->c = fastModExp(this->m, this->e, this->n);
}

// Compute m' = c^d mod n Using Fast Modular Exponentiation
void CryptoSystem::computemP() {
    this->mP = fastModExp(this->c, this->d, this->n);
}

// Print Out All Final Variables
void CryptoSystem::printAllVariables() {
    std::cout << "\t p: " << this->p << std::endl;
    std::cout << "\t q: " << this->q << std::endl;
    std::cout << "\t n: " << this->n << std::endl;
    std::cout << "\t T(n): " << this->Tn << std::endl;
    std::cout << "\t e: " << this->e << std::endl;
    std::cout << "\t d: " << this->d << std::endl;
    std::cout << "\t m: " << this->m << std::endl;
    std::cout << "\t c: " << this->c << std::endl;
    std::cout << "\t m': " << this->mP << std::endl;
}