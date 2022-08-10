#include<conio2.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*************************************************************
Descrição do Algoritmo:
Disciplina: Algoritmo II
Professor: Leonair Neves de Sousa
Alunos: Joelma Silva Campos Godoy
	Gabriel Acassio Correia
Turma: 2021/2
RGA: 202115310001
     202111310049
Data da entrega: 10/08/2022
**************************************************************/
void imprimeModa(int tamanho,int amostra[])
{
	int i, j, quantRepet=1;
	for(i=1; i<tamanho; i++)
	{
		if(amostra[i-1]!=amostra[i])
		{
			quantRepet++;
		}
	}
	int acumulo=0, moda;
	if(quantRepet==tamanho)
	{
		printf("\n Nao ha moda");
	}
	else
	{
		int matRepet[2][quantRepet], cont=0;
		i=0;
		while(i<tamanho)
		{ 
			matRepet[1][cont]=0;
			while( j<tamanho)
			{
				if(amostra[i]==amostra[j])
				{
					matRepet[0][cont]=amostra[i];
					matRepet[1][cont]++;
				}
				else
				{
					j=tamanho;
				}
				j++
			}
			i+=matRepet[1][cont];
			j=i;
			cont++;
			if(matRepet[1][moda]<matRepet[1][cont])
			{
				moda=cont;
			}		
		}
		int outrasModas=0;
		for(j=0;j<quantRepet;j++)
		{	
		 	if(matRepet[1][moda]==matRepet[1][j])
					{
						outrasModas++;
					}
		}
		int vetOutrasModas[outrasModas];
		i=0;
		for(j=0; j<quantRepet; j++)
		{
		 	if(matRepet[1][moda]==matRepet[1][j])
					{
						 vetOutrasModas[i]=matRepet[0][j];
						 i++;	
					}
		}
		if(outrasModas* matRepet[1][moda]==tamanho)
		{
			printf("\n Nao ha moda");
		}else{
			switch (outrasModas)
			{
				case 1:
					printf("\n A moda e %d", matRepet[0][moda]);
					break;
				default:
					printf("\n As modas sao  ");
					for(i=0;i<outrasModas;i++)
					{
						(i!=outrasModas-1&&i!=0)? printf(", "): (i==outrasModas-1)? printf(" e "): printf("");
						printf("%d",vetOutrasModas[i]);
						
					}	
					break;	
			}	
		}
	}			
}
int main()//programa principal
{	
	int tamanho;
	printf("Ola, para iniciar a construção da sua tabela de frequência insira o numero de elementos da amostra:");
	scanf("%d", &tamanho);
	int amostra[tamanho];
	
	int i, j;
	float soma=0;
	for(i=0; i<tamanho; i++)
	{
		printf("Insira o elemento [%d] da amostra= ", i+1);
		scanf("%d", &amostra[i]);
		soma+=amostra[i];
	}
	
	//Ordenação	
	int cont=1, primeiro=0, aux, menor, maior;			
	while(cont<=tamanho)
	{
		menor=primeiro;
		for(i=primeiro+1; i<tamanho; i++)
		{
			if(amostra[menor]>amostra[i])
			{
				menor=i;
			}
		}
		aux=amostra[primeiro];
		amostra[primeiro]=amostra[menor];
		amostra[menor]=aux;
		primeiro=primeiro + 1;
		cont++;
	}
	
	//definindo valores
	int k, at, atc;
	k=((int)(ceil(sqrt(tamanho))));
	at=amostra[tamanho-1]-amostra[0];
	atc=ceil(at/((float)k));
	
	//media
	float media=0;
	media=soma/tamanho;
	
	//mediana
	float mediana=0;
	if(tamanho%2==1)
	{
		mediana=amostra[(tamanho-1)/2];
	}
	else
	{
		mediana=((float)(amostra[(tamanho/2)-1]+amostra[tamanho/2]))/2;
	}
		
	//definindo a tabela	
	float tabela[k][8];
	int acumuloAux=0, acumulo=0, maiorFI=0;
	for(i=0; i<k; i++)
	{
		tabela[i][0]=amostra[0]+acumulo;
		acumulo+=atc;
		tabela[i][1]=tabela[i][0]+atc-1;
		if (tabela[k-1][1]<amostra[tamanho-1])
		{
			tabela[k-1][1]=amostra[tamanho-1];
		}		
		tabela[i][3]=(tabela[i][0]+tabela[i][1])/2;
		tabela[i][6]=tabela[i][0]-0.5;
		tabela[i][7]=tabela[i][1]+0.5;	
		tabela[i][2]=0;
		for(j=0; j<tamanho;  j++)
		{
			if(amostra[j]>=tabela[i][0]&&amostra[j]<=tabela[i][1])
			{
				tabela[i][2]++;
			}
		}
		if(maiorFI<tabela[i][2])
		{
			maiorFI=tabela[i][2];
		}
		tabela[i][4]=(tabela[i][2]*100)/tamanho;
		acumuloAux+=tabela[i][2];
		tabela[i][5]=acumuloAux;	
	}

	//imprimindo o resultado
	system("cls");
	gotoxy(40, 3);
	printf("AMOSTRA");
	gotoxy(43-tamanho*2, 5);
	for(i=0; i<tamanho; i++)
	{
		printf(" %3.d", amostra[i]);
	}
	printf("\n\n Media amostral: %4.2f \n Mediana: %4.2f", media, mediana);
	imprimeModa(tamanho, amostra);
	printf("\n");
	printf(" _________________________________________________________________________________________\n");
	printf("|                     |          |          |           |          |                      |\n");
	printf("|       CLASSES       |          |          |           |          | FRONTEIRA DE CLASSES |\n");
	printf("|_____________________|__________|__________|___________|__________|______________________|\n");
	printf("|          |          |          |          |           |          |          |           |\n");
	printf("|    CI    |   CS     |    FI    |    XI    |    FR     |   FCA    |   FCI    |    FCS    |\n");
	printf("|__________|__________|__________|__________|___________|__________|__________|___________|\n");
	printf("|          |          |          |          |           |          |          |           |\n");
    for(i=0; i<k; i++) 
    {
    	printf("|");
		for(j=0; j<8; j++) 
		{ 
    		(j==4)? printf("%8.2f%%  |", tabela[i][j]) : (j==7)? printf("% 8.2f   |", tabela[i][j]) : printf("%8.2f  |", tabela[i][j]);        
		}
        printf("\n|__________|__________|__________|__________|___________|__________|__________|___________|\n");
        (i!=k-1)? printf("|          |          |          |          |           |          |          |           |\n") :printf("\n");
	}
	  
	//Grafico
	printf("\n");
	printf("                                      HISTOROGRAMA   \n\n");
	int corGraf[k-1];
	for(i=0; i<k; i++)
	{
		corGraf[i]=rand()%9+1;	
	}
	for(j=maiorFI+1; j>=0; j--)
	{
		gotoxy(43-k, 21+maiorFI+k*3-j);
	    for(i=0; i<k; i++)
		{   
			if(tabela[i][2]>=j){
				textcolor(corGraf[i]);
				if(tabela[i][2]==j)
				{
					printf(" %.f ", tabela[i][2]);	
				}
				else
				{
					printf("%c%c%c", 178, 178, 178);	
				}
			}
			else
			{
				printf("   ");
			}
		}
		textcolor(7);
		printf("\n");
	}	
	return 0;
}
