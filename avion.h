//
// Created by omr_t on 06/10/2023.
//

#ifndef SKYFURY_AVION_H
#define SKYFURY_AVION_H


class Avion {
private:
    float corazones;
    float vidas;
    float velocidad_avion;
    float coordenada_avion_x;
    float coordenada_avion_y;
    sf::Texture textura_avion;
    sf::Sprite sprite_avion;

public:
    //Constructor avion
    Avion(float x, float y, float corazones, float vidas, float velocidad_avion) :
            coordenada_avion_x(x), coordenada_avion_y(y), corazones(corazones), vidas(vidas), velocidad_avion(velocidad_avion)
    {
        //Cargando la textura_avion de la avion (set // get de la libreria)
        textura_avion.loadFromFile("../Resources/Images/avion.png");
        sprite_avion.setTexture(textura_avion);
        sprite_avion.setPosition(coordenada_avion_x, coordenada_avion_y);
    }

    //Dibujando la avion en la ventana
    void pintar_avion(sf::RenderWindow& window) {
        sprite_avion.setScale(0.2f, 0.2f); //Redimenzionando el tamaño de la avion
        window.draw(sprite_avion);
    }

    //Mover avion
    void mover_avion(sf::RenderWindow&) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (coordenada_avion_x < 800 - sprite_avion.getGlobalBounds().width) {
                coordenada_avion_x += velocidad_avion; // Mover hacia la derecha
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (coordenada_avion_x > 0){
                coordenada_avion_x -= velocidad_avion; // Mover hacia la izquierda
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if(coordenada_avion_y > 0) {
                coordenada_avion_y -= velocidad_avion; // Mover hacia arriba
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if(coordenada_avion_y < 750 - sprite_avion.getGlobalBounds().height) {
                coordenada_avion_y += velocidad_avion; // Mover hacia abajo
            }
        }

        // Actualizar la posición del sprite_avion
        sprite_avion.setPosition(coordenada_avion_x, coordenada_avion_y);

    }

    float GetCoordenada_avion_x() {
        return coordenada_avion_x;
    }

    float GetCoordenada_avion_y() {
        return coordenada_avion_y;
    }

};

#endif //SKYFURY_AVION_H