//
// Created by omr_t on 06/10/2023.
//

#ifndef SKYFURY_AVION_H
#define SKYFURY_AVION_H


class Avion {
private:
    int coordenada_x;
    int coordenada_y;
    int corazones;
    int vidas;
    sf::Texture textura;
    sf::Sprite sprite;

public:
    //Constructor avion
    Avion(int x, int y, int corazones, int vidas) :
            coordenada_x(x), coordenada_y(y), corazones(corazones), vidas(vidas)
    {
        if (!textura.loadFromFile("Resources/Images/avion.png")) {
            // Manejar el error si no se puede cargar la textura
        }
        sprite.setTexture(textura);
        sprite.setPosition(coordenada_x, coordenada_y);
    }

    int getcoordenada_x() {
        return coordenada_x;
    }
    int getcoordenada_y() {
        return coordenada_y;
    }
    int getvidas() {
        return vidas;
    }
    int getcorazones() {
        return corazones;
    }

    void pintar_avion(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    //Mover avion
    void mover_avion(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (coordenada_x + sprite.getLocalBounds().width < window.getSize().x) {
                coordenada_x += 5;
                sprite.setPosition(coordenada_x, coordenada_y);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (coordenada_x > 0) {
                coordenada_x -= 5;
                sprite.setPosition(coordenada_x, coordenada_y);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if (coordenada_y > 0) {
                coordenada_y -= 5;
                sprite.setPosition(coordenada_x, coordenada_y);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if (coordenada_y + sprite.getLocalBounds().height < window.getSize().y) {
                coordenada_y += 5;
                sprite.setPosition(coordenada_x, coordenada_y);
            }
        }
    }
};



#endif //SKYFURY_AVION_H
