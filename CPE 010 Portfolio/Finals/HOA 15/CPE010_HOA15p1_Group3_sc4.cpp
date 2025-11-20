#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int remainingTime;
    int waitingTime = 0;
    int turnAroundTime = 0;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for(int i=0; i<n; i++) {
        processes[i].pid = i+1;
        cout << "Enter burst time for P" << i+1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    cout << "Enter time quantum: ";
    cin >> quantum;
    queue<int> q;
    q.push(0);
    vector<bool> inQueue(n, false);
    inQueue[0] = true;

    int currentTime = 0;
    int completed = 0;
    while(completed < n) {
        int idx = q.front(); q.pop();

        int execTime = min(quantum, processes[idx].remainingTime);
        processes[idx].remainingTime -= execTime;
        currentTime += execTime;

   
        for(int i=0; i<n; i++) {
            if(processes[i].remainingTime > 0 && !inQueue[i])
                q.push(i), inQueue[i] = true;
        }

        if(processes[idx].remainingTime > 0)
            q.push(idx); 
        else {
            processes[idx].turnAroundTime = currentTime;
            processes[idx].waitingTime = processes[idx].turnAroundTime - processes[idx].burstTime;
            completed++;
        }
    }


    float totalWT = 0, totalTAT = 0;
    cout << "\nP\tBT\tWT\tTAT\n";
    for(int i=0; i<n; i++) {
        cout << "P" << processes[i].pid << "\t" 
             << processes[i].burstTime << "\t" 
             << processes[i].waitingTime << "\t" 
             << processes[i].turnAroundTime << "\n";
        totalWT += processes[i].waitingTime;
        totalTAT += processes[i].turnAroundTime;
    }

    cout << "\nAverage Waiting Time = " << totalWT/n;
    cout << "\nAverage Turnaround Time = " << totalTAT/n << "\n";

    return 0;
}
