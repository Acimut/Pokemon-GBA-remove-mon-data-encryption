# Pokemon-GBA-remove-mon-data-encryption
Modificación en C que remueve el encriptado de datos en Pokémon de GBA.


Características:
-
+ Compatibilidad con Pokémon Fire Red.
+ Próximamente compatibilidad con otras rom.
+ Ahora puedes leer y modificar los datos de los pokémon directamente de la memoria y no corromperá al pokémon (huevo malo).
+ Luego de aplicar esta modificación, será necesario iniciar un nuevo juego si ya tienes un archivo de guardado con pokémon.
+ También es posible reacomodar la estructura de datos, siempre que el tamaño de la estructura sea la misma.


***Notas:***

- DevkitARM y ARMIPS son necesarios (versiones más recientes).

- Para compilar es necesario tener preproc.exe y gbagfx.exe dentro alguna ruta de la variable PATH

- Abrir el archivo config.mk, buscar y cambiar ff0000 de la siguiente línea por un offset alineado con suficiente espacio libre:
        `INSERT_INTO ?= 0x08ff0000`
- En el archivo config.mk, buscar la siguiente línea
        `ROM_CODE ?= BPRE`
        - dejar BPRE para compilar usando Fire Red
        - cambiar a BPRS para compilar usando Rojo Fuego en español (disponible próximamente)
        - cambiar a BPEE para compilar usando Emerald (disponible próximamente)

- Compilan ejecutando make con su terminal, y una rom con la inyección aparecerá en una carpeta llamada build.

- Archivos dentro de la carpeta include fueron tomados de pokefirered.

