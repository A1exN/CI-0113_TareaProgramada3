#ifndef ExcepcionDivideEntreCero_H
#define ExcepcionDivideEntreCero_H

#include <exception>

class ExcepcionNombreInvalido : public std::exception
{
    public:
    ExcepcionNombreInvalido() noexcept = default;
    ~ExcepcionNombreInvalido() = default;

    virtual const char* what() const noexcept {
        return "El nombre de la tienda no puede ser nulo o exceder los 20 caracteres";
    }
};

#endif