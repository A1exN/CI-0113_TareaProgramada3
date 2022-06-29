#include "tienda.h"
#include <sstream>

Tienda::Tienda(string nombreTienda, string direccionInternet, string direccionFisica, string telefono)
{
    strcpy(this->nombreTienda, nombreTienda.c_str());
    strcpy(this->direccionInternet, direccionInternet.c_str());
    strcpy(this->direccionFisica, direccionFisica.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Tienda::Tienda()
{
    strcpy(this->nombreTienda, "");
    strcpy(this->direccionInternet, "");
    strcpy(this->direccionFisica, "");
    strcpy(this->telefono, "");
}

Tienda::~Tienda()
{
    for (Producto *producto : this->productos)
    {
        delete producto;
    }
}

void Tienda::AgregarProducto(Producto *producto)
{
    this->productos.push_back(producto);
}

Producto* Tienda::ObtenerProducto(int idProducto)
{
    return this->productos.at(idProducto - 1);   
}

void Tienda::EliminarProducto(int idProducto)
{
    this->productos.erase(this->productos.begin() + (idProducto - 1));
}

void Tienda::ModificarNombreProducto(int idProducto, string nuevoNombreProducto)
{
    this->productos.at(idProducto - 1)->ModificarNombre(nuevoNombreProducto);
}

void Tienda::ModificarExistenciasProducto(int idProducto, int nuevaCantidadEnExistencia)
{
    this->productos.at(idProducto - 1)->ModificarExistencias(nuevaCantidadEnExistencia);
}

void Tienda::CargarDesdeStreamBinario(istream *streamEntrada)
{
    // Agregar Información de la tienda
    streamEntrada->read(this->nombreTienda, 15);
    streamEntrada->read(this->direccionInternet, 24);
    streamEntrada->read(this->direccionFisica, 24);
    streamEntrada->read(this->telefono, 8);

    // Determinar la cantidad de productos
    streamEntrada->seekg(0, std::ios::end);
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = (cantidadBytesEnArchivo - 71) / sizeof(Producto);
    
    // Leer cada producto
    streamEntrada->seekg(71);
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto));

        this->AgregarProducto(producto);
    }
}

void Tienda::GuardarEnStreamBinario(ostream *streamSalida)
{
    streamSalida->write(this->nombreTienda, 15);
    streamSalida->write(this->direccionInternet, 24);
    streamSalida->write(this->direccionFisica, 24);
    streamSalida->write(this->telefono, 8);

    for (Producto *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << "Productos:" << std::endl;

    for (Producto *producto : tienda->productos)
    {
        o << producto << endl;
    }
    
    return o;
}