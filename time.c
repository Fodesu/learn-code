#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

    time_t times;
    times = time(NULL);
    printf("time is %s", ctime(&times));

}