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
const GLdouble M_PI = 3.1415926535897932384626433832795;


class Satelite
{
public:
	//Radio = radio con el que aproximamos la circunferencia.
	//numL = numero de lados que queremos para aproximar la circunferencia.
	//numQ = numero de caras que formara el "cono" que tiene el satelite.
	Satelite(int radio, int numL, int numQ)
	{
		int numVertices= 3*numL+numQ*numL;
		int numNorCaras= 2*numL+numQ*numL; //Hay una normal por cara.
		sat = new Malla(numVertices,numNorCaras,numNorCaras);

		//Calculo de la cara inferior e insertamos los vertices en la malla.
		PV3D centro = PV3D(0,0,0,false);
		GLdouble alfa=360.00/(GLdouble)numL;
        GLdouble beta= (180.00-alfa)/2;
        GLdouble lado= 2*radio*cos(M_PI*beta/180.00);
		Lapiz l (centro,0.0);
		l.forward(radio,false);
		sat->anadirVertice(new PV3D (l.pos.x,l.pos.y,l.pos.z,false));
		l.dir=180-beta;
		for (int i=1; i< numL; i++)
		{
			l.forward(lado,false);
			l.turnTo(alfa);
			sat->anadirVertice(new PV3D (l.pos.x,l.pos.y,l.pos.z,false));
		}
		//Calculo de la cara superior e insertamos los vertices en la malla.
		Lapiz l2 (PV3D (0,5,0,false),0.0);
		l2.forward(radio,false);
		sat->anadirVertice(new PV3D (l2.pos.x,l2.pos.y,l2.pos.z,false));
		l2.dir=180-beta;
		for (int i=1; i< numL; i++)
		{
			l2.forward(lado,false);
			l2.turnTo(alfa);
			sat->anadirVertice(new PV3D (l2.pos.x,l2.pos.y,l2.pos.z,false));
		}
		//Calculo de las caras y normales que forman estos vertices que hemos añadido.
		for (int j=0; j<numL;j++)
		{
			int debug=j;
			Cara* caraAnadir= new Cara(3); //metemos un 4 por que las caras son rectangulos.
			caraAnadir->setValor(0,j,j);
			debug=(j+1)%numL;
			caraAnadir->setValor(1,(j+1)%numL,j);
			//debug=(j+1+numL)%(numL*2);
			debug=debug+numL;
			caraAnadir->setValor(2,debug,j); // indice de los vertices dado en sentido antihorario empezando desde abajo a la izquierda, primero el punto i, luego el i+1
			debug=j+numL;
			caraAnadir->setValor(3,j+numL,j);   // despues de estos el siguiente es el i+numL+1 (numero de lados, es el de arriba a la derecha) y por ultimo el i+numL.
			sat->anadirNormal (sat->calculoVectorNormalPorNewell(*caraAnadir)); // Esto calcula la normal de la cara y la inserta en su posicion correspondiente en la maya.
			sat->anadirCara(caraAnadir); 
		}

	}

	~Satelite(void){}

	void dibuja();

private:
	Malla *sat;
};

