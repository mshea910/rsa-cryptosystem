//
// Created by Michael Shea on 4/10/23.
#include "CryptoSystem.h"

// Function to Check if Number is Prime
bool checkPrime(int num){
    if(num % 2 == 0) {
        return false;
    }
    return true;
}

int main() {
    // Initalize Variables
    int p, q, m, e = 0;
    bool err = false;

    // Collect Initial User Input
    std::cout << "\t~~ Welcome to the RSA CryptoSystem v1.0.0 ~~" << std::endl;
    std::cout << "\nPlease enter your first Prime Number: ";
    std::cin >> p;
    err = checkPrime(p);
    // Ensure Prime Number was Given and Handle Error
    while(!err){
        std::cout << "\n\nI'm sorry, it seems you've entered a non-prime number." << std::endl;
        std::cout << "\nPlease enter your first Prime Number: ";
        std::cin >> p;
        err = checkPrime(p);
    }
    std::cout << std::endl << "\nPlease enter your second Prime Number: ";
    std::cin >> q;
    err = checkPrime(q);
    // Ensure Prime Number was Given and Handle Error
    while(!err){
        std::cout << "\n\nI'm sorry, it seems you've entered a non-prime number." << std::endl;
        std::cout << "\nPlease enter your second Prime Number: ";
        std::cin >> q;
        err = checkPrime(q);
    }

    // Create CryptoSystem object
    auto * mySys = new CryptoSystem(p, q);

    // List All e Values
    std::cout << "\n\nExcellent! Here are the possible values for e: ";
    mySys->printList();

    // Collect e Value
    std::cout << "\nPlease select your e value: ";
    std::cin >> e;
    err = mySys->checkEValue(e);
    // Ensure e Value Requirements are Met and Handle Error
    while(!err){
        std::cout << "\n\nI'm sorry, it seems that was not a valid selection." << std::endl;
        std::cout << "\nPlease select your e value: ";
        std::cin >> e;
        err = mySys->checkEValue(e);
    }

    // Set e Value
    mySys->setEValue(e);

    // Collect m Value (Message Plaintext)
    std::cout << "\n\nGreat! Please enter the numeric message you would like to encrypt: ";
    std::cin >> m;
    err = mySys->checkMValue(m);
    // Ensure m Value Requirements are Met and Handle Error
    while(!err){
        std::cout << "\n\nI'm sorry, it seems that was not a valid selection. Your message must be a positive"
                     " integer less than " << p*q << "." << std::endl;
        std::cout << "\nPlease enter the numeric message you would like to encrypt: ";
        std::cin >> m;
        err = mySys->checkMValue(m);
    }

    // Set m Value
    mySys->setMValue(m);

    // Final Print Out of All Variables
    std::cout << "\n\nPerfect! Here is the final readout of all variables: " << std::endl;
    mySys->printAllVariables();
}
//
