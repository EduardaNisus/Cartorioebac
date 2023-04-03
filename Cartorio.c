
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca ce aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()  //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio cria��� de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s referece a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da vari�vel
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
	
	printf("Digite o cargo do usu�rio: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	//printf("Voc� escolheu o registrar nomes!\n");
	//system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //comando que informa que a linguagem dos textos � em portugues 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, N�o conseguimos encontrar.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
	//printf("Voc� escolheu a consulta de nomes!\n");
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
		printf("o usu�rio n�o se encontra no sistema. \n");
		system("pause");
	}
	
	
	
	
	//printf("Voc� escolheu excluir nomes!\n");
	//system("pause");
}

int main ()
{
	int opcao=0; //Definindo vari�veis 
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //comando que informa que a linguagem dos textos � em portugues 
		
		printf("### Cart�rio da EBAC ###\n\n"); // \n para pular uma linha
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t 1 - Registro de nomes\n"); // \t para dar um espa�o antes de come�ar a frase 
		printf("\t 2 - Consulta de nomes\n");
		printf("\t 3 - Exclus�o de nomes\n");
		printf("\t 4 - Sair do sistema\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao); // "%d" esta dizendo para armazenar uma vari�vel
		
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		}
		
		 	
	}
	
	
}







