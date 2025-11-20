#include <iostream>
#include "queue.h"

class Job {
public:
    int jobID;
    std::string userName;
    int pageCount;

    Job(int id, std::string user, int pages) {
        jobID = id;
        userName = user;
        pageCount = pages;
    }
    Job() : jobID(0), userName(""), pageCount(0) {}

    void printDeets() const {
        std::cout << "Job ID: " << jobID << "\n";
        std::cout << "User Name: " << userName << "\n";
        std::cout << "Page Count: " << pageCount << "\n";
    }
};

// Overload << for Job
std::ostream& operator<<(std::ostream& os, const Job& job) {
    os << "Job ID: " << job.jobID
       << ", User Name: " << job.userName
       << ", Page Count: " << job.pageCount;
    return os;
}

class Printer {
private:
    Queue<Job> jobQueue;

public:
    void addJob(const Job& newJob) {
        jobQueue.enqueue(newJob);
        std::cout << "Added job to queue\n";
        newJob.printDeets();
    }

    void processJobs() {
        while (!jobQueue.isEmpty()) {
            std::cout << "Processing job...\n";
            jobQueue.getFront();
            jobQueue.dequeue();
        }
        std::cout << "All jobs processed.\n";
    }
};

int main() {
    Printer companyPrinter;
    companyPrinter.addJob(Job(241, "Roman", 100));
    companyPrinter.addJob(Job(242, "Jimlord", 200));
    companyPrinter.addJob(Job(243, "Robin", 300));

    std::cout << "\nProcessing Jobs \n";
    companyPrinter.processJobs();

    return 0;
}
