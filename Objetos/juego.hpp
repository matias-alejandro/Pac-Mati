/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/

#ifndef JUEGO_HPP
#define JUEGO_HPP

class Juego
{
	public:
		Juego();

		void actualizar(sf::RenderWindow &ventana);
		void KeyPressed(sf::Event &evento);
		void KeyReleased(sf::Event &evento);
	private:
		enum
		{
			ItemJuego,
			ItemEditor,
			ItemSalir,
			ItemMenu
		};
		int modo = ItemMenu;
		Jugador pacman;
		Mapa mapa;
		Puntero puntero;
		Menu menu;
};
#endif