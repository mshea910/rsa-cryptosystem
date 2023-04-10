//
// Created by Michael Shea on 4/10/23.
//

#include "CryptoSystem.h"

CryptoSystem::CryptoSystem(int primeA, int primeB) {
    this->p = primeA;
    this->q = primeB;

    computeN();
    computeTn();
}

void CryptoSystem::computeN() {
    this->n = this->p * this->q;
}

void CryptoSystem::computeTn() {
    this->Tn = (this->p - 1) * (this->q - 1);
}