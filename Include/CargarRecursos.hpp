#ifndef INCLUDE_CARGARRECURSOS_HPP
#define INCLUDE_CARGARRECURSOS_HPP

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename Recurso, typename Identificador>
class CargarRecursos{
public:
    void cargar(Identificador id, const std::string& filename);

    template <typename Parameter>
    void cargar(Identificador id, const std::string& filename, const Parameter& secondParam);

    Recurso& get(Identificador id);
    const Recurso& get(Identificador id) const;



};




#endif