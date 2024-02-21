#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocaçao de espaço em memoria
#include <locale.h> // biblioteca de alocação de texto por regiao
#include <string.h> //biblioteca responsavelpor cuidar das strings>

int registro()//funcao reponsavel por cadastrar os usuarios no sistema
{
	//inicio da criacao de variaveis
	char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis
	
	printf("Digite o CPF a ser cadastrado:");//Responsavel por copíar os valores das strings
	scanf("%s",cpf);//%s referese a string
	
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	
	FILE*file;//cria o arquivo
	file=fopen(arquivo,"w");//cria o arquivo e o w siginifica write
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser Cadastrado:");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
	
	
}

 int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");
  
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:");
    scanf("%s",cpf);
 
 	FILE *file;
 	file=fopen(cpf,"r");
 	
 	if(file== NULL)
	 {
    printf("Não foi possivel encontrar esse cpf!.\n");
	 }
	 
	while(fgets(conteudo,200,file)!=NULL)
{
	 	 
     printf("\nEssas são as informações do usuario:");
     printf("%s",conteudo);
     printf("\n\n");
	 }	
	 
	 system("pause");
	 fclose(file);
 }
 
 int deletar()
{
  
    char cpf[40];
    
	printf("Digite o CPF do usuario a ser deletado:\n");
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file==NULL)
	{
	printf("\nO usuario não se encontra no sistema!.\n");
	system("pause");
	}
	
	remove(cpf);//remove é uma funcao basica que ja apaga
	
	
	if (file!=NULL)
	{
	printf("\n\nUsuario deletado com sucesso\n\n");
	system("pause");
 }
	
 }
 
int main ()
{
    int opcao=0;//Definindo variaveis
   	
    int ciclo=1;
 
    for(ciclo=1;ciclo=1;)
	{
		system("cls");//reponsavel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese");// definindo linguagens
	
	printf("###Cártorio da Ebac###\n\n");// inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf ("\t1 - Registrar nomes\n");
	printf ("\t2 - Consultar nomes\n");
	printf ("\t3 - Deletar nomes\n\n\n\n");
	printf("\t4 - Sair do Sistema\n\n");
	printf("opcão:");// fim do menu

    scanf("%d", &opcao);//armazenamento a escolha de cada usuario
	
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
		deletar();
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
			
		break;
			
	    default:
	    printf("Essa opcão não está disponivel\n");
		system("pause"); //fim da seleção
		}
	}
}
