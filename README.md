Estructura de un producto:

|    Campo    | Offset | Bytes |
| ----------- |:------:|:-----:|
| ID          | 0      | 4     |
| Nombre      | 4      | 20    |
| Existencias | 24     | 4     |
| Total Bytes |        | 28    |

Estructura de una tienda:

|       Campo       | Offset |   Bytes   |
| ----------------- |:------:|:---------:|
| Nombre            | 0      | 15        |
| Direccion Intenet | 15     | 24        |
| Dieccion Física   | 39     | 24        |
| Teléfono          | 63     |  8        |
| Productos         | 71     | 28*$n$    |
| Total Bytes       |        | 71+28*$n$ |

En donde $n$ es la cantidad de productos en la tienda.