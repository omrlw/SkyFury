//--------------------------------------------------------------------------------------------

template <typename Recurso, typename Identificador>
void CargarRecursos<Recurso, Identificador> load::(Identificador id, const std::string& filename){
    //Creando y cargando recursos
    std::unique_ptr<Recurso> recurso(new Recurso());
    if (!recurso->loadFromFile(filename))
        throw std::runtime_error("CargarRecursos::load - Failed to load " + filename);

    insertarRecurso(id, std::move(recurso));
}
template <typename Recurso, typename Identificador>

//--------------------------------------------------------------------------------------------
//          SOBRECARGA DE FUNCIONES
//--------------------------------------------------------------------------------------------

template <typename Parametro>
void CargarRecursos<Recurso, Identificador>::cargar(Identificador id, const std::string& filename, const Parametro& secondParam)
{
    //Crear y cargar el recurso
    std::unique_ptr<Recurso> recurso(new Recurso());
    if (!recurso->loadFromFile(filename, secondParam))
        throw std::runtime_error("CargarRecursos::load - Failed to load " + filename);

    insertarRecurso(id, std::move(recurso));
}
template <typename Recurso, typename Identificador>

//--------------------------------------------------------------------------------------------


