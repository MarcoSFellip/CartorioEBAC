#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: ");//Coletando informção do usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //"w" significa escrever
	fprintf(file, "#CPF: "); //Salva "CPF" no arquivo
	fclose(file);//fecha arquivo
	

	file = fopen(arquivo, "a"); //"a" para atualizar informação
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a");//"a" para atualizar informação
	fprintf(file, "\n#NOME: ");//Salva "NOME" dentro do aquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Coletando informção do usuário
	scanf("%s", nome);
	
	
	file = fopen(arquivo, "a");//"a" para atualizar informação
	fprintf(file,nome);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" para atualizar informação
	fprintf(file,"\n#SOBRENOME: ");//Salva "SOBRENOME" dentro do aquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coletando informção do usuário
	scanf("%s", sobrenome);
	
	
	file = fopen(arquivo, "a");//"a" para atualizar informação
	fprintf(file,sobrenome);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" para atualizar informação
	fprintf(file, "\n#CARGO: ");//Salva "CARGO" dentro do aquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informção do usuário
	scanf("%s", cargo);
	
	
	file = fopen(arquivo, "a");//"a" para atualizar informação
	fprintf(file,cargo);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo idioma
	
	//Início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//Coletando informção do usuário
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");//Abre arquivo para leitura "r"
	
	if(file == NULL)
	{
		printf("\nNão foi possível abir o arquivo, não localizado.\n\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);//Mostra conteúdo da variável na tela
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
		printf("Usuário não se encontra no sistema\n\n");
		system("pause");
	}
}



int main()
{
	int opcao=0,laco=1, retorno=-1; //definindo variáveis
	char letra;
	
	for(laco=1;laco=1;) //loop da seleção do menu
	{
	
		system("cls");//responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");//Definindo idioma
		
		printf(" ### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		do{
			printf("Opção:"); //fim do menu
			retorno = scanf("%d", &opcao); //armazenando a escolha do usuário
			printf("Essa opção não está disponivel\n");	
			do{
				letra = getchar(); //Limpando banner do teclado
			}while(letra != '\n'); //Limpando banner do teclado
		}while(retorno == 0);
		
		
		system("cls");//responsável por limpar a tela
	
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();//chamda de funções
			break;
			
			case 3:
			deletar();//chamda de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel\n");
			system("pause");	
			break;
		} //fim da seleção
		
	}
}
