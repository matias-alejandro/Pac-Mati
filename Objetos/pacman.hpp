/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/

#ifndef JUGADORES_HPP
#define JUGADORES_HPP

#include <SFML/Graphics.hpp>
#include "../funciones.hpp"
#include "mapa.hpp"

class Jugador : public sf::Sprite
{
	public:
		int Vidas=DefVidasInit;
		int puntos=0;

		Jugador();
		
		void actualizar();
		void controlColision(Mapa &mapa);
		void teclado(sf::Event &evento);
	private:
		sf::Vector2f velocidad;
		sf::Texture tex_pacman;
		Nodo *nodoAux=NULL;

		bool anim;
		bool colicionando=false;
		int AnimDireccion;
		clock_t Reloj;

		void animacion();
};
#endif