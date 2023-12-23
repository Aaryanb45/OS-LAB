#include <stdio.h>
#include <string.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

int main() {
    int n;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;
    int selected_process = -1;

    while (completed != n) {
        int min_burst_time = 1000000;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time < min_burst_time && p[i].remaining_time > 0) {
                min_burst_time = p[i].remaining_time;
                selected_process = i;
            }
        }

        if (selected_process == -1) {
            current_time++;
            continue;
        }

        if (p[selected_process].remaining_time == p[selected_process].burst_time) {
            p[selected_process].start_time = current_time;
            p[selected_process].response_time = p[selected_process].start_time - p[selected_process].arrival_time;
        }

        p[selected_process].remaining_time--;

        if (p[selected_process].remaining_time == 0) {
            p[selected_process].completion_time = current_time + 1;
            p[selected_process].turnaround_time = p[selected_process].completion_time - p[selected_process].arrival_time;
            p[selected_process].waiting_time = p[selected_process].turnaround_time - p[selected_process].burst_time;
            total_turnaround_time += p[selected_process].turnaround_time;
            total_waiting_time += p[selected_process].waiting_time;
            total_response_time += p[selected_process].response_time;
            completed++;
        }

        current_time++;
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
    cpu_utilisation = ((float) (current_time - total_idle_time) / current_time) * 100;
    throughput = (float) n / current_time;

    printf("\n#P\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].start_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time, p[i].response_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
    printf("CPU Utilization: %.2f%%\n", cpu_utilisation);
    printf("Throughput: %.2f processes/unit time\n", throughput);

    return 0;
}
