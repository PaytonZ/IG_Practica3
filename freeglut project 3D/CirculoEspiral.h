/********************************************************************************
*																				*
*		Practica 3 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/


#include "Malla.h"
#include "Lapiz.h"
#include <cmath>

extern const GLdouble M_PI;

class CirculoEspiral 
{
public:
	GLint nP;
	GLint nQ;
	GLdouble r;



	Malla *espiral;
	//num Q num figuras
	// num L como aproximamos el circulo
	CirculoEspiral(int radio, int numL, int numQ)
	{
		nP=numL;
		nQ=numQ;
		int numVertices= numQ*numL;
		int numNorCaras= numVertices-nP; //Hay una normal por cara.
		espiral = new Malla(numVertices,numNorCaras,numNorCaras);

		//Calculo de la cara inferior e insertamos los vertices en la malla.
		PV3D centro = PV3D(0,0,0,false);
		GLdouble alfa=360.00/(GLdouble)numL;
		GLdouble beta= (180.00-alfa)/2;
		GLdouble lado= 2*radio*cos(M_PI*beta/180.00);
		Lapiz l (centro,0.0);
		l.forward(radio,false);
		espiral->anadirVertice(new PV3D (l.pos.x,l.pos.z,0,false));
		l.dir=180-beta;
		for (int h=1; h< numL; h++)
		{
			l.forward(lado,false);
			l.turnTo(alfa);
			espiral->anadirVertice(new PV3D (l.pos.x,l.pos.z,0,false));
		}
		/* f -------------------> f' ----------> f''
		x(t) = cos(t) + t*sen(t)  --> t cos(t) --> cos(t) - t * sin(t)
		y(t) = 0 ----------------------> 0 ---------> 0 
		z(t) = sen(t) – t*cos(t)  --> t sin(t) -> sen`(t)  + t *cos(t)
		*/

		/*
		0     1       2    3
		N(t), B(t), T(t), C(t))
		N(t) es B(t)* t(t)
		El vector T(t) es la normalización de C’(t).
		El vector binormal B(t) -> c'(t) *c''(t)
		t(t)
		*/

		double tiempo = 0.2;
		for(int i=0; i < numQ-1 ; i++)
		{
			//Transformar los puntos
			for(int w=0; w<numL; w++)
			{
				PV3D c (cos(tiempo) + tiempo*sin(tiempo), 0 , sin(tiempo) - tiempo*cos(tiempo),false);
				PV3D cprimera(tiempo*cos(tiempo) ,0 , tiempo*sin(tiempo),true );
				PV3D csegunda(cos(tiempo) - tiempo*sin(tiempo),0,sin(tiempo) +tiempo*cos(tiempo),true);
				PV3D b = cprimera * csegunda;
				b=b.normalizarVector();
				PV3D t= cprimera.normalizarVector();
				PV3D n = b * t;		
				PV3D* punto = espiral->vertice[w];	
				double ax=n.x * punto->x +  b.x * punto->y + t.x * punto->z + c.x;
				double ay=n.y * punto->x +  b.y * punto->y + t.y * punto->z + c.y;
				double az=n.z * punto->x +  b.z * punto->y + t.z * punto->z + c.z;
				espiral->anadirVertice(new PV3D(n.x * punto->x +  b.x * punto->y + t.x * punto->z + c.x ,n.y * punto->x +  b.y * punto->y + t.y * punto->z + c.y ,n.z * punto->x +  b.z * punto->y + t.z * punto->z + c.z ,	false));
			}
			//Inicializo las caras
			for(int j=numL*(i); j <numL*(i+1); j++)
			{
				Cara* caraAnadir= new Cara(4); //metemos un 4 por que las caras son rectangulos.
				int debug=j;
				PV3D* debugPuntos=espiral->vertice[debug];
				caraAnadir->setValor(0,j,j);

				debug=j+numL;
				debugPuntos= espiral->vertice[debug];
				caraAnadir->setValor(1,debug,j);

				debug=((j+1)%numL)+numL*(i+1);
				debugPuntos=espiral->vertice[debug];
				caraAnadir->setValor(2,debug,j); 

				debug=((j+1)%numL)+numL*i;
				debugPuntos= espiral->vertice[debug];
				caraAnadir->setValor(3,debug,j);   

				espiral->anadirNormal (espiral->calculoVectorNormalPorNewell(*caraAnadir)); // Esto calcula la normal de la cara y la inserta en su posicion correspondiente en la maya.
				espiral->anadirCara(caraAnadir); 
			}
			tiempo=tiempo+0.2;
		}
	}

	void pintar();

	~CirculoEspiral(void)
	{
		delete espiral;

	}
};

