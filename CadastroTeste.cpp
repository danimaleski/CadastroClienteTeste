#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#define SIZE 200
#define EXIT_SUCESS 0

typedef struct enderecoCliente{
	char rua[SIZE];
	char bairro[SIZE];
	char cidade[SIZE];
	char estado[SIZE];
	char numero[SIZE];
	char cep[SIZE];
}Endereco;

typedef struct cadastroCliente{
	char nome[SIZE];
	char telefone[SIZE];
	char email[SIZE];
	char CPF[SIZE];
	Endereco end;
}Cliente;

int input=0, qtdClientes, tamClientes;
Cliente *clientes;


int InserirCliente();
void AlterarCadastro();
int ExcluirCadastro(int qtd);
Cliente *PesquisarCadastro();
Cliente receberCliente();
Endereco receberEndereco();

int main(void){
	setlocale (LC_ALL, "Portuguese");
	
	do{
		printf("\n");
		printf("\t\t Cadastro \t\t\n");
		printf("\t\t 1.Novo Cadastro \t\t\\n");
		printf("\t\t 2.Alterar Cadastro \t\t\n");
		printf("\t\t 3.Excluir Cadastro \t\t\n");
		printf("\t\t 4.Pesquisas Cadastro \t\t\n");
		printf("\t\t 5.Sair \t\t\n");
		printf("\n\n");
		printf("Por favor, selecione uma opção");
		scanf("%d", &input);
		switch(input){
		case 1:
			InserirCliente(Cliente);
			break;
		case 2:
			AlterarCadastro();
			break;
		case 3:
			ExcluirCadastro(qtdClientes);
			break;
		case 4:
			PesquisarCadastro();
			break;
		case 5:
			exit(EXIT_SUCESS);
		default:
			printf("\tOpção inválida\n");
		}
	}
	while(input !=0);
	system("cls");
}

void receberString(char *string_destino, int quantidade_caracteres){
	fgets(string_destino, quantidade_caracteres, stdin);
}

Cliente receberCliente(){
	Cliente c;
	
	printf("Nome: \n");
	receberString(c.nome, 199);
	printf("CPF: \n");
	receberString(c.CPF, 199);
	fflush(stdin);
	printf("Email: \n");
	receberString(c.email, 199);
	printf("Telefone: \n");
	receberString(c.telefone, 199);
	
	c.end=receberEndereco();
	
	return c;
}

Endereco receberEndereco(){
	Endereco e;
	
	printf ("Rua: \n");
    receberString(e.rua, 199);
    fflush(stdin);
    printf ("Numero: ");
    receberString(e.numero, 199);
    fflush(stdin);
    printf ("CEP: \n");
    receberString(e.cep, 199);
    fflush(stdin);
    printf ("Bairro: \n");
    receberString(e.bairro, 199);
    printf ("Cidade: \n");
    receberString(e.cidade, 199);
    printf ("Estado: \n");
    receberString(e.estado, 199);
    
    return e;	
	
}

int InserirCliente(Cliente c){
	if(qtdClientes==tamClientes){
		tamClientes *=1.5;
		clientes = (Cliente*) realloc(clientes, tamClientes *sizeof(Cliente));
	}
	clientes[qtdClientes]=c;
	qtdClientes++;
}

void AlterarCadastro(){
	
    int i;
    char cpf[11], nome[40];
    printf ("Digite o CPF do cliente a os dados alterados: ");
    fgets(cpf, 11, stdin);
    printf ("Digite o novo nome: ");
    fgets(nome, 39, stdin);
    for (i=0; i < qtdClientes; i++)
    {
        if(strcmp(clientes[i].CPF, cpf) == 0)
        {
            strcpy(clientes[i].nome, nome);
            break;
        }
    }
    
    char fone[11];
	printf ("Digite o novo telefone: ");
    fgets(fone, 11, stdin);
    for (i=0; i < qtdClientes; i++)
    {
        if(strcmp(clientes[i].CPF, cpf) == 0)
        {
            strcpy(clientes[i].telefone, fone);
            break;
        }
    }
    
    Endereco e;
    e = receberEndereco();
    for (i=0; i < qtdClientes; i++)
    {
        if(strcmp(clientes[i].CPF, cpf) == 0)
        {
            clientes[i].end = e;
            break;
        }
    }
       
}

Cliente *PesquisarCadastro(){

    Cliente *c = NULL;
    int i;
    char cpf[12];
    printf ("Digite o CPF do cliente a ser pesquisado: ");
    fgets(cpf, 11, stdin);
    for (i=0; i < qtdClientes; i++)
    {
        if(strcmp(clientes[i].CPF, cpf) == 0)
        {
            c = &clientes[i];    
            break;
        }
    }
    return c;
}

int ExcluirCadastro(int qtd){
	
	int i, CPF, sucess = 0;
	printf("Digite o CPF do cliente que deseja remover: ");
	scanf ("%d", &CPF);
	for (i=0; i < qtd; i++){
		
    	if((clientes[i].CPF - CPF) == 0){
    		
        	while(i < qtd-1){
        		clientes[i] = clientes[i+1];
				i++;
        	}
        	qtd--;
        	sucess = 1;
        	break;
    	}
    	else{
        printf("Erro. Tente novamente\n");
    	}
	}
	return sucess;
}




