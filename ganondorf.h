#ifndef GANONDORF_H
#define GANONDORF_H

#include <iostream>
#include <cstdlib>
#include "contrincante.h"

class Ganondorf : public Contrincante {

private:
	float vidaGanondorf=40.0;
	float fuerzaWarlock=15.0;
	float fuerzaFlame=10.0;
	float fuerzaVolcano=25.0;

public:
	float getvidaGanon() { return vidaGanondorf; }
	float getfuerzaWarlock() { return fuerzaWarlock; }
	float getfuerzaFlame() { return fuerzaFlame; }
	float getfuerzaVolcano() { return fuerzaVolcano; }
	void atacarJugador(string decision, int aJ);
	Ganondorf(){}
	Ganondorf(float vidaEnem, float fuerzaEnem1, float fuerzaEnem2, float fuerzaEnem3):Contrincante(vidaEnem, fuerzaEnem1, fuerzaEnem2,fuerzaEnem3){}
};

void Ganondorf::atacarJugador(string decision, int aJ) {
	string nombreJug;
	nombreJug = jugador.getnombreJug();
	int turnoContrincante, defensaChance, contrincanteAtaque, ataqueChance;
	turnoContrincante = rand() % 2;
	defensaChance = rand() % 3;
	contrincanteAtaque = rand() % 2;
	ataqueChance = rand() % 3;
	if (decision == "D") {
		if (defensaChance == 0 || defensaChance == 1 || defensaChance == 2)
		{
			if (turnoContrincante == 0) {
				cout << "Ganondorf ha fallado su ataque mientras " << nombreJug << " defendia, asi que sigue la pelea igual" << endl;
			}
			else if (turnoContrincante == 1) {
				cout << "IMPRESIONANTE " << nombreJug << " SE HA DEFENDIDO CONTRA GANONDORF CON EXITO" << endl;
			}
			else if (turnoContrincante == 2) {
				cout << "...No pues, ambos se defendieron,bueno PELIEN" << endl;
			}
		}
		else if (defensaChance == 3) {
			if (turnoContrincante == 0) {
				cout << "GANONDORF HA FALLADO SU ATAQUE, tiene suerte " << nombreJug << " porque su defensa habia fallado" << endl;
			}
			else if (turnoContrincante == 1) {
				float vidaJug;
				if (contrincanteAtaque == 0) {
					vidaJug = jugador.getvidaJug() - fuerzaCont1;
					jugador.setvidaJug(vidaJug);
					cout << "GANONDORF HA USADO SU WARLOCK PUNCH CON EXITO!!!, el rey demonio no va a ser derribado tan facil" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					vidaJug = jugador.getvidaJug() - fuerzaCont2;
					jugador.setvidaJug(vidaJug);
					cout << "GANONDORF HA USADO FLAME CHOKE CON EXITO!!!, el rey demonio no va a ser derribado tan faci" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					vidaJug = jugador.getvidaJug() - fuerzaCont3;
					jugador.setvidaJug(vidaJug);
					cout << "GANONDORF HA USADO VOLCANO KICK CON EXITO!!!, el rey demonio no va a ser derribado tan faci" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
			}
			else if (turnoContrincante == 2) {
				cout << "La defensa de " << nombreJug << " fallo, pero Ganondorf se estaba defendiendo...bueno PELIEN" << endl;
			}
		}
	}
	if (decision == "A") {
		if (ataqueChance == 0 || ataqueChance == 1 || ataqueChance == 2) {
			if (turnoContrincante == 0) {
				if (aJ == 1) {
					vidaCont = vidaCont - jugador.getfuerzaAtaque1();
					cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque1() << " Ganondorf se ve enojado" << endl;
					cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
				}
				if (aJ == 2) {
					vidaGanondorf = vidaCont- jugador.getfuerzaAtaque2();
					cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque2() << " Ganondorf se ve enojado" << endl;
					cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
				}
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont1 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Warlock Punch, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont1 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Warlock Punch, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 1) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont2 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont- (jugador.getfuerzaAtaque1() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Flame Choke, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont2 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont= vidaCont - (jugador.getfuerzaAtaque2() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Flame Choke, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
				else if (contrincanteAtaque == 2) {
					if (aJ == 1) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont3 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont - (jugador.getfuerzaAtaque1() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque1() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Volcano Kick, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
					if (aJ == 2) {
						float vidaJug;
						vidaJug = jugador.getvidaJug() - (fuerzaCont3 / 2);
						jugador.setvidaJug(vidaJug);
						vidaCont = vidaCont- (jugador.getfuerzaAtaque2() / 2);
						cout << "INCREIBLE " << nombreJug << " HA ATACADO A GANONDORF CON " << jugador.getnombreAtaque2() << endl;
						cout << "Pero Ganondorf usando la trifuerza del poder ha rematado con un Volcano Kick, esto se pone fiero" << endl;
						cout << "La vida de Ganondorf ahora es: " << vidaCont << endl;
						cout << "La vida de " << nombreJug << " ahora es: " << jugador.getvidaJug() << endl;
					}
				}
			}
			else if (turnoContrincante == 2) 
				cout << nombreJug << " HA ATACADO A GANONDORF" << endl;
				cout << "Pero Ganondorf se ha defendido, el rie al defender el ataque" << endl;
			}
		}

		else if (ataqueChance == 3) {
			if (turnoContrincante == 0) {
				cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
				cout << "Pero el ataque de Ganondorf tambi�n ha fallado, el rey Demonio parece ser que se debilita" << endl;
			}
			else if (turnoContrincante == 1) {
				if (contrincanteAtaque == 0) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() - fuerzaCont1;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Ganondorf ha rematado con un Warlock Punch, el rey Demonio viene fuerte esta noche!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 1) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() - fuerzaCont2;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Ganondorf ha rematado con un Flame Choke, el rey Demonio viene fuerte esta noche!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (contrincanteAtaque == 2) {
					float vidaJug;
					vidaJug = jugador.getvidaJug() - fuerzaCont3;
					jugador.setvidaJug(vidaJug);
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Ahora Ganondorf ha rematado con un Volcano Kick, el rey Demonio viene fuerte esta noche!!!!" << endl;
					cout << "La vida de" << nombreJug << " ahora es " << jugador.getvidaJug() << endl;
				}
				else if (turnoContrincante == 2) {
					cout << "EL ATAQUE DE " << nombreJug << " HA FALLADO" << endl;
					cout << "Pero Ganondorf solo bloqueaba, el rey Demonio se rie en la cara de " << nombreJug << endl;
				}
			}
		}
	}
#endif