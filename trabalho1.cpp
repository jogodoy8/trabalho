//#include<conio2.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iosotrem>
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
	int amostra[6],l,c,cont=1,primeiro=0,aux,menor,i,at,atc;
	int moda,a,j,v2[6],maior;
	float tabela[5][8],k,soma=0,media=0,mediana=0;
	int tamanho = sizeof(amostra)/sizeof(amostra[0]);
	
	for(i=0;i<tamanho;i++)
	{
		printf("Insira os elementos da amostra[%d]= ",i+1);
		scanf("%d",&amostra[i]);
		soma+=amostra[i];
	}
	for(i=0;i<tamanho;i++)
	{
		printf(" %d",amostra[i]);
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
	k=ceil(sqrt(tamanho));
	printf("K e igual: %.2f\n",k);
	at=amostra[tamanho-1]-amostra[0];
	printf("AT e igual: %d\n",at);
	atc=ceil(at/k);
	printf("ATC e igual: %d\n",atc);
	//media
	media=soma/tamanho;
	printf("\nMedia: %.2f\n",media);
	//mediana
	if(tamanho%2)
	{
		mediana=amostra[tamanho/2];
	}
	else
	{
		mediana=((float)amostra[tamanho/2-1]+amostra[tamanho/2])/2;
	}
	printf("Mediana: %.2f\n",mediana);
	//moda
	//vetor 2 define as repetições, deixando primeiro todas iguais a 0
	for(i=0;i<amostra;i++){
			v2[i]=0;
	}
	//verificando se dois numeros são iguais, caso sim, aumenta no vetor repetições
	for(i=0;i<amostra;i++){
		for(j=1;j<amostra;j++){
			if((amostra[i])==v2[j]){
				v2[i]=v2[i]+1;
			}
			
		}
	}
	//determinando qual é o maior numero de repetições
	maior=0
	for(i=0;i<amostra;i++){
		if(v2[i]>maior){
			maior=v2[i];
		}
	}
	//verificando o numero mais repetido	
	for(i=0;i<amostra;i++){
		if(v2[i]==maior){
			moda=i;
		}
	}
	printf("\nModa: %d",amostra[moda]);
	
	/*for(l=0;l<5;l++) 
      {for(c=0;c<8;c++) 
         {if(c==0)
            {
				(primeiro,l+1,c+1);
            	scanf("%f",&tabela[l][c]);
		    }*/
		 /* if(c==1)
		    {matriz[l][c]=matriz[l][0]*0.1;
		    }
		  if(c==2)
		    {matriz[l][c]=matriz[l][0]*1.05;
		    }
		  if(c==3)
		    {do
		       {printf("\nInforme quantidade de parcela entre[1 e 3]: ");
                scanf("%f",&matriz[l][c]);
                if (matriz[l][c]<1 ||matriz[l][c]>3)
                  {printf("N?mero de parcela invalida!!\n");
				  }
			   }while (tabela[l][c]<1 ||tabela[l][c]>3);
		    }
		  if (c==4)  
		     {tabela[l][c]=tabela[l][2]/tabela[l][3];
			 }
		  
         }*/
	  }
	printf("   CI   CS   FI  XI  FR  FCA  FCI  FCS    \n");
    for(l=0;l<5;l++) 
      {for(c=0;c<8;c++) 
         {printf("   %.2f",tabela[l][c]);        
         }
         printf("\n\n");
	  }
	return 0;
}
}
		
		
		
	
	

