/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/

#include "puntero.hpp"

Puntero::Puntero() : sf::Sprite()
{
	if(!tex_mapa.loadFromFile("Imagenes/mapa.png"))
	{
		printf("Error al cargar la textura");
	}
	tex_mapa.setSmooth(true);
	tex_mapa.setRepeated(false);
	this->setPosition(0,0);
	this->setColor(sf::Color(150, 150, 150));
	this->EstablecerSprite(0);
}
/*********************************************************************/
void Puntero::MoverA(int x, int y)
{
	this->setPosition(x*13, y*13);
	this->cordEnGrilla[0]=x;
	this->cordEnGrilla[1]=y;
}
/*********************************************************************/
void Puntero::teclado(sf::Event &evento)
{
	if(evento.key.code == sf::Keyboard::Up)
	{
		if(this->NumSprite==CantDeSprites)
		{
			this->NumSprite=0;
		}
		else
		{
			this->NumSprite++;
		}
		this->EstablecerSprite(this->NumSprite);
	}
	else if(evento.key.code == sf::Keyboard::Down)
	{
		if(this->NumSprite==0)
		{
			this->NumSprite=CantDeSprites;
		}
		else
		{
			this->NumSprite--;
		}
		this->EstablecerSprite(this->NumSprite);
	}
}
/*********************************************************************/
void Puntero::actualizar(sf::RenderWindow &Ventana, Mapa &mapa)
{
	this->MousePos = sf::Mouse::getPosition(Ventana);
	if(this->MousePos.x < 0 || this->MousePos.x > Ancho_Pantalla-13 || this->MousePos.y < 0 || this->MousePos.y > Alto_Pantalla-13) //Le resto 13 para que no quede un espacio sin graficafr
		return;

	if(this->MousePos.x/13!=this->cordEnGrilla[0] || this->MousePos.y/13!=this->cordEnGrilla[1])
	{
		MoverA((int) (this->MousePos.x/13), (int) (this->MousePos.y/13));
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->NodoAux=mapa.BuscarNodo(this->cordEnGrilla[0], this->cordEnGrilla[1]);
		if(!this->NodoAux)
			this->NodoAux=mapa.CrearCasillero(this->cordEnGrilla[0], this->cordEnGrilla[1]);
		if(this->NodoAux->NumSprite!=this->NumSprite)
		{
			this->NodoAux->NumSprite=this->NumSprite;
			mapa.EstablecerSprite(*this->NodoAux);
		}
	}
	else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		this->NodoAux=mapa.BuscarNodo(this->cordEnGrilla[0], this->cordEnGrilla[1]);
		if(this->NodoAux)
			mapa.BorrarCasillero(this->NodoAux);
	}
}
/*********************************************************************/
void Puntero::EstablecerSprite(int NumSprite)
{
	sf::IntRect frame(0, NumSprite*13, 13, 13);
	this->setTextureRect(frame);
	this->setTexture(this->tex_mapa);
}
/*********************************************************************/