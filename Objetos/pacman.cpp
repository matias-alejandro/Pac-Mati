/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/
#include "pacman.hpp"

/*********************************************************************/
Jugador::Jugador() : sf::Sprite()
{
	if(!this->tex_pacman.loadFromFile("Imagenes/pacman.png"))
	{
		printf("Error al cargar Sprite");
	}
	
	this->tex_pacman.setSmooth(true);
	this->tex_pacman.setRepeated(false);
	this->anim=true;
	this->setPosition( 13 , 13 );
	this->setTexture(this->tex_pacman);

	this->AnimDireccion=1; //dirección inicial

	this->Reloj = clock();
}
/*********************************************************************/
void Jugador::actualizar()
{
	this->move(this->velocidad);
	this->animacion();
}
/*********************************************************************/
void Jugador::teclado(sf::Event &evento)
{
	if((int)this->getPosition().x%13!=0 && (int)this->getPosition().y%13!=0 && this->colicionando==false)
		return;

	if(evento.key.code == sf::Keyboard::A)
	{
		this->velocidad.x = -VelocidadJugador;
		this->velocidad.y = 0;
		this->AnimDireccion=1;
	}
	else if(evento.key.code == sf::Keyboard::D)
	{
		this->velocidad.x = VelocidadJugador;
		this->velocidad.y = 0;
		this->AnimDireccion=0;
	}
	else if(evento.key.code == sf::Keyboard::S)
	{
		this->velocidad.y = VelocidadJugador;
		this->velocidad.x = 0;
		this->AnimDireccion=3;
	}
	else if(evento.key.code == sf::Keyboard::W)
	{
		this->velocidad.y = -VelocidadJugador;
		this->velocidad.x = 0;
		this->AnimDireccion=2;
	}
}
/*********************************************************************/
void Jugador::animacion()
{
	if(2 < (clock() - this->Reloj)/10000)//aproximadamente 2 segundos
	{
		this->anim=!this->anim;
		this->Reloj = clock();
	}
	sf::IntRect frame(13*(int)this->anim, this->AnimDireccion*13, 13, 13);
	this->setTextureRect(frame);
}
/*********************************************************************/
void Jugador::controlColision(Mapa &mapa)
{
	this->nodoAux=mapa.BuscarNodo(this->getPosition().x/13, this->getPosition().y/13);

	if(this->nodoAux && this->nodoAux->NumSprite==tipo_bolita)
	{
			mapa.BorrarCasillero(nodoAux);
			this->puntos++;
	}

	if(this->velocidad.x > 0) // >>
	{
		this->nodoAux=mapa.BuscarNodo((this->getPosition().x/13)+1, this->getPosition().y/13);
	}
	else if(this->velocidad.x < 0) // <<
	{
		this->nodoAux=mapa.BuscarNodo((this->getPosition().x/13)-1, this->getPosition().y/13);
	}
	else if(this->velocidad.y > 0) // V
	{
		this->nodoAux=mapa.BuscarNodo(this->getPosition().x/13, (this->getPosition().y/13)+1);
	}
	else if(this->velocidad.y < 0) // ^
	{
		this->nodoAux=mapa.BuscarNodo(this->getPosition().x/13, (this->getPosition().y/13)-1);
	}

	if(this->nodoAux && this->nodoAux->NumSprite != tipo_bolita)
	{
		this->colicionando = true;
	}
	this->colicionando = false;
}
/*********************************************************************/