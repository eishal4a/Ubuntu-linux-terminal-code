include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

struct Process {

string id;

int burst, priority, waiting, turnaround;

};

void priority_scheduling(vector<Process> &processes) {

int n = processes.size();

int current_time = 0;

sort(processes.begin(), processes.end(), [](Process a, Process b) {

return a.priority < b.priority;

});

for (int i = 0; i < n; i++) {

current_time += processes[i].burst;

processes[i].turnaround = current_time;

processes[i].waiting = processes[i].turnaround - processes[i].burst;

}

float avg_waiting = 0, avg_turnaround = 0;

for (auto &p: processes) {

avg_waiting += p.waiting;

avg_turnaround += p.turnaround;

}

avg_waiting /= n;

avg_turnaround /= n;

cout << "Priority Scheduling Results:\n";

for (auto &p: processes) {

cout << p.id << ": Waiting = " << p.waiting << ", Turnaround = " <<

p.turnaround << endl;

cout << "Average Waiting Time: " << avg_waiting << endl;

}

cout << "Average Turnaround Time: " << avg_turnaround << endl;

}

int main() {

vector<Process> processes = {{"P1", 6, 2}, {"P2", 8, 1}, {"P3", 7, 3}};

priority_scheduling(processes);

return 0;

}