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

VectorPosicion CalcularPosicion(int X, int Y)
{
	VectorPosicion Var;
	Var.x=X*13; //13 es el ancho del casillero
	Var.y=Y*13; //13 es el alto del casillero
	return Var;
}
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