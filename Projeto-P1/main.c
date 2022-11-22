#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


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
    setlocale(LC_ALL,"Portuguese");

    struct Laptop laptop[30];

    printf(" _               _____ _______ ____  _____    _____  ______ ____  _    _ ______  _____ _______\n");
    printf("| |        /\   |  __ \__   __/ __ \|  __ \  |  __ \|  ____/ __ \| |  | |  ____|/ ____|__   __|\n");
    printf("| |       /  \  | |__) | | | | |  | | |__) | | |__) | |__ | |  | | |  | | |__  | (___    | |\n");
    printf("| |      / /\\ \ |  ___/  | | | |  | |  ___/  |  _  /|  __|| |  | | |  | |  __|  \___ \   | |\n");
    printf("| |____ / ____ \| |      | | | |__| | |      | | \\ \\| |___| |__| | |__| | |____ ____) |  | |\n)");
    printf("|______/_/    \\_\_|      |_|  \____/|_|      |_|  \\_\\______\___\_\\____/|______|_____/   |_|\n)");



    return 0;
}
