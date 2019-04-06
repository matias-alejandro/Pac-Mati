/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/

#ifndef MAPA_HPP
#define MAPA_HPP

class Mapa
{
	public:
		Mapa();

		void Dibujar(sf::RenderWindow &Ventana);

		void Cargar(/*int NumMap*/);
		void Guardar(/*int NumMap*/);

		void teclado(sf::Event &evento);

		Nodo *BuscarNodo(int x, int y);
		
		void BorrarCasillero(Nodo *Casillero);
		Nodo *CrearCasillero(int X, int Y);

		void EstablecerSprite(Nodo &Casillero);
	private:
		sf::Texture tex_mapa;
		Nodo *Inicio=NULL;

		void EstablecerPosicion(int X, int Y, Nodo &Casillero);
		void Inicializar(Nodo &Casillero);
};
#endif