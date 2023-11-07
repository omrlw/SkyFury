#ifndef INCLUDE_ESCENA_HPP
#define INCLUDE_ESCENA_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

class Escena :  public sf::Transformable, public sf::Drawable, private sf::NonCopyable{
public:
    typedef std::unique_ptr<Escena> Ptr; //Creando puntero encargadore de liberar memoria

    Escena();



};






#endif