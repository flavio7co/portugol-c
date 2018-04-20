/**************************************************#
#                                                  #
# PORTUGOL-C (GCC 5.0+) - Arquivo desatualizado    #
# Tradução e compilação do Portugol adaptado para  #
# linguagem C.                                     #
#                                                  #
# Autor: Flávio O. Sousa                           #
# Instituto Federal Fluminense - Campus Itaperuna  #
# flavio7co@gmail.com                              #
#                                                  #
#**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TT 21

FILE *arqin, *arqfunc;
char linha[100];

struct palavras
{
	char p[50];
	char c[50];
} tag[TT];


void tabela()
{
	// TABELA DE CORREÇÕES
	strcpy(tag[0].p,"<-");
	strcpy(tag[0].c,"= ");
	
	strcpy(tag[1].p,"inicio");
	strcpy(tag[1].c,"{     ");
	
	strcpy(tag[2].p,"fim");
	strcpy(tag[2].c,"}  ");
	
	strcpy(tag[3].p,"escreva(\"");
	strcpy(tag[3].c," printf(\"");

	strcpy(tag[4].p,"escreva (\"");
	strcpy(tag[4].c," printf (\"");

	strcpy(tag[5].p,"senão");
	strcpy(tag[5].c,"else  ");
	
	strcpy(tag[6].p,"senao");
	strcpy(tag[6].c,"else ");	
	
	strcpy(tag[7].p,"se(");
	strcpy(tag[7].c,"if(");

	strcpy(tag[8].p,"se (");
	strcpy(tag[8].c,"if (");

	strcpy(tag[9].p,"leia(");
	strcpy(tag[9].c,"scanf(typeof(");

	strcpy(tag[10].p,"leia (");
	strcpy(tag[10].c,"scanf (typeof(");
	
	strcpy(tag[11].p,"escreva(");
	strcpy(tag[11].c,"printf(typeof(");

	strcpy(tag[12].p,"escreva (");
	strcpy(tag[12].c,"printf (typeof(");
	
	strcpy(tag[13].p,"enquanto(");
	strcpy(tag[13].c,"while   (");

	strcpy(tag[14].p,"enquanto (");
	strcpy(tag[14].c,"while    (");

	strcpy(tag[15].p,"escolha(");
	strcpy(tag[15].c,"switch (");

	strcpy(tag[16].p,"escolha (");
	strcpy(tag[16].c,"switch  (");

	strcpy(tag[17].p,"caso ");
	strcpy(tag[17].c,"case ");

	strcpy(tag[18].p,"abandone");
	strcpy(tag[18].c,"   break");

	strcpy(tag[19].p,"padrão");
	strcpy(tag[19].c,"default");

	strcpy(tag[20].p,"padrao");
	strcpy(tag[20].c,"default");

	// FIM DA TABELA DE CORREÇÕES
}


void traduzlinha()
{
	char linha2[100]={};
	int x,n,ok=0;				
	// Para cada palavra reservada, percorre linha.
	for(n=0;n<TT;n++)
	{
		// Percorre linha até encontrar o final (final da string= \0).
		for(x=0;linha[x]!='\0';x++)
		{ 
				int	dif=0;
                //Pega a o tamanho da presente tag encontrada na linha
				if(linha[x]==tag[n].p[ok]) ok++;
				  else ok=0;

				// Mesmo tamanho indica TAG presente
				if(strlen(tag[n].p)==ok && ok!=0)
				{
					// variáveis para Leia e Escreva (typedef)
					int contador=0;
					char variavel[30], tagc[50];

				    // Pega a diferença de tamanho entre .p e .c
					dif=strlen(tag[n].c)-ok;

					// Formando TAG LEIA e ESCREVA por conta dos %d, etc.
					if(n>=9 && n<=12 && linha[x+1]!='"')
					{


						 // pegando o nome da variável
						 for(contador=0;linha[x+contador+1]!=')';contador++)
						 {variavel[contador] = linha[x+contador+1];}
						 // transformando em string
						 variavel[contador] = '\0';
						 
						 // P.S.: O contador também obtém o tamanho do nome da variável.
						 // Formando tag[n].c com variável para typedef
						 strcpy(tagc,tag[n].c);
						 strcat(tagc,variavel);

						 // Completando Leia e Escreva.
						 // Se for leia inserir ),& se for escreva inserir ),
						 if(n==9 || n==10)
						 { 
							 strcat(tagc,"),&");
							 dif+=contador+3;
							 
						 } else if(n==11 || n==12)
						        {
									 strcat(tagc,"),");
									 dif+=contador+2;
								}
						 // Variável denovo
						 strcat(tagc, variavel);
						 strcat(tagc, ");");	
						 strcpy(tag[n].c, tagc);
					}

					int cont=0,k;					
					// Arredando para a frente caso .c seja maior que .p

					// mostrando dif
					if(dif>0) 
					{
						//printf("%s,%s:%d ",tag[n].p,tag[n].c,dif);
						//for(k=x+dif;k>=x;k--) linha[k]=linha[k-dif];
						for(k=99;k>=x;k--) linha[k]=linha[k-dif];
						linha[99]='\0';
					}
					
					/* x-=ok-1 -> pega a posição da linha menos o tamanho da tag (-1 é para pegar o ponto certo do inicio da palavra).
					 * cont<strlen(tag[n].c) -> enquanto a contagem for menor que o tamanho da tag.  
					 * */
					for(x-=ok-1;cont<strlen(tag[n].c);x++)
					{
						//printf("l:%s\n", linha);
						linha[x]=tag[n].c[cont];
						cont++;
					}
  				    if(n==9)strcpy(tag[n].c, "scanf(typeof(");
  				    if(n==10)strcpy(tag[n].c, "scanf (typeof(");
  				    if(n==11)strcpy(tag[n].c, "printf(typeof(");
  				    if(n==12)strcpy(tag[n].c, "printf (typeof(");
				}
				//linha2[x]=linha[x];
		}
	}
	linha[x]='\0';
//	printf("%s",linha); 
	  // linhas para pausar conversão
	//  char pause;
	//  printf("%s\n", linha);
	//  scanf(" %c", &pause);

}


void criaprincipal()
{
	FILE *arqprinc;
	int result;
	arqprinc = fopen(".portugolc/portugolc.c", "w");
	if(arqprinc == NULL){
		system("mkdir .portugolc");
		printf("Erro ao criar função principal\n");
	} else
	  {

			result = fputs("#define typeof(var) _Generic((var),char:\" %c\",int:\"%d\",float:\"%f\",char *:\"%s\",void *:\"%p\",double:\"%f\", default:\"%s\")\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("#include <stdio.h>\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("typedef int inteiro;\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("typedef float real;\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("typedef char caracter;\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("void novalinha(int x){int i;for(i=0;i<x;i++)printf(\"\\n\");}\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("#include \"programa.h\"\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("int main(){\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("printf(\"--------------------------------------------\\n\");\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("printf(\"# Traduzido de PortugolC - Flávio O. Sousa #\\n\");\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("printf(\"--------------------------------------------\\n\");\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("programa();\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");
			result = fputs("}\n", arqprinc);
			if (result == EOF) printf("Erro na Gravacao\n");	
			fclose(arqprinc);
	  }
}


void criafuncao()
{
	int result;
	char * res;

	result = fputs("void programa(){\n", arqfunc);
	if (result == EOF) printf("Erro na Gravacao\n");
	
	while (!feof(arqin))
	{
      res = fgets(linha, 100, arqin);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (res)
      {  
		traduzlinha();
		result = fputs(linha, arqfunc);
		if (result == EOF) printf("Erro na Gravacao\n");
		//fputs("\n", arqfunc);
		if (result == EOF) printf("Erro na Gravacao\n");
	  }	  
	}
	result = fputs("}\n", arqfunc);
	if (result == EOF) printf("Erro na Gravacao\n");	
	fclose(arqfunc);
}

int preprocessamento()
{
	int x;
	char * res;
	printf("\nPreprocessando arquivo...\n");
	while (!feof(arqin))
	{
      res = fgets(linha, 100, arqin);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (res)
      {  
		for(x=0;linha[x]!='\0';x++)
		{ 
				if(linha[x]=='"') 
				{
					while(linha[x+1]!='"') x++;
					x++;
				}
				if(linha[x]=='=')
				  if(linha[x+1]=='=') x+=1;
				    else return 0;
		}
	  }
	}
	return 1;
}

int main(int argc, char **argv)
{

	// Opção para preparar pasta para compilar.
	if(argc > 1 && strcmp(argv[1],"preparar")==0)
	{
		printf("Preparando arquivos...");
		system("mkdir .portugolc");
		arqin = fopen(".portugolc/programa.h", "w");
		if(arqin == NULL){
			printf("Erro ao preparar arquivo programa.h\n");
		}
		fclose(arqin);
		arqin = fopen(".portugolc/portugolc.c", "w");
		if(arqin == NULL){
			printf("Erro ao preparar arquivo portugolc.c\n");
		}
		fclose(arqin);
		arqin = fopen("algoritmo.alg", "w");
		if(arqin == NULL){
			printf("Erro ao preparar arquivo algoritmo.alg\n");
		} 
		fclose(arqin);
		printf("concluido\n");
	} else
	  {
		  
		// inicializando tags
		tabela();

		// Variáveis para receber as respostas de leitura e gravação
		int result;
		char * res, nomeprog[50]="exec", agrt[15];
		
		// Função que cria classe principal.
		criaprincipal(); 
		
		// Preprocessamento.
		arqin = fopen("algoritmo.alg", "r");
		if(arqin == NULL) printf("Erro ao abrir arquivo de origem: algoritmo\n");
		  else
		  {
			  if(!preprocessamento())
			  { printf("ERRO: COMANDO DE ATRIBUIÇÃO INVÁLIDO\n");return 0;}
			  fclose(arqin);			  
		  }
		
		// Abrindo arquivo em portugol-c  
		arqin = fopen("algoritmo.alg", "rt");
		if(arqin == NULL) printf("Erro ao abrir arquivo de origem: algoritmo.alg\n");
		  else
		  {
			// Aprindo biblioteca de saída.  
			arqfunc = fopen(".portugolc/programa.h", "wt");
			if(arqfunc == NULL){
				printf("Erro ao criar biblioteca programa.h\n");
			} else
	          {
			      system("clear");
				  // Lendo linha com nome do programa.
			      result = fscanf(arqin, "%s %s",agrt,nomeprog); //(Linha, 100, arqin);  // o 'fgets' lê até 99 caracteres ou até o '\n'
			      printf("Programa a ser compilado: %s ... Executando:\n", nomeprog);
			      res = fgets(linha, 100, arqin);
			      //printf("Recebendo a segunda linha: %s\n", linha);  
			      // Chama função que cria função no arquivo programa.h
				  criafuncao();
			  }
		  }
		//Linhas para a compilação do programa resultante.
		//Variável que recebe o comando
		if(strcmp(agrt,"algoritmo")==0||strcmp(agrt,"Algoritmo")==0)
		{
			char comando[100];
			strcpy(comando,"cc .portugolc/portugolc.c -o ");
			// copiando nome do programa para o final do comando
			strcat(comando,nomeprog);
			system(comando);
			// Executando comando
			strcpy(comando,"./");
			strcat(comando,nomeprog);
			system(comando);
		} else printf("\nPalavra reservada \"Algoritmo\" não encontrada\n\n");
	}
}
