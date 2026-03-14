*Este proyecto ha sido creado como parte del currículo de 42 por davgarc4.*

# get_next_line

## Descripción

**get_next_line** es un proyecto del currículo de **42** cuyo objetivo es implementar una función en C capaz de leer un archivo **línea por línea** utilizando un descriptor de archivo.

La función `get_next_line` devuelve cada vez que se llama la siguiente línea disponible del archivo hasta llegar al final del mismo. Esto permite trabajar con archivos grandes sin necesidad de cargarlos completamente en memoria.

El proyecto se centra en varios conceptos fundamentales de la programación en C:

- Gestión manual de memoria
- Uso de file descriptors
- Uso de la función `read`
- Manejo de buffers
- Manipulación de strings
- Persistencia de datos entre llamadas mediante variables estáticas

La función mantiene internamente un buffer donde guarda los datos leídos que todavía no se han devuelto como línea completa. Cuando encuentra el separador de línea (`\n`), devuelve la línea correspondiente y conserva el resto para la siguiente llamada.

---

## Instrucciones

### Compilación

Este proyecto está escrito en **C** y puede compilarse con `cc`.

Ejemplo de compilación junto con un programa `main.c`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`BUFFER_SIZE` define el número de bytes que se leerán en cada llamada a `read`.

---

### Uso

La función principal del proyecto es:

```c
char *get_next_line(int fd);
```

Parámetro:

- `fd`: descriptor de archivo desde el que se quiere leer.

Valor de retorno:

- Devuelve una cadena con la siguiente línea del archivo.
- Devuelve `NULL` cuando se alcanza el final del archivo o ocurre un error.

---

### Ejemplo de uso

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}
```

Este programa imprimirá el contenido del archivo **línea por línea**.

---

## Algoritmo utilizado

El algoritmo utilizado se basa en la **lectura incremental del archivo usando un buffer** y en el uso de una **variable estática (`saved`)** para conservar información entre llamadas a la función.

### Funcionamiento paso a paso

1. **Lectura inicial**

Si no existe contenido previo guardado, la función llama a `reader()` para leer `BUFFER_SIZE` bytes desde el archivo.

2. **Búsqueda de salto de línea**

Se busca el carácter separador (`\n`) dentro del buffer guardado utilizando `ft_strchr`.

3. **Si no hay salto de línea**

- Se sigue leyendo del archivo.
- Los nuevos datos se concatenan con los anteriores mediante `ft_strjoin`.
- El proceso continúa hasta encontrar un salto de línea o alcanzar el final del archivo.

4. **Cuando se encuentra un salto de línea**

- Se separa la línea completa.
- Se devuelve esa línea.
- El resto del contenido se guarda en `saved` para la siguiente llamada.

5. **Final del archivo (EOF)**

- Si quedan caracteres en `saved`, se devuelven como última línea.
- Si no queda contenido, se devuelve `NULL`.

---

### Justificación del algoritmo

Este enfoque se eligió por varias razones:

- Permite **leer archivos de cualquier tamaño** sin cargarlos completamente en memoria.
- Reduce el número de llamadas a `read`, mejorando la eficiencia.
- Mantiene el estado entre llamadas mediante una **variable estática**, lo que permite continuar leyendo exactamente donde se dejó.
- Mantiene un consumo de memoria controlado gracias al uso del `BUFFER_SIZE`.

Este diseño sigue la estrategia clásica usada en sistemas Unix para la lectura incremental de archivos.

---

## Funciones auxiliares

El proyecto implementa varias funciones auxiliares para manipular strings:

- `ft_strlen` → calcula la longitud de una cadena
- `ft_strchr` → busca un carácter en una cadena
- `ft_strdup` → duplica una cadena
- `ft_strjoin` → concatena dos cadenas

Estas funciones replican funcionalidades de la librería estándar pero se implementan manualmente como parte del aprendizaje del proyecto.

---

## Recursos

Documentación y referencias utilizadas para el proyecto:

Manual de `read`  
https://man7.org/linux/man-pages/man2/read.2.html

Documentación sobre file descriptors  
https://man7.org/linux/man-pages/man2/open.2.html

Documentación del lenguaje C  
https://en.cppreference.com/w/c

Guía de gestión de memoria en C  
https://www.gnu.org/software/libc/manual/html_node/Memory-Allocation.html

---

### Uso de IA

Se ha utilizado IA como herramienta de apoyo en las siguientes tareas:

- Revisión de explicaciones teóricas del algoritmo.
- Mejora de la redacción de la documentación del proyecto.
- Organización del contenido del archivo README.

La implementación del código y la lógica principal del algoritmo han sido desarrolladas manualmente.