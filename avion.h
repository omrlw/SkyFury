//
// Created by omr_t on 06/10/2023.
//

#ifndef SKYFURY_AVION_H
#define SKYFURY_AVION_H


class Avion {
private:
    int corazones;
    int vidas;
    float coordenada_x;
    float coordenada_y;
    sf::Texture textura;
    sf::Sprite sprite;

public:

    //Constructor avion
    Avion(float x, float y, int corazones, int vidas) :
            coordenada_x(x), coordenada_y(y), corazones(corazones), vidas(vidas)
    {
        //Cargando la textura de la avion
        textura.loadFromFile("../Resources/Images/avion.png");
        sprite.setTexture(textura);
        sprite.setPosition(coordenada_x, coordenada_y);
    }


    //Dibujando la avion en la ventana
    void pintar_avion(sf::RenderWindow& window) {
        sprite.setScale(0.5f, 0.5f); //Redimenzionando el tamaño de la avion
        window.draw(sprite);
    }

    //Mover avion
    void mover_avion(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            coordenada_x += 5; // Mover hacia la derecha
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            coordenada_x -= 5; // Mover hacia la izquierda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            coordenada_y -= 5; // Mover hacia arriba
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            coordenada_y += 5; // Mover hacia abajo
        }

        // Actualizar la posición del sprite
        sprite.setPosition(coordenada_x, coordenada_y);

        // Resto de la lógica de movimiento...
    }


};



#endif //SKYFURY_AVION_H