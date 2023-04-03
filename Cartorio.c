
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca ce alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()  //Função responsável por cadastrar os usuários no sistema
{
	//Inicio criaçãõ de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s referece a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo do usuário: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	//printf("Você escolheu o registrar nomes!\n");
	//system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //comando que informa que a linguagem dos textos é em portugues 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, Não conseguimos encontrar.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
	//printf("Você escolheu a consulta de nomes!\n");
	//system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usuário não se encontra no sistema. \n");
		system("pause");
	}
	
	
	
	
	//printf("Você escolheu excluir nomes!\n");
	//system("pause");
}

int main ()
{
	int opcao=0; //Definindo variáveis 
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //comando que informa que a linguagem dos textos é em portugues 
		
		printf("### Cartório da EBAC ###\n\n"); // \n para pular uma linha
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t 1 - Registro de nomes\n"); // \t para dar um espaço antes de começar a frase 
		printf("\t 2 - Consulta de nomes\n");
		printf("\t 3 - Exclusão de nomes\n");
		printf("\t 4 - Sair do sistema\n");
		printf("Opção: ");
		
		scanf("%d", &opcao); // "%d" esta dizendo para armazenar uma variável
		
		system("cls"); // cls diz para limpar a tela
		
		switch(opcao)
		{
			case 1:
				registro();
				break;
				
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Ogrigado por utilizar o sistema!\n");
				return 0;	
				break;
				
			default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
		}
		
		 	
	}
	
	
}







