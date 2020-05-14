#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int calcoli_figlio(int vett[], int n) {
  int somma;
  for(int i = 0; i < n / 2; i++){
    somma = somma + vett[i];
  }
  // sleep(10);
  return somma;
} 

int calcoli_padre(int vett[], int n) {
  int somma;
  for(int i = n / 2; i < n; i++) {
    somma = somma + vett[i];
  }
  return somma;
}

int calcoli_padre2(x, y) {
  int somma = x + y;
  return somma;
}

int main() {
  int N, min, max, status, pid, x, y, z;
  int correggi;

  printf("Inserisci lunghezza vettore: ");
  scanf("%d", &N);

  printf("Inserisci numero minimo da usare: ");
  scanf("%d", &min);

  printf("Inserisci numero massimo da usare: ");
  scanf("%d", &max);
  
  if(N % 2 != 0){
    N = N + 1;
    correggi = 1;
  }

  int vett[N];
  srand(time(0));
  for(int i = 0; i < N; i++) {
    vett[i] = rand() % ((max + 1) - min) + min;
  }

  if(correggi == 1) {
    vett[N - 1] = 0;
  }

  pid = fork();
  if(pid == 0) {
    x = calcoli_figlio(&vett[0], N);
    exit(x);
  }
  else {
    y = calcoli_padre(&vett[0], N);
  }

  wait(&status);
  printf("Ecco a lei \n");
  if  WIFEXITED(status) {
    x = WEXITSTATUS(status);
    z = calcoli_padre2(x, y);
    printf("%d + %d = %d\n", x, y, z);
  }
  else {
    printf("The child did NOT terminate normally: exit status of the child was %d\n", status);
  }

    printf("Vettore: ");
  for(int i = 0; i < N; i++) {
    printf("%d ", vett[i]);
  }
  return 0;
}