//
// Created by Michael Shea on 4/10/23.
#include "CryptoSystem.h"

int main() {
    int p, q, m, e = 0;
    bool err = false;

    std::cout << "\t~~ Welcome to the RSA CryptoSystem v1.0.0 ~~" << std::endl;
    std::cout << "\nPlease enter your first Prime Number: ";
    std::cin >> p;
    // Need to add Prime Number checking
    std::cout << std::endl << "\nPlease enter your second Prime Number: ";
    std::cin >> q;
    // Need to add Prime Number checking

    auto * mySys = new CryptoSystem(p, q);

    std::cout << "\n\nExcellent! Here are the possible values for e: ";
    mySys->printList();

    std::cout << "\nPlease select your e value: ";
    std::cin >> e;
    err = mySys->checkEValue(e);
    while(!err){
        std::cout << "\n\nI'm sorry, it seems that was not a valid selection." << std::endl;
        std::cout << "\nPlease select your e value: ";
        std::cin >> e;
        err = mySys->checkEValue(e);
    }

    mySys->setEValue(e);

    std::cout << "\n\nGreat! Please enter the numeric message you would like to encrypt: ";
    std::cin >> m;
    err = mySys->checkMValue(m);
    while(!err){
        std::cout << "\n\nI'm sorry, it seems that was not a valid selection. Your message must be a positive"
                     " integer less than " << p*q << "." << std::endl;
        std::cout << "\nPlease enter the numeric message you would like to encrypt: ";
        std::cin >> m;
        err = mySys->checkMValue(m);
    }

    mySys->setMValue(m);

    std::cout << "Perfect! Here is the final readout of all variables: "
}
//
