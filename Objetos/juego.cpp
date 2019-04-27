/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/
#include "juego.hpp"

/*********************************************************************/
Juego::Juego()
{
	this->menu.agregarTitulo("Pac Mati");
	this->menu.agregarOpcion("Jugar");
	this->menu.agregarOpcion("Editor");
	this->menu.agregarOpcion("Salir");
}
/*********************************************************************/
void Juego::actualizar(sf::RenderWindow &ventana)
{
	switch(modo)
	{
		case ItemJuego:
			this->mapa.Dibujar(ventana);
			this->pacman.actualizar();
			this->pacman.controlColision(this->mapa);
			ventana.draw(this->pacman);
		break;

		case ItemEditor:
			this->mapa.Dibujar(ventana);
			this->puntero.actualizar(ventana, this->mapa);
			ventana.draw(this->puntero);
		break;

		case ItemMenu:
			this->menu.actualizar(ventana);
		break;

		case ItemSalir:
			ventana.close();
		break;
	}
}
/*********************************************************************/
void Juego::KeyPressed(sf::Event &evento)
{
	if(modo==ItemJuego)
		this->pacman.teclado(evento);
}
/*********************************************************************/
void Juego::KeyReleased(sf::Event &evento)
{
	switch(modo)
	{
		case ItemJuego:
			this->mapa.teclado(evento);
		break;

		case ItemEditor:
			this->puntero.teclado(evento);
			this->mapa.teclado(evento);
		break;

		case ItemMenu:
			this->menu.teclado(evento, this->modo);
		break;
	}

	if(evento.key.code == sf::Keyboard::Key::Escape)
	{
		modo=ItemMenu;
	}
}
/*********************************************************************/