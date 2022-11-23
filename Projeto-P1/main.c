#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


// Struturas

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

typedef struct Laptops
{
    int id;
    char processor[3];
    int ram;
    char state[10];
    char location[10];
    struct Date date;
} Laptop;

//Declaração de funções

void cls(void);
void flushStdin(void);
void readOption(int *num, int min, int max);
void requestLaptop(void);
void writeBinaryData(Laptop testelap[30],int numElemen);


int main()
{
    int option;

    setlocale(LC_ALL,"Portuguese");

    Laptop laptop[30];

    /*No prompt de comandos é mostrado da seguinte maneira:
     _               _____ _______ ____  _____    _____  ______ ____  _    _ ______  _____ _______
    | |        /\   |  __ \__   __/ __ \|  __ \  |  __ \|  ____/ __ \| |  | |  ____|/ ____|__   __|
    | |       /  \  | |__) | | | | |  | | |__) | | |__) | |__ | |  | | |  | | |__  | (___    | |
    | |      / /\ \ |  ___/  | | | |  | |  ___/  |  _  /|  __|| |  | | |  | |  __|  \___ \   | |
    | |____ / ____ \| |      | | | |__| | |      | | \ \| |___| |__| | |__| | |____ ____) |  | |
    |______/_/    \_\_|      |_|  \____/|_|      |_|  \_\______\___\_\\____/|______|_____/   |_|

    Criado por: André Rosa e Caio Barbosa.

    Pressione ENTER para continuar...
    */

    printf(" _               _____ _______ ____  _____    _____  ______ ____  _    _ ______  _____ _______\n");
    printf("| |        /\\   |  __ \\__   __/ __ \\|  __ \\  |  __ \\|  ____/ __ \\| |  | |  ____|/ ____|__   __|  TM\n");
    printf("| |       /  \\  | |__) | | | | |  | | |__) | | |__) | |__ | |  | | |  | | |__  | (___    | |\n");
    printf("| |      / /\\ \\ |  ___/  | | | |  | |  ___/  |  _  /|  __|| |  | | |  | |  __|  \\___ \\   | |\n");
    printf("| |____ / ____ \\| |      | | | |__| | |      | | \\ \\| |___| |__| | |__| | |____ ____) |  | |\n");
    printf("|______/_/    \\_\\_|      |_|  \\____/|_|      |_|  \\_\\______\\___\\_\\\\____/|______|_____/   |_|\n\n");
    printf("Criado por: André Rosa e Caio Barbosa.\n\n");
    printf("Pressione ENTER para continuar...");
    getchar();

    cls();

    int test, test2;
    test = 12;
    test2 =1200;

    laptop[1].id = 1;

    writeBinaryData(laptop,2);

    do
    {

        printf("                    _____ ___ ___ _ _\n");
        printf("                   |     | -_|   | | |\n");
        printf("                   |_|_|_|___|_|_|___|\n\n");
        printf("         ________________________________________\n");
        printf("        |                                        |\n");
        printf("        | Portáteis existentes: %2d               |\n",test);
        printf("        | Portáteis disponíveis: %2d              |\n",test);
        printf("        |                                        |\n");
        printf("        | Quantidade de requisições ativas: %4d |\n",test);
        printf("        | Quantidade total de requisições: %5d |\n",test2);
        printf("        |________________________________________|\n\n");

        printf("        ___________________________________________\n");
        printf("       |                                           |\n");
        printf("       | OPÇÕES:                                   |\n");
        printf("       | 1 - Requisitar um portátil                |\n");
        printf("       | 2 - Devolver um portátil                  |\n");
        printf("       | 3 - Informações dos portáteis             |\n");
        printf("       | 4 - Alterar a localização de um portátil  |\n");
        printf("       | 5 - Renovar a requisição de um portátil   |\n");
        printf("       | 6 - Relatar avaria de um portátil         |\n");
        printf("       | 7 - Sair                                  |\n");
        printf("       |___________________________________________|\n\n");


        readOption(&option,1,7);

        switch (option)
        {

        case 1:
            printf("Caso 1");
            //requestLaptop();
            break;
        case 2:
            printf("Caso 2");
            //givebackLaptop();
            break;
        case 3:
            printf("Caso 3");
            //infoLaptop();
            break;
        case 4:
            printf("Caso 4");
            //changeLocationLaptop();
            break;
        case 5:
            printf("Caso 5");
            //renewRequestLaptop();
            break;
        case 6:
            printf("Caso 6");
            //reportProblemLaptop();
            break;
        default:
            printf("Caso 7");

            break;

        }
    }
    while(option != 7);














    return 0;
}

void cls(void)
{
    int i;
    for(i=0; i<=27; i++)
    {
        printf("\n");
    };

}

void flushStdin(void)
{
    char trash;

    do
    {
        trash = getchar();
    }
    while (trash!='\n' && trash!=EOF);
}

void readOption(int *option, int min, int max)
{
    int control;
    do
    {
        printf("        Selecione uma opção (%d-%d): ",min,max);

        scanf("%d",option);
        flushStdin();

        if (*option < min || *option > max)
        {
            printf("        Valor inválido!\n");
        }

    }
    while(*option < min || *option > max);


}

void writeBinaryData(Laptop testelap[30],int numElemen) {
    FILE *teste;

    teste = fopen("teste.dat","wb");
    if (teste == NULL){
        printf("Erro ao abrir o ficheiro!");
    } else {
        fwrite(&numElemen,sizeof(int),1,teste);
        fwrite(testelap,sizeof(Laptop),30,teste);

    fclose(teste);
    }


}

//void readBinaryData() {}

//void writeTextData() {}

//void readTextData() {}
