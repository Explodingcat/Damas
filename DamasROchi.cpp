#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Moves  //STRUCT CREADO PARA LOGRAR HACER LA MEJOR ELECCIÓN AL MOMENTO DE MOVER UNA PIEZA
{
	int	Nombre;
	int Valor;
};

void llenarTabla (int t[][12], int b[], int n[])  // VOID QUE LLENA LA TABLA CON LOS DATOS CORRESPONDIENTES PARA EL JUEGO
{
	int i, j, y=1;
  	for(i=0; i<15; i++)
  	{
  		b[i]=i+1;
  	}
  	for(i=0; i<15; i++)
  	{
  		n[i]=i+1;
  	}
  	for(i=0; i<12; i++)
  	{
  		for(j=0; j<12; j++)
	  	{
	  		if(i==0 || j==0 || i==11 ||  j==11)
	       	{
	       		t[i][j]=99;
		   	}
		   	else
		   	{
		   		t[i][j]=0;
	       	}
		  
		}
  	}
  	for(i=0; i<12; i++)
  	{
  		for(j=0; j<12; j++)
     	{
     		if( (0<i && i<4 && 0<j && j<11) || (i>7 && i<11 && 0<j && j<11) )
       		{
       			if(i%2!=0)
          		{
          			if(j%2==0)
             		{
             			t[i][j]=y;
                		y++;
             		}
          		}
          		else
          		{
          			if(j%2!=0)
             		{
             			t[i][j]=y;
                		y++;
             		}
          		}
       		}
     	}
   	}
}

void dobledamaCom(int t[][12], int d, int *dir)
{
	int a1,a2,a3,a4,a5=0,fila,colum,i,j,k;
    for(k=0;k<12;k++)
    {  	
	   for(j=0;j<12;j++)
	   {
		   if(t[k][j]==d)
		   {
		   	    a1=0;
		   	    a2=0;
		   	    a3=0;
		   	    a4=0;
		   	    i=1;
		   	    fila=k;
		   	    colum=j;
		   	    k=12;
		   	    j=12;
                while(a1==0 || a2==0 || a3==0 || a4==0)
				{
					if(fila+i<=10 && colum-i<=10 && colum-i>=1 && fila+i>=1 && a1==0)
					{
                        if(((t[fila+i][colum-i]>=1 && t[fila+i][colum-i]<=15) || (t[fila+i][colum-i]<=-1 && t[fila+i][colum-i]>=-15)) && t[fila+i+1][colum-i-1]==0)
                        {
                            a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        	k=12;
                        	j=12;
                        }

                        if((t[fila+i][colum-i]>=16 && t[fila+i][colum-i]<=30) || (t[fila+i][colum-i]<=-16 && t[fila+i][colum-i]>=-30))
                        {
                        	a1=1;
                        }
                        
						if(((t[fila+i][colum-i]>=1 && t[fila+i][colum-i]<=15) || (t[fila+i][colum-i]<=-1 && t[fila+i][colum-i]>=-15)) && t[fila+i+1][colum-i-1]!=0)
                        {
                            a1=1;
                        }
					}
                    else
                    {
                    	a1=1;
                    }
                    
                    if(fila+i<=10 && colum+i<=10 && colum+i>=1 && fila+i>=1 && a2==0)
                    {
                        if(((t[fila+i][colum+i]>=1 && t[fila+i][colum+i]<=15) || (t[fila+i][colum+i]<=-1 && t[fila+i][colum+i]>=-15)) && t[fila+i+1][colum+i+1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=2;
                        	k=12;
                        	j=12;
                        }
                        if((t[fila+i][colum+i]>=16 && t[fila+i][colum+i]<=30) || (t[fila+i][colum+i]<=-16 && t[fila+i][colum+i]>=-30))
                        {
                        	a2=1;
                        }
                        
						if(((t[fila+i][colum+i]>=1 && t[fila+i][colum+i]<=15) || (t[fila+i][colum+i]<=-1 && t[fila+i][colum+i]>=-15)) && t[fila+i+1][colum+i+1]!=0)
                        {
                            a2=1;
                        }
                        
					}
                    else
                    {
                    	a2=1;
                    }
                    
                    if(fila-i<=10 && colum-i<=10 && colum-i>=1 && fila-i>=1 && a3==0)
                    {
                        if(((t[fila-i][colum-i]>=1 && t[fila-i][colum-i]<=15) || (t[fila-i][colum-i]<=-1 && t[fila-i][colum-i]>=-15)) && t[fila-i-1][colum-i-1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=3;
                        	k=12;
                        	j=12;
                        }
                        
						if((t[fila-i][colum-i]>=16 && t[fila-i][colum-i]<=30) || (t[fila-i][colum-i]<=-16 && t[fila-i][colum-i]>=-30))
                        {
                        	a3=1;
                        }
                        
						if(((t[fila-i][colum-i]>=1 && t[fila-i][colum-i]<=15) || (t[fila-i][colum-i]<=-1 && t[fila-i][colum-i]>=-15)) && t[fila-i-1][colum-i-1]!=0)
                        {
                            a3=1;
                        }
                    }
                    else
                    {
                    	a3=1;
                    }
                    
                    if(fila-i<=10 && colum+i<=10 && colum+i>=1 && fila-i>=1 && a4==0)
                    {
                        if(((t[fila-i][colum+i]>=1 && t[fila-i][colum+i]<=15) || (t[fila-i][colum+i]<=-1 && t[fila-i][colum+i]>=-15)) && t[fila-i-1][colum+i+1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=4;
                        	k=12;
                        	j=12;
                        }
                        
                        if((t[fila-i][colum+i]>=16 && t[fila-i][colum+i]<=30) || (t[fila-i][colum+i]<=-16 && t[fila-i][colum+i]>=-30))
                        {
                        	a4=1;
                        }
                        
						if(((t[fila-i][colum+i]>=1 && t[fila-i][colum+i]<=15) || (t[fila-i][colum+i]<=-1 && t[fila-i][colum+i]>=-15)) && t[fila-i-1][colum+i+1]!=0)
                        {
                            a4=1;
                        }
                    }
                    else
                    {
                    	a4=1;
                    }
                    i++;
				}
		  }
	   }
    }
    *dir=a5;
}

void damaCom(int t[][12], int *d, int *dir)
{
	int a1,a2,a3,a4,a5=0,fila,colum,i,j,k;
    for(k=0;k<12;k++)
    {  	
	   for(j=0;j<12;j++)
	   {
		   if(t[k][j]<=-16 && t[k][j]>=-30)
		   {
		   	    *d=t[k][j];
		   	    a1=0;
		   	    a2=0;
		   	    a3=0;
		   	    a4=0;
		   	    i=1;
		   	    fila=k;
		   	    colum=j;
                while(a1==0 || a2==0 || a3==0 || a4==0)
				{
					if(fila+i<=10 && colum-i<=10 && colum-i>=1 && fila+i>=1 && a1==0)
					{
                        if(((t[fila+i][colum-i]>=1 && t[fila+i][colum-i]<=15) || (t[fila+i][colum-i]<=-1 && t[fila+i][colum-i]>=-15)) && t[fila+i+1][colum-i-1]==0)
                        {
                            a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        	k=12;
                        	j=12;
                        }

                        if((t[fila+i][colum-i]>=16 && t[fila+i][colum-i]<=30) || (t[fila+i][colum-i]<=-16 && t[fila+i][colum-i]>=-30))
                        {
                        	a1=1;
                        }
                        
						if(((t[fila+i][colum-i]>=1 && t[fila+i][colum-i]<=15) || (t[fila+i][colum-i]<=-1 && t[fila+i][colum-i]>=-15)) && t[fila+i+1][colum-i-1]!=0)
                        {
                            a1=1;
                        }
					}
                    else
                    {
                    	a1=1;
                    }
                    
                    if(fila+i<=10 && colum+i<=10 && colum+i>=1 && fila+i>=1 && a2==0)
                    {
                        if(((t[fila+i][colum+i]>=1 && t[fila+i][colum+i]<=15) || (t[fila+i][colum+i]<=-1 && t[fila+i][colum+i]>=-15)) && t[fila+i+1][colum+i+1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=2;
                        	k=12;
                        	j=12;
                        }
                        if((t[fila+i][colum+i]>=16 && t[fila+i][colum+i]<=30) || (t[fila+i][colum+i]<=-16 && t[fila+i][colum+i]>=-30))
                        {
                        	a2=1;
                        }
                        
						if(((t[fila+i][colum+i]>=1 && t[fila+i][colum+i]<=15) || (t[fila+i][colum+i]<=-1 && t[fila+i][colum+i]>=-15)) && t[fila+i+1][colum+i+1]!=0)
                        {
                            a2=1;
                        }
                        
					}
                    else
                    {
                    	a2=1;
                    }
                    
                    if(fila-i<=10 && colum-i<=10 && colum-i>=1 && fila-i>=1 && a3==0)
                    {
                        if(((t[fila-i][colum-i]>=1 && t[fila-i][colum-i]<=15) || (t[fila-i][colum-i]<=-1 && t[fila-i][colum-i]>=-15)) && t[fila-i-1][colum-i-1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=3;
                        	k=12;
                        	j=12;
                        }
                        
						if((t[fila-i][colum-i]>=16 && t[fila-i][colum-i]<=30) || (t[fila-i][colum-i]<=-16 && t[fila-i][colum-i]>=-30))
                        {
                        	a3=1;
                        }
                        
						if(((t[fila-i][colum-i]>=1 && t[fila-i][colum-i]<=15) || (t[fila-i][colum-i]<=-1 && t[fila-i][colum-i]>=-15)) && t[fila-i-1][colum-i-1]!=0)
                        {
                            a3=1;
                        }
                    }
                    else
                    {
                    	a3=1;
                    }
                    
                    if(fila-i<=10 && colum+i<=10 && colum+i>=1 && fila-i>=1 && a4==0)
                    {
                        if(((t[fila-i][colum+i]>=1 && t[fila-i][colum+i]<=15) || (t[fila-i][colum+i]<=-1 && t[fila-i][colum+i]>=-15)) && t[fila-i-1][colum+i+1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=4;
                        	k=12;
                        	j=12;
                        }
                        
                        if((t[fila-i][colum+i]>=16 && t[fila-i][colum+i]<=30) || (t[fila-i][colum+i]<=-16 && t[fila-i][colum+i]>=-30))
                        {
                        	a4=1;
                        }
                        
						if(((t[fila-i][colum+i]>=1 && t[fila-i][colum+i]<=15) || (t[fila-i][colum+i]<=-1 && t[fila-i][colum+i]>=-15)) && t[fila-i-1][colum+i+1]!=0)
                        {
                            a4=1;
                        }
                    }
                    else
                    {
                    	a4=1;
                    }
                    i++;
				}
		  }
	   }
    }
    *dir=a5;
}

int mejorOp(int t[][12], int peon)
{
	int aux[12][12];
	int aux2[12][12];
	int i, j, der=0, izq=0;
	for(i=0; i<12; i++)
	{
		for(j=0; j<12; j++)
		{
			aux[i][j]=t[i][j];
		   	aux2[i][j]=t[i][j];
	    }
	}
	for(int p=0; p<4;  p++)
	{
		for(i=0; i<12; i++)
    	{
    		for(j=0; j<12; j++)
    		{
    			if(aux[i][j]==peon)
    			{
    				if(((aux[i-1][j+1]<0 && aux[i-1][j+1]>-16) || (aux[i-1][j+1]>0 && aux[i-1][j+1]<16)) && aux[i-2][j+2]==0)
                	{
                		aux[i][j]=0;
						aux[i-1][j+1]=0;
						aux[i-2][j+2]=peon;
						der++;
						j=12;
						i=12;
                	}
                	else
                	{
                		if(((aux[i-1][j-1]<0 && aux[i-1][j-1]>-16) || (aux[i-1][j-1]>0 && aux[i-1][j-1]<16)) && aux[i-2][j-2]==0)
	                	{
	                		aux[i][j]=0;
				        	aux[i-1][j-1]=0;
					    	aux[i-2][j-2]=peon;
					    	der++;
					    	j=12;
					    	i=12;
	                	}
	                	else
	                	{
	                		j=12;
	                		i=12;
	                	}
                	}
           		}
        	}
    	}
    	for(i=0; i<12; i++)
    	{
    		for(j=0; j<12; j++)
    	 	{
    	 		if(aux2[i][j]==peon)
    			{
    				if(((aux2[i-1][j-1]<0 && aux2[i-1][j-1]>-16) || (aux2[i-1][j-1]>0 && aux2[i-1][j-1]<16)) && aux2[i-2][j-2]==0)
                	{
                		aux2[i][j]=0;
				    	aux2[i-1][j-1]=0;
						aux2[i-2][j-2]=peon;
						izq++;
						j=12;
	                	i=12;
                	}
                	else
                	{
                		if(((aux2[i-1][j+1]<0 && aux2[i-1][j+1]>-16) || (aux2[i-1][j+1]>0 && aux2[i-1][j+1]<16)) && aux2[i-2][j+2]==0)
                    	{
                    		aux2[i][j]=0;
					    	aux2[i-1][j+1]=0;
					    	aux2[i-2][j+2]=peon;
					    	izq++;
					    	j=12;
	                		i=12;
	                	}
	                	else
	                	{
	                		j=12;
	                		i=12;
	                	}
                	}
            	}
       		}
   		}
	}
	if(der>izq)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

void dobleMov(Moves pos[], int t[][12])  //VOID QUE VERIFICA SÍ EXISTEN MOVIMIENTOS DOBLES EN UN PEÓN PARA DARLE MAS PRIORIDAD
{
	int aux[12][12], i, j, l, f, op=0;
    for(l=0; l<15; l++)
	{
		if(pos[l].Valor>1)
	    {
	    	f=0;
			for(i=0; i<12; i++)
	        {
	        	for(j=0; j<12; j++)
		      	{
		      		aux[i][j]=t[i][j];
	    	   	}
	        }
			while(f==0)
			{
				for(i=0; i<12; i++)
				{
					for(j=0; j<12; j++)
					{
						if(aux[i][j]==pos[l].Nombre)
						{
							if((((aux[i-1][j+1]<0 && aux[i-1][j+1]>-16) || (aux[i-1][j+1]>0 && aux[i-1][j+1]<16)) && aux[i-2][j+2]==0) && (((aux[i-1][j-1]<0 && aux[i-1][j-1]>-16) || (aux[i-1][j-1]>0 && aux[i-1][j-1]<16)) && aux[i-2][j-2]==0) && op==0)	
	                    	{
	                    		op=mejorOp(aux,aux[i][j]);
	                    	}
	                    	else
	                    	{
	                    		if(((aux[i-1][j+1]<0 && aux[i-1][j+1]>-16) || (aux[i-1][j+1]>0 && aux[i-1][j+1]<16)) && aux[i-2][j+2]==0 && (op==1 || op==0))
						    	{
						    		aux[i][j]=0;
						    		aux[i-1][j+1]=0;
						    		aux[i-2][j+2]=pos[l].Nombre;
						    		pos[l].Valor=pos[l].Valor+2;
						    		op=0;
						    	}
						    	else
						    	{
						    		if(((aux[i-1][j-1]<0 && aux[i-1][j-1]>-16) || (aux[i-1][j-1]>0 && aux[i-1][j-1]<16)) && aux[i-2][j-2]==0 && (op==2 || op==0))
						        	{
						        		aux[i][j]=0;
							       		aux[i-1][j-1]=0;
							       		aux[i-2][j-2]=pos[l].Nombre;
							       		pos[l].Valor=pos[l].Valor+2;
							       		op=0;
                                	}
						        	else
									{
										f=1;
					            	}
					        	}
	                    	}
				    	}
					}
				}
	   		}
		}
	}
}

int valorMov(Moves posibles[], int p)  //FUNCIÓN INT DONDE EN LAS POSIBLES PIEZAS QUE SE PUEDEN MOVER HACE LA ELECCIÓN MÁS ADECUADA
{
	int i, j=0, k=0;
	int resul[15];
   	for(i=0; i<p; i++)
   	{
   		if(posibles[i].Valor>j)
	   	{
	   		j=posibles[i].Valor;
	   	}
   	}
   	for(i=0; i<p; i++)
   	{
   		if(posibles[i].Valor==j)
	   	{
	   		resul[k]=posibles[i].Nombre;
		  	k++;
	   	}
   	}
   	k= rand() % k;  //VARIABLE AUXULIAR, SI EXISTIESEN DOS O MÁS PIEZAS CON EL MISMO GRADO DE EFECTIVIDAD SELECCIONA UNA AL AZAR
   	return resul[k];  //RETORNA EL PEÓN QUE SE MOVERÁ
}

void basicMov(int t[][12], int p, int *conti)  //VOID DONDE SE HACEN LOS MOVIMIENTOS DEL PEÓN
{
	Moves pos[15];
	int i, j, r=0, comp=0, l, cont, h=0, e=0, op=0,dam=0,dir=0,fila=0,colum=0;
    for(i=0; i<15; i++)
    {
		pos[i].Valor=0;
		pos[i].Nombre=0;
	}
	damaCom(t,&dam,&dir);
	if(dir==0)
	{
	for(i=0; i<12; i++)
	{
		for(j=0; j<12; j++)
		{
			if(15<t[i][j] && t[i][j]<31)
			{
				comp=0;
				if(t[i-1][j-1]==0 || t[i-1][j+1]==0)
                {
                	pos[r].Nombre=t[i][j];
					pos[r].Valor=(pos[r].Valor)+1;
					r++;
				}
				if((((0>t[i-1][j-1] && -16<t[i-1][j-1]) || (0<t[i-1][j-1] && 16>t[i-1][j-1])) && t[i-2][j-2]==0) || (((0>t[i-1][j+1] && -16<t[i-1][j+1]) || (0<t[i-1][j+1] && 16>t[i-1][j+1])) && t[i-2][j+2]==0))
				{
					for(cont=0; cont<r; cont++)
					{
						if(pos[cont].Nombre==t[i][j])
						{
							comp=1;
							pos[cont].Valor=(pos[cont].Valor)+2;
						}
					}
					if(comp==0)
					{
						pos[r].Nombre=t[i][j];
					    pos[r].Valor=(pos[r].Valor)+2;
					    r++;
					}	    
			    }
			}	
		}
	}
	if(r>0)
	{
	    dobleMov(pos,t);
	    l=valorMov(pos,r); //VARIABLE QUE RETORNA EL NOMBRE DE LA PIEZA QUE SE MOVERÁ
        while(pos[e].Nombre!=l)
        {
    	    e++;
        }
    }
   }
   else
   {
   	 e=0;
   	 pos[e].Nombre=dam;
   	 pos[e].Valor=15;
   }
   if(pos[0].Nombre==0)
   {
   	*conti=1;
   }
   else
   {
    if(pos[e].Valor==1) //IF QUE EN EL CASO DE QUE EL PEÓN SÓLO SE PUEDA MOVER A ESPACIOS VACÍOS
	{
		for(i=0; i<12; i++)
		{
			for(j=0; j<12; j++)
			{
				if(t[i][j]==pos[e].Nombre)
				{
					if(t[i-1][j-1]==0)
					{
						t[i][j]=0;
						t[i-1][j-1]=l;
						j=12;
						i=12;
					}
					else
					{
						t[i][j]=0;
						t[i-1][j+1]=l;
						i=12;
						j=12;
					}
				}
			}
		}
	}
	if(pos[e].Valor>=4 && pos[e].Valor<=5) //IF EN EL CASO DE QUE EL PEÓN PUEDA COMER UNA VEZ
	{
		for(i=0; i<12; i++)
		{
			for(j=0; j<12; j++)
			{
				if(t[i][j]==l)
				{
					if(((t[i-1][j+1]<0 && t[i-1][j+1]>-16) || (t[i-1][j+1]>0 && t[i-1][j+1]<16)) && t[i-2][j+2]==0)
					{
						t[i][j]=0;
						t[i-1][j+1]=0;
						t[i-2][j+2]=l;
						i=12;
						j=12;
					}
					else
					{
						t[i][j]=0;
						t[i-1][j-1]=0;
						t[i-2][j-2]=l;
						i=12;
						j=12;
					}
				}
			}
		}
	}
	if(pos[e].Valor>=6 && pos[e].Valor<=14) //IF EN EL CASO CUANDO EL PEÓN PUEDE COMER MÁS DE UN ENEMIGO
	{
		while(h==0)
		{
			for(i=0; i<12; i++)
			{
				for(j=0; j<12; j++)
				{
					if(t[i][j]==l)
					{
						if((((t[i-1][j+1]<0 && t[i-1][j+1]>-16) || (t[i-1][j+1]>0 && t[i-1][j+1]<16)) && t[i-2][j+2]==0) && (((t[i-1][j-1]<0 && t[i-1][j-1]>-16) || (t[i-1][j-1]>0 && t[i-1][j-1]<16)) && t[i-2][j-2]==0) && op==0)	
	                    {
	                    	op=mejorOp(t,l);
	                    }
	                    else
	                    {
	                    	if(((t[i-1][j+1]<0 && t[i-1][j+1]>-16)||(t[i-1][j+1]>0 && t[i-1][j+1]<16)) && t[i-2][j+2]==0 && (op==1 || op==0))
						    {
						    	t[i][j]=0;
						    	t[i-1][j+1]=0;
						        t[i-2][j+2]=l;
						    	op=0;
						    }
						    else
						    {
						    	if(((t[i-1][j-1]<0 && t[i-1][j-1]>-16) || (t[i-1][j-1]>0 && t[i-1][j-1]<16)) && t[i-2][j-2]==0 && (op==2 || op==0))
						        {
						        	t[i][j]=0;
							        t[i-1][j-1]=0;
							        t[i-2][j-2]=l;
							        op=0;
                                }
						        else
								{
									h=1;
					            }
					        }
	                    }
                    }
				}
			}
        }
    }
    
    if(pos[e].Valor==15)
    {
    	
      while(dir!=0)
      {  
         for(i=0;i<12;i++)
         {
         	for(j=0;j<12;j++)
         	{
         		if(t[i][j]==dam)
         		{
         			fila=i;
         			colum=j;
         		}
            }
         }
         i=1;
         if(dir==1)
         {
            while(t[fila+i][colum-i]==0)
            {
            	i++;
            }
            t[fila+i][colum-i]=0;
            i++;
            t[fila+i][colum-i]=dam;
            t[fila][colum]=0;
            
         }
         if(dir==2)
         {
         	while(t[fila+i][colum+i]==0)
         	{
         		i++;
         	}
         	t[fila+i][colum+i]=0;
            i++;
            t[fila+i][colum+i]=dam;
            t[fila][colum]=0;
         }
         if(dir==3)
         {
         	while(t[fila-i][colum-i]==0)
         	{
         		i++;
         	}
         	t[fila-i][colum-i]=0;
            i++;
            t[fila-i][colum-i]=dam;
            t[fila][colum]=0;
         }
         if(dir==4)
         {
         	while(t[fila-i][colum+i]==0)
         	{
         		i++;
         	}
         	t[fila-i][colum+i]=0;
            i++;
            t[fila-i][colum+i]=dam;
            t[fila][colum]=0;
        }
         dir=0;
         dobledamaCom(t,dam,&dir);
      }
    }
  }
}

void sensorDama(int t[][12])  //VOID QUE VERIFICA SI ALGUN PEÓN A LLEGADO A LA ESQUINA CONTRARIA PARA CONVERTIRSE EN DAMA
{
	int j;
	for(j=0; j<12; j++)
	{
        if(0<t[10][j] && 16>t[10][j])
        {
			t[10][j]=t[10][j]*-1;
		}
	}
    for(j=0; j<12; j++)
	{
        if(15<t[1][j] && 31>t[1][j])
        {
			t[1][j]=t[1][j]*-1;
		}
	}
}

void imprimirTablero(int t[][12]) //VOID QUE IMPRIME EL TABLERO DE JUEGO
{
	ifstream archivolec("Registros.txt");
    ofstream archivoesc;
    archivoesc.open("Registros.txt", ios::app);
	int i, j, n=1;
	cout<<endl;
	cout<<endl;
	cout<<"\t            1  2  3  4  5  6  7  8  9  10"<<endl;
    archivoesc <<"\t 1  2  3  4  5  6  7  8  9  10"<<endl;
	cout<<endl;
	archivoesc<<""<<endl;
    for(i=1; i<12; i++)
    {
    	if(n!=11)
		{
			cout<<"        \t"<<n<<"\t\b\b\b\b\b";
			archivoesc<<n<<"\t";
		}
		for(j=0; j<12; j++)
      	{
      		if(0<t[i][j] && t[i][j]<16)
		  	{
		  		cout<<" x ";
			 	archivoesc<<" x ";
		  	}
		  	else
		  	{
		  		if(15<t[i][j] && t[i][j]<31)
			  	{
			  		cout<<" o ";
				  	archivoesc<<" o ";
			  	}
			  	else
			  	{
			  		if(t[i][j]==0)
				  	{
				  		if(i%2!=0)
					  	{
					  		if(j%2==0)
						  	{
						  		cout<<"▒▒▒";
						    	archivoesc<<"###";
						  	}
						  	else
						  	{
						  		cout<<"▓▓▓";
							  	archivoesc<<"---";
						  	}
					  	}
					  	else
						{
							if(j%2!=0)
						  	{
						  		cout<<"▒▒▒";
							  	archivoesc<<"###";
						  	}
						  	else
						  	{
						  		cout<<"▓▓▓";
							  	archivoesc<<"---";
						  	}
					  	}
				  	}
				  	else
				  	{
				  		     if(0>t[i][j] && t[i][j]>-16)
		  	                 {
		  		                  cout<<" X ";
			 	                  archivoesc<<" X ";
		  	                 }
		  	                 else
		  	                 {
		  		                  if(-15>t[i][j] && t[i][j]>-31)
			  	                  {
			  		                   cout<<" O ";
				   	                   archivoesc<<" O ";
			  	                    }
				  	          }
			  	     }
		  	     } 
             	if(j==11)
         	    {
         		    cout<<""<<endl;
           		    archivoesc<<""<<endl;
           		    n++;
         	    }
      	     }
         }
    }
   archivoesc.close();
   archivolec.close();
}

void Reglas(int t[][12],int p,int *h) //VOID QUE VERIFICA SI LA PIEZA QUE QUIERE MOVER EL JUGADOR EFECTIVAMENTE SE PUEDE MOVER
{
	int i, j, r=0;
	if(p>0 && p<16)
	{
		for(i=0; i<12; i++)
		{
			for(j=0; j<12; j++)
			{
				if(t[i][j]==p)
				{
					r=1;
					if(t[i+1][j+1]==0 || t[i+1][j-1]==0)
					{
						*h=1;
					}
					else
					{
						if((((t[i+1][j+1]<-15 && -31<t[i+1][j+1]) || (t[i+1][j+1]>15 && 31>t[i+1][j+1])) && t[i+2][j+2]==0) || (((t[i+1][j-1]<-15 && -31<t[i+1][j-1]) || (t[i+1][j-1]>15 && 31>t[i+1][j-1])) && t[i+2][j-2]==0))
						{
							*h=1;
						}
						else
						{
							cout<<"Esta Pieza no se puede Mover!"<<endl;
							*h=0;
						}
					}
				}
			}
		}
		if(r==0)
		{
			cout<<"Esta Pieza ya no se encuentra en la Batalla!"<<endl;
			*h=0;
		}
	}
	else
	{
		if(p<0 && p>-16)
		{
			cout<<"Haz seleccionado una Dama."<<endl;
			*h=1;
		}
		else
		{
		     cout<<"No se encuentra ninguno de tus Piezas aqui!"<<endl;
		     *h=0;
	    }
	}
}

void validador(string c, int *rval)//EVITA QUE EL USUARIO INGRESE CARÁCTERES INVÁLIDOS EN LA PETICIÓN DE COORDENADAS
{
	int len=0, k=0, l=0;
	len=c.length();
	for(int i=0; i<len; i++)
	{
		k=c[i];
		if(k<48 || k>57)
		{
			*rval=0;
          	l=1;
        }
	}
	if(l==0)
    {
    	*rval=1;
    }
    else
    {
    	cout<<"Datos ingresados invalidos!"<<endl;
    }
}
void damaReglas(int t[][12], int peon, int dir, int cant, int *moval, int *comer,int pref)
{
	int fil,colum,i,j, aux[12][12],cont=0;
	
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			aux[i][j]=t[i][j];
			if(t[i][j]==peon)
			{
				fil=i;
				colum=j;
			}
		}
	}
	
    if(dir==1)
    {
        for(i=1;i<=cant;i++)
        {
        	if(t[fil+i][colum-i]==99)
        	{
        		cout<<"Fuera del tablero"<<endl;
        		i=10;
        	}
        	else
        	{
        		if((t[fil+i][colum-i]>=1 && t[fil+i][colum-i]<=15) || (t[fil+i][colum-i]<=-1 && t[fil+i][colum-i]>=-15))
        		{
        			cout<<"No puedes pasar por encima de tus otras fichas!"<<endl;
        			i=10;
        		}
        		else
        		{
        			if(t[fil+i][colum-i]>=16 && t[fil+i][colum-i]<=30 && t[fil+i+1][colum-i-1]!=0)
        			{
        				cout<<"No se puede mover hacia ese lugar"<<endl;
        				i=10;
        			}
        			else
        			{
        				if(i==cant && t[fil+i][colum-i]!=0)
        				{
        					cout<<"Lugar Ocupado!"<<endl;
        					i=10;
        				}
        				else
        				{
        					if((t[fil+i][colum-i]>=16 && t[fil+i][colum-i]<=30) || (t[fil+i][colum-i]<=-16 && t[fil+i][colum-i]>=-30))
        					{
        						if(cont==0)
        						{
        						    cont++;
        						}
        						else
        						{
        							cout<<"No puedes comer mas de una pieza por movimiento"<<endl;
        							i=10;
        						}
        					}
        					if(i==cant)
        					{
        						if(*comer==1 && cont==0)
        						{
        							cout<<"Para un segundo movimiento debes comer obligatoriamente!"<<endl;
        						}
        						else
        						{
        							if(pref==1 && cont==0)
        							{
        								cout<<"Asegurate de comer con esta dama"<<endl;
        							}
        							else
        							{
        							
        						     t[fil+cant][colum-cant]=peon;
        						     for(i=0;i<cant;i++)
        						     {
        							     t[fil+i][colum-i]=0;
        						     }
        						     *moval=1;
        						     if(cont==1)
        						     {
        							     *comer=1;
        						     }
        						    }
        						   
        					    }
        					}
        				}
        			}
        		}
        	}
        }
    }
    else
    {
    	if(dir==2)
    	{
        for(i=1;i<=cant;i++)
        {
        	if(t[fil+i][colum+i]==99)
        	{
        		cout<<"Fuera del tablero"<<endl;
        		i=10;
        	}
        	else
        	{
        		if((t[fil+i][colum+i]>=1 && t[fil+i][colum+i]<=15) || (t[fil+i][colum+i]<=-1 && t[fil+i][colum+i]>=-15))
        		{
        			cout<<"No se puede mover hacia ese lugar"<<endl;
        			i=10;
        		}
        		else
        		{
        			if(t[fil+i][colum+i]>=16 && t[fil+i][colum+i]<=30 && t[fil+i+1][colum+i+1]!=0)
        			{
        				cout<<"No se puede mover hacia ese lugar"<<endl;
        				i=10;
        			}
        			else
        			{
        				if(i==cant && t[fil+i][colum+i]!=0)
        				{
        					cout<<"Lugar no disponible"<<endl;
        					i=10;
        				}
        				else
        				{
        					if((t[fil+i][colum+i]>=16 && t[fil+i][colum+i]<=30) || (t[fil+i][colum+i]<=-16 && t[fil+i][colum+i]>=-30))
        					{
        						if(cont==0)
        						{
        						    cont++;
        						}
        						else
        						{
        							cout<<"no puedes comer mas de una pieza por movimiento"<<endl;
        							i=10;
        						}
        					}
        					if(i==cant)
        					{
        						if(*comer==1 && cont==0)
        						{
        							cout<<"Para un segundo movimiento debes comer obligatoriamente!"<<endl;
        						}
        						else
        						{
        							if(pref==1 && cont==0)
        							{
        								cout<<"Asegurate de comer con esta dama"<<endl;
        							}
        							else
        							{
        							
        						     t[fil+cant][colum+cant]=peon;
        						     for(i=0;i<cant;i++)
        						     {
        							     t[fil+i][colum+i]=0;
        						     }
        						     *moval=1;
        						     if(cont==1)
        						     {
        							     *comer=1;
        						     }
        						   }
        						 }
        					}
        				}
        			}
        		}
        	}
        }
    	}
    	else
    	{
    		if(dir==3)
    		{
    			 for(i=1;i<=cant;i++)
                 {
        	         if(t[fil-i][colum-i]==99)
        	         {
        		         cout<<"Fuera del tablero"<<endl;
        		         i=10;
        	         }
        	         else
        	         {
        		         if((t[fil-i][colum-i]>=1 && t[fil-i][colum-i]<=15) || (t[fil-i][colum-i]<=-1 && t[fil-i][colum-i]>=-15))
        		         {
        			         cout<<"No se puede mover hacia ese lugar"<<endl;
        			         i=10;
        		         }
        		         else
        		         {
        			        if(t[fil-i][colum-i]>=16 && t[fil-i][colum-i]<=30 && t[fil-i-1][colum-i-1]!=0)
        			        {
        				        cout<<"No se puede mover hacia ese lugar"<<endl;
        				        i=10;
        			        }
        			        else
        			        {
        				         if(i==cant && t[fil-i][colum-i]!=0)
        				         {
        					         cout<<"Lugar no disponible"<<endl;
        					         i=10;
        				         }
        				         else
        				         {
        					          if((t[fil-i][colum-i]>=16 && t[fil-i][colum-i]<=30) || (t[fil-i][colum-i]<=-16 && t[fil-i][colum-i]>=-30))
        					          {
        					            	if(cont==0)
        						           {
        						               cont++;
        						           }
        						            else
        						           {
        							            cout<<"no puedes comer mas de una pieza por movimiento"<<endl;
        							            i=10;
        						           }
        					          }
        					         if(i==cant)
        					         {
        					         	  if(*comer==1 && cont==0)
        						          {
        						 	         cout<<"Para un segundo movimiento debes comer obligatoriamente!"<<endl;
        						          }
        						          else
        						          {
        						                if(pref==1 && cont==0)
        							           {
        								          cout<<"Asegurate de comer con esta dama"<<endl;
        							           }
        							           else
        							           {
        							
        						                t[fil-cant][colum-cant]=peon;
        						               for(i=0;i<cant;i++)
        						               {
        							                t[fil-i][colum-i]=0;
        						               }
        						                *moval=1;
        						               if(cont==1)
        						               {
        							               *comer=1;
        						               }
        						              }
        						          }
        					        }
        				         }
        			       }
        		        }
                     }
                 } 
    		}
    		else
    		{
    			if(dir==4)
    			{
                    for(i=1;i<=cant;i++)
                   {
        	           if(t[fil-i][colum+i]==99)
        	          {
        		           cout<<"Fuera del tablero"<<endl;
        		           i=10;
        	          }
        	          else
        	          {
        		           if((t[fil-i][colum+i]>=1 && t[fil-i][colum+i]<=15) || (t[fil-i][colum+i]<=-1 && t[fil-i][colum+i]>=-15))
        		           {
        			           cout<<"No se puede mover hacia ese lugar"<<endl;
        			           i=10;
        		           }
        		           else
        		           {
        			           if(t[fil-i][colum+i]>=16 && t[fil-i][colum+i]<=30 && t[fil-i-1][colum+i+1]!=0)
        			           {
        				          cout<<"No se puede mover hacia ese lugar"<<endl;
        				          i=10;
        			           }
        			           else
        			           {
        				             if(i==cant && t[fil-i][colum+i]!=0)
        				             {
        					             cout<<"Lugar no disponible"<<endl;
        					             i=10;
        				             } 
        				             else
        				             {
        					            if((t[fil-i][colum+i]>=16 && t[fil-i][colum+i]<=30) || (t[fil-i][colum+i]<=-16 && t[fil-i][colum+i]>=-30))
        					            {
        						             if(cont==0)
        						             {
        						                cont++;
        						             }
        						             else
        						              {
        							              cout<<"no puedes comer mas de una pieza por movimiento"<<endl;
        							              i=10;
        						              }
        					            }
        					            if(i==cant)
        					            {
        					            	if(*comer==1 && cont==0)
        						            {
        							            cout<<"Para un segundo movimiento debes comer obligatoriamente!"<<endl;
        						            }
        						            else
        						            {
        						                if(pref==1 && cont==0)
        							           {
        								          cout<<"Asegurate de comer con esta dama"<<endl;
        							           }
        							           else
        							           {
        							
        						                 t[fil-cant][colum+cant]=peon;
        						                  for(i=0;i<cant;i++)
        						                  {
        							                 t[fil-i][colum+i]=0;
        						                  }
        						                  *moval=1;
        						                  if(cont==1)
        						                  {
        						 	                 *comer=1;
        						                  }
        						               }
        						           }
        					            }
        				            }
        			           }
        		          }
        	          }
                  }
    			}
    		}
    	}
    }
}

void prefDama(int t[][12], int *pref, int dam[])
{
	int a1,a2,a3,a4,a5=0,fila,colum,i,j,k,o;
	for(i=0;i<5;i++)
	{
		dam[i]=0;
	}
    for(k=0;k<12;k++)
    {  	
	   for(j=0;j<12;j++)
	   {
		   if(t[k][j]<=-1 && t[k][j]>=-15)
		   {
	            i=1;
	            a1=0;
	            a2=0;
	            a3=0;
	            a4=0;
	            o=0;
	            fila=k;
	            colum=j;
				while(a1==0 || a2==0 || a3==0 || a4==0)
				{
					if(fila+i<=10 && colum-i<=10 && colum-i>=1 && fila+i>=1 && a1==0)
					{
                        if(((t[fila+i][colum-i]>=16 && t[fila+i][colum-i]<=30) || (t[fila+i][colum-i]<=-16 && t[fila+i][colum-i]>=-30)) && t[fila+i+1][colum-i-1]==0)
                        {
                            a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        	dam[o]=t[k][j];
                        	o++;
                        }

                        if((t[fila+i][colum-i]>=1 && t[fila+i][colum-i]<=15) || (t[fila+i][colum-i]<=-1 && t[fila+i][colum-i]>=-15))
                        {
                        	a1=1;
                        }
                        
						if(((t[fila+i][colum-i]>=16 && t[fila+i][colum-i]<=30) || (t[fila+i][colum-i]<=-16 && t[fila+i][colum-i]>=-30)) && t[fila+i+1][colum-i-1]!=0)
                        {
                            a1=1;
                        }
					}
                    else
                    {
                    	a1=1;
                    }
                    
                    if(fila+i<=10 && colum+i<=10 && colum+i>=1 && fila+i>=1 && a2==0)
                    {
                        if(((t[fila+i][colum+i]>=16 && t[fila+i][colum+i]<=30) || (t[fila+i][colum+i]<=-16 && t[fila+i][colum+i]>=-30)) && t[fila+i+1][colum+i+1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        	dam[o]=t[k][j];
                        	o++;
                        }
                        if((t[fila+i][colum+i]>=1 && t[fila+i][colum+i]<=15) || (t[fila+i][colum+i]<=-1 && t[fila+i][colum+i]>=-15))
                        {
                        	a2=1;
                        }
                        
						if(((t[fila+i][colum+i]>=16 && t[fila+i][colum+i]<=30) || (t[fila+i][colum+i]<=-16 && t[fila+i][colum+i]>=-30)) && t[fila+i+1][colum+i+1]!=0)
                        {
                            a2=1;
                        }
                        
					}
                    else
                    {
                    	a2=1;
                    }
                    
                    if(fila-i<=10 && colum-i<=10 && colum-i>=1 && fila-i>=1 && a3==0)
                    {
                        if(((t[fila-i][colum-i]>=16 && t[fila-i][colum-i]<=30) || (t[fila-i][colum-i]<=-16 && t[fila-i][colum-i]>=-30)) && t[fila-i-1][colum-i-1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        	dam[o]=t[k][j];
                        	o++;
                        }
                        
						if((t[fila-i][colum-i]>=1 && t[fila-i][colum-i]<=15) || (t[fila-i][colum-i]<=-1 && t[fila-i][colum-i]>=-15))
                        {
                        	a3=1;
                        }
                        
						if(((t[fila-i][colum-i]>=16 && t[fila-i][colum-i]<=30) || (t[fila-i][colum-i]<=-16 && t[fila-i][colum-i]>=-30)) && t[fila-i-1][colum-i-1]!=0)
                        {
                            a3=1;
                        }
                    }
                    else
                    {
                    	a3=1;
                    }
                    
                    if(fila-i<=10 && colum+i<=10 && colum+i>=1 && fila-i>=1 && a4==0)
                    {
                        if(((t[fila-i][colum+i]>=16 && t[fila-i][colum+i]<=30) || (t[fila-i][colum+i]<=-16 && t[fila-i][colum+i]>=-30)) && t[fila-i-1][colum+i+1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        	dam[o]=t[k][j];
                        	o++;
                        }
                        
                        if((t[fila-i][colum+i]>=1 && t[fila-i][colum+i]<=15) || (t[fila-i][colum+i]<=-1 && t[fila-i][colum+i]>=-15))
                        {
                        	a4=1;
                        }
                        
						if(((t[fila-i][colum+i]>=16 && t[fila-i][colum+i]<=30) || (t[fila-i][colum+i]<=-16 && t[fila-i][colum+i]>=-30)) && t[fila-i-1][colum+i+1]!=0)
                        {
                            a4=1;
                        }
                    }
                    else
                    {
                    	a4=1;
                    }
                    i++;
				}
				*pref=a5;
		  }
	  }
  }
}
void movPlayer(int t[][12], int *peon, int *comer)
{
	int fila, colum,fil,col, rval=0, moval=0, n, allval=0, nval=0, valdama=0,pref=0,dam[5],p=0,i;
	string filaxcolum, numero, nvals;
	while(allval==0)                                          //"allval" verifica que la total operacion fue un exito
	{
		while(moval==0)
		{
			rval=0;
	    	while(rval==0)                                    //"rval" se usa para verificar si los datos ingresados son numeros
	   		{
	   			cout<<"Ingrese Fila"<<endl;
	   			cin>>filaxcolum;
		   		validador(filaxcolum,&rval);
	   		}
	   		rval=0;
	   		fila=atoi(filaxcolum.c_str());
	   		while(rval==0)
	   		{
	   			cout<<"Ingrese Columna"<<endl;
	   			cin>>filaxcolum;
		   		validador(filaxcolum,&rval);
	   		}
	    	colum=atoi(filaxcolum.c_str());
	    	if(fila>=1 && fila<=10 && colum>=1 && colum<=10)
	    	{
	    		Reglas(t,t[fila][colum],&moval);                  //"moval" para verificar que el peon de las coordenadas se puede mover
	    	}
        	else
        	{
        		cout<<"Dimensiones fuera del tablero"<<endl;
        	}
        	prefDama(t,&pref,dam);
        	p=0;
        	if(pref==1)
        	{
        		for(i=0;i<5;i++)
        		{
        			if(dam[i]==t[fila][colum])
        			{
        				p=1;
        			}
        		}
        		if(p==0)
        		{
        			moval=0;
        			cout<<"Regla Preferencia Dama, debes obligatoriamente comer con la dama que lo pueda hacer"<<endl;
        		}
        	}
        }
    	if(t[fila][colum]>0)
    	{
    		rval=0;
    		*peon=t[fila][colum];
    		cout<<"Ingrese (1) para mover a la izquierda-abajo"<<endl;
    		cout<<"Ingrese (2) para mover a la derecha-abajo"<<endl;
    		cout<<"Ingrese (3) para cambiar pieza"<<endl;
    		cin>>numero;
    		validador(numero,&rval);
    		if(rval==1)
    		{
    			n=atoi(numero.c_str());
    		    if(n==2)
    		    {
    		        if(t[fila+1][colum+1]==0)
                    {
                	    allval=1;
                	    t[fila+1][colum+1]=t[fila][colum];
                	    t[fila][colum]=0;
                    }
                    else
                    {
    	                if(t[fila+2][colum+2]==0 && ((t[fila+1][colum+1]<=-16 && t[fila+1][colum+1]>=-30) || (t[fila+1][colum+1]>=16 && t[fila+1][colum+1]<=30)))
    	                {
    	            	    allval=1;
    	            	    t[fila+2][colum+2]=t[fila][colum];
    	            	    t[fila+1][colum+1]=0;
    	            	    t[fila][colum]=0;
    	            	    *comer=1;
    	                }
    	                else
    	                {
    	            	    cout<<"Movimiento Invalido"<<endl;
    	                }
                    }
    		    }
    		    else
    		    {
    			    if(n==1)
    			    {
    			        if(t[fila+1][colum-1]==0)
                        {
                    	    allval=1;
    	               	    t[fila+1][colum-1]=t[fila][colum];
    	               	    t[fila][colum]=0;
                        }
                        else
                        {
                            if(t[fila+2][colum-2]==0 && ((t[fila+1][colum-1]>=16 && t[fila+1][colum-1]<=30) || (t[fila+1][colum-1]<=-16 && t[fila+1][colum-1]>=-30)))
                            {
                        	    allval=1;
                            	t[fila+2][colum-2]=t[fila][colum];
                        	    t[fila+1][colum-1]=0;
                        	    t[fila][colum]=0;
                        	    *comer=1;
                            }
                            else
                            {
                        	    cout<<"Movimiento Invalido"<<endl;
                            }
                        }

    			    }
    			    else
    			    {
    				    if(n==3)
    				    {
    					    moval=0;
    				    }
    				    else
    				    {
    					    cout<<"Opcion Invalida"<<endl;
    				    }
    			    }
    		    }
    	    }
  	    } 
  	    else
  	    {
  	    	if(-1>=t[fila][colum] && -15<=t[fila][colum])
  	    	{
                  rval=0;
                  valdama=0;
                  nval=0;
    		      *peon=t[fila][colum];
    		      cout<<"Ingrese (1) para mover a la izquierda-abajo"<<endl;
    		      cout<<"Ingrese (2) para mover a la derecha-abajo"<<endl;
    		      cout<<"Ingrese (3) para mover a la izquierda-arriba"<<endl;
    		      cout<<"Ingrese (4) para mover a la derecha-arriba"<<endl;
    		      cout<<"Ingrese (5) para cambiar pieza"<<endl;
    		      cin>>numero;
    		      validador(numero,&rval);
    		      if(rval==1)
    		      {
    			      n=atoi(numero.c_str());
    		          if(n==2)
    		          {
    		          	     while(nval==0)
                             {
                                cout<<"Cuantos Espacios?. \t          Ingrese 0 Para Cambiar la Accion."<<endl;
                                cin>>nvals;
                                validador(nvals,&nval);
                             }
                             nval=atoi(nvals.c_str());
                             if(nval>0 && 10>nval)
                             {
                          	     if((fila+nval)<=10 && (colum+nval)<=10)
                          	     {
                                      damaReglas(t,*peon,n,nval,&valdama,&*comer,pref);
                                      if(valdama==1)
                                      {
                                      	allval=1;
                                      }
                          	     }
                          	     else
                          	     {
                          	     	cout<<"Movimiento Invalido."<<endl;
                          	     }
                             }
                             else
                             {
                          	   if(10<=nval)
                          	   {
                          		   cout<<"Opcion Invalida."<<endl;
                          	   }
                             }
    		          }
    		          else
    		          {
    			        if(n==1)
    			        {
                             while(nval==0)
                             {
                                cout<<"Cuantos Espacios?. \t          Ingrese 0 Para Cambiar la Accion."<<endl;
                                cin>>nvals;
                                validador(nvals,&nval);
                             }
                             nval=atoi(nvals.c_str());
                             if(nval>0 && 10>nval)
                             {
                          	     if((fila+nval)<=10 && (colum-nval)<=10)
                          	     {
                          	     	  damaReglas(t,*peon,n,nval,&valdama,&*comer,pref);
                                      if(valdama==1)
                                      {
                                      	allval=1;
                                      }
                          	     }
                          	     else
                          	     {
                          	     	cout<<"Movimiento Invalido."<<endl;
                          	     }
                             }
                             else
                             {
                          	   if(10<=nval)
                          	   {
                          		   cout<<"Opcion Invalida."<<endl;
                          	   }
                             }
                        }
                        
    			        else
    			        {
    				        if(n==3)
    				        {
    				        	    while(nval==0)
                                   {
                                       cout<<"Cuantos Espacios?. \t          Ingrese 0 Para Cambiar la Accion."<<endl;
                                       cin>>nvals;
                                       validador(nvals,&nval);
                                   }
                                   nval=atoi(nvals.c_str());
                                   if(nval>0 && 10>nval)
                                   {
                          	           if((fila-nval)<=10 && (colum-nval)<=10)
                          	           {
                          	     	        damaReglas(t,*peon,n,nval,&valdama,&*comer,pref);
                                            if(valdama==1)
                                            {
                                      	        allval=1;
                                            }
                          	           }
                          	           else
                          	           {
                          	            	cout<<"Movimiento Invalido."<<endl;
                          	           }
                                  }
                                   else
                                  {
                          	         if(10<=nval)
                          	        {
                          		         cout<<"Opcion Invalida."<<endl;
                          	        }
                                 }
    					        
    				        }
    				        else
    				        {
    					          if(n==4)
    					          {
    					          	    while(nval==0)
                                        {
                                            cout<<"Cuantos Espacios?. \t          Ingrese 0 Para Cambiar la Accion."<<endl;
                                            cin>>nvals;
                                            validador(nvals,&nval);
                                        }
                                         nval=atoi(nvals.c_str());
                                         if(nval>0 && 10>nval)
                                         {
                          	                if((fila-nval)<=10 && (colum+nval)<=10)
                          	                {
                          	     	             damaReglas(t,*peon,n,nval,&valdama,&*comer,pref);
                                                 if(valdama==1)
                                                 {
                                      	            allval=1;
                                                 }
                          	                }
                          	                 else
                          	                {
                          	            	      cout<<"Movimiento Invalido."<<endl;
                          	                }
                                         }
                                         else
                                         {
                          	                if(10<=nval)
                          	                {
                          		                 cout<<"Opcion Invalida."<<endl;
                          	                }
                                         }
    					          }
    					          else
    					          {
    					      	      if(n==5)
    					      	      {
    					      	      	  moval=0;
    					      	      }
    					      	      else
    					      	      {
    					      	      	  cout<<"Opcion Invalida"<<endl;
    					      	      }
    					          }
    				        }
    			        }
    		         }
    	         }
  	    	 }
  	     }
   }
} 

void doblePlayer(int t[][12], int p, int*k,int comer)
{
	int n, fila, colum,rval=0,cant=0,moval=0,nval=0;
	string srval, nvals, numero;
if(comer==1)
{
	if(p>0)
	{
	    while(rval==0)
	   {
	    cout<<"Ingrese (1) para mover a la izquierda-abajo"<<endl;
        cout<<"Ingrese (2) para mover a la derecha-abajo"<<endl;
        cout<<"Ingrese (3) para terminar turno"<<endl;
        cin>>srval;
        validador(srval, &rval);
      }
    n=atoi(srval.c_str());
    
    for(int i=0; i<12; i++)
    {
    	for(int j=0; j<12; j++)
    	{
    		if(t[i][j]==p)
    		{
    			fila=i;
    			colum=j;
    		}
    	}
    }
    if(n==2 && comer==1)
    {
    	if(t[fila+2][colum+2]==0 && ((t[fila+1][colum+1]<=-16 && t[fila+1][colum+1]>=-30) || (t[fila+1][colum+1]>=16 && t[fila+1][colum+1]<=30)))
		{
			t[fila+2][colum+2]=t[fila][colum];
    	    t[fila+1][colum+1]=0;
    	    t[fila][colum]=0;
    	}
    	else
    	{
    		cout<<"Movimiento Invalido"<<endl;
    	}
    }
    else
    {
    	if(n==1 && comer==1)
    	{
    		if(t[fila+2][colum-2]==0 && ((t[fila+1][colum-1]>=16 && t[fila+1][colum-1]<=30) || (t[fila+1][colum-1]<=-16 && t[fila+1][colum-1]>=-30)))
            {
            	t[fila+2][colum-2]=t[fila][colum];
                t[fila+1][colum-1]=0;
                t[fila][colum]=0;
            }
            else
            {
            	cout<<"Movimiento Invalido"<<endl;
            }
    	}
    	else
    	{
    		if(n==3)
    		{
    			*k=1;
    		}
    		else
    		{
    			cout<<"No puedes mover otra vez esta ficha."<<endl;
    		}
    	}
    }
   }
   else
   {
   	    	cout<<"Ingrese (1) para mover a la izquierda-abajo"<<endl;
    		cout<<"Ingrese (2) para mover a la derecha-abajo"<<endl;
    		cout<<"Ingrese (3) para mover a la izquierda-arriba"<<endl;
    		cout<<"Ingrese (4) para mover a la derecha-arriba"<<endl;
    		cout<<"Ingrese (5) para terminar turno"<<endl;
    		cin>>numero;
    		validador(numero,&rval);
    		if(rval==1)
    		{
    			n=atoi(numero.c_str());

    		    while(nval==0 && n!=5)
                {
                    cout<<"Cuantos Espacios?."<<endl;
                    cin>>nvals;
                    validador(nvals,&nval);
                }
                cant=atoi(nvals.c_str());
                damaReglas(t,p,n,cant,&moval,&comer,0);
            }
            if(n==5)
            {
            	*k=1;
            }
   }
}
else
{
	cout<<"Si no comiste una pieza no puedes mover otra vez"<<endl;
}
}





void Menu()
{
	cout<<endl;
	
	cout<<"\t\t.....:::::::DAMAS A LA CHILENA:::::::....."<<endl;
	cout<<endl;
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<"\t\t      ";
		for(int j=0;j<10;j++)
		{
			if(i%2==0)
			{
			      if(j%2==0)
			      cout<<"▓▓▓";
			      else
			     cout<<"▒▒▒";
			 }
			 else
			 {
			 	  if(j%2!=0)
			      cout<<"▓▓▓";
			      else
			     cout<<"▒▒▒";
			 }
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	cout<<"Presiona ENTER para continuar"<<endl;
	while ( getchar() != '\n');
	system("clear");
	cout<<endl;
	cout<<"INSTRUCCIONES DE JUEGO"<<endl;
	cout<<endl;
	cout<<"1.- Para poder mover tus piezas, debes ingresar las coordenadas fijadas a los costados del tablero en la cual esta posicionada la pieza que deseas mover, esto desplegara las opciones de movimiento validas para la pieza."<<endl;
	cout<<"2.- Despues de mover en cada turno se te preguntara si deseas terminar o seguir tu turno, en el caso de que veas que puedes seguir jugando continua haciendolo hasta que no lo puedas hacer."<<endl;
	cout<<"3.- Si por alguna razon dejas pasar una oportunidad de comer una pieza enemiga, tu contrincante te castigara robandote la pieza."<<endl;
	cout<<"4.- En este juego las fichas blancas estan simbolizadas por la letra 'o' y las negras con 'x', si llegan a convertirse en dama alguna de las piezas, se transformaran en letras mayusculas respectivamente."<<endl;
	cout<<"5.- En el caso de que tengas una dama y efectivamente en ese turno pueda comer, se le da prioridad a la dama sin importar que con un peon puedas comer mas piezas."<<endl;
	cout<<"6.- Siempre las fichas 'o' comenzaran los juegos."<<endl;
	cout<<"7.- En el caso de que a ambos jugadores solo les quede 1 piezas en el tablero, automaticamente se daran 3 turnos para conseguir un resultado, en el caso de que no lo haya se dara por empatada la partida."<<endl;
    cout<<""<<endl;
	cout<<"Presiona ENTER para continuar!"<<endl;
	while ( getchar() != '\n');
	system("clear");
	cout<<"HORA DE JUGAR!!"<<endl;
	
}

void sopladita(int t[][12], int peon, int comer, int pt[][12])
{
	int fila,colum,a1=0,a2=0,a3=0,a4=0,a5=0,i,j,k,q,w;
	if(comer==1)
	{
		for(i=0;i<12;i++)
		{
			for(j=0;j<12;j++)
			{
				if(t[i][j]==peon)
				{
					fila=i;
					colum=j;
					i=12;
					j=12;
				}
			}
		}
		
		if(peon>0)
		{
			if(t[fila+2][colum-2]==0 && ((t[fila+1][colum-1]>=16 && t[fila+1][colum-1]<=30) || (t[fila+1][colum-1]<=-16 && t[fila+1][colum-1]>=-30)))
            {
              t[fila][colum]=0;
              cout<<"Una de tus Fichas a sido Robada por la sopladita!!"<<endl;
              cout<<"Presiona ENTER para continuar"<<endl;
	          while ( getchar() != '\n');
	          while (getchar() != '\n');
              
            }
           
		   if(t[fila+2][colum+2]==0 && ((t[fila+1][colum+1]<=-16 && t[fila+1][colum+1]>=-30) || (t[fila+1][colum+1]>=16 && t[fila+1][colum+1]<=30)))
		   {
              t[fila][colum]=0;
              cout<<"Una de tus Fichas a sido Robada por la sopladita!!"<<endl;
              cout<<"Presiona ENTER para continuar......."<<endl;
              while ( getchar() != '\n');
              while (getchar() != '\n');
    	   }
		}
		else
		{
			if(peon<0)
			{
				i=1;
				while(a1==0 || a2==0 || a3==0 || a4==0)
				{
					if(fila+i<=10 && colum-i<=10 && colum-i>=1 && fila+i>=1 && a1==0)
					{
                        if(((t[fila+i][colum-i]>=16 && t[fila+i][colum-i]<=30) || (t[fila+i][colum-i]<=-16 && t[fila+i][colum-i]>=-30)) && t[fila+i+1][colum-i-1]==0)
                        {
                            a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        }

                        if((t[fila+i][colum-i]>=1 && t[fila+i][colum-i]<=15) || (t[fila+i][colum-i]<=-1 && t[fila+i][colum-i]>=-15))
                        {
                        	a1=1;
                        }
                        
						if(((t[fila+i][colum-i]>=16 && t[fila+i][colum-i]<=30) || (t[fila+i][colum-i]<=-16 && t[fila+i][colum-i]>=-30)) && t[fila+i+1][colum-i-1]!=0)
                        {
                            a1=1;
                        }
					}
                    else
                    {
                    	a1=1;
                    }
                    
                    if(fila+i<=10 && colum+i<=10 && colum+i>=1 && fila+i>=1 && a2==0)
                    {
                        if(((t[fila+i][colum+i]>=16 && t[fila+i][colum+i]<=30) || (t[fila+i][colum+i]<=-16 && t[fila+i][colum+i]>=-30)) && t[fila+i+1][colum+i+1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        }
                        if((t[fila+i][colum+i]>=1 && t[fila+i][colum+i]<=15) || (t[fila+i][colum+i]<=-1 && t[fila+i][colum+i]>=-15))
                        {
                        	a2=1;
                        }
                        
						if(((t[fila+i][colum+i]>=16 && t[fila+i][colum+i]<=30) || (t[fila+i][colum+i]<=-16 && t[fila+i][colum+i]>=-30)) && t[fila+i+1][colum+i+1]!=0)
                        {
                            a2=1;
                        }
                        
					}
                    else
                    {
                    	a2=1;
                    }
                    
                    if(fila-i<=10 && colum-i<=10 && colum-i>=1 && fila-i>=1 && a3==0)
                    {
                        if(((t[fila-i][colum-i]>=16 && t[fila-i][colum-i]<=30) || (t[fila-i][colum-i]<=-16 && t[fila-i][colum-i]>=-30)) && t[fila-i-1][colum-i-1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        }
                        
						if((t[fila-i][colum-i]>=1 && t[fila-i][colum-i]<=15) || (t[fila-i][colum-i]<=-1 && t[fila-i][colum-i]>=-15))
                        {
                        	a3=1;
                        }
                        
						if(((t[fila-i][colum-i]>=16 && t[fila-i][colum-i]<=30) || (t[fila-i][colum-i]<=-16 && t[fila-i][colum-i]>=-30)) && t[fila-i-1][colum-i-1]!=0)
                        {
                            a3=1;
                        }
                    }
                    else
                    {
                    	a3=1;
                    }
                    
                    if(fila-i<=10 && colum+i<=10 && colum+i>=1 && fila-i>=1 && a4==0)
                    {
                        if(((t[fila-i][colum+i]>=16 && t[fila-i][colum+i]<=30) || (t[fila-i][colum+i]<=-16 && t[fila-i][colum+i]>=-30)) && t[fila-i-1][colum+i+1]==0)
                        {
                        	a1=1;
                        	a2=1;
                        	a3=1;
                        	a4=1;
                        	a5=1;
                        }
                        
                        if((t[fila-i][colum+i]>=1 && t[fila-i][colum+i]<=15) || (t[fila-i][colum+i]<=-1 && t[fila-i][colum+i]>=-15))
                        {
                        	a4=1;
                        }
                        
						if(((t[fila-i][colum+i]>=16 && t[fila-i][colum+i]<=30) || (t[fila-i][colum+i]<=-16 && t[fila-i][colum+i]>=-30)) && t[fila-i-1][colum+i+1]!=0)
                        {
                            a4=1;
                        }
                    }
                    else
                    {
                    	a4=1;
                    }
                    i++;
				}
				if(a5==1)
				{
					t[fila][colum]=0;
					cout<<"Una de tus Fichas a sido Robada por la sopladita!!"<<endl;
					cout<<"Presiona ENTER para continuar"<<endl;
	                while ( getchar() != '\n');
	                while (getchar() != '\n');
				}
			}
		}
		
	}
	else
	{
			for(k=0;k<12;k++)
			{
				for(j=0;j<12;j++)
				{
					if(pt[k][j]>=1 && pt[k][j]<=15)
					{
					    if(pt[k+2][j-2]==0 && ((pt[k+1][j-1]>=16 && pt[k+1][j-1]<=30) || (pt[k+1][j-1]<=-16 && pt[k+1][j-1]>=-30)))
                        {
                        	if(peon==pt[k][j])
                        	{
                        	   pt[k][j]=0;
                        	   for(q=1;q<12;q++)
  	                           {
  	                             for(w=1;w<12;w++)
  	                             {
  	   	                             t[q][w]=pt[q][w];
  	                             }
  	                           }
     	                    }
     	                    else
     	                    {
     	                    	t[k][j]=0;
     	                    }
                           k=12;
                           j=12;
                           cout<<"Una de tus Fichas a sido Robada por la sopladita!"<<endl;
                           cout<<"Presiona ENTER para continuar"<<endl;
	                       while ( getchar() != '\n');
	                       while (getchar() != '\n');
                       }
           
		               if(pt[k+2][j+2]==0 && ((pt[k+1][j+1]<=-16 && pt[k+1][j+1]>=-30) || (pt[k+1][j+1]>=16 && pt[k+1][j+1]<=30)))
		                {
                        	if(peon==pt[k][j])
                        	{
                        	   pt[k][j]=0;
                        	   for(q=1;q<12;q++)
  	                           {
  	                             for(w=1;w<12;w++)
  	                             {
  	   	                             t[q][w]=pt[q][w];
  	                             }
  	                           }
     	                    }
     	                    else
     	                    {
     	                    	t[k][j]=0;
     	                    }
                            k=12;
                            j=12;
                            cout<<"Una de tus Fichas a sido Robada por la sopladita!"<<endl;
                            cout<<"Presiona ENTER para continuar"<<endl;
	                        while ( getchar() != '\n');
	                        while (getchar() != '\n');
    	                }
    	           }
			   }
			}
	   
	}
}

int terminoJuego(int t[][12])
{
	int i,j,contn=0,contb=0;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if((t[i][j]>=1 && t[i][j]<=15) || (t[i][j]<=-1 && t[i][j]>=-15))
			{
				contn++;
			}
			else
			{
				if((t[i][j]>=16 && t[i][j]<=30) || (t[i][j]<=-16 && t[i][j]>=-30))
				{
					contb++;
				}
			}
		}
	}
	if(contn==1 && contb==1)
	{
		return 1;
	}
	else
	{
		if(contn==0)
		{
			return 2;
		}
		else
		{
			if(contb==0)
			{
				return 4;
			}
			else
			{
				return 0;
			}
		}
	}
}

int main()
{
	int tablero [12][12];
   	int ptablero[12][12];
   	int blancas [15];
   	int negras [15];
   	int n=2, conf, peon, rval, comer=0,conti=0,i,j,again=1,ulturn=3,termino=0,againval=0;
   	string val, confirmar, agains;
    while(again==1)
    {
    	Menu();
    	ifstream archivolec("Registros.txt");
   	    ofstream archivoesc;
   	    archivoesc.open("Registros.txt",ios::app);
   	    archivoesc <<"----------------------INICIO JUEGO----------------------"<<endl;
   	    archivoesc <<""<<endl;
   	    archivoesc.close();
   	    archivolec.close();
   	    llenarTabla(tablero,blancas,negras);
   	    imprimirTablero(tablero);
    	while(n!=3 && ulturn!=0)
    	{
    		cout<<"Turno de los blancos (cpu)"<<endl;
            basicMov(tablero,1,&conti);
            cout<<"Presiona ENTER para continuar"<<endl;
	        while ( getchar() != '\n');
	        while (getchar() != '\n');
            system("clear");
            sensorDama(tablero);
            imprimirTablero(tablero);
            if(conti==1)
       	    {
       	    	ifstream archivolec("Registros.txt");
   	            ofstream archivoesc;
   	            archivoesc.open("Registros.txt",ios::app);
   	            archivoesc <<"----------------------TERMINO DE JUEGO----------------------"<<endl;
   	            archivoesc <<"LAS NEGRAS GANAN!"<<endl;
   	            archivoesc <<""<<endl;
   	            archivoesc.close();
   	            archivolec.close();
       		    n=3;
       		    cout<<"Blancas se ha quedado sin movimientos, Negras Ganan"<<endl;
       	    }
       	    else
       	    {
       	    	   comer=0;
  		           conf=0;
  	               for(i=1;i<12;i++)
  	               {
  	                   for(j=1;j<12;j++)
  	                   {
  	   	                   ptablero[i][j]=tablero[i][j];
  	                   }
                	}
                	cout<<"Turno de las Negras (Jugador)"<<endl;
                    movPlayer(tablero,&peon,&comer);
                    system("clear");
                    sensorDama(tablero);
  	  	            imprimirTablero(tablero);
  	  	            while(conf!=1)
  	  	            {
  	  	 	           cout<<"Ingresa (1) para ACABAR EL TURNO"<<endl;
  	  	 	           cout<<"Ingresa (2) para SEGUIR EL TURNO"<<endl;
  	  	 	           rval=0;
  	  	 	           while(rval==0)
  	  	 	           {
	     	               cin>>confirmar;
	     	               validador(confirmar,&rval);
	     	           }
	     	            conf=atoi(confirmar.c_str());
	     	            if(conf==2)
	     	           {
	     		           doblePlayer(tablero,peon,&conf,comer);
	     		           cout<<"Presiona ENTER para continuar"<<endl;
	                       while (getchar() != '\n');
	                       while (getchar() != '\n');
	     		           system("clear");
	     		           imprimirTablero(tablero);
	     	           }
	     	           else
	     	           {
	     		           sopladita(tablero,peon,comer,ptablero);
	     		           system("clear");
	     		           imprimirTablero(tablero);
	     		           if(conf<1 || conf>2)
	     		           {
	     			           cout<<"Opcion Invalida"<<endl;
	     		           }
	     	           }
	  	            }
       	      }
       	      if(termino==0)
       	      {
       	      	termino=terminoJuego(tablero);
       	      }
       	      else
       	      {
       	      	if(termino==1)
       	      	{
       	      		cout<<"Ambos Poseen 1 Ficha, turnos para terminar en empate: "<<ulturn<<endl;
       	      		ulturn--;
       	      	}
       	      	else
       	      	{
       	      		if(termino==2)
       	      		{
       	      			ifstream archivolec("Registros.txt");
   	                    ofstream archivoesc;
   	                    archivoesc.open("Registros.txt",ios::app);
   	                    archivoesc <<"----------------------TERMINO DE JUEGO----------------------"<<endl;
   	                    archivoesc <<"LAS BLANCAS GANAN!"<<endl;
   	                    archivoesc <<""<<endl;
   	                    archivoesc.close();
   	                    archivolec.close();
       		            n=3;
       		            cout<<"Negras se ha quedado sin movimientos, Blancas Ganan"<<endl;
       	      		}
       	      		else
       	      		{
       	      			if(termino==4 && conti!=1)
       	      			{
       	      				ifstream archivolec("Registros.txt");
   	                        ofstream archivoesc;
   	                        archivoesc.open("Registros.txt",ios::app);
   	                        archivoesc <<"----------------------TERMINO DE JUEGO----------------------"<<endl;
   	                        archivoesc <<"LAS NEGRAS GANAN!"<<endl;
   	                        archivoesc <<""<<endl;
   	                        archivoesc.close();
   	                        archivolec.close();
       		                n=3;
       		                cout<<"BLANCAS se ha quedado sin movimientos, NEGRAS Ganan"<<endl;
       	      			}
       	      		}
       	      	 }
       	       }
       	}
       	if(termino==1 && ulturn<=0)
       	{
       		    ifstream archivolec("Registros.txt");
   	            ofstream archivoesc;
   	            archivoesc.open("Registros.txt",ios::app);
   	            archivoesc <<"----------------------TERMINO DE JUEGO----------------------"<<endl;
   	            archivoesc <<"EMPATE!"<<endl;
   	            archivoesc <<""<<endl;
   	            archivoesc.close();
   	            archivolec.close();
       		    cout<<"No se a podido decidir al ganador!,EMPATE"<<endl;
        }
        rval=0;
        while(rval==0)
  	  	{
  	  	 	cout<<"Jugar Otra Vez? Si (1)  No (num!=1)"<<endl;
            cin>>agains;
	        validador(agains,&rval);
	    }
	    again=atoi(agains.c_str());
    }
    cout<<"Diseñado por Roberto Rocuant Venegas, Jonathan Acuña Herrera y  Felipe Roa Aguilera"<<endl;
    cout<<"GRACIAS POR JUGAR :)"<<endl;
}
