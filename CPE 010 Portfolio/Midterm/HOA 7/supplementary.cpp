//
// Created by oms2v on 18/09/2025.
//
#include <iostream>
#include <cstdlib>
#include "sorting.h"
#include "searching.h"
#include "candidates.h"


const int maxSize = 100;

void randomNumberArray(int arr[], size_t arrSize) {
    for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % 5) + 1;
    }
}

void line() {
    std::cout << "---------------------------------------------\n";
}
int main() {

    int data[maxSize];

    std::cout << "Candidates: \n";

    Candidates c[] = {
        Candidates("Bo Dalton Capistrano", 0),
        Candidates("Cornelius Raymon Agustin", 0),
        Candidates("Deja Jayla Banaga", 0),
        Candidates("Lalla Brielle Yabut",0),
        Candidates("Franklin Relano Castro", 0),
    };

    line();

    std::cout << "Votes: \n";
    randomNumberArray(data, maxSize);
    printArray(data, maxSize);
    line();

    std::cout << "Sorting Votes: \n";
    selectionSort(data, maxSize);
    printArray(data, maxSize);
    line();

    std::cout << "Counting Votes...\n";
    countVotes(c, data, 5, maxSize);
    std::cout << "Successfully counted...\n";

    for (int i = 0; i < 5; i++) {
        cDisplay(c[i]);
    }

    line();
    sortCandidatesByVotes(c, 5);
    line();

    std::cout << "Candidates from most votes to least: \n";
    for (int i = 0; i < 5; i++) {
        cDisplay(c[i]);
    }

    line();
    std::cout << "The winner is: \n";
    cDisplay(c[0]);
    line();

    return 0;
}