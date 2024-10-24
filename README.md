# Juego del Gato (Tres en Raya) en C++

Una implementación avanzada del clásico juego Tres en Raya (Tic-Tac-Toe) desarrollada en C++, utilizando programación orientada a objetos y estructuras de datos dinámicas. Este proyecto demuestra la aplicación práctica de conceptos fundamentales de POO como herencia, encapsulamiento y manejo de memoria dinámica.

## Características Principales

- 🎮 Sistema de coordenadas alfanuméricas (ejemplo: A1, B2, C3)
- 📝 Registro histórico de partidas con fecha y hora
- 👥 Gestión dinámica de jugadores
- 💾 Persistencia de datos en archivo
- 🔄 Sistema de turnos automatizado
- ⚡ Interfaz de consola limpia y profesional

## Estructura del Proyecto

### Clases Principales
- `Jugador`: Gestión de información de jugadores
- `Tablero`: Lógica del tablero y validaciones
- `Juego`: Hereda de Tablero, maneja la lógica principal
- `Jugada`: Estructura para el historial de movimientos

### Características Técnicas

#### Gestión de Memoria
- Implementación de lista enlazada para histórico de jugadas
- Manejo dinámico de memoria
- Limpieza automática de recursos

#### Validaciones
- Control de coordenadas válidas
- Verificación de casillas ocupadas
- Detección automática de victoria
- Control de empates

#### Almacenamiento
- Registro de partidas en archivo de texto
- Almacenamiento de fecha y hora de cada partida
- Historial consultable de ganadores

## Funcionalidades del Menú

1. 🎮 Iniciar Nueva Partida
2. 👥 Modificar Nombres de Jugadores
3. 📊 Consultar Historial de Ganadores
4. ℹ️ Ver Créditos del Equipo
5. ❓ Ayuda y Coordenadas
6. 🚪 Salir del Juego

## Características Técnicas Destacadas

- **Multiplataforma**: Compatibilidad con Windows y sistemas Unix
- **Entrada/Salida**: Manejo de archivos con `fstream`
- **Gestión del Tiempo**: Implementación de `ctime` para registro temporal
- **Estructuras Dinámicas**: Lista enlazada para histórico de movimientos
- **Herencia**: Implementación de herencia simple para extensibilidad
- **Validación**: Sistema robusto de validación de entradas
- **Interfaz**: Sistema de limpieza de pantalla multiplataforma

## Equipo de Desarrollo
- Michell Alexis Policarpio Moran - zS21002379
- Samuel Obed Garcia Velandia - zS21002413
- Luis Fernando Bravo Ibanez - zS21002428

## Contexto Académico
Desarrollado para la asignatura de Paradigmas de Programación II
Facultad de Ingeniería Eléctrica y Electrónica - Universidad Veracruzana

## Requisitos del Sistema
- Compilador C++ con soporte para C++11 o superior
- Sistema operativo compatible (Windows/Unix)
- Terminal con soporte para comandos de limpieza de pantalla

## Instrucciones de Compilación
```bash
g++ -o juego_gato main.cpp -std=c++11
```

## Instrucciones de Uso
1. Ejecutar el programa compilado
2. Ingresar nombres de los jugadores
3. Utilizar coordenadas alfanuméricas (A1-C3) para realizar jugadas
4. Seguir las instrucciones en pantalla para navegación del menú

## Notas de Implementación
- Uso de programación orientada a objetos
- Implementación de herencia simple
- Manejo de memoria dinámica
- Sistema de coordenadas intuitivo
- Validaciones robustas de entrada
- Persistencia de datos en archivo

Este proyecto representa una implementación robusta y profesional del clásico juego del gato, demostrando buenas prácticas de programación y diseño orientado a objetos.
