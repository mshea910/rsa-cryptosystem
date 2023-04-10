//
// Created by Michael Shea on 4/10/23.
//

#ifndef RSA_CRYPTOSYSTEM_CRYPTOSYSTEM_H
#define RSA_CRYPTOSYSTEM_CRYPTOSYSTEM_H
#include <iostream>


class CryptoSystem {
public:
    CryptoSystem(int primeA, int primeB);

private:
    int p;
    int q;
    int n;
    int Tn;
    int e;
    int d;
    int m;
    int mP;
    int c;

    void computeN();
    void computeTn();
};


#endif //RSA_CRYPTOSYSTEM_CRYPTOSYSTEM_H
