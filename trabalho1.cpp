//#include<conio2.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<iosotrem>
/*************************************************************
Descrição do Algoritmo:
Disciplina: Algoritmo II
Professor: Leonair Neves de Sousa
Alunos: Joelma Silva Campos Godoy
		Gabriel Acassio
Turma: 2021/2
RGA: 20211153001
	 2021
Data da entrega: 10/08/2022
**************************************************************/

int main()//programa principal
{	
	int k,l,c,cont=1,primeiro=0,aux,menor,i,at,atc;
	int moda,a,j,v2[6],maior;
	float soma=0,media=0,mediana=0;
	int tamanho;
	
	printf("Olá, para iniciar a construção da sua tabela de frequência insira o numero de elementos da amostra:");
	scanf("%d", &tamanho);
	
	int amostra[tamanho];
	
	for(i=0; i<tamanho; i++)
	{
		printf("Insira o elemento [%d] da amostra= ",i+1);
		scanf("%d", &amostra[i]);
		soma+=amostra[i];
	}
	
	for(i=0;i<tamanho;i++)
	{
		printf(" %d", amostra[i]);
	}		
		
	while (cont <= tamanho)
	{
		menor = primeiro;
		for(i = primeiro + 1; i < tamanho; i++)
		{
			if(amostra[menor] > amostra[i])
			{
				menor = i;
			}
		}
		aux = amostra[primeiro];
		amostra[primeiro] = amostra[menor];
		amostra[menor]=aux;
		primeiro = primeiro + 1;
		cont++;
	}
	
	printf("\n");
	
	for(int i = 0; i < tamanho; i++)
	{
		printf(" %d", amostra[i]);
	}
	
	printf("\n");
	
	k=((int)(ceil(sqrt(tamanho))));
	float tabela[k][8];
	printf("\nK e igual: %d",k);
	at=amostra[tamanho-1]-amostra[0];
	printf("\nAT e igual: %d",at);
	atc=ceil(at/((float)k));
	printf("\nATC e igual: %d",atc);
	
	//media
	media=soma/tamanho;
	printf("\nMedia: %.2f",media);
	
	//mediana
	
	if(tamanho%2==1)
	{
		mediana=amostra[(tamanho-1)/2];
	}
	else
	{
		mediana=((float)(amostra[(tamanho/2)-1]+amostra[tamanho/2]))/2;
	}
	
	printf("\nMediana: %.2f",mediana);
	
	//moda

	int quantRepet=1;
	int acumulo=0;
	for(i=1;i<tamanho;i++)
	{
		if(amostra[i-1]!=amostra[i])
		{
			quantRepet++;
		}
	}
	if(quantRepet==tamanho)
	{
		printf("\nNao ha moda");
	}else{
		int matRepet[2][quantRepet];
		j=0;
		for(i=1;i<tamanho;i++)
		{
			if((amostra[i-1]!=amostra[i])||((amostra[tamanho-1]==amostra[tamanho-2])&&(i==tamanho-1)))
			{
				matRepet[1][j]=amostra[i-1];
				if(j==0)
				{
					matRepet[2][j]=i;
					moda=j;
				}else{
					acumulo+=matRepet[2][j-1];
					if((amostra[tamanho-1]==amostra[tamanho-2])&&(i==tamanho-1))
					{
						acumulo--;
					}
					if(amostra[tamanho-1]==amostra[tamanho-2])
					{
						matRepet[2][j+1]=1;	
					}
					matRepet[2][j]=i-acumulo;
					if(matRepet[2][moda]<matRepet[2][j])
					{
						moda=j;
					}
				}
				j++;
			}
		}
		int outrasModas=0;
		for(j=0;j<quantRepet;j++)
		{
			printf("\nR=%d",matRepet[2][j]);
		 	if(matRepet[2][moda]==matRepet[2][j])
					{
						outrasModas++;
						printf("\nM=%d",outrasModas);
					}
		}
		int vetOutrasModas[outrasModas];
		i=0;
		for(j=0;j<quantRepet;j++)
		{
		 	if(matRepet[2][moda]==matRepet[2][j])
					{
						 vetOutrasModas[i]=matRepet[1][j];
						 i++;	
					}
		}
		if(outrasModas* matRepet[2][moda]==tamanho)
		{
			printf("\nNao ha moda");
		}else{
			switch (outrasModas)
			{
				case 1:
					printf("\nA moda e %d", matRepet[1][moda]);
					break;
				default:
					printf("\nAs modas sao  ");
					for(i=0;i<outrasModas;i++)
					{
						(i!=outrasModas-1&&i!=0)? printf(", "): (i==outrasModas-1)? printf(" e "): printf("");
						printf("%d",vetOutrasModas[i]);
						
					}	
					break;	
			}	
		}
		
	}
	//definindo classe inicial e final
	
	acumulo=0;
	for(l=0;l<k;l++)
	{
		tabela[l][0]=amostra[0]+acumulo;
		acumulo+=atc;
		tabela[l][1]=amostra[0]+acumulo-1;
		tabela[l][3]=(tabela[l][0]+tabela[l][1])/2;
		tabela[l][6]=tabela[l][0]-0.5;
		tabela[l][7]=tabela[l][1]+0.5;
		
	}
	acumulo=0;
	for(l=0;l<k;l++)
	{   
	    tabela[l][2]=0;
		for(i=0;i<tamanho;i++)
		{
			if(amostra[i]>=tabela[l][0]&&amostra[i]<=tabela[l][1])
			{
				tabela[l][2]++;
			}
		}
		tabela[l][4]=(tabela[l][2]*100)/tamanho;
		acumulo+=tabela[l][2];
		tabela[l][5]=acumulo;
	}
	printf("\n\n");
	  
	printf("    CI      CS      FI      XI      FR       FCA     FCI     FCS    \n");
    for(l=0;l<k;l++) 
      {for(c=0;c<8;c++) 
         {
         	
		 printf("    %.2f", tabela[l][c]);        
         }
         printf("\n\n");
	  }
	return 0;
}
