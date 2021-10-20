#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define pi  3.14159265358979323846
#define TAM 1000 


FILE * fp;

double ref(double x,double t)
{ return 1+sin(2*pi*(x-t)); }

int main()
{

	fp = fopen("t5.dat", "w" );
	
	int i,t;

	double tam=TAM;

	double x[TAM],y[TAM];

	double erro;

	for (i = 0; i < TAM; ++i)
	{
		x[i]=i/(tam);
		y[i]=1+sin(2*pi*x[i]);

	//	fprintf(fp, "%lf\t",x[i]);
	//	fprintf(fp, "%lf\n",y[i]);

	}
	
	for (t = 1; t < TAM; ++t)
	{
		for (i = 0; i < TAM; ++i)
		{
			//[ ( TAM + ( index % TAM ) ) % TAM ]// truque da condição de contorno periódica

				y[i]=y[i]-0.5*(y[i]-y[( TAM + i-1) % TAM  ]); // parte A - método upwind	

				// 0.5 corresponde ao valor de 'c' escolhido.			

			/* Checagem de erros

			if (ref(x[i],t/(tam))!=0)
			{
				erro = (y[i]-ref(x[i],t/(tam)))/ref(x[i],t/(tam));				
			}
			else
				erro = 0;			
			
			if(erro>0.1)
				{
					printf("Problema em y[%d,%d], erro de %lf\n",i,t,erro);
					printf("valor obtido = %lf, valor real = %lf\n",y[i],ref(x[i],t/(tam)));
				}
			*/

//
			if (t==200)
			{
				fprintf(fp, "%lf\t",x[i]);
				fprintf(fp, "%lf\n",y[i]);
			}
//		
		}
	}
	
	fclose(fp);

	return 0;
}