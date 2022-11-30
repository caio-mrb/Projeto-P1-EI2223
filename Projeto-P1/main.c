#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

//Constantes
#define MAX_LAPTOPS 30
#define MAX_REQUESTS 9999

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
    char processor[20];
    int ram;
    float price;
    char location[10];
    char state[20];
    struct Date date;
} Laptop;

typedef struct Requests
{
    char code[10];
    char name[50];
    char type[30];
    char state[10];
    char renewLocation[10];
    int requestPeriod;
    int delayFee;
    //struct Laptop laptop;
    struct Date requestDate;
    struct Date renewDate;

} Request;

//Declaração de funções

void cls(void);
void flushStdin(void);
void readOption(int *option,int zeroToCancel,char message[50], int min, int max);
void generateLaptops(Laptop laptop[MAX_LAPTOPS]);
void mainMenu(Laptop laptop[MAX_LAPTOPS],Request request[MAX_REQUESTS]);
void exitMenu(int *option);
void requestLaptop(Laptop laptop[MAX_LAPTOPS],Request request[MAX_REQUESTS]);
void writeLaptopsData(Laptop testelap[MAX_LAPTOPS]);
void readLaptopsData(Laptop laptop[MAX_LAPTOPS]);
void requestByID(Laptop laptop[MAX_LAPTOPS], Request request[MAX_REQUESTS]);
void confirmRequest(Laptop laptop[MAX_LAPTOPS],Request request[MAX_REQUESTS], int index);
void alignSpaceForString(Laptop laptop[MAX_LAPTOPS],int index,int margin);
void requestForm(Laptop laptop[MAX_LAPTOPS],Request request[MAX_REQUESTS],int index);




int main()
{
    int option;

    int test, test2;

    FILE *checker;

    setlocale(LC_ALL,"Portuguese");

    Laptop laptop[MAX_LAPTOPS];

    Request request[MAX_REQUESTS];

    checker = fopen("laptops.dat", "rb");

    if (checker == NULL)
    {
        printf(" _________________________\n");
        printf("|                         |\n");
        printf("|  Bem-Vindo ao Programa! |\n");
        printf("|_________________________|\n\n");
        generateLaptops(laptop);
        writeLaptopsData(laptop);
    }
    else
    {
        printf(" __________________________________\n");
        printf("|                                  |\n");
        printf("|  Bem-Vindo de Volta ao Programa! |\n");
        printf("|  Todos os dados foram carregados |\n");
        printf("|  com sucesso!                    |\n");
        printf("|__________________________________|\n\n");
        readLaptopsData(laptop);
        fclose(checker);
    };


    //Zona de Teste



    //generateLaptops(laptop);
    for (option=0; option<MAX_LAPTOPS; option++)
    {
        printf("ID#%d\n",laptop[option].id);
        printf("%s\n",laptop[option].processor);
        printf("%d GB\n",laptop[option].ram);
        printf("%.2f $EUR\n\n",laptop[option].price);

    }



    //Fim Zona de Teste

    printf(" _               _____ _______ ____  _____    _____  ______ ____  _    _ ______  _____ _______\n");
    printf("| |        /\\   |  __ \\__   __/ __ \\|  __ \\  |  __ \\|  ____/ __ \\| |  | |  ____|/ ____|__   __|  TM\n");
    printf("| |       /  \\  | |__) | | | | |  | | |__) | | |__) | |__ | |  | | |  | | |__  | (___    | |\n");
    printf("| |      / /\\ \\ |  ___/  | | | |  | |  ___/  |  _  /|  __|| |  | | |  | |  __|  \\___ \\   | |\n");
    printf("| |____ / ____ \\| |      | | | |__| | |      | | \\ \\| |___| |__| | |__| | |____ ____) |  | |\n");
    printf("|______/_/    \\_\\_|      |_|  \\____/|_|      |_|  \\_\\______\\___\\_\\\\____/|______|_____/   |_|\n\n");
    printf("Criado por: André Rosa e Caio Barbosa.\n\n");
    printf("Pressione ENTER para continuar...");

    if (getchar() != '\n')
    {
        flushStdin();
    }




    test = 12;
    test2 =1200;

    mainMenu(laptop,request);



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

void readOption(int *option,int zeroToCancel,char message[50], int min, int max)
{
    int control;

    if (zeroToCancel == 0)
    {

        do
        {
            printf("        %s (%d-%d): ",message,min,max);

            control = scanf("%d",option);
            flushStdin();

            if (*option < min || *option > max || control == 0)
            {
                printf("        Valor inválido!\n");
            }

        }
        while(*option < min || *option > max || control == 0);

    }
    if (zeroToCancel == 1)
    {
        do
        {
            printf("        %s (%d-%d): ",message,min,max);

            control = scanf("%d",option);
            flushStdin();

            if ((*option < min || *option > max || control == 0) && *option != 0)
            {
                printf("        Valor inválido!\n");
            }

        }
        while((*option < min || *option > max || control == 0) && *option != 0);


    }

}

void writeLaptopsData(Laptop laptop[MAX_LAPTOPS])
{
    FILE *data;

    data = fopen("laptops.dat","wb");
    if (data == NULL)
    {
        printf("Erro ao abrir o ficheiro!");
    }
    else
    {
        //fwrite(&numElemen,sizeof(int),2,data);
        fwrite(laptop,sizeof(Laptop),MAX_LAPTOPS,data);
        fclose(data);
    }


}

void readLaptopsData(Laptop laptop[MAX_LAPTOPS])
{
    FILE *data;

    data=fopen("laptops.dat","rb");
    if (data == NULL)
    {
        printf ("Erro abrir ficheiro");
    }
    else
    {
        //fread(numElemen,sizeof(int),2,data);
        fread(laptop,sizeof(Laptop),MAX_LAPTOPS, data);
        fclose(data);
    }

}

void mainMenu(Laptop laptop[MAX_LAPTOPS],Request request[MAX_REQUESTS]){

    int option;

    do
    {
        cls();

        printf("                    _____ ___ ___ _ _\n");
        printf("                   |     | -_|   | | |\n");
        printf("                   |_|_|_|___|_|_|___|\n\n");
        printf("         ________________________________________\n");
        printf("        |                                        |\n");
        printf("        | Portáteis existentes: %2d               |\n",MAX_LAPTOPS);
        printf("        | Portáteis disponíveis: %2d              |\n",20);
        printf("        |                                        |\n");
        printf("        | Quantidade de requisições ativas: %4d |\n",20);
        printf("        | Quantidade total de requisições: %5d |\n",20);
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

        char text[50] = "Selecione uma opção";

        readOption(&option,0,text,1,7);

        switch (option)
        {

        case 1:
            printf("Caso 1\n");
            requestLaptop(laptop,request);
            break;
        case 2:
            printf("Caso 2\n");
            //givebackLaptop();
            break;
        case 3:
            printf("Caso 3\n");
            //infoLaptop();
            break;
        case 4:
            printf("Caso 4\n");
            //changeLocationLaptop();
            break;
        case 5:
            printf("Caso 5\n");
            //renewRequestLaptop();
            break;
        case 6:
            printf("Caso 6\n");
            //reportProblemLaptop();
            break;
        default:
            printf("Caso 7\n");
            exitMenu(&option);
        }
    }
    while(option != 7);

}

void exitMenu(int *option)
{
    cls();

    printf("         _______________________________\n");
    printf("        |_SAIR______________________(X)_|\n");
    printf("        |                               |\n");
    printf("        | Tem certeza que deseja sair?  |\n");
    printf("        | 1 - Não                       |\n");
    printf("        | 2 - Sim                       |\n");
    printf("        |_______________________________|\n\n");

    char text[50] = "Selecione uma opção";

    readOption(option,0,text,1,2);

    if (*option == 2)
    {
        *option = 7;
    };
}



void generateLaptops(Laptop laptop[MAX_LAPTOPS])
{
    int i, c, equal, r;
    srand(time(0));

    for(i=0; i<MAX_LAPTOPS; i++)
    {

        do
        {
            equal = 0;
            r = rand() % 9 + 1;
            r += (rand() % 9 + 1) * 10;
            r += (rand() % 9 + 1) * 100;
            r += (rand() % 9 + 1) * 1000;
            for(c=0; c<=i; c++)
            {
                if (r == laptop[c].id)
                {
                    printf("%d\n",r);
                    printf("%d\n",c);
                    printf("%d\n\n",laptop[c].id);
                    equal += 1;
                }
            }
        }
        while (equal != 0);
        laptop[i].id = r;

        laptop[i].price = 250.0;
        strcpy(laptop[i].location,"Biblioteca");
        strcpy(laptop[i].state,"Disponível");
        r = rand() % 10 + 1;
        switch (r)
        {
        case 1:
            strcpy(laptop[i].processor,"Intel Celeron");
            laptop[i].price += 56.90;
            break;
        case 2:
            strcpy(laptop[i].processor,"Intel Pentium");
            laptop[i].price += 84.90;
            break;
        case 3:
            strcpy(laptop[i].processor,"Intel Core i3");
            laptop[i].price += 122.40;
            break;
        case 4:
            strcpy(laptop[i].processor,"Intel Core i5");
            laptop[i].price += 156.45;
            break;
        case 5:
            strcpy(laptop[i].processor,"Intel Core i7");
            laptop[i].price += 291.90;
            break;
        case 6:
            strcpy(laptop[i].processor,"Intel Core i9");
            laptop[i].price += 680.05;
            break;
        case 7:
            strcpy(laptop[i].processor,"AMD Ryzen 3");
            laptop[i].price += 91.48;
            break;
        case 8:
            strcpy(laptop[i].processor,"AMD Ryzen 5");
            laptop[i].price += 141.90;
            break;
        case 9:
            strcpy(laptop[i].processor,"AMD Ryzen 7");
            laptop[i].price += 239.90;
            break;
        case 10:
            strcpy(laptop[i].processor,"AMD Ryzen 9");
            laptop[i].price += 709.89;
            break;
        };
        r = rand() % 6 + 1;
        switch (r)
        {
        case 1:
            laptop[i].ram = 2;
            laptop[i].price += 7.38;
            break;
        case 2:
            laptop[i].ram = 4;
            laptop[i].price += 14.76;
            break;
        case 3:
            laptop[i].ram = 8;
            laptop[i].price += 35.04;
            break;
        case 4:
            laptop[i].ram = 16;
            laptop[i].price += 73.80;
            break;
        case 5:
            laptop[i].ram = 32;
            laptop[i].price += 130.00;
            break;
        case 6:
            laptop[i].ram = 64;
            laptop[i].price += 221.60;
            break;
        }




    };


}

void requestLaptop(Laptop laptop[MAX_LAPTOPS],Request request[MAX_REQUESTS])
{
    int option;

    do {
    cls();

    printf("         _______________________________\n");
    printf("        |_REQUISITAR________________(X)_|\n");
    printf("        |                               |\n");
    printf("        | Procurar portátil disponível  |\n");
    printf("        | através do(a):                |\n");
    printf("        | 1 - Número de Identificação   |\n");
    printf("        | 2 - Processador               |\n");
    printf("        | 3 - RAM                       |\n");
    printf("        | 4 - Voltar                    |\n");
    printf("        |_______________________________|\n\n");

    char text[50] = "Selecione uma opção";

    readOption(&option,0,text,1,4);

    switch (option)
    {
    case 1:
        requestByID(laptop,request);
        break;
    case 2:
        //requestByProcessor()
        break;
    case 3:
        //requestByRAM()
        break;
    }

    }while(option != 4);
    mainMenu(laptop,request);

}

void requestByID(Laptop laptop[MAX_LAPTOPS], Request request[MAX_REQUESTS])
{
    int option, i, b;
    do {
    i = 0;
    b = 0;

    printf("         ____________________________________\n");
    printf("        |_REQUISITAR_____________________(X)_|\n");
    printf("        |                                    |\n");
    printf("        | Digite o número de identificação   |\n");
    printf("        | do portátil que deseja requisitar. |\n");
    printf("        | Este número é único e pode estar   |\n");
    printf("        | entre 1111 e 9999 inclusive.       |\n");
    printf("        |                                    |\n");
    printf("        | Ou digite 0 para cancelar.         |\n");
    printf("        |____________________________________|\n\n");

    char text[50] = "Digite o número de identificação";

    readOption(&option,1,text,1111,9999);

    //strcpy(laptop[6].state,"Indisponível");

    do{
        if ((laptop[i].id == option) && ((strcmp(laptop[i].state,"Disponível")) == 0))  {
            confirmRequest(laptop,request,i);
            b = 1;
        }
        if ((laptop[i].id == option) && ((strcmp(laptop[i].state,"Disponível")) != 0))  {
            printf("O portátil ID#%d está indisponível\n",laptop[i].id);
            b = 1;
        }
        if ((laptop[i].id != option)) {
            i++;
            //printf("%d\n",i);
        }
    }while(b!=1 && i<MAX_LAPTOPS);
     //ou <30
    if (i==MAX_LAPTOPS){
        printf("        Não existe um portátil com este ID\n");
    }

    }while(option != 0);
    requestLaptop(laptop,request);
}

void confirmRequest(Laptop laptop[MAX_LAPTOPS],Request request[MAX_REQUESTS], int index){

    int option;

    printf("         ____________________________________\n");
    printf("        |_REQUISITAR_____________________(X)_|\n");
    printf("        |                                    |\n");
    printf("        | O laptop ID#%d está disponível.  |\n",laptop[index].id);
    printf("        |                                    |\n");
    printf("        | ~~ESPECIFICAÇÕES~~                 |\n");
    printf("        | Processador: %s",laptop[index].processor);
    alignSpaceForString(laptop,index,22);
    printf("        | RAM: %2d GB                         |\n",laptop[index].ram);
    printf("        |                                    |\n");
    printf("        | Deseja mesmo requisitar?           |\n");
    printf("        | 1 - Não                            |\n");
    printf("        | 2 - Sim                            |\n");
    printf("        |____________________________________|\n\n");

    char text[50] = "Selecione uma opção";

    readOption(&option,0,text,1,2);

    if (option == 1) {
        requestByID(laptop,request);
    }
    if (option == 2) {
        requestForm(laptop,request,index);
    }


}

void alignSpaceForString(Laptop laptop[MAX_LAPTOPS],int index,int margin){

    int i;
    for(i=0;i<(int)(margin-strlen(laptop[index].processor));i++){
        printf(" ");
    }
    printf("|\n");


}

void requestForm(Laptop laptop[MAX_LAPTOPS],Request request[MAX_REQUESTS],int index){

    char name[25], surname[25];
    int i;

    printf("         ______________________________________\n");
    printf("        |_FORMULÁRIO_DE_REQUISIÇÃO_________(X)_|\n");
    printf("        |                                      |\n");
    printf("        | Preencha os campos conforme pedido.  |\n");
    printf("        | Para retornar ao campo anterior      |\n");
    printf("        | digite 0.                            |\n");
    printf("        |______________________________________|\n\n");
    printf("         Nome: ");
    fgets(name, 25,stdin);
    //printf("%c",request[1].name[2]);
    if (name[0]=='0'){
        cls();
        confirmRequest(laptop,request,index);

    }
    printf("         Apelido: ");
    fgets(surname, sizeof(surname),stdin);

    if (strcmp(surname,"0")==0){
        printf("%s",surname);
        requestForm(laptop,request,index);
    }

}

//void writeRequestsData() {}  em txt

//void readRequestsData() {}   em txt
