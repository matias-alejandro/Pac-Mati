#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

/*********************************************************************/
#define Alto_Pantalla 13*28 //Multiplo de 13
#define Ancho_Pantalla 13*28//793 //Multiplo de 13

#define VelocidadJugador 1.0
#define CantDeSprites 11-1   //TEMPORAL, DESPUES BORRAR
#define DefTamSprite 13
#define DefVidasInit 3
/*********************************************************************/
enum
{
	tipo_bolita,
	tipo_vertical,
	tipo_horizontal,
	tipo_esq_inf_der,
	tipo_esq_inf_izq,
	tipo_esq_sup_izq,
	tipo_esq_sup_der,
	tipo_fin_inf,
	tipo_fin_sup,
	tipo_fin_izq,
	tipo_fin_der
};
/*********************************************************************/
struct VectorPosicion
{
	int x,y;
};
/*********************************************************************/
struct Nodo
{		
	Nodo *Sig=NULL;
	Nodo *Ant=NULL;

	sf::Sprite SpriteCasillero;

	int x,y;
	int NumSprite=0;
	VectorPosicion PosicionReal;
};
/*********************************************************************/
/*void mostrarError(char error[100])
{
	std::cout << "[ERROR] "<< error << std::endl;
}*/
/*********************************************************************/
#endif