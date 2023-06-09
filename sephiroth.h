/*
 * Proyecto Juego de Peleas
 * Samir Baidon Pardo
 * A01705403
 * 20/05/2023
 * versio : 4
 * Esta clase define la clase de Sephiroth, esta clase hereda
 * de la clase de Contrincante y sobreescribe unas de sus funciones
 */
#ifndef SEPHIROTH_H
#define SEPHIROTH_H

#include <iostream>
#include <cstdlib>

/*Se incluye la clase de Contrincante
*para heredar de ella
*/
#include "contrincante.h"

using namespace std;

class Sephiroth : public Contrincante {

/*Se declaran los m�todos p�blicos
* */
public:
	/*Declaramos de nuevo la funci�n para tener polimorfismo
	*/
	void atacarJugador(string decision, int aJ,
		Jugador* jugador,Contrincante* sephiroth); 
	Sephiroth(){}
	Sephiroth(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, 
		float fuerzaEnem3, float fuerzaEnem4):
		Contrincante(vidaEnem, fuerzaEnem1, fuerzaEnem2, 
			fuerzaEnem3, fuerzaEnem4) {}
};

/*Funcion:Alterar la vida de tanto el enemigo como el jugador
*se tiene sobreescritura al tener un dialogo diferente 
*
*Parametros: Se toma un parametro string para 
*la decision del jugador, un parametro int para
*el ataque que decidio usar el jugador, un parametro apuntador
*para poder evitar que se creen copias del jugador y
*un parametro apuntador de Contrincante para poder usar el mismo
*enemigo durante el round
*
*Retorno: Al ser una funci�n void no se regresa algo en s�,solo se 
*alteran los valores de vida del jugador y el enemigo 
*/
void Sephiroth::atacarJugador(string decision, int aJ,
	Jugador* jugador,Contrincante* sephiroth) {
	int turnoContrincante, defensaChance, 
		contrincanteAtaque, ataqueChance;
	float vidaJug, vidaCont;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 3;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 || 
			defensaChance == 2)
		{
			if (turnoContrincante == 0) {
				cout << "El ataque de Sephiroth ha fallado,\
					el solo r�e, ya que " 
					<< jugador->getnombreJug() 
					<< " solo se estaba defendiendo" << endl;
			}
			else if (turnoContrincante == 1) {
				cout << jugador->getnombreJug() 
					<< " SE HA DEFENDIDO CONTRA SEPHIROTH" << endl;
				cout << "Pero Sephiroth solo sonr�e,\
					el �ngel de un ala ya se lo esperaba" << endl;
			}
			else if (turnoContrincante == 2) {
				cout << "...No pues, ambos se defendieron,\
					bueno PELIEN" << endl;
				cout << "Parece ser Sephiroth hace una sonrisa,\
					pensando el ya gano" << endl;
			}
		}
		else if (defensaChance == 3) {
			if (turnoContrincante == 0) {
				cout << "WOW,tanto Sephiroth como " 
					<< jugador->getnombreJug() 
					<< " han fallado sus ataques, no ha sucedido nada" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					vidaJug = jugador->getvidaJug() - sephiroth->getfuerzaCont1();
					jugador->setvidaJug(vidaJug);
					cout << "Sephiroth ha usado su mitica Masamune con exito,\
						sonrie al ver a " << jugador->getnombreJug() 
						<< " caer" << endl;
					cout << "La vida de " << jugador->getnombreJug() << 
						" ahora es : " << jugador->getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador->getvidaJug() - sephiroth->getfuerzaCont2();
					jugador->setvidaJug(vidaJug);
					cout << "Sephiroth ha usado Shadow Flare con exito,\
						sonrie al ver a " << jugador->getnombreJug() 
						<< " caer" << endl;
					cout << "La vida de " << jugador->getnombreJug() 
						<< " ahora es : " << jugador->getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					vidaJug = jugador->getvidaJug() - sephiroth->getfuerzaCont3();
					jugador->setvidaJug(vidaJug);
					cout << "Sephiroth ha usado Octaslash con exito,\
						sonrie al ver a " << jugador->getnombreJug() 
						<< " caer" << endl;
					cout << "La vida de " << jugador->getnombreJug() 
						<< " ahora es : " << jugador->getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 3) {
					vidaJug = jugador->getvidaJug() - sephiroth->getfuerzaCont4();
					jugador->setvidaJug(vidaJug);
					cout << "Sephiroth ha usado Super Nova con exito,\
						sonrie al ver a " << jugador->getnombreJug() 
						<< " caer" << endl;
					cout << "La vida de " << jugador->getnombreJug() 
						<< " ahora es : " << jugador->getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "La defensa de " << jugador->getnombreJug() 
					<< " ha fallado" << endl;
				cout << "Sephiroth solo se queda defendiendo,\
					llama a " << jugador->getnombreJug() << " patetico" << endl;
			}
		}
	}
	if (decision == "A") {
		if (ataqueChance == 0 || ataqueChance == 1 || 
			ataqueChance == 2) {
			if (turnoContrincante == 0) {
				if (aJ == 1) {
					vidaCont = sephiroth->getvidaCont() 
						- jugador->getfuerzaAtaque1();
					sephiroth->setvidaCont(vidaCont);
					cout << "NO ME LO CREO " << jugador->getnombreJug() 
						<< " HA ATACADO A SEPHIROTH CON " 
						<< jugador->getnombreAtaque1() << endl;
					cout << "Pero parece ser Sephiroth solo sonrie\
						al haber recibido el ataque" << endl;
					cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
				}
				if (aJ == 2) {
					vidaCont = sephiroth->getvidaCont() 
						- jugador->getfuerzaAtaque2();
					sephiroth->setvidaCont(vidaCont);
					cout << "NO ME LO CREO " << jugador->getnombreJug() 
						<< " HA ATACADO A SEPHIROTH CON " 
						<< jugador->getnombreAtaque2() << endl;
					cout << "Pero parece ser Sephiroth solo sonrie\
						al haber recibido el ataque" << endl;
					cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
				}
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador->getvidaJug() 
							- (sephiroth->getfuerzaCont1() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = sephiroth->getvidaCont() 
							- (jugador->getfuerzaAtaque1()/2);
						sephiroth->setvidaCont(vidaCont);
						cout << "NO ME LO CREO " << jugador->getnombreJug() 
							<< " HA ATACADO A SEPHIROTH CON " 
							<< jugador->getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata\
							con su Masamune, parece ser Sephiroth\
							disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() 
							<< " ahora es: " << jugador->getvidaJug() << endl;

					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador->getvidaJug() 
							- (sephiroth->getfuerzaCont1() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = sephiroth->getvidaCont() 
							- (jugador->getfuerzaAtaque2() / 2);
						sephiroth->setvidaCont(vidaCont);
						cout << "NO ME LO CREO " << jugador->getnombreJug() 
							<< " HA ATACADO A SEPHIROTH CON " 
							<< jugador->getnombreAtaque2() << endl;
						cout << "Pero Sephiroth no se queda atras y remata\
							con su Masamune, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " << vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() 
							<< " ahora es: " << jugador->getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador->getvidaJug() 
							- (sephiroth->getfuerzaCont2() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = sephiroth->getvidaCont() 
							- (jugador->getfuerzaAtaque1() / 2);
						sephiroth->setvidaCont(vidaCont);
						cout << "NO ME LO CREO " << jugador->getnombreJug() 
							<< " HA ATACADO A SEPHIROTH CON " 
							<< jugador->getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata\
							con Shadow Flare, parece ser Sephiroth\
							disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() 
							<< " ahora es: " << jugador->getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador->getvidaJug() 
							- (sephiroth->getfuerzaCont2() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = sephiroth->getvidaCont() 
							- (jugador->getfuerzaAtaque2() / 2);
						sephiroth->setvidaCont(vidaCont);
						cout << "NO ME LO CREO " << jugador->getnombreJug() 
							<< " HA ATACADO A SEPHIROTH CON " 
							<< jugador->getnombreAtaque2() << endl;
						cout << "Pero Sephiroth no se queda atras y remata\
							con Shadow Flare, parece ser Sephiroth\
							disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() 
							<< " ahora es: " << jugador->getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 2) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador->getvidaJug() 
							- (sephiroth->getfuerzaCont3() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = sephiroth->getvidaCont() 
							- (jugador->getfuerzaAtaque1() / 2);
						sephiroth->setvidaCont(vidaCont);
						cout << "NO ME LO CREO " << jugador->getnombreJug() 
							<< " HA ATACADO A SEPHIROTH CON " 
							<< jugador->getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata\
							con Octaslash, parece ser Sephiroth\
							disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() 
							<< " ahora es: " << jugador->getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador->getvidaJug() 
							- (sephiroth->getfuerzaCont3() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = sephiroth->getvidaCont() 
							- (jugador->getfuerzaAtaque2() / 2);
						sephiroth->setvidaCont(vidaCont);
						cout << "NO ME LO CREO " << jugador->getnombreJug() 
							<< " HA ATACADO A SEPHIROTH CON " 
							<< jugador->getnombreAtaque2() << endl;
						cout << "Pero Sephiroth no se queda atras y remata\
							con Octaslash, parece ser Sephiroth\
							disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() 
							<< " ahora es: " << jugador->getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 3) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador->getvidaJug() 
							- (sephiroth->getfuerzaCont4() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = sephiroth->getvidaCont() 
							- (jugador->getfuerzaAtaque1() / 2);
						sephiroth->setvidaCont(vidaCont);
						cout << "NO ME LO CREO " << jugador->getnombreJug() 
							<< " HA ATACADO A SEPHIROTH CON " 
							<< jugador->getnombreAtaque1() << endl;
						cout << "Pero Sephiroth no se queda atras y remata\
							con Super Nova, parece ser Sephiroth\
							disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() 
							<< " ahora es: " << jugador->getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador->getvidaJug() 
							- (sephiroth->getfuerzaCont4() / 2);
						jugador->setvidaJug(vidaJug);
						vidaCont = sephiroth->getvidaCont() 
							- (jugador->getfuerzaAtaque2() / 2);
						sephiroth->setvidaCont(vidaCont);
						cout << "NO ME LO CREO " << jugador->getnombreJug() 
							<< " HA ATACADO A SEPHIROTH CON " 
							<< jugador->getnombreAtaque2() << endl;
						cout << "Pero Sephiroth no se queda atras y remata\
							con Super Nova, parece ser Sephiroth disfruta esta pelea" << endl;
						cout << "La vida de Sephiroth ahora es: " 
							<< vidaCont << endl;
						cout << "La vida de " << jugador->getnombreJug() 
							<< " ahora es: " << jugador->getvidaJug() << endl;
					}
				}
			}
			else if (turnoContrincante == 2) {
				cout << jugador->getnombreJug() 
					<< " HA ATACADO A SEPHIROTH" << endl;
				cout << "Pero Sephiroth se ha defendido, el dice al fin\
					estar feliz de tener una pelea divertida" << endl;
			}
		}

		else if (ataqueChance == 3) {
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE " << jugador->getnombreJug() 
					<< " HA FALLADO" << endl;
				cout << "Pero el ataque de Sephiroth tambi�n,\
					el angel de una Ala se esta cansando" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 2) {
					float vidaJug;
					vidaJug = jugador->getvidaJug() - sephiroth->getfuerzaCont1();
					jugador->setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << jugador->getnombreJug() 
						<< " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con un su Masamune,\
						parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de " << jugador->getnombreJug() 
						<< " ahora es " << jugador->getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					float vidaJug;
					vidaJug = jugador->getvidaJug() - sephiroth->getfuerzaCont2();
					jugador->setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << jugador->getnombreJug() 
						<< " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con Shadow Flare,\
						parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de " << jugador->getnombreJug() 
						<< " ahora es " << jugador->getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					float vidaJug;
					vidaJug = jugador->getvidaJug() - sephiroth->getfuerzaCont3();
					jugador->setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << jugador->getnombreJug() 
						<< " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con Octaslash,\
						parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de " << jugador->getnombreJug() 
						<< " ahora es " << jugador->getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 3) {
					float vidaJug;
					vidaJug = jugador->getvidaJug() - sephiroth->getfuerzaCont4();
					jugador->setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << jugador->getnombreJug() 
						<< " HA FALLADO" << endl;
					cout << "Ahora Sephiroth ha rematado con una Super Nova,\
						parece ser que quiere terminar ya esta pelea!!!!" << endl;
					cout << "La vida de " << jugador->getnombreJug() 
						<< " ahora es " << jugador->getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "EL ATAQUE DE " << jugador->getnombreJug() 
					<< " HA FALLADO" << endl;
				cout << "Pero Sephiroth solo bloqueaba, el angel\
					de un ala llama patetico a " 
					<< jugador->getnombreJug() << endl;
			}
		}
	}
}
#endif 

