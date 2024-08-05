#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocaçãoo de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string 

int registrar() //Função responsável por cadatrar os usuários no sistema 

{
	   // Início da criação de variáveis/ string 
	    char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40]; //criação das variáveis 
		// Final da criação das variáveis 
		
		printf("Digite o CPF a ser cadastrado: "); //perguntou o valor do cpf, coletando informações 
		scanf("%s", cpf); // está se referindo ao armazenamento das string 
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das strings 
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo, o "w" significa escrever 
		fprintf(file, cpf); //salva o valor da variável 
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //atualização de uma informaçõa 
		fprintf(file, ","); //adicionamos uma vírgula 
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: "); 
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome); //salvando a variável nome dentro do arquivo
		fclose(file);
		
		file = fopen(arquivo, "a"); //atualização de uma informaçõa 
		fprintf(file, ","); //adicionamos uma vírgula 
		fclose(file); 
		
		printf("Digite o sobrenome a ser cadastrado: "); 
		scanf("%s", sobrenome); 
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome); //adicionando a informação sobrenome 
		fclose(file); 
		
		file = fopen(arquivo, "a"); //atualização de uma informaçõa 
		fprintf(file, ","); //adicionamos uma vírgula 
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: "); 
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo); //adicionando a inforação do cargo 
		fclose(file); 
		
		system("pause"); //é aquela pausa antes de reiniciar o sistema "digite uma tecla para continuar"
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//criação das variáveis 
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser consultado:  ");
	scanf("%s", cpf); 
	
	FILE *file; 
	file = fopen(cpf,"r"); //vai ler o banco de dados procurando a informação 
	
	if(file == NULL) //significa que o arquivo é nulo, ou seja, não existe no sistema 
	{
		printf("Nâo foi possível abrir, arquivo não localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //rodar enquanto for diferente de nulo 
	{
		printf("\nEssas são as informações do usuário:  ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause"); 
	
	
}

int deletar()
{
	char cpf[40]; 
	
	printf("Digite o CPF do suário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //Deletar usuário 
	{
		printf("O usuário foi deletado do sistema.\n");
		system("pause");
	}
	
	FILE *file;
	file = fopen(cpf, "r"); //Abrir, ler e consultar usuário 
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	}

}


int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;  
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela 
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
		
		printf("### Registro de Nomes dos Alunos da EBAC ###\n\n"); //Início do menu	
		printf("## Menu de Opções: ##\n\n");
		printf("\t1- Registrar Usuários\n");
		printf("\t2- Consultar Usuários\n");
		printf("\t3- Deletar Usuários\n");
		printf("\t4- Sair do sistema\n\n");
		printf("Opção:  "); //fim do menu 
		
		
		scanf("%d", &opcao); //armazenando as escolhas do usuário 
		
		system("cls"); //responsável por limpar a tela 
		
		switch(opcao) //início da seleção do menu 
		{
			case 1: 
			registrar(); //chamada das funções 
			break;
			
			case 2:
			consultar(); //chamada das funções
			break;
			
			case 3:
			deletar(); //chamada das funções
			break;
			
			case 4: 
			printf("Obrigado por utilizar o sistema :)\n");
			return 0; 
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção 
	}
}
