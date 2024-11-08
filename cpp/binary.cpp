#include <stdio.h>

int num_to_bin(int num) {
  int count = 0;
  while (num != 0) {
    if(num % 2 == 1) count += 1;
    num /= 2;
  }
  return count;
}

int main(int argc, char const *argv[])
{
  printf("包含 1 的个数：%d", num_to_bin(100));
  return 0;
}
