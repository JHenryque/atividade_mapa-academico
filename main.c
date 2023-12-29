/*
        Nome: Jose Henrique Ferreira
        R.A: 23236634-5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define TAM 50
typedef struct{
    char cnpj[15];
    int Qtdcnpj;
}juridica;

typedef struct
{
    char nome[50];
    char cpf[15];
    juridica opcaoCnpj[TAM];
    int tipoAtendimento;
} lista;

lista listar[TAM];

void sleepTime();
void sistemaPauseClear();
void mensagemEntrada();
void mensagemErros(char testo[]);
int retornoTipoAtendimento(int opcao);
void aberturaDeContas();
int listaUsuario(int i);
void listarRegistro();
void setorAtendimentoFiltrado();

int registro = 0;
int opcao = 0;
int op;

int main(){
    setlocale(LC_ALL, NULL); //<- NULL rodado no VScode

    do
    {
        mensagemEntrada();
        printf("\t| Informe o numero do atendimento! |\n");
        printf("\t************************************\n");
        printf("\n\t1 - Solicitar Atendimento\n\t2 - Listar Atendimentos Registrados \n\t3 - Listar Atendimento por Setor\n\t4 - Sair\n");
        printf("\t");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            aberturaDeContas();
            break;
        case 2:
            listarRegistro();
            break;
        case 3:
            setorAtendimentoFiltrado();
            break;
        case 4:
            system("cls");
            puts("\n\n\tFinalizado o atendimento Obrigado.. :{)\n\n");
            break;
        default:
            system("cls");
            mensagemErros("\t\tOpcao invalida!\t\t\t");
            sistemaPauseClear();
            break;
        }
    } while (opcao != 4);
    return 0;
}

void aberturaDeContas(){
    system("cls");
    printf("\t| Abertura de Conta |\n");
    puts("\t+-------------------+\n");
    int validarCPF, validarCNPJ;

    if (registro < TAM) {
        fflush(stdin);
        printf("Digite seu nome completo: \n");
        fgets(listar[registro].nome, sizeof(listar[registro].nome), stdin);
        listar[registro].nome[strcspn(listar[registro].nome, "\n")] = '\0';
        
        printf("Voce tem CNPJ?\n1 - Sim 2 - nao\nDigite: ");
        fflush(stdin);
        scanf("%d", &op);
        do{ 
            if (op == 1){
                fflush(stdin);
                printf("Digite seu CNPJ: \n");
                scanf("%49[^\n]s\n", listar->opcaoCnpj[registro].cnpj);
                listar->opcaoCnpj[registro].Qtdcnpj += 1;
                validarCNPJ = strlen(listar->opcaoCnpj[registro].cnpj);
                if (validarCNPJ == 14) {
                    break;
                } else {
                    printf("CNPJ Invalido Tente novamente...\n");
                }
            } else {
                fflush(stdin);
                printf("Digite seu CPF: \n");
                fgets(listar[registro].cpf, sizeof(listar[registro].cpf), stdin);
                listar[registro].cpf[strcspn(listar[registro].cpf, "\n")] = '\0'; 
                validarCPF = strlen(listar[registro].cpf);
                if (validarCPF == 11) {
                    break;
                } else {
                    printf("\n\tCPF Invalido Tente novamente...\n\n");
                    system("pause");
                }
            }
        } while (1);
        system("cls");

        while (1){            
            printf("\t| Informe o numero do atendimento |\n");
            puts("\t+---------------------------------+");
            printf("\t1 - Abertura de Conta\n\t2 - Caixa\n\t3 - Gerente Pessoa Fisica\n\t4 - Gerente Pessoa Juridica\n");
            printf("\t");
            fflush(stdin);
            scanf("%d", &listar[registro].tipoAtendimento);
            if (listar[registro].tipoAtendimento != 1 && listar[registro].tipoAtendimento != 2 && listar[registro].tipoAtendimento != 3 && listar[registro].tipoAtendimento != 4) {
                system("cls");
                mensagemErros("\tOpcao Invalida tente de novo...\t\t");
                sistemaPauseClear();
            } else {
                break;;
            } 
        }
        
        registro++;
        sleepTime();
        mensagemErros("\t\tCadatrado Com Sucesso...\t");
        sistemaPauseClear();
    } else {
        mensagemErros("O limente de cadastramento ja foi preenchiodo...");
        sistemaPauseClear();
    }
}

int listaUsuario(int i){
    printf("Nome: %s\n", listar[i].nome);
    listar->opcaoCnpj[i].Qtdcnpj ? printf("CNPJ: %s\n", listar->opcaoCnpj[i].cnpj) : printf("CPF: %s\n", listar[i].cpf);
    printf("Tipo Atendimento - %d - ", listar[i].tipoAtendimento);
    retornoTipoAtendimento(listar[i].tipoAtendimento);
    printf("\n=======================================================\n");
    return i;
}

void listarRegistro(){
    system("cls");
    if (registro == 0) {
        system("cls");
        mensagemErros("\t Ainda nao foram registrados...\t\t");
        sistemaPauseClear();
    }else {
        for (int i = 0; i < registro; i++) {
            listaUsuario(i);
        }
        sistemaPauseClear();
    }
}

void setorAtendimentoFiltrado(){
    system("cls");
    int buscar = 0, contaFiltrado = 0;
    do{
    puts("\tBuscar Setor Filtrados");
    printf("1 - Abertura de Conta\n2 - Caixa\n3 - Gerente Pessoa Fisica\n4 - Gerente Pessoa Juridica\n5 - Voltar\n");
    scanf("%d", &buscar);
    fflush(stdin);

    system("cls");
    for (int i = 0; i < registro; i++){
        if (buscar == listar[i].tipoAtendimento){
                listaUsuario(i);
                contaFiltrado++;           
        } 
    }

    if (buscar == 5) {
        break;
    } else if(contaFiltrado == 0){
       mensagemErros("\t Sua Busca nao foi Encontrada. . .\t");
    } else {
        buscar = 5;
    }
    sistemaPauseClear();
    }while(buscar != 5);
}

int retornoTipoAtendimento(int i){
        switch (i){
        case 1:
            printf("Abertura de conta");
            break;
        case 2:
            printf("Caixa");
            break;
        case 3:
            printf("Gerente Pessoa Fisica");
            break;
        case 4:
            printf("Gerente Pessoa Juridica");
            break;  
        default:
            break;
        }
    return i;
}

void mensagemEntrada() {
    printf("**************************************************\n");
    printf("|                                                |\n");
    printf("*--BEM-VINDO-AO-SISTEMA-DE-ATENDIMENTO-DO-BANCO--*\n");
    printf("|                                                |\n");
      puts("**************************************************");
}


void mensagemErros(char testo[]){
    printf("**************************************************\n");
    printf("* %s *\n", testo);
    puts("**************************************************\n");
}

void sleepTime() {
    system("cls");
    printf("*****************************************\n");
    printf("*\tAguarde uns minutos!\t\t*\n");
     for (int i = 0; i < 41; i++) {
          Sleep(100);
          printf("*");
     }
     printf("\n");
     system("cls");
}

void sistemaPauseClear() {
    system("pause");
    system("cls");
}