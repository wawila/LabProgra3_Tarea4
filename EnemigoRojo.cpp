#include "EnemigoRojo.h"

EnemigoRojo::EnemigoRojo(SDL_Renderer* renderer, list<Personaje*> *personajes, bool e)
{
    this->ene = e;
    vector<SDL_Texture*>*texturas = new vector<SDL_Texture*>();
    vector<SDL_Texture*>*texturas_left = new vector<SDL_Texture*>();

    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/1.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/2.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/3.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/4.png"));

    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing_left/1.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing_left/2.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing_left/3.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing_left/4.png"));

    mapa_texturas["left"]=texturas_left;
    mapa_texturas["right"]=texturas;

    vector_actual_str = "left";
    rect.x = 850;
    rect.y = 200;

    init(renderer, personajes);
}

EnemigoRojo::~EnemigoRojo()
{
    //dtor
}

int i = 1;
void EnemigoRojo::act()
{

    rect.x-=i;

    if(rect.x <= 10 || rect.x >= 855 ){
        if( vector_actual_str == "left")
            vector_actual_str = "right";
            else
             vector_actual_str = "left";
        i = i * (-1);
    }

    if(frame%400==0)
        atacando = true;
    else
        atacando = false;

    attackCheck();

}
