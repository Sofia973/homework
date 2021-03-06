/*
 * Jacopo Del Granchio
 * #087 20.01.2020
 *
 * Sostituzione di una stringa in modo particolare.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdarg.h>
#include <stdbool.h>

#define LENGTH 64

// Macro
#define chiedi(msg, format, ...) \
  printf(msg); \
  scanf(format, __VA_ARGS__);

// Prototipi
bool sostituisci(char a[LENGTH], int x, int y, char b[LENGTH], int w, int z);
int len(char *input);

// Funzioni
int main() {
  setlocale(LC_ALL, "");

  char a[LENGTH], b[LENGTH];
  int x, y, w, z;

  printf("Inserire la prima stringa: ");
  fflush(stdin);
  gets(a);
  printf("Inserire le coordinate della prima stringa: ");
  scanf("%d %d", &x, &y);

  printf("Inserire la seconda stringa: ");
  fflush(stdin);
  gets(b);
  printf("Inserire le coordinate della seconda stringa: ");
  scanf("%d %d", &w, &z);

  bool risultato = sostituisci(a, x, y, b, w, z);

  if (risultato) printf("Output: %s\n", a);
  else printf("La sostituzione e' fallita.");

  // getchar();
  // system("pause");
  return 0;
}

bool sostituisci(char *a, int x, int y, char *b, int w, int z) {
  if (x < 0 || y > len(a)) return false;

  if (w < 0 || z > len(b)) return false;

  if (y - x != z - w) return false;

  int i, c = 0;

  for (i = w; i <= z; i++)
    a[x + (c++)] = b[i];

  return true;
}

int len(char *input) {
  int i = 0;

  while (input[i] != '\0') i++;

  return i;
}
