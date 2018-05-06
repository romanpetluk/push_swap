#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* инициализация базы временем и вывод первых ста чисел */
int main(void)
{
    int i, stime;
    long ltime;
    int min;
    int max;

    min = -2147483648;
    max = 2147483647;

/* получение текущего календарного времени */
    stime = time (NULL);
    //stime = (unsigned int) ltime/2;
    //srand(stime);
    printf("%d", (min + rand() % (max - min)));
}