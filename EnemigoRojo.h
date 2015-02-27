#ifndef ENEMIGOROJO_H
#define ENEMIGOROJO_H

#include "Enemigo.h"

class EnemigoRojo : public Enemigo
{
    public:
        EnemigoRojo(SDL_Renderer* renderer,list<Personaje*> *personajes, bool e);
        virtual ~EnemigoRojo();

        void act();
    protected:
    private:
};

#endif // ENEMIGOROJO_H
