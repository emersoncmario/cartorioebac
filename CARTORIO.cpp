#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h>
#include <windows.h> // necessário para acentos no Windows

int registro()
{
    // Configuração para acentos no Windows
    setlocale(LC_ALL, "Portuguese");
    
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("\n\tInforme os dados a serem cadastrados: \n");
    printf("\tCPF: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);
    
    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, "CPF: %s\n", cpf);
    fclose(file);
           
    printf("\tNOME: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "NOME: %s\n", nome);
    fclose(file);
    
    printf("\tSOBRENOME: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "SOBRENOME: %s\n", sobrenome);
    fclose(file);
    
    printf("\tCARGO: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, "CARGO: %s\n", cargo);
    fclose(file);
    
    printf("\t\nDADOS CADASTRADOS COM SUCESSO\n\n");
    system("pause");
}

int consulta()
{
    // Configuração para acentos no Windows
    
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    char conteudo[200];
    
    printf("\n\tDigite o CPF a ser consultado: ");
    scanf("%s", cpf);
    printf("\n");
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
        printf("\t*** Usuário não localizado ***\n");
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\t%s", conteudo);
    }
    
    system("pause");
}

int excluir()
{
    // Configuração para acentos no Windows
    
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
        
    printf("\tDigite o CPF do usuário que deseja excluir:\t");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
        printf("\n\t*** Usuário não encontrado ***\n");
        system("pause");
    }
    else
    {
        fclose(file);
        remove(cpf);
        printf("\n\t*** Usuário excluído com sucesso ***\n");
        system("pause");
    }
}

int main()
{
    // Configuração para acentos no Windows
    
    setlocale (LC_ALL, "Portuguese");
    
    int opcao = 0;
    int laco = 1;
    
    for(laco = 1; (laco = 1);)
    {
        system("cls");
        
        printf("\t### Lista de alunos da EBAC ###\n\n");
        printf("\tInforme o número desejado do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Excluir nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("\tOpção:");
        
        scanf("%d", &opcao);
        
        system("cls");
        
        switch(opcao)
        {
            case 1:
                registro();
                break;
                
            case 2:
                consulta();
                break;
                
            case 3:
                excluir();
                break;
                
            case 4:
                printf("\tObrigado por utilizar o sistema\n");
                return 0;
                break;
                
            default:
                printf("\n\tOpção inválida\n\n");
                system("pause");
                break;
                
        }

    }
}
