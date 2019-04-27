#Makefile
#
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJS = main.o $(carpetaObjetos)pacman.o $(carpetaObjetos)juego.o $(carpetaObjetos)puntero.o $(carpetaObjetos)mapa.o $(carpetaObjetos)menu.o
carpetaObjetos = Objetos/

all: Pac-Mati

%.o: %.cpp
	g++ -c $< -o $@

%.o: %.hpp
	g++ -c $< -o $@

Pac-Mati: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS)

clean:
	rm -f Pac-Mati *.o $(carpetaObjetos)*.o

install:
	cp Pac-Mati /usr/bin/

uninstall:
	$(RM) /usr/bin/Pac-Mati