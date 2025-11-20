#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string name;
    int arrival, burst;
    int waiting, turnaround, completion;
};

bool sortByArrival(Process a, Process b) {
    return a.arrival < b.arrival;
}

int main() {
 
    vector<Process> p = {
        {"P1", 0, 2},
        {"P2", 0, 8},
        {"P3", 0, 1},
        {"P4", 0, 4}
    };

    int n = p.size();
    sort(p.begin(), p.end(), sortByArrival);

    int currentTime = 0;
    vector<string> order;
    double totalWT = 0, totalTAT = 0;

    vector<bool> done(n, false);
    int completed = 0;

    while (completed < n) {
        int idx = -1, minBurst = 9999;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= currentTime && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                idx = i;
            }
        }

        if (idx == -1) {
            currentTime++;
            continue;
        }

        currentTime += p[idx].burst;
        p[idx].completion = currentTime;
        p[idx].turnaround = p[idx].completion - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;
        done[idx] = true;
        completed++;
        order.push_back(p[idx].name);

        totalWT += p[idx].waiting;
        totalTAT += p[idx].turnaround;
    }

    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n";
    for (auto &x : p) {
        cout << x.name << "\t" << x.arrival << "\t" << x.burst << "\t"
             << x.waiting << "\t" << x.turnaround << "\t\t" << x.completion << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n;

    cout << "\n\nGantt Chart Order: ";
    for (auto &x : order) cout << x << " ";
    cout << endl;

    return 0;
}
