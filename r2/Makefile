CC     = gcc
CFLAGS = -g
LIBS   = -lstdc++ -lglut -lGL -lGLU -lm -L/usr/X11R6/lib -lX11 -lXext -lXmu -lXi -lglui -lm
CFILES = error.c utilitaire.c graphic.c projecteur.c reflecteur.c photon.c \
 absorbeur.c modele.c rendu2.cpp
OFILES = $(CFILES:.cpp=.o)
CIBLE  = rendu2.x

$(CIBLE): $(OFILES)
	$(CC) $(OFILES) ${LIBS} -o $(CIBLE)


rendu2.o: rendu2.cpp
	$(CC) -c rendu2.cpp $(CFLAGS)

# Definitions de cibles particulieres :

depend:
	@echo " *** MISE A JOUR DES DEPENDANCES ***"
	@(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	  $(CC) -MM $(CFLAGS) $(CFILES) | \
	  egrep -v "/usr/include" \
	 ) >Makefile.new
	@mv Makefile.new Makefile

clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f *.o *.x



error.o: error.c error.h
utilitaire.o: utilitaire.c utilitaire.h constantes.h tolerance.h
projecteur.o: projecteur.c projecteur.h constantes.h tolerance.h error.h \
 utilitaire.h
reflecteur.o: reflecteur.c reflecteur.h constantes.h tolerance.h error.h \
 utilitaire.h
photon.o: photon.c photon.h constantes.h tolerance.h error.h utilitaire.h
absorbeur.o: absorbeur.c absorbeur.h constantes.h tolerance.h error.h \
 utilitaire.h
modele.o: modele.c modele.h constantes.h tolerance.h error.h projecteur.h \
 utilitaire.h
rendu2.o: rendu2.cpp modele.h constantes.h tolerance.h error.h \
 projecteur.h utilitaire.h
error.o: error.c error.h
utilitaire.o: utilitaire.c utilitaire.h constantes.h tolerance.h
projecteur.o: projecteur.c projecteur.h constantes.h tolerance.h error.h \
 utilitaire.h
reflecteur.o: reflecteur.c reflecteur.h constantes.h tolerance.h error.h \
 utilitaire.h
photon.o: photon.c photon.h constantes.h tolerance.h error.h utilitaire.h
absorbeur.o: absorbeur.c absorbeur.h constantes.h tolerance.h error.h \
 utilitaire.h
modele.o: modele.c modele.h constantes.h tolerance.h error.h projecteur.h \
 utilitaire.h
rendu2.o: rendu2.cpp modele.h constantes.h tolerance.h error.h \
 projecteur.h utilitaire.h
error.o: error.c error.h
utilitaire.o: utilitaire.c utilitaire.h constantes.h tolerance.h
projecteur.o: projecteur.c projecteur.h constantes.h tolerance.h error.h \
 utilitaire.h
reflecteur.o: reflecteur.c reflecteur.h constantes.h tolerance.h error.h \
 utilitaire.h
photon.o: photon.c photon.h constantes.h tolerance.h error.h utilitaire.h
absorbeur.o: absorbeur.c absorbeur.h constantes.h tolerance.h error.h \
 utilitaire.h
modele.o: modele.c modele.h constantes.h tolerance.h error.h reflecteur.h \
 utilitaire.h projecteur.h absorbeur.h photon.h
rendu2.o: rendu2.cpp modele.h constantes.h tolerance.h error.h \
 reflecteur.h utilitaire.h projecteur.h absorbeur.h photon.h
error.o: error.c error.h
utilitaire.o: utilitaire.c utilitaire.h
projecteur.o: projecteur.c projecteur.h constantes.h tolerance.h error.h \
 utilitaire.h
reflecteur.o: reflecteur.c reflecteur.h constantes.h tolerance.h error.h \
 utilitaire.h graphic.h
photon.o: photon.c photon.h constantes.h tolerance.h error.h utilitaire.h
absorbeur.o: absorbeur.c absorbeur.h constantes.h tolerance.h error.h \
 utilitaire.h
modele.o: modele.c modele.h constantes.h tolerance.h error.h reflecteur.h \
 utilitaire.h absorbeur.h projecteur.h photon.h
rendu2.o: rendu2.cpp modele.h constantes.h tolerance.h error.h \
 reflecteur.h utilitaire.h absorbeur.h projecteur.h photon.h
error.o: error.c error.h
utilitaire.o: utilitaire.c utilitaire.h constantes.h tolerance.h
graphic.o: graphic.c graphic.h
projecteur.o: projecteur.c projecteur.h constantes.h tolerance.h error.h \
 utilitaire.h photon.h graphic.h
reflecteur.o: reflecteur.c reflecteur.h constantes.h tolerance.h error.h \
 utilitaire.h graphic.h
photon.o: photon.c photon.h constantes.h tolerance.h error.h utilitaire.h
absorbeur.o: absorbeur.c absorbeur.h constantes.h tolerance.h error.h \
 utilitaire.h graphic.h
modele.o: modele.c modele.h constantes.h tolerance.h error.h reflecteur.h \
 utilitaire.h projecteur.h absorbeur.h photon.h
rendu2.o: rendu2.cpp modele.h constantes.h tolerance.h error.h \
 reflecteur.h utilitaire.h projecteur.h absorbeur.h photon.h
error.o: error.c error.h
utilitaire.o: utilitaire.c utilitaire.h constantes.h tolerance.h
graphic.o: graphic.c graphic.h
projecteur.o: projecteur.c projecteur.h constantes.h tolerance.h error.h \
 utilitaire.h graphic.h
reflecteur.o: reflecteur.c reflecteur.h constantes.h tolerance.h error.h \
 utilitaire.h graphic.h
photon.o: photon.c photon.h constantes.h tolerance.h error.h utilitaire.h \
 graphic.h
absorbeur.o: absorbeur.c absorbeur.h constantes.h tolerance.h error.h \
 utilitaire.h graphic.h
modele.o: modele.c modele.h constantes.h tolerance.h error.h utilitaire.h \
 reflecteur.h projecteur.h absorbeur.h photon.h
rendu2.o: rendu2.cpp modele.h constantes.h tolerance.h error.h \
 utilitaire.h reflecteur.h projecteur.h absorbeur.h photon.h graphic.h
