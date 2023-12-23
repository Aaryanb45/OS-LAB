#include <stdio.h> 

#include <stdlib.h> 

#include <pthread.h> 

#include <unistd.h> 

#define N 5 // Number of philosophers 

pthread_mutex_t chopsticks[N]; 

void *philosopher(void *arg) { 

int id = *((int *)arg); 

int right = (id + 1) % N; 

int left = id; 

while (1) { 

printf("Philosopher %d is thinking\n", id); 

sleep(1); 

pthread_mutex_lock(&chopsticks[left]); 

if (pthread_mutex_trylock(&chopsticks[right]) == 0) { 

// Philosopher has both chopsticks, can eat 

printf("Philosopher %d is eating\n", id); 

sleep(2); 

pthread_mutex_unlock(&chopsticks[right]); 

} 

pthread_mutex_unlock(&chopsticks[left]); 

} 

} 

int main() { 

pthread_t philosophers[N]; 

int ids[N]; 

for (int i = 0; i < N; i++) { 

pthread_mutex_init(&chopsticks[i], NULL); 

} 

for (int i = 0; i < N; i++) { 

ids[i] = i; 

pthread_create(&philosophers[i], NULL, philosopher, &ids[i]); 

} 

for (int i = 0; i < N; i++) { 

pthread_join(philosophers[i], NULL); 

} 

return 0;
} 