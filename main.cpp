/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/
#include <SFML/Graphics.hpp>
#include <iostream>

#define Alto_Pantalla 13*28 //Multiplo de 13
#define Ancho_Pantalla 13*28//793 //Multiplo de 13

#define VelocidadJugador 1.0
#define CantDeSprites 11-1   //TEMPORAL, DESPUES BORRAR
#define DefTamSprite 13
#define DefVidasInit 3

#include "funciones.h"
#include "Objetos/mapa.cpp"
#include "Objetos/pacman.cpp"
#include "Objetos/puntero.cpp"
#include "Objetos/menu.cpp"
#include "Objetos/juego.cpp"

using namespace std;
/*********************************************************************/
int main()
{
	sf::RenderWindow ventana(sf::VideoMode(Ancho_Pantalla, Alto_Pantalla), "Pac-Mati");
	sf::Event evento;
	ventana.setVerticalSyncEnabled(true);
	ventana.setMouseCursorVisible(false);

	Juego juego;
	
	while (ventana.isOpen())
	{	
		ventana.clear(sf::Color::Black);

		juego.actualizar(ventana);

		ventana.display();

		while (ventana.pollEvent(evento))
		{
			switch (evento.type)
	   		{
				case evento.Closed:
				{
					ventana.close();
					break;
				}
				case evento.KeyPressed:
				{
					juego.KeyPressed(evento);
					
					break;
				}
				case evento.KeyReleased:
				{
					juego.KeyReleased(evento);

					break;
				}
				default:
				{
					break;
				}
			}
		}
	}
    return 0;
}