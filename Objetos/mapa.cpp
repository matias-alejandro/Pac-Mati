/*****************************************************************************************
 ________  ________  ________                _____ ______   ________  _________  ___     
|\   __  \|\   __  \|\   ____\              |\   _ \  _   \|\   __  \|\___   ___\\  \    
\ \  \|\  \ \  \|\  \ \  \___|  ____________\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \   
 \ \   ____\ \   __  \ \  \    |\____________\ \  \\|__| \  \ \   __  \   \ \  \ \ \  \  
  \ \  \___|\ \  \ \  \ \  \___\|____________|\ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ 
   \ \__\    \ \__\ \__\ \_______\             \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\
    \|__|     \|__|\|__|\|_______|              \|__|     \|__|\|__|\|__|    \|__|  \|__|
*****************************************************************************************/

#include "mapa.hpp"

/*********************************************************************/
Mapa::Mapa()
{
	if(!tex_mapa.loadFromFile("Imagenes/mapa.png"))
	{
		printf("Error al cargar la textura");
	}
	tex_mapa.setSmooth(true);
	tex_mapa.setRepeated(false);

	this->Cargar();
}
/*********************************************************************/
void Mapa::Guardar(/*int NumMap*/)
{
	//Comprobar si existe un Archivo con ese nombre antes de guardar.
	FILE *Archivo = fopen("Mapas/1.mapa", "wb");
	Nodo *NodoAux=this->Inicio;

	if (Archivo==NULL)
		return;
	
	while(NodoAux!=NULL)
	{
		fwrite(NodoAux, sizeof(Nodo), 1, Archivo);
		NodoAux=NodoAux->Sig;
	}

	fclose(Archivo);
	return;
}
/*********************************************************************/
void Mapa::Cargar(/*int NumMap*/)
{
	FILE *Archivo = fopen("Mapas/1.mapa", "rb");
	Nodo NodoLeido;
	Nodo *Nuevo;
	Nodo *Aux;

	if (Archivo==NULL)
	{
		//std::cout << "[ERROR] Mapa no encontrado" << std::endl;
		return;
	}

	while(!feof(Archivo))
	{
		fread(&NodoLeido, sizeof(Nodo), 1, Archivo);

		if(this->Inicio==NULL)
		{
			this->Inicio=new Nodo();
			this->Inicio->x = NodoLeido.x;
			this->Inicio->y = NodoLeido.y;
			this->Inicio->NumSprite = NodoLeido.NumSprite;

			Aux=this->Inicio;
		}
		else
		{
			Aux->Sig=new Nodo();
			Aux->Sig->Ant=Aux;
			Aux=Aux->Sig;
			Aux->x = NodoLeido.x;
			Aux->y = NodoLeido.y;
			Aux->NumSprite = NodoLeido.NumSprite;
		}
		this->Inicializar(*Aux);
	}

	fclose(Archivo);
	return;
}
/*********************************************************************/
void Mapa::Dibujar(sf::RenderWindow &Ventana)
{
	Nodo *InicioAux=NULL;
	InicioAux=this->Inicio;
	while(InicioAux!=NULL)
	{
		Ventana.draw(InicioAux->SpriteCasillero);
		InicioAux=InicioAux->Sig;
	}
}
/*********************************************************************/
void Mapa::teclado(sf::Event &evento)
{
	if(evento.key.code == sf::Keyboard::G)
	{
		this->Guardar();
		//std::cout << "[AVISO] Mapa guardado"<< std::endl;
	}
}
/*********************************************************************/
void Mapa::EstablecerSprite(Nodo &Casillero)
{
	sf::IntRect frame(0, Casillero.NumSprite*13, 13, 13);
	Casillero.SpriteCasillero.setTextureRect(frame);
	Casillero.SpriteCasillero.setTexture(tex_mapa);
}
/*********************************************************************/
void Mapa::EstablecerPosicion(int X, int Y, Nodo &Casillero)
{
	VectorPosicion Pos = this->CalcularPosicion(X, Y);
	Casillero.SpriteCasillero.setPosition(Pos.x, Pos.y);
}
/*********************************************************************/
void Mapa::Inicializar(Nodo &Casillero)
{
	this->EstablecerSprite(Casillero);
	VectorPosicion Pos = CalcularPosicion(Casillero.x, Casillero.y);
	Casillero.SpriteCasillero.setPosition(Pos.x, Pos.y);
}
/*********************************************************************/
Nodo *Mapa::BuscarNodo(int x, int y)
{
	Nodo *InicioAux=this->Inicio;
	while(InicioAux!=NULL)
	{
		if(InicioAux->x==x && InicioAux->y==y)
			return InicioAux;
		InicioAux=InicioAux->Sig;
	}
	return NULL;
}
/*********************************************************************/
void Mapa::BorrarCasillero(Nodo *Casillero)
{
	if(!Casillero->Ant && !Casillero->Sig)
	{
		delete Casillero;
		return;
	}
	else if(!Casillero->Ant)
	{
		Casillero->Sig->Ant=NULL;
	}
	else if(!Casillero->Sig)
	{
		Casillero->Ant->Sig=NULL;
	}
	else
	{
		Casillero->Ant->Sig=Casillero->Sig;
		Casillero->Sig->Ant=Casillero->Ant;
	}
	delete Casillero;
}
/*********************************************************************/
Nodo *Mapa::CrearCasillero(int X, int Y)
{
	Nodo *Nuevo;
	if (!this->Inicio || Y < this->Inicio->y || (Y==this->Inicio->y && X < this->Inicio->x) )
	{
		if (!this->Inicio)
		{
			this->Inicio = new Nodo();
			this->Inicio->x = X;
			this->Inicio->y = Y;
			this->EstablecerSprite(*this->Inicio);
			this->EstablecerPosicion(X, Y, *this->Inicio);
			return this->Inicio;
		}
		else
		{
			Nuevo = new Nodo();
			Nuevo->x = X;
			Nuevo->y = Y;
			Nuevo->Sig = this->Inicio;
			this->Inicio->Ant = Nuevo;
			Nuevo->Ant = NULL;
			this->Inicio = Nuevo;
		}
	}
	else
	{
		Nodo *Aux = this->Inicio;
		Nuevo = new Nodo();
		Nuevo->x = X;
		Nuevo->y = Y;
		Nuevo->Sig = NULL;
		Nuevo->Ant = NULL;
		while (Aux->Sig && (Aux->Sig->y < Y || (Aux->Sig->y==Y && Aux->Sig->x < X)))
		{
			Aux =  Aux->Sig;
		}
		if (!Aux->Sig)
		{
			Nuevo->Ant = Aux;
			Aux->Sig = Nuevo;
		}
		else
		{
			Aux->Sig->Ant = Nuevo;
			Nuevo->Sig = Aux->Sig;
			Nuevo->Ant = Aux;
			Aux->Sig = Nuevo;	
		}
	}
	this->EstablecerSprite(*Nuevo);
	this->EstablecerPosicion(X, Y, *Nuevo);
	return Nuevo;
}
/*********************************************************************/
VectorPosicion Mapa::CalcularPosicion(int X, int Y)
{
	VectorPosicion Var;
	Var.x=X*13; //13 es el ancho del casillero
	Var.y=Y*13; //13 es el alto del casillero
	return Var;
}
/*********************************************************************/