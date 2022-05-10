#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool isVogal(char c) {
  const char vogais[] = "aeiouAEIOU";
  for (int i = 0; vogais[i]; i++) {
    if (c == vogais[i])
      return true;
  }
  return false;
}
int contaVogais(char *s) {
  int vogais = 0;
  for (int i = 0; s[i]; i++)
    if (isVogal(s[i]))
      vogais++;
  return vogais;
}
int retiraVogaisRep_Arr(char *s) {
  int i = 0;
  for (; s[i]; i++)
    ;
  char *aux = malloc(sizeof(char) * (i + 1));
  char last = '\0';
  int j = 0;
  for (i = 0; s[i]; i++) {
    if (!isVogal(s[i])) {
      aux[j] = s[i];
      j++;
    }
    if (isVogal(s[i]) && s[i] != last) {
      last = s[i];
      aux[j] = s[i];
      j++;
    }
  }
  int ret = i - j;
  for (i = 0; aux[i]; i++) {
    s[i] = aux[i];
  }
  s[i] = '\0';
  free(aux);
  return ret;
}

int retiraVogaisRep_IP(char *s) {
  int res = 0;
  char last = '\0';
  for (int i = 0; s[i]; i++) {
    if (isVogal(s[i]) && s[i] != last) {
      last = s[i];
    } else if (isVogal(s[i]) && s[i] == last) {
      res++;
      for (int j = i; s[j]; j++) {
        s[j] = s[j + 1];
      }
      i--;
    }
  }
  return res;
}

int duplicaVogais_Arr(char *s) {
  int i;
  for (i = 0; s[i]; i++)
    ;
  char *aux = malloc(sizeof(char) * i * 2);
  int j = 0;
  for (i = 0; s[i]; i++, j++) {
    if (isVogal(s[i])) {
      aux[j] = s[i];
      aux[j + 1] = s[i];
      j++;
    } else {
      aux[j] = s[i];
    }
  }
  int ret = j - i;
  for (i = 0; aux[i]; i++) {
    s[i] = aux[i];
  }
  s[i] = '\0';
  free(aux);
  return ret;
}
void swapC(char *c1, char *c2) {
  char temp = *c1;
  *c1 = *c2;
  *c2 = temp;
}
int duplicaVogais_IP(char *s) {
  int i, n = 0;
  for (i = 0; s[i]; i++) {
    if (isVogal(s[i])) {
      char aux = s[i];
      for (int j = i + 1; s[j - 1]; j++) {
        swapC(&aux, &s[j]);
      }
      i++;
      n++;
    }
  }
  return n;
}

int main() {
  char str1[40] = ("isto e maluco");
  int i = duplicaVogais_IP(str1);
  printf("%s, %d", str1, i);
  return 0;
}