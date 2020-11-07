#include <stdio.h>
#include <stdlib.h>
int main () {
  FILE *fp;
  fp = fopen("we_can_do_it.dat" , "r");
  if (fp == NULL) {
    perror("File  is not opening");
    return (-1);
  }
  int R, C;
  fscanf(fp, "%d %d", &R, &C);
  int i;
  int j;

  char arr[500][500];
  int r, c; char ch[5]; const char sym1 = '@';
  while (fscanf(fp, "%d %d %s", &r, &c, ch) != EOF) {
    if (ch[0] == sym1) {
      arr[r][c] = ' ';
    }
    else {
      arr[r][c] = ch[0];
    }
  }

  for (i = 0; i < R; ++i) {
    for (j = 0; j < C; ++j) {
      printf("%c", arr[i][j]);
    }
    puts("");
  }
  FILE* art;
  art = fopen("output.txt", "w"); //write the file in write mode
  for (i = 0; i < R; i++) {
    for (j = 0; j < C; j++) {
      fprintf(art, "%c ", arr[i][j]);
    }
    fprintf(art, "\n");
  }
  fclose(art);
  fclose(fp);
  return (0);
}