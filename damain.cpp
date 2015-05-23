#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct Moves  //STRUCT CREADO PARA LOGRAR HACER LA MEJOR ELECCION AL MOMENTO DE MOVER UNA PIEZA
{
	int	Nombre;
	int Valor;
};

void llenartabla(int t[][12],int b[],int n[])  //LLENA LA TABLA CON LOS DATOS CORRESPONDIENTES PARA EL JUEGO
{
  int i,j,y=1;
  for(i=0;i<15;i++)
  {
     b[i]=i+1;
  }
  for(i=0;i<15;i++)
  {
     n[i]=i+1;
  }
  for(i=0;i<12;i++)
  {
	  for(j=0;j<12;j++)
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
  for(i=0;i<12;i++)
  {
     for(j=0;j<12;j++)
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

void dobleMov(Moves pos[], int t[][12])  //VERIFICA SI EXISTEN MOVIMIENTOS DOBLES EN UN PEON PARA DARLE MAS PRIORIDAD
{
	int aux[12][12],i,j,l,f;
    
	for(l=0;l<15;l++)
	{  

	    if(pos[l].Valor>1)
	    {
			f=0;
			for(i=0;i<12;i++)
	        {
		      for(j=0;j<12;j++)
		      {
			    aux[i][j]=t[i][j];
	    	   }
	         }

		    while(f==0){
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
				{

		            
					if(aux[i][j]==pos[l].Nombre)
					{
	                  
						if(aux[i-1][j+1]>0 && aux[i-1][j+1]<16 && aux[i-2][j+2]==0)
						{
							aux[i][j]=0;
							aux[i-1][j+1]=0;
							aux[i-2][j+2]=pos[l].Nombre;
							pos[l].Valor=pos[l].Valor+2;
						}
						else
						{
							if(aux[i-1][j-1]>0 && aux[i-1][j-1]<16 && aux[i-2][j-2]==0)
						    {   
						       aux[i][j]=0;
							   aux[i-1][j-1]=0;
							   aux[i-2][j-2]=pos[l].Nombre;
							   pos[l].Valor=pos[l].Valor+2;

						     }
						   else{
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

int valorMov(Moves posibles[], int p)  //DENTRO DE LAS POSIBLES PIEZAS QUE SE PUEDEN MOVER HACE UNA ELECCION DE LA MAS ADECUADA
{
	int i, j=0,k=0;
	int resul[15];
   for(i=0;i<p;i++)
   {
	   if(posibles[i].Valor>j)
	   {
		   j=posibles[i].Valor;
	   }
   }
   for(i=0;i<p;i++)
   {
	   if(posibles[i].Valor==j)
	   {
		  resul[k]=posibles[i].Nombre;
		  k++;
	   }
   }
   k= rand() % k;  //SI EXISTIESEN 2 O MAS PIEZAS CON EL MISMO GRADO DE EFECTIVIDAD SELECCIONA UNA AL AZAR
   
   return resul[k];  //RETORNA EL PEON QUE SE MOVERA
}

void basicMov(int t[][12],int p)  //MOVIMIENTOS DEL PEON
{
	Moves pos[15];
	int i,j,r=0,n,comp=0,l,cont,h=0;
    for(i=0;i<15;i++)
    {
		pos[i].Valor=0;
	}
	if(p==1)
	{
		for(i=0;i<12;i++)
		{
			for(j=0;j<12;j++)
			{
				if(15<t[i][j] && t[i][j]<31)
				{
				   if(t[i-1][j-1]==0 || t[i-1][j+1]==0)
                   {
					   pos[r].Nombre=t[i][j];
					   pos[r].Valor=(pos[r].Valor)+1;
					   r++;
				   }

				   if((0<t[i-1][j-1] && 16>t[i-1][j-1] && t[i-2][j-2]==0) || (0<t[i-1][j+1] && 16>t[i-1][j+1] && t[i-2][j+2]==0))
				   {
					   for(cont=0;cont<r;cont++)
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
		dobleMov(pos,t);
		l=valorMov(pos,r);
		for(i=0;i<r;i++)
		{
			if(pos[i].Nombre==l)
			{
				if(pos[i].Valor>1 && pos[i].Valor<6)
				{
					n=2;
				}
				else
				{
					if(pos[i].Valor>5)
					{
						n=3;
					}
					else
					n=rand() % 2;
				}
			}
		}

	    if(n==0)
		{
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
				{
					if(t[i][j]==l)
					{
						if(t[i-1][j-1]==0)
						{
							t[i][j]=0;
							t[i-1][j-1]=l;
						}
						else{
						    t[i][j]=0;
						    t[i-1][j+1]=l;
						}
					}
				}
			}
		}
		if(n==1)
		{
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
				{
					if(t[i][j]==l)
					{
						if(t[i-1][j+1]==0)
						{
						    t[i][j]=0;
							t[i-1][j+1]=l;						
						}
						else{
							t[i][j]=0;
						    t[i-1][j-1]=l;
						}
					}
				}
			}
		}
		if(n==2)
		{
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
				{
					if(t[i][j]==l)
					{
						if(t[i-1][j+1]>0 && t[i-1][j+1]<16 && t[i-2][j+2]==0)
						{
							t[i][j]=0;
							t[i-1][j+1]=0;
							t[i-2][j+2]=l;
						}
						else
						{
						    t[i][j]=0;
							t[i-1][j-1]=0;
							t[i-2][j-2]=l;
						}
					}
				}
			}
		}
		if(n==3)
		{
		  while(h==0){
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
				{

		            
					if(t[i][j]==l)
					{
	                  
						if(t[i-1][j+1]>0 && t[i-1][j+1]<16 && t[i-2][j+2]==0)
						{
							t[i][j]=0;
							t[i-1][j+1]=0;
							t[i-2][j+2]=l;
						}
						else
						{
							if(t[i-1][j-1]>0 && t[i-1][j-1]<16 && t[i-2][j-2]==0)
						    {   
						       t[i][j]=0;
							   t[i-1][j-1]=0;
							   t[i-2][j-2]=l;

						     }
						   else{
						   h=1;
					           }
					   }
					
				  }
				}
			}
	   	  }
        }
   }
}

void sensorDama(int t[][12])  //VERIFICA SI ALGUN PEON A LLEGADO A LA ESQUINA CONTRARIA PARA CONVERTIRSE EN DAMA
{
	int j;
	for(j=0;j<12;j++)
	{
        if(0<t[10][j] && 16>t[10][j])
        {
			t[10][j]=t[10][j]*-1;
		}
	}
    for(j=0;j<12;j++)
	{
        if(15<t[1][j] && 31>t[1][j])
        {
			t[1][j]=t[1][j]*-1;
		}
	}
	
}


int JuegoTerminado(int b[],int n[]) //VERIFICA SI EL JUEGO TERMINO O NO
{
   int i=0;
   int c=0;
   for(i=0;i<15;i++)
   {
     if(b[i]!=0)
     {
        c=1;
     }
   }
   if(c==1)
   {
     for(i=0;i<15;i++)
     {
       if(n[i]!=0)
       {
         c=2;
       }
     }
   }
   if(c==0)
   {
     return 1;
   }
   if(c==1)
   {
     return 2;
   }
   if(c==2)
   {
     return 0;
   }
   return 5;
}

void imprimirTablero(int t[][12]) //IMPRIME EL TABLERO DE JUEGO
{
	int i,j,n=1;
	cout<<"\t\b\b\b\b 1  2  3  4  5  6  7  8  9  10"<<endl;
	cout<<""<<endl;
    for(i=1;i<12;i++)
    {   if(n!=11)
		cout<<n<<"\t\b\b\b\b";
		
      for(j=0;j<12;j++)
      {
		  if(0<t[i][j] && t[i][j]<16)
		  {
		  	if(t[i][j]<10 && t[i][j]>0){

		    	cout<<"00"<<t[i][j];
		    }
		  	else{
		  	cout<<"0"<<t[i][j];
		    }
		  }
		  else
		  {
			  if(15<t[i][j] && t[i][j]<31)
			  {
				  cout<<"0"<<t[i][j];
			  }
			  else
			  {
				  if(t[i][j]==0)
				  {
					  if(i%2!=0)
					  {
						  if(j%2==0)
						  {
						    cout<<"###";
						  }
						  else
						  {
							  cout<<"   ";
						  }
					  }
					  else{
						  if(j%2!=0)
						  {
							  cout<<"###";
						  }
						  else
						  {
							  cout<<"   ";
						  }
					  }
				  }
			  }
		  } 
          if(j==11)
         {
           cout<<""<<endl;
           n++;
         }
      }
   }
}

void Reglas(int t[][12],int p,int tip,int *h) //VERIFICA SI LA PIEZA QUE QUIERE MOVER EL JUGADOR EFECTIVAMENTE SE PUEDE MOVER
{
	int i,j,r=0;
	if(tip==2)
	{
		if(p>0 && p<16)
		{
			for(i=0;i<12;i++)
			{
				for(j=0;j<12;j++)
				{
					if(t[i][j]==p)
					{
						r=1;
						if(t[i+1][j+1]==0 || t[i+1][j-1]==0)
						{
							cout<<"Hacia donde lo deseas mover?"<<endl;
							*h=1;
						}
						else
						{
							if((t[i+1][j+1]>15 && 31>t[i+1][j+1] && t[i+2][j+2]==0) || (t[i+1][j-1]>15 && 31>t[i+1][j-1] && t[i+2][j-2]==0))
							{
								cout<<"Hacia donde lo deseas mover?"<<endl;
								*h=1;
							}
							else
							{
								system("cls");
							    imprimirTablero(t);
								cout<<"Este Peon no se puede Mover!"<<endl;
								*h=0;
							}
						}
					}
				}
			}
			if(r==0)
			{
				system("cls");
				imprimirTablero(t);
				cout<<"Este Peon ya no se encuentra en la Batalla!"<<endl;
				*h=0;
		    }
		}
		else
		{
			system("cls");
			imprimirTablero(t);
			cout<<"Este Peon No te Pertenece!"<<endl;
			cout<<"Escoje otro!(01-15)"<<endl;
			*h=0;
		}
	}
}

void validador(string c, int *rval)
{
	int len=0,k=0,l=0;
	len=c.length();
	for(int i=0;i<len;i++)
	{
		k=c[i];
		if(k<48 || k>57)
		{
          *rval=0;
          l=1;
          
		}
	}
	if(l==0)
    *rval=1;
    else
    cout<<"Datos ingresados invalidos!"<<endl;
}

void movPlayer(int t[][12],int peon,int *conf)
{
	int fila,colum,h=0,i,j,rval,rval2;
	string lel;
	string fil,col;
	while(h==0 && *conf==0){
		rval=0;
		rval2=0;
	    while(rval==0){
	     cout<<"Ingresa la fila:"<<endl;
	     cin>>fil;
	     validador(fil,&rval);
	    }
	    while(rval2==0)
	    {
	     cout<<"Ingresa la columna"<<endl;
	     cin>>col;
	     validador(col,&rval2);
	    }
	fila=atoi(fil.c_str());
	colum=atoi(col.c_str());
	if(fila<11 && fila>0 && colum<11 && colum>0)
	{
	    if(t[fila][colum]==0)
		{
	    
	     for(i=0;i<12;i++)
	     {
		     for(j=0;j<12;j++)
	     	{
		    	if(peon==t[i][j])
	     		{   
                    if((fila==i+1 && colum==j+1)|| (fila==i+1 && colum==j-1))
                    {
                    	t[i][j]=0;
                    	t[fila][colum]=peon;
                    	j=12;
                    	i=12;
                    	h=1;
                        system("cls");
                    	
                    }
                    else
                    {
                    	if(t[i+1][j+1]>15 && t[i+1][j+1]<31 && i+2==fila && colum==j+2)
                    	{
                    		t[i][j]=0;
                    		t[i+1][j+1]=0;
                        	t[fila][colum]=peon;
                        	j=12;
                        	i=12;
                        	h=1;
                        	system("cls");
                    	}
                    	else
                    	{
                    		if((t[i+1][j-1]>15 && t[i+1][j-1]<31 && i+2==fila && colum==j-2))
                    		{
                    			t[i][j]=0;
                    	    	t[i+1][j-1]=0;
                            	t[fila][colum]=peon;
                            	j=12;
                            	i=12;
                            	h=1;
                            	system("cls");
                    		}
                    		else
                    		{
                    			system("cls");
							    imprimirTablero(t);
							    cout<<peon<<endl;
                    			cout<<"Este peon no se puede mover a esta locacion!"<<endl;
                    			cout<<"Deseas Cambiar la Pieza?(S/N)"<<endl;
                    			cin>>lel;
                    			lel=toupper(lel[0]);
                    	         if(lel=="S")
                    			{
                    				*conf=1;
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
	   	  system("cls");
		  imprimirTablero(t);
		  cout<<peon<<endl;
		  cout<<"Este lugar esta ocupado!"<<endl;
		  cout<<"Deseas Mover Otra Pieza?(S/N)"<<endl;
	   	  cin>>lel;
	      lel=toupper(lel[0]);
	     if(lel=="S")
         {
            *conf=1;
         }
	   }
    }
     else
    {
      system("cls");
	  imprimirTablero(t);
	  cout<<peon<<endl;
   	  cout<<"Dimensiones fuera del tablero!"<<endl;
   	  cout<<"Deseas Mover Otra Pieza?(S/N)"<<endl;
      cin>>lel;
   	  lel=toupper(lel[0]);
	  if(lel=="S")
      {
        *conf=1;
      }
    }
   }
}


int main()
{
   int tablero [12][12];
   int blancas [15];
   int negras [15];
   int x=3,n,h,f,conf,rval;
   string val;

   llenartabla(tablero,blancas,negras);
   imprimirTablero(tablero);
  while(n!=3)
  {
  	sensorDama(tablero);
   	 h=0;
   	 conf=0;
	 while(h==0)
	 {

	 	rval=0;
	 	while(rval==0){
           cout<<"Que Pieza desea mover?"<<endl;
		   cin>>val;
		   validador(val,&rval);
	     }
		f=atoi(val.c_str());
	 	Reglas(tablero,f,2,&h);
     }
     	 	   imprimirTablero(tablero);
	 
	 movPlayer(tablero,f,&conf);
	 if(conf==0)
	 {
	   basicMov(tablero,1);
       imprimirTablero(tablero);
     }
  }
         
   
   while(x==0)
   {
     
     x=JuegoTerminado(blancas,negras);
   }
   if(x==1)
   {
     cout<<"Juego Terminado!"<<endl;
     cout<<"NEGROS GANAN!"<<endl;
   }
   if(x==2)
   {
     cout<<"Juego Terminado!"<<endl;
     cout<<"BLANCOS GANAN!"<<endl;    
   }
}
