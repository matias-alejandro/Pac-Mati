/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/
#include "menu.hpp"

Menu::Menu()
{
	if(!this->fuente.loadFromFile("Fuentes/PAC-FONT.ttf"))
	{
			std::cout << "[ERROR] No se encontró la this->fuente" << std::endl;
	}
}
/*********************************************************************/
void Menu::agregarTitulo(const char palabra[])
{
	this->titulo.setString(palabra);
	this->titulo.setFont(this->fuente);
	this->titulo.setCharacterSize(24);
	this->titulo.setPosition((Ancho_Pantalla/2)-(this->titulo.getLocalBounds().width/2), (Alto_Pantalla-200)/2+((24)*this->cantidad));
	this->titulo.setFillColor(sf::Color(255, 155, 46));
}
/*********************************************************************/
void Menu::agregarOpcion(const char palabra[])
{
	NodoTxt *Aux;
	if(!this->InicioTxt)
	{
		this->InicioTxt = new NodoTxt();
		Aux=this->InicioTxt;
	}
	else
	{
		while(Aux->Sig)
			Aux=Aux->Sig;
		Aux->Sig = new NodoTxt();
		Aux->Sig->Ant=Aux;
		Aux=Aux->Sig;
	}
	Aux->texto.setString(palabra);
	Aux->texto.setFont(this->fuente);
	Aux->texto.setCharacterSize(Aux->tam);
	Aux->texto.setPosition((Ancho_Pantalla/2)-(Aux->texto.getLocalBounds().width/2), (Alto_Pantalla)/2+((Aux->tam+5)*this->cantidad));
	Aux->id=cantidad;
	this->cantidad++;
}
/*********************************************************************/
int Menu::opcionSeleccionada()
{
	if(this->Selector)
		return this->Selector->id;
	return -1;
}
/*********************************************************************/
/*void Menu::inhabilitarOpcion()
{

}
/*********************************************************************/
/*void Menu::habilitarOpcion()
{

}
/*********************************************************************/
void Menu::actualizar(sf::RenderWindow& win)
{	
	NodoTxt *Aux=this->InicioTxt;
	if(!this->Selector)
		this->Selector=this->InicioTxt;

	win.draw(this->titulo);

	while(Aux)
	{
		if(Aux==Selector)
			Aux->texto.setFillColor(sf::Color(255, 255, 100));
		else
		{
			if(Aux->id!=-1)
				Aux->texto.setFillColor(sf::Color(255, 255, 255));
		}

		win.draw(Aux->texto);
		Aux=Aux->Sig;
	}
}
/*********************************************************************/
void Menu::teclado(sf::Event &evento, int &modo)
{
	if(evento.key.code == sf::Keyboard::S)
	{
		if(this->Selector->Sig)
			this->Selector=this->Selector->Sig;
	}
	else if(evento.key.code == sf::Keyboard::W)
	{
		if(this->Selector->Ant)
			this->Selector=this->Selector->Ant;
	}
	else if(evento.key.code == sf::Keyboard::Key::Space)
	{
		modo=this->Selector->id;
	}
}