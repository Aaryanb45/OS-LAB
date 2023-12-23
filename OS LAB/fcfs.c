#include <stdio.h>
int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processOrder[n];
    int arrivalTime[n];
    int burstTime[n];
    int waitingTime[n];
    int turnaroundTime[n] ;
    int completionTime[n];
    int responseTime[n];
    // Input arrival times and burst times for each process
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        processOrder[i] = i + 1; // Track the original order
    }
    // Sort the processes based on arrival time (and process order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrivalTime[j] > arrivalTime[j + 1] || (arrivalTime[j] == arrivalTime[j + 1] && processOrder[j] > processOrder[j + 1])) {
                // Swap arrival times, burst times, and process order
                int tempArrival = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = tempArrival;

                int tempBurst = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = tempBurst;

                int tempProcessOrder = processOrder[j];
                processOrder[j] = processOrder[j + 1];
                processOrder[j + 1] = tempProcessOrder;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        completionTime[i] = (i == 0) ? arrivalTime[i] + burstTime[i] : completionTime[i - 1] + burstTime[i];
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        responseTime[i] = waitingTime[i];
    }

    float avgWaitingTime = 0;
    float avgTurnaroundTime = 0;
    // Calculate average waiting time and average turnaround time
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;
    // Display results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processOrder[i], arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i], responseTime[i], completionTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    return 0;
}