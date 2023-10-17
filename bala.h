//
// Created by Omar Chacon on 14/10/23.
//

#ifndef SKYFURY_BALA_H
#define SKYFURY_BALA_H

class Bala {
private:
    int velocidad;
    int impacto;
    float coordenada_bala_x;
    float coordenada_bala_y;
    sf::Texture textura_bala;
    sf::Sprite sprite_bala;
public:

    Bala(float x, float y, int impacto, int velocidad):
        coordenada_bala_x(x), coordenada_bala_y(y), impacto(impacto), velocidad(velocidad)
    {
        textura_bala.loadFromFile("../Resources/Images/bala.png");
        sprite_bala.setTexture(textura_bala);
        sprite_bala.setPosition(coordenada_bala_x, coordenada_bala_y);

    }

    void pintar_bala(sf::RenderWindow& window) {
        sprite_bala.setScale(0.5f, 0.5f); //Escalando tamño de la bala al 50% 0.5f
        window.draw(sprite_bala);
    }

    void mover_bala(sf::RenderWindow& window){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            pintar_bala(window);
            sprite_bala.setPosition(coordenada_bala_x,coordenada_bala_y);

        }

    }




};




#endif //SKYFURY_BALA_H
