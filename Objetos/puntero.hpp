/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/

#ifndef PUNTERO_HPP
#define PUNTERO_HPP

#include <SFML/Graphics.hpp>
#include "../funciones.hpp"
#include "mapa.hpp"

class Puntero : public sf::Sprite
{
	public:
		Puntero();
		void actualizar(sf::RenderWindow &Ventana, Mapa &mapa);

		void teclado(sf::Event &evento);
		
	private:
		sf::Texture tex_mapa;
		sf::Vector2i MousePos;

		Nodo *NodoAux;
		
		int NumSprite;
		int cordEnGrilla[2];

		void MoverA(int x, int y);
		void EstablecerSprite(int NumSprite);
};
#endif