#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: ");//Coletando inform��o do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //"w" significa escrever
	fprintf(file, "#CPF: "); //Salva "CPF" no arquivo
	fclose(file);//fecha arquivo
	

	file = fopen(arquivo, "a"); //"a" para atualizar informa��o
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a");//"a" para atualizar informa��o
	fprintf(file, "\n#NOME: ");//Salva "NOME" dentro do aquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Coletando inform��o do usu�rio
	scanf("%s", nome);
	
	
	file = fopen(arquivo, "a");//"a" para atualizar informa��o
	fprintf(file,nome);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" para atualizar informa��o
	fprintf(file,"\n#SOBRENOME: ");//Salva "SOBRENOME" dentro do aquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coletando inform��o do usu�rio
	scanf("%s", sobrenome);
	
	
	file = fopen(arquivo, "a");//"a" para atualizar informa��o
	fprintf(file,sobrenome);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" para atualizar informa��o
	fprintf(file, "\n#CARGO: ");//Salva "CARGO" dentro do aquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando inform��o do usu�rio
	scanf("%s", cargo);
	
	
	file = fopen(arquivo, "a");//"a" para atualizar informa��o
	fprintf(file,cargo);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo idioma
	
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//Coletando inform��o do usu�rio
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");//Abre arquivo para leitura "r"
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel abir o arquivo, n�o localizado.\n\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);//Mostra conte�do da vari�vel na tela
		printf("\n\n");
	}
	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema\n\n");
		system("pause");
	}
}



int main()
{
	int opcao=0,laco=1, retorno=-1; //definindo vari�veis
	char letra;
	
	for(laco=1;laco=1;) //loop da sele��o do menu
	{
	
		system("cls");//respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");//Definindo idioma
		
		printf(" ### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		do{
			printf("Op��o:"); //fim do menu
			retorno = scanf("%d", &opcao); //armazenando a escolha do usu�rio
			printf("Essa op��o n�o est� disponivel\n");	
			do{
				letra = getchar(); //Limpando banner do teclado
			}while(letra != '\n'); //Limpando banner do teclado
		}while(retorno == 0);
		
		
		system("cls");//respons�vel por limpar a tela
	
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();//chamda de fun��es
			break;
			
			case 3:
			deletar();//chamda de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");	
			break;
		} //fim da sele��o
		
	}
}
