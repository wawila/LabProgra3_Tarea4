#include "EnemigoVerde.h"

EnemigoVerde::EnemigoVerde(SDL_Renderer* renderer, list<Personaje*> *personajes, bool e)
{
    this->ene = e;
    vector<SDL_Texture*>*texturas = new vector<SDL_Texture*>();
    vector<SDL_Texture*>*texturas_left = new vector<SDL_Texture*>();

    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/1.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/2.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/3.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/4.png"));

    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing_left/1.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing_left/2.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing_left/3.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing_left/4.png"));

    mapa_texturas["left"] = texturas_left;
    mapa_texturas["right"] = texturas;

    vector_actual_str = "right";

    rect.x = 350;
    rect.y = 50;

    init(renderer, personajes);
}

EnemigoVerde::~EnemigoVerde()
{
    //dtor
}

    int k = 1;

void EnemigoVerde::act()
{
      rect.y+=k;
    if(rect.y >= 250 || rect.y <= 0 ){
        if( vector_actual_str == "left")
            vector_actual_str = "right";
            else
             vector_actual_str = "left";
        k = k * (-1);
    }

    if(frame%300==0)
        atacando = true;
    else
        atacando = false;

    attackCheck();

}
