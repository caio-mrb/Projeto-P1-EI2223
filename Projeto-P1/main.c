#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct date {
    int day;
    int month;
    int year;

};

struct laptop {
    int id;
    char processor[3];
    int ram;
    char state[10];
    char location[10];
    struct date date;

    };

int main()
{

    struct laptop laptop;
    struct date date;
    laptop.date.day = 1;

    printf("%d",laptop.date.day);

    return 0;
}
