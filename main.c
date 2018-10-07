#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/* Arthur Gramiscelli Branco
   Rajha Fajardo de Alencar Marçal
   Felipe Carvalho de Melo

   Engenharia de Software/manhã - 1º Período/2ºsemestre/2018 */

int cbd(){
    int n,i=0,erro=0,soma=0;
    printf("\n Insira o número na base 2 a ser convertido para base 10: ");
    scanf("%d", &n);
    //Separando a parte inteira de decimal nas duas linhas abaixo
    while(n!=0){
        soma=soma+(n%10)*pow(2,i); //Usamos a função resto para "quebrar" o número inserido e prosseguir com o cálculo com cada número//
        if(((n%10)!=1)&&((n%10)!=0)&&((n%10)!=-1)){
            erro = 1;
            n = 0;
        }
        n=n/10;
        i++;
    }

    if(erro==1){
        printf("\n Erro! Número inválido!\n");
    }else{
        printf("\n O equivalente em decimal é: %d\n", soma);
    }
    return 0;
}

int cdb(){
    int n,r[255];
    float vDN;
    int i=0;
    printf("\n Insira o número na base 10 a ser convertido para base 2: ");
    scanf("%f", &vDN);
    //Separando a parte inteira de decimal nas duas linhas abaixo
    n=vDN;
    vDN=vDN-n;
    //Tratamento da parte inteira:
    while(n>1){
        r[i]=n%2;
        n=n/2;
        i++;
    }
    r[i]=n%2;
    printf("\n O equivalente em binário é: " );
    for(i=i;i>=0;i--){
        printf("%d",r[i]);
    }
    printf(","); //Separar o inteiro da parte decimal

    //Tratamento da parte decimal:

    while(i<4){ //Esse i vai ajudar a pegar 5 casa de precisão imprimindo 5 vezes até o while sair
        if(vDN<1.0){
            printf("0");
            vDN=vDN*2;
            i++;
        }
        if(vDN>=1.0){
            printf("1");
            vDN--;
            vDN=vDN*2;
            i++;
        }
    }
    return 0;
}

int chd(){
    int i=0,j=0,erro=0,soma=0,aux[255];
    char hex[255];
    printf("\n Insira o número na base 16 a ser convertido para base 10: ");
    fflush (stdin); //Linha pra desbugar o fgets (ele não pede entrada pro usuário caso não tenha isso)
    fgets(hex, 255, stdin);
    //Tratamento da parte inteira:
    while (hex[i] != '\n'){
        switch (hex[i]){
            case '0':
                aux[i]=0;
                break;
            case '1':
                aux[i]=1;
                break;
            case '2':
                aux[i]=2;
                break;
            case '3':
                aux[i]=3;
                break;
            case '4':
                aux[i]=4;
                break;
            case '5':
                aux[i]=5;
                break;
            case '6':
                aux[i]=6;
                break;
            case '7':
                aux[i]=7;
                break;
            case '8':
                aux[i]=8;
                break;
            case '9':
                aux[i]=9;
                break;
            case 'a':
            case 'A':
                aux[i]=10;
                break;
            case 'b':
            case 'B':
                aux[i]=11;
                break;
            case 'c':
            case 'C':
                aux[i]=12;
                break;
            case 'd':
            case 'D':
                aux[i]=13;
                break;
            case 'e':
            case 'E':
                aux[i]=14;
                break;
            case 'f':
            case 'F':
                aux[i]=15;
                break;
            default:
                printf("\n Erro! Algo inserido é inválido!\n");
                erro=1; //Vai ser usado abaixo para decidir se vai ser impresso as contas feitas em um if
            }
        i++;
    }
    i--;
    for(i=i;i>=0;i--){
        soma=soma+pow(16,i)*aux[j];
        j++;
    }
    if(erro!=1){
        printf("\n O equivalente em decimal é: %d\n", soma);
    }
    return 0;
}

int cdh(){
    int n,r[255];
    float vDN;
    int i=0;
    printf("\n Insira o número na base 10 a ser convertido para base 16: ");
    scanf("%f", &vDN);
    //Separando a parte inteira de decimal nas duas linhas abaixo
    n=vDN;
    vDN=vDN-n;
    //Tratamento da parte inteira:
    while(n>15){
        r[i]=n%16;
        n=n/16;
        i++;
    }
    r[i]=n%16;
    printf("\n O equivalente em hexadecimal é: ");
    for(i=i;i>=0;i--){
        switch (r[i]){
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d",r[i]);
        }
    }
    printf(","); //Separar o inteiro da parte decimal

    //Tratamento da parte decimal:

    while(i<4){
            //multiplicando a parte decimal por 16 e depois separando ela da parte inteira
            vDN=vDN*16;
            n=vDN;
            vDN=vDN-n;
            i++; //esse i vai ajudar a pegar 5 casa de precisão imprimindo 5 vezes até o while sair
            switch (n){
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d",n);
            }
    }
    return 0;
}

int menu(){
    //Nosso lindo menu
    int n;
    printf("\n---------Escolha uma operação----------\n");
    printf("---------------------------------------\n");
    printf("\n 1. Cálculo de binário para decimal");
    printf("\n 2. Cálculo de decimal para binário");
    printf("\n 3. Cálculo de hexadecimal para decimal");
    printf("\n 4. Cálculo de decimal para hexadecimal \n");
    printf("\n---------------------------------------\n");
    printf("\n\n Insira o número da operação que deseja: ");
    scanf("%d",&n);
    system("cls");

    switch(n){
        case 1:
            cbd();
            break;
        case 2:
            cdb();
            break;
        case 3:
            chd();
            break;
        case 4:
            cdh();
            break;
        //Erro no default, caso alguém digite fora de 1 até 4
        default:
            printf("---------------------------------------\n");
            printf("Insira um número válido!\n");
            printf("---------------------------------------\n\n");
            system("pause");
            system("cls");
            menu();
    }
    return 0;
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int n=0;
    menu();
    //Repetição do menu dentro do main a seguir:
    while(n!=2){
        printf("\n\n\n Deseja executar outro programa?");
        printf("\n---------------------------------------\n");
        printf("\n1.Sim");
        printf("\n2.Nao\n");
        printf("\nResposta: ");
        scanf("%d",&n);
        system("cls");
        if(n==1){
            menu(); //Disparo da repetição caso o usuário selecione 1
        }else{
            printf("---------------------------------------\n");
            printf("Fim do programa."); //Saída do programa (return 0)
            printf("\n---------------------------------------\n");
            return 0;
        }
    }
}
