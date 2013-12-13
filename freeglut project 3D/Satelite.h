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
		nl=numL;
		nq=numQ;
		int numVertices= 3*numL+numQ*numL;
		int numNorCaras= 2*numL+numQ*numL; //Hay una normal por cara.
		sat = new Malla(numVertices,numNorCaras,numNorCaras);
		//sat = new Malla(numVertices,numL,numL);   // ESTO ES PARA DEBUGERA CUANDO SE TERMIEN DESCOMENTAR LO DE ARRIBA.

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
			
			Cara* caraAnadir= new Cara(4); //metemos un 4 por que las caras son rectangulos.
			int debug=j;
			PV3D* debugPuntos= sat->vertice[debug];
			caraAnadir->setValor(0,j,j);

			debug=j+numL;
			debugPuntos= sat->vertice[debug];
			caraAnadir->setValor(1,debug,j);

			debug=((j+1)%numL)+numL;
			debugPuntos= sat->vertice[debug];
			caraAnadir->setValor(2,debug,j); 

			debug=(j+1)%numL;
			debugPuntos= sat->vertice[debug];
			caraAnadir->setValor(3,debug,j);   

			sat->anadirNormal (sat->calculoVectorNormalPorNewell(*caraAnadir)); // Esto calcula la normal de la cara y la inserta en su posicion correspondiente en la maya.
			sat->anadirCara(caraAnadir); 
		}

		//Aqui empezamos con la parte de la maya que hace un cono que hace un "Cono"
		Lapiz l3 (PV3D (0,7,0,false),0.0);
		l3.forward(radio/5,false);
		sat->anadirVertice(new PV3D (l3.pos.x,l3.pos.y,l3.pos.z,false));
		l3.dir=180-beta;
		for (int i=1; i< numL; i++)
		{
			l3.forward(lado/5,false);
			l3.turnTo(alfa);
			sat->anadirVertice(new PV3D (l3.pos.x,l3.pos.y,l3.pos.z,false));
		}
		//Calculo de las caras y las normales
		for (int j=numL; j<numL*2;j++)
		{
			
			Cara* caraAnadir= new Cara(4); //metemos un 4 por que las caras son rectangulos.
			int debug=j;
			PV3D* debugPuntos= sat->vertice[debug];
			caraAnadir->setValor(0,j,j);

			debug=j+numL;
			debugPuntos= sat->vertice[debug];
			caraAnadir->setValor(1,debug,j);

			debug=((j+1)%numL)+numL*2;
			debugPuntos= sat->vertice[debug];
			caraAnadir->setValor(2,debug,j); 

			debug=((j+1)%numL)+numL;
			debugPuntos= sat->vertice[debug];
			caraAnadir->setValor(3,debug,j);   

			sat->anadirNormal (sat->calculoVectorNormalPorNewell(*caraAnadir)); // Esto calcula la normal de la cara y la inserta en su posicion correspondiente en la maya.
			sat->anadirCara(caraAnadir); 
		}

		//Calculo de la antena del satelite.
		double trozosRadio=(double)radio/numQ;
		double crecer= 5.00/numQ; // 5 es el tamaño de la antena (Por ejemplo) pues cada fraccion crecera 5 dividido numero de fracciones.
		double acumulacionRadio= trozosRadio;
		double acumulacionCrecer=crecer;

		for (int k=0 ; k<numQ; k++)
		{
			lado= 2*acumulacionRadio*cos(M_PI*beta/180.00); //Calculo del nuevo lado de cara.
			Lapiz l4 (PV3D (0,7+acumulacionCrecer,0,false),0.0);
			l4.forward(acumulacionRadio,false);
			sat->anadirVertice(new PV3D (l4.pos.x,l4.pos.y,l4.pos.z,false));
			l4.dir=180-beta;
			for (int i=1; i< numL; i++)
			{
				l4.forward(lado,false);
				l4.turnTo(alfa);
				sat->anadirVertice(new PV3D (l4.pos.x,l4.pos.y,l4.pos.z,false));
			}
			acumulacionRadio+=trozosRadio;
			acumulacionCrecer+=crecer;
			
			// Añadimos las caras que forman estos vertices


			for (int j=numL*(k+2); j<numL*(k+3);j++)
			{			
				Cara* caraAnadir= new Cara(4); //metemos un 4 por que las caras son rectangulos.
				int debug=j;
				PV3D* debugPuntos= sat->vertice[debug];
				caraAnadir->setValor(0,j,j);

				debug=j+numL;
				debugPuntos= sat->vertice[debug];
				caraAnadir->setValor(1,debug,j);

				debug=((j+1)%numL)+numL*(k+3);
				debugPuntos= sat->vertice[debug];
				caraAnadir->setValor(2,debug,j); 

				debug=((j+1)%numL)+numL*(k+2);
				debugPuntos= sat->vertice[debug];
				caraAnadir->setValor(3,debug,j);   

				sat->anadirNormal (sat->calculoVectorNormalPorNewell(*caraAnadir)); // Esto calcula la normal de la cara y la inserta en su posicion correspondiente en la maya.
				sat->anadirCara(caraAnadir); 
			}
		}


	}

	~Satelite(void){}

	void dibuja();

	//De momento esto lo dejamos publico para debugear
	Malla *sat;
	int nl,nq;
private:
	//Malla *sat;
};

