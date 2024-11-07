#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mini_random() {
    int current = 1;
    int step = 2;
    for (int i = 0; i < 100; i++) {
        printf("%d\n", current);
        current += step;
        if (current > 100) {
            break;
        }
        if (step == 1 || step == 3) {
            step += 1;
        } else if (step == 2 || step == 4) {
            step -= 1;
        }
    }
}

int main(int argc, char const *argv[])
{
  printf("%d, ", rand()% 1000);
  srand(time(0));
  printf("%d\n", rand()% 1000);
  mini_random();
  return 0;
}
