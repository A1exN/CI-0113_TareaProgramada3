#include <gtest/gtest.h>
#include "./../src/tienda.h"

namespace
{
    TEST(Tienda_Test, Test_Agregar_y_Obtener_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Arroz", 4);

        tienda->AgregarProducto(arroz);

        // Act - ejecute la operación
        Producto *actual = tienda->ObtenerProducto(1);
        Producto *esperado = arroz;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Test_Eliminar_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Bolsas de Arroz", 200);
        Producto *latasMaiz = new Producto(2, "Maíz en lata", 50);

        tienda->AgregarProducto(arroz);
        tienda->AgregarProducto(latasMaiz);

        // Act - ejecute la operación
        tienda->EliminarProducto(2);
        ostringstream streamListaProductos;
        streamListaProductos << tienda;

        string actual = streamListaProductos.str();
        string esperado = "Productos:\n1. Bolsas de Arroz. En existencia: 200\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Test_Modificar_Nombre_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Bolsas de Arroz", 200);
        Producto *latasMaiz = new Producto(2, "Maíz en lata", 50);

        tienda->AgregarProducto(arroz);
        tienda->AgregarProducto(latasMaiz);

        // Act - ejecute la operación
        tienda->ModificarNombreProducto(2, "Atún en lata");
        ostringstream streamListaProductos;
        streamListaProductos << tienda;
        string actual = streamListaProductos.str();
        string esperado = "Productos:\n1. Bolsas de Arroz. En existencia: 200\n2. Atún en lata. En existencia: 50\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Test_Modificar_Existencias_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Bolsas de Arroz", 200);
        Producto *latasMaiz = new Producto(2, "Maíz en lata", 50);

        tienda->AgregarProducto(arroz);
        tienda->AgregarProducto(latasMaiz);

        // Act - ejecute la operación
        tienda->ModificarExistenciasProducto(1, 150);
        ostringstream streamListaProductos;
        streamListaProductos << tienda;
        string actual = streamListaProductos.str();
        string esperado = "Productos:\n1. Bolsas de Arroz. En existencia: 150\n2. Maíz en lata. En existencia: 50\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

    TEST(Tienda_Test, Test_Consultar_Productos)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("La Principal", "www.laprincipal.com", "Avenida 2nda, local #2", "88888888");

        Producto *arroz = new Producto(1, "Bolsas de Arroz", 200);
        Producto *latasMaiz = new Producto(2, "Maíz en lata", 50);

        tienda->AgregarProducto(arroz);
        tienda->AgregarProducto(latasMaiz);

        // Act - ejecute la operación
        ostringstream streamListaProductos;
        streamListaProductos << tienda;
        string actual = streamListaProductos.str();
        string esperado = "Productos:\n1. Bolsas de Arroz. En existencia: 200\n2. Maíz en lata. En existencia: 50\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

        delete tienda;
    }

}