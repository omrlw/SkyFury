//
// Created by Omar Chacon on 14/10/23.
//


#ifndef SKYFURY_BALA_H
#define SKYFURY_BALA_H

#include "avion.h"
#include <list>
#include <iterator>
using namespace std;
class Bala {
private:
    int velocidad;
    int impacto;
    float coordenada_bala_x;
    float coordenada_bala_y;
    sf::Texture textura_bala;
    sf::Sprite sprite_bala;

    list<Bala*> bala_lista;

public:

    Bala(float x, float y, int impacto, int velocidad):
        coordenada_bala_x(x), coordenada_bala_y(y), impacto(impacto), velocidad(velocidad)
    {
        textura_bala.loadFromFile("../Resources/Images/bala.png");
        sprite_bala.setTexture(textura_bala);
        sprite_bala.setPosition(coordenada_bala_x, coordenada_bala_y);

    }

    void pintar_bala(sf::RenderWindow& window) {
        sprite_bala.setScale(0.2f, 0.1f); //Escalando tamño de la bala al 50% 0.5f
        window.draw(sprite_bala);
    }

    void mover_bala(sf::RenderWindow& window,  Avion& avion){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            bala_lista.push_back(new Bala(avion.GetCoordenada_avion_x() + 10, avion.GetCoordenada_avion_y(), 0,1));
            sprite_bala.setPosition(avion.GetCoordenada_avion_x() + 10,avion.GetCoordenada_avion_y());
            pintar_bala(window);
        }
//        for (list<Bala*>::iterator it = bala_lista.begin(); it != bala_lista.end(); ) {
//            Bala* b = *it;
//            b->mover_bala(window, avion);
//
//
//            if (b->coordenada_bala_x <= 0) {
//                delete b;
//                it = bala_lista.erase(it);
//            }
//            else {
//                ++it;
//            }
//        }


    }




};




#endif //SKYFURY_BALA_H
