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

void CryptoSystem::computeN() {
    this->n = this->p * this->q;
}

void CryptoSystem::computeTn() {
    this->Tn = (this->p - 1) * (this->q - 1);
}

void CryptoSystem::computeEValues() {
    int val;
    for(int i = 1; i <= this->Tn; i++){
        val = gcd(i, this->Tn);
        if(val == 1){
            this->eList.push_back(i);
        }
    }
}

int CryptoSystem::gcd(int n1, int n2) {
    int num = 0;
    for(int i = 1; i <= n2; i++){
        if(n1 % i == 0 && n2 % i == 0){
            num = i;
        }
    }

    return num;
}

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

bool CryptoSystem::checkEValue(int num) {
    for(int i : this->eList){
        if(num == eList[i]){
            return true;
        } else if(i == this->eList.size() - 1){
            return false;
        }
    }
}

void CryptoSystem::setEValue(int num) {
    this->e = num;
    computeD();
}

void CryptoSystem::computeD() {
    for(int i = 1; i < this->Tn ; i++){
        if((i*this->e) % this->Tn == 1){
            this->d = i;
        }
    }
}

bool CryptoSystem::checkMValue(int num) {
    if(num < this->n && num >= 0){
        return true;
    }

    return false;
}

void CryptoSystem::setMValue(int num) {
    this->m = num;
    computeC();
    computemP();
}

int CryptoSystem::fastModExp(int a, int b, int n) {
    int x, prod;

    prod = 1;
    x = a % n;

    while(b > 0) {
        if((b % 2) > 0) {
            prod = (prod * x) % n;
        }
        x = (x * x) % n;
        b = floor(b/2);
    }

    return prod;
}

void CryptoSystem::computeC() {
    this->c = fastModExp(this->m, this->e, this->n);
}

void CryptoSystem::computemP() {
    this->mP = fastModExp(this->c, this->d, this->n);
}

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