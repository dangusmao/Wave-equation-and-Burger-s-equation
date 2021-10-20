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
	
	fp = fopen("bt5.dat", "w" );

	int i,t;

	double tam=TAM, d=1/(tam);

	double x[TAM],y[TAM];

	for (i = 0; i < TAM; ++i)
	{
		x[i]=i/(tam);
		y[i]=1+sin(2*pi*x[i]);

//		fprintf(fp, "%lf\t",x[i]);
//		fprintf(fp, "%lf\n",y[i]);

	}
	
	for (t = 1; t < TAM; ++t)
	{
		for (i = 0; i < TAM; ++i)
		{
			//[ ( TAM + ( index % TAM ) ) % TAM ]// truque da condição de contorno periódica
			
			y[i]=y[i]-0.1*y[i]*((y[i]-y[ ( TAM + i-1) % TAM  ])); // parte B - método upwind
//			
			if (t==999)
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