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
	Satelite(double radio, int numL, int numQ)
	{
		nl=numL;
		nq=numQ;
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
		Lapiz l2 (PV3D (0,0.5,0,false),0.0);
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
		Lapiz l3 (PV3D (0,0.7,0,false),0.0);
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
		double crecer= 0.9/numQ; // 5 es el tamaño de la antena (Por ejemplo) pues cada fraccion crecera 5 dividido numero de fracciones.
		double acumulacionRadio= trozosRadio;
		double acumulacionCrecer=crecer;

		for (int k=0 ; k<numQ; k++)
		{
			lado= 2*acumulacionRadio*cos(M_PI*beta/180.00); //Calculo del nuevo lado de cara.
			Lapiz l4 (PV3D (0,0.7+acumulacionCrecer,0,false),0.0);
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

		//Construccion de las aspas.
		//Primeras aspa
		PV3D* pPunto = new PV3D (radio*4, 0,0.2, false);
		PV3D* sPunto = new PV3D (radio*4, 0,-0.2, false);
		PV3D* tPunto = new PV3D (radio*4, -0.3,0.2, false);
		PV3D* cPunto = new PV3D (radio*4, -0.3,-0.2, false);

		PV3D* qPunto = new PV3D (-radio*4, 0,0.2, false);
		PV3D* sePunto = new PV3D (-radio*4, 0,-0.2, false);
		PV3D* sepPunto = new PV3D (-radio*4, -0.3,0.2, false);
		PV3D* oPunto = new PV3D (-radio*4, -0.3,-0.2, false);

		//Creacion de las caras de la primera aspa, iene 6 caras
		aspas1 = new Malla(8,6,6);
		aspas1->anadirVertice(pPunto);
		aspas1->anadirVertice(sPunto);
		aspas1->anadirVertice(tPunto);
		aspas1->anadirVertice(cPunto);
		aspas1->anadirVertice(qPunto);
		aspas1->anadirVertice(sePunto);
		aspas1->anadirVertice(sepPunto);
		aspas1->anadirVertice(oPunto);

		Cara* cara1 = new Cara(4);
		Cara* cara2 = new Cara(4);
		Cara* cara3 = new Cara(4);
		Cara* cara4 = new Cara(4);
		Cara* cara5 = new Cara(4);
		Cara* cara6 = new Cara(4);

		cara1->setValor(0,0,0);
		cara1->setValor(1,1,0);
		cara1->setValor(2,3,0);
		cara1->setValor(3,2,0);

		cara2->setValor(0,0,1);
		cara2->setValor(1,2,1);
		cara2->setValor(2,6,1);
		cara2->setValor(3,4,1);

		cara3->setValor(0,0,2);
		cara3->setValor(1,4,2);
		cara3->setValor(2,6,2);
		cara3->setValor(3,1,2);

		cara4->setValor(0,1,3);
		cara4->setValor(1,5,3);
		cara4->setValor(2,7,3);
		cara4->setValor(3,3,3);

		cara5->setValor(0,2,4);
		cara5->setValor(1,3,4);
		cara5->setValor(2,7,4);
		cara5->setValor(3,6,4);

		cara6->setValor(0,7,5);
		cara6->setValor(1,5,5);
		cara6->setValor(2,4,5);
		cara6->setValor(3,6,5);

		aspas1->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara1));
		aspas1->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara2));
		aspas1->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara3));
		aspas1->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara4));
		aspas1->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara5));
		aspas1->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara6));

		aspas1->anadirCara(cara1);
		aspas1->anadirCara(cara2);
		aspas1->anadirCara(cara3);
		aspas1->anadirCara(cara4);
		aspas1->anadirCara(cara5);
		aspas1->anadirCara(cara6);

		//Construccion de las aspas.
		//Primeras aspa
		PV3D* pP = new PV3D (0.2, 0,radio*4, false);
		PV3D* sP = new PV3D (-0.2, 0,radio*4, false);
		PV3D* tP = new PV3D (0.2, -0.3,radio*4, false);
		PV3D* cP = new PV3D (-0.2, -0.3,radio*4, false);

		PV3D* qP = new PV3D (0.2, 0,-radio*4, false);
		PV3D* seP = new PV3D (-0.2, 0,-radio*4, false);
		PV3D* sepP = new PV3D (0.2, -0.3,-radio*4, false);
		PV3D* oP = new PV3D (-0.2, -0.3,-radio*4, false);

		//Creacion de las caras de la primera aspa, iene 6 caras
		aspas2 = new Malla(8,6,6);
		aspas2->anadirVertice(pP);
		aspas2->anadirVertice(sP);
		aspas2->anadirVertice(tP);
		aspas2->anadirVertice(cP);
		aspas2->anadirVertice(qP);
		aspas2->anadirVertice(seP);
		aspas2->anadirVertice(sepP);
		aspas2->anadirVertice(oP);

		Cara* cara7 = new Cara(4);
		Cara* cara8 = new Cara(4);
		Cara* cara9 = new Cara(4);
		Cara* cara10 = new Cara(4);
		Cara* cara11 = new Cara(4);
		Cara* cara12 = new Cara(4);

		cara7->setValor(0,0,0);
		cara7->setValor(1,1,0);
		cara7->setValor(2,3,0);
		cara7->setValor(3,2,0);

		cara8->setValor(0,0,1);
		cara8->setValor(1,2,1);
		cara8->setValor(2,6,1);
		cara8->setValor(3,4,1);

		cara9->setValor(0,0,2);
		cara9->setValor(1,4,2);
		cara9->setValor(2,6,2);
		cara9->setValor(3,1,2);

		cara10->setValor(0,1,3);
		cara10->setValor(1,5,3);
		cara10->setValor(2,7,3);
		cara10->setValor(3,3,3);

		cara11->setValor(0,2,4);
		cara11->setValor(1,3,4);
		cara11->setValor(2,7,4);
		cara11->setValor(3,6,4);

		cara12->setValor(0,7,5);
		cara12->setValor(1,5,5);
		cara12->setValor(2,4,5);
		cara12->setValor(3,6,5);

		aspas2->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara7));
		aspas2->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara8));
		aspas2->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara9));
		aspas2->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara10));
		aspas2->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara11));
		aspas2->anadirNormal(aspas1->calculoVectorNormalPorNewell(*cara12));

		aspas2->anadirCara(cara7);
		aspas2->anadirCara(cara8);
		aspas2->anadirCara(cara9);
		aspas2->anadirCara(cara10);
		aspas2->anadirCara(cara11);
		aspas2->anadirCara(cara12);
	}

	~Satelite(void){
		delete sat;
		delete aspas1;
		delete aspas2;
	}

	void dibuja();
	void dibujaAspas();

	//De momento esto lo dejamos publico para debugear
	Malla *sat;
	Malla *aspas1;
	Malla *aspas2;
	int nl,nq;
private:
	//Malla *sat;
};

