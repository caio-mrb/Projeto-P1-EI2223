#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Date {
    int day;
    int month;
    int year;

};

struct Laptop {
    int id;
    char processor[3];
    int ram;
    char state[10];
    char location[10];
    struct Date date;

    };

int main()
{

    struct Laptop laptop[30];
    laptop[30].date.day = 1;

    printf("%d",laptop[30].date.day);

    return 0;
}
