#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string name;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

bool compareArrival(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

int main() {
    int n = 5;
    vector<Process> processes(n);

    processes[0] = {"P1", 6, 2};
    processes[1] = {"P2", 2, 5};
    processes[2] = {"P3", 8, 1};
    processes[3] = {"P4", 3, 0};
    processes[4] = {"P5", 4, 4};

    sort(processes.begin(), processes.end(), compareArrival);

    int currentTime = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {

        if (currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;

        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    cout << "Process\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].name << "\t"
             << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t"
             << processes[i].waitingTime << "\t"
             << processes[i].turnaroundTime << "\t\t"
             << processes[i].completionTime << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWaitingTime / n;
    cout << "\nAverage Turnaround Time: " << totalTurnaroundTime / n << endl;

    return 0;
}
