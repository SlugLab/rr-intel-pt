#include <random>
#include <stdio.h>

static __inline__ unsigned long long rdtsc(void) {
  unsigned hi, lo;
  __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
  return ((unsigned long long)lo) | (((unsigned long long)hi) << 32);
}

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(1, 100);
  long max = 10000000;
  auto a = new int[10000000],b= new int[10000000];
  for (int i = 0; i < 10000000; ++i) {
    a[i] = dis(gen);
    b[i] = dis(gen);
  }
  long long s = rdtsc();
  for (int i = 0; i < 10000000; i++) {
    a[i] = a[i] + b[i];
  }
  long long e = rdtsc();

  printf(":: %ld ( %ld ; %2.2lf ns )\n", e - s, (e - s) / max,
         ((e - s) / (double)max) / 4);
}
