//
// Created by oms2v on 18/09/2025.
//

#ifndef CANDIDATES_H
#define CANDIDATES_H
#include <iostream>
#include "searching.h"
#include "sorting.h"

class Candidates {
public:
    std::string name;
    int votes;

    // Default Constructor
    Candidates() {
        name = "";
        votes = 0;
        std::cout << "Candidate created\n";
    }
    // Constructor with parameter
    Candidates(const std::string &n, const int v) {
        name = n;
        votes = v;
        std::cout << "Candidate " << name << " created\n";
    }

    //Copy Constructor
    Candidates(const Candidates& orig) {
        name = orig.name;
        votes = orig.votes;
        std::cout << "Copy candidate " << name << " created\n";
    }
    // Destructor
    ~Candidates() {
        std::cout << "Candidate " << name << " deleted\n";
    }


};
inline void sortCandidatesByVotes(Candidates arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j].votes > arr[maxIndex].votes) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Candidates temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}
inline void countVotes(Candidates candidates[], int votes[], int numCandidates, int voteArraySize) {
    for (int i = 0; i < numCandidates; ++i) {
        candidates[i].votes = countOccurrencesArray(votes, voteArraySize, i + 1);
    }
}
inline void cDisplay(const Candidates &candidate)  {
    std::cout << "Candidate " << candidate.name << " has " << candidate.votes << " votes.\n";
}

#endif //CANDIDATES_H
