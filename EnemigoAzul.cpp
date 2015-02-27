#include "EnemigoAzul.h"

EnemigoAzul::EnemigoAzul(SDL_Renderer* renderer, list<Personaje*> *personajes, bool e)
{
    this->ene = e;
    vector<SDL_Texture*>*texturas = new vector<SDL_Texture*>();
    vector<SDL_Texture*>*texturas_left = new vector<SDL_Texture*>();

    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/1.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/2.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/3.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/4.png"));

    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing_left/1.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing_left/2.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing_left/3.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing_left/4.png"));

    mapa_texturas["left"]=texturas_left;
    mapa_texturas["right"]=texturas;

    vector_actual_str = "right";

    rect.x = 70;
    rect.y = 200;

    init(renderer,personajes);
}

EnemigoAzul::~EnemigoAzul()
{
    //dtor
}

int j = 1;
int l = 1;

void EnemigoAzul::act()
{

     rect.x-=j;

    if(rect.x <= 10 || rect.x >= 850 ){
        if( vector_actual_str == "left")
            vector_actual_str = "right";
            else
             vector_actual_str = "left";
        j = j * (-1);
    }

     rect.y+=l;
    if(rect.y >= 250 || rect.y <= 0 ){
        if( vector_actual_str == "left")
            vector_actual_str = "right";
            else
             vector_actual_str = "left";
        l = l * (-1);
    }


    if(frame%400==0)
        atacando = true;
    else
        atacando = false;

    attackCheck();
}



