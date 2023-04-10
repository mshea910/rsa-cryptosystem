//
// Created by Michael Shea on 4/10/23.
//

#ifndef RSA_CRYPTOSYSTEM_CRYPTOSYSTEM_H
#define RSA_CRYPTOSYSTEM_CRYPTOSYSTEM_H
#include <iostream>
#include <vector>


class CryptoSystem {
public:
    CryptoSystem(int primeA, int primeB);

    // Public Setters
    void setEValue(int num);
    void setMValue(int num);

    void printList();
    void printAllVariables();
    bool checkEValue(int num);
    bool checkMValue(int num);

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

    std::vector<int> eList;

    void computeN();
    void computeTn();
    void computeEValues();
    void computeD();
    void computeC();
    void computemP();
    int gcd(int n1, int n2);
};


#endif //RSA_CRYPTOSYSTEM_CRYPTOSYSTEM_H
