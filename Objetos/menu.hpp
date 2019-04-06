/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
	public:
		Menu();
		void agregarOpcion(const char palabra[]);
		void agregarTitulo(const char palabra[]);
		//void inhabilitarOpcion();
		//void habilitarOpcion();

		void actualizar(sf::RenderWindow &Ventana);
		int opcionSeleccionada();

		void teclado(sf::Event &evento, int &modo);
	private:
		sf::Font fuente;
		sf::Text titulo;
		struct NodoTxt
		{		
			sf::Text texto;
			int tam=24;
			int id;

			NodoTxt *Sig=NULL;
			NodoTxt *Ant=NULL;
		};
		int cantidad=0;
		NodoTxt *InicioTxt=NULL;
		NodoTxt *Selector=NULL;
};
#endif