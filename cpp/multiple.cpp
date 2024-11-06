#include <stdio.h>

int main(int argc, char const *argv[])
{
  /* code */
  int a,b;

  for (a = 0; a <= 9; a++)
  {
    for( b= 1; b <= a; b++) {
      printf("%d * %d = %d\t",a, b, a*b);
    }
    /* code */
    printf("\n");
  }
  
  return 0;
}
