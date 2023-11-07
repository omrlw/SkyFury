#ifndef INCLUDE_IDENTIFICADORTEXTURAS_HPP
#define INCLUDE_IDENTIFICADORTEXTURAS_HPP


namespace sf
{
    class Texturas;
}

namespace Texturas
{
    enum ID //Enumeramos en un identificador
    {
        Falcon,
        Light,
        Fondo1,
    };
}
template <typename Recurso, typename Identificador>
class CargarRecursos;
typedef CargarRecursos<sf::Texturas, Texturas::ID> CargarTexturas;

#endif