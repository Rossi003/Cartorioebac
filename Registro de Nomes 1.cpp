#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��oo de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string 

int registrar() //Fun��o respons�vel por cadatrar os usu�rios no sistema 

{
	   // In�cio da cria��o de vari�veis/ string 
	    char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40]; //cria��o das vari�veis 
		// Final da cria��o das vari�veis 
		
		printf("Digite o CPF a ser cadastrado: "); //perguntou o valor do cpf, coletando informa��es 
		scanf("%s", cpf); // est� se referindo ao armazenamento das string 
		
		strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings 
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo, o "w" significa escrever 
		fprintf(file, cpf); //salva o valor da vari�vel 
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //atualiza��o de uma informa��a 
		fprintf(file, ","); //adicionamos uma v�rgula 
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: "); 
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome); //salvando a vari�vel nome dentro do arquivo
		fclose(file);
		
		file = fopen(arquivo, "a"); //atualiza��o de uma informa��a 
		fprintf(file, ","); //adicionamos uma v�rgula 
		fclose(file); 
		
		printf("Digite o sobrenome a ser cadastrado: "); 
		scanf("%s", sobrenome); 
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome); //adicionando a informa��o sobrenome 
		fclose(file); 
		
		file = fopen(arquivo, "a"); //atualiza��o de uma informa��a 
		fprintf(file, ","); //adicionamos uma v�rgula 
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: "); 
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo); //adicionando a infora��o do cargo 
		fclose(file); 
		
		system("pause"); //� aquela pausa antes de reiniciar o sistema "digite uma tecla para continuar"
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//cria��o das vari�veis 
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser consultado:  ");
	scanf("%s", cpf); 
	
	FILE *file; 
	file = fopen(cpf,"r"); //vai ler o banco de dados procurando a informa��o 
	
	if(file == NULL) //significa que o arquivo � nulo, ou seja, n�o existe no sistema 
	{
		printf("N�o foi poss�vel abrir, arquivo n�o localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //rodar enquanto for diferente de nulo 
	{
		printf("\nEssas s�o as informa��es do usu�rio:  ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause"); 
	
	
}

int deletar()
{
	char cpf[40]; 
	
	printf("Digite o CPF do su�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //Deletar usu�rio 
	{
		printf("O usu�rio foi deletado do sistema.\n");
		system("pause");
	}
	
	FILE *file;
	file = fopen(cpf, "r"); //Abrir, ler e consultar usu�rio 
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}

}


int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;  
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela 
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
		
		printf("### Registro de Nomes dos Alunos da EBAC ###\n\n"); //In�cio do menu	
		printf("## Menu de Op��es: ##\n\n");
		printf("\t1- Registrar Usu�rios\n");
		printf("\t2- Consultar Usu�rios\n");
		printf("\t3- Deletar Usu�rios\n");
		printf("\t4- Sair do sistema\n\n");
		printf("Op��o:  "); //fim do menu 
		
		
		scanf("%d", &opcao); //armazenando as escolhas do usu�rio 
		
		system("cls"); //respons�vel por limpar a tela 
		
		switch(opcao) //in�cio da sele��o do menu 
		{
			case 1: 
			registrar(); //chamada das fun��es 
			break;
			
			case 2:
			consultar(); //chamada das fun��es
			break;
			
			case 3:
			deletar(); //chamada das fun��es
			break;
			
			case 4: 
			printf("Obrigado por utilizar o sistema :)\n");
			return 0; 
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o 
	}
}
