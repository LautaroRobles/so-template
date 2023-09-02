# Estructura del proyecto

- **.vscode** - en esta carpeta se guardan archivos de configuracion que permiten que funcione el Debugger en VSCode 
- **build** - en esta carpeta se guardan los binarios compilados por el Makefile
- **cpu | kernel | memoria | filesystem** - cada modulo es una carpeta y todos tienen la misma subestructura:
    - **config** - guardamos las configs para el modulo
    - **logs** - guardamos los logs de ejecucion del modulo
    - **src** - codigo fuente del modulo, archivos .c y .h<br>
    (pueden estar en subcarpetas "cpu/src/subcarpeta/codigo.c")
- **shared** - este es un modulo especial. No tiene carpeta src y contiene codigo que puede ser utilizado por cualquier modulo.<br>
Para poder importar codigo de `shared` en un modulo se debe escribir en el header `#include <shared/estructuras.h>` (puede ser estructuras.h o algun otro, siempre tienen que ser .h porque ahi van la definicion de tipos y funciones)
- **Makefile** - el archivo Makefile nos permitira *compilar*, *correr* y *probar con valgrind* cada uno de los modulos.<br>
Es basicamente un conjunto de "targets", cada "target" es una secuencia de comandos a ejecutar. Por ejemplo `make install-commons` lo que hace es clonarse el repo de las biblioteca de la catedra, compilarla e instalarla en el sistema. <br>
`make cpu` compila todos los archivos dentro de la carpeta "cpu" y crea un ejecutable llamado "cpu" dentro de "build".

# ¿Puedo probar que funciona?

Primero instalamos las commons (Biblioteca de la catedra)

```
make install-commons
```

Ejecutar algun modulo (cpu | kernel | memoria | filesystem)

```
make run modulo=cpu
```

El target `run` acepta ademas el argumento **parametros**

```
make run modulo=cpu parametros="arg1 arg2 config/cpu.config etc"
```

# Makefile

Para poder ver todos los targets disponibles correr

```
make help
```

# Valgrind

Instalar **valgrind** 
```
sudo apt-get install valgrind
```

Ejecutar un modulo usando valgrind 

```
make valgrind modulo=cpu
```

## Debug

Instalar la extension de [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) para VSCode.

Instalar **gdb** 
```
sudo apt-get install gdb
```

En **VSCode** agregar breakpoints en algun modulo y presionar F5, elegir el modulo a debuggear y agregar parametros si es necesario.
