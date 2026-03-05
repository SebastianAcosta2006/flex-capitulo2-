# flex-capitulo2-

# Ejercicios Capítulo 2 - Flex

Repositorio con la implementación de los ejercicios del Capítulo 2 de flex con instrucciones para compilarlo pantallazos y pruebas todas en la maquina virtual con mi nombre 

REQUISITOS PARA LA EJECUCION 

Paquetes:

flex
sudo apt install flex gcc make git -y
 <img width="1280" height="800" alt="SSSSSSSSSSSSSS" src="https://github.com/user-attachments/assets/76b56210-6c89-416f-a0eb-501bdf6ab051" />

Instalacion:

sudo apt update
<img width="1280" height="800" alt="ssss" src="https://github.com/user-attachments/assets/99a0301a-5458-4166-882b-c68e08b80484" />

sudo apt install -y flex gcc 
Verificacion:

flex --version
gcc --version

## Ejercicio 1

El ejemplo original compara caracteres uno a uno.
Se modificó el patrón para reconocer líneas completas usando:

[^\n]*\n

Esto permite coincidir con bloques de texto más grandes evitando el uso incorrecto de:

^.*\n

ya que el operador `.` en Flex no incluye el salto de línea.

### Compilación

flex ejercicio1.l
gcc lex.yy.c -o ejercicio1

### Ejecución

./ejercicio1

PRUEBAS: 
<img width="1280" height="800" alt="PRIMER EJERCICIO CAPITULO 2 DE FLEX" src="https://github.com/user-attachments/assets/8ea04b1e-2612-453a-8745-da1194fc50e7" />

## Ejercicio 2

Se modificó el programa de concordancia para que no distinga entre mayúsculas y minúsculas.

Cambios realizados:

- Uso de `tolower()` en la función `symhash()`
- Uso de `strcasecmp()` para comparar palabras

Esto permite que palabras como:
Casa
casa
CASA
se traten como una sola entrada.

Compilación
gcc ejercicio2.c -o ejercicio2

PRUEBAS
<img width="1280" height="800" alt="captura de pantalla ejercicio 2" src="https://github.com/user-attachments/assets/2cd34730-eed8-4beb-8382-c3b38e8bea41" />
<img width="1280" height="800" alt="ejercicio 2 prueba 2" src="https://github.com/user-attachments/assets/9bc3f1d0-4c78-4cc6-9a4b-6806a612fe89" />

## Ejercicio 3

La tabla de símbolos original tenía tamaño fijo.
Se implementó chaining (encadenamiento) para permitir un número variable de elementos en la tabla hash.

Cada posición de la tabla contiene una lista enlazada de palabras, evitando que el programa falle cuando la tabla se llena.

Compilación
gcc ejercicio3.c -o ejercicio3

PRUEBAS
<img width="1280" height="800" alt="ejercicio 3" src="https://github.com/user-attachments/assets/9ebe3f69-1f46-4e9b-b88b-573bb2ccf67d" />

