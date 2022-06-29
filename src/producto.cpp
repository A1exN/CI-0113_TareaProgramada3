#include "producto.h"

Producto::Producto(int id, string nombreProducto, int existencias)
{
    this->id = id;
    strcpy(this->nombreProducto, nombreProducto.c_str());
    this->existencias = existencias;
}

Producto::Producto()
{
    this->id = 0;
    strcpy(this->nombreProducto, "");
    this->existencias = 0;
}

Producto::~Producto()
{

}

void Producto::ModificarNombre(string nuevoNombre)
{
    strcpy(this->nombreProducto, nuevoNombre.c_str());
}

void Producto::ModificarExistencias(int nuevaCantidadEnExistencia)
{
    this->existencias = nuevaCantidadEnExistencia;
}

ostream& operator << (ostream &streamSalida, const Producto *producto)
{
    streamSalida << producto->id << ". " << producto->nombreProducto << ". En existencia: " << producto->existencias;

    return streamSalida;
}