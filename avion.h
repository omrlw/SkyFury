//
// Created by omr_t on 06/10/2023.
//

#ifndef SKYFURY_AVION_H
#define SKYFURY_AVION_H


class Avion {
private:
    int corazones;
    int vidas;
    int coordenada_avion_x;
    int coordenada_avion_y;
    sf::Texture textura_avion;
    sf::Sprite sprite_avion;

public:

    //Constructor avion
    Avion(int x, int y, int corazones, int vidas) :
            coordenada_avion_x(x), coordenada_avion_y(y), corazones(corazones), vidas(vidas)
    {
        //Cargando la textura_avion de la avion
        textura_avion.loadFromFile("../Resources/Images/avion.png");
        sprite_avion.setTexture(textura_avion);
        sprite_avion.setPosition(coordenada_avion_x, coordenada_avion_y);
    }


    //Dibujando la avion en la ventana
    void pintar_avion(sf::RenderWindow& window) {
        sprite_avion.setScale(0.5f, 0.5f); //Redimenzionando el tamaño de la avion
        window.draw(sprite_avion);
    }

    //Mover avion
    void mover_avion(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (coordenada_avion_x < 800 - sprite_avion.getGlobalBounds().width) {
                coordenada_avion_x += 5; // Mover hacia la derecha
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (coordenada_avion_x > 0){
                coordenada_avion_x -= 5; // Mover hacia la izquierda
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if(coordenada_avion_y > 0) {
                coordenada_avion_y -= 5; // Mover hacia arriba
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if(coordenada_avion_y < 750 - sprite_avion.getGlobalBounds().height) {
                coordenada_avion_y += 5; // Mover hacia abajo
            }
        }

        // Actualizar la posición del sprite_avion
        sprite_avion.setPosition(coordenada_avion_x, coordenada_avion_y);
    }


};

#endif //SKYFURY_AVION_H