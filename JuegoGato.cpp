#include<iostream>
#include<fstream>
#include<ctime>
#include<limits>
using namespace std;

void limpiarPantalla();  //Limpia la pantalla según el sistema operativo

//Estructura de lista simple enlazada para representar una jugada
struct Jugada{
    int fila, columna;   //Almacenar coordenadas de la jugada
    char jugador;        //Almacenar simbolo del jugador ('X' o 'O')
    Jugada* siguiente;   //Puntero a la siguiente jugada en el historial :p

    Jugada(int f, int c, char j, Jugada* sig = nullptr) 
        : fila(f), columna(c), jugador(j), siguiente(sig) {}
};

// Clase Jugador 
class Jugador{
public:
    string nombre;
    char simbolo;

    Jugador(string n, char s) : nombre(n), simbolo(s){}

    void imprimirInfo()
    {
        cout<<"Jugador: " << nombre << " con simbolo: " << simbolo << endl;
    }
};

// Clase Tablero 
class Tablero{
private:
    char tablero[3][3];
    Jugada* historial;

public:
    Tablero()
    {
        resetear();
        historial = nullptr;
    }

    void resetear()
    {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                tablero[i][j] = ' ';
    }

    //Imprime el tablero actual en consola
    void imprimir() 
    {
        limpiarPantalla();
        cout<<"\t************************************"<<endl;
        cout<<"\t**********JUEGO DEL GATO************"<<endl;
        cout<<"\t************************************\n"<<endl;
        
        // Agregar las etiquetas de las columnas A, B, C
        cout<<"   A  B  C"<<endl;

        for(int i = 0; i < 3; ++i) 
        {
            // Imprimir la etiqueta de la fila 1, 2, 3
            cout<<i + 1<<" ";
            for(int j = 0; j < 3; ++j)
            {
                cout<<tablero[i][j];
                if(j < 2) cout<<" | ";  // Separadores de columnas
            }
            cout<<endl;
            if(i < 2) cout<<"  --+---+--"<<endl;  // Separadores de filas
        }
    }

    //Revisa si una posición está ocupada
    int estaOcupada(int fila, int columna) 
    {
        return tablero[fila][columna] != ' ' ? 1 : 0;
    }

    //Coloca el símbolo de un jugador en el tablero y guarda la jugada en el historial
    void colocarSimbolo(int fila, int columna, char simbolo)
    {
        tablero[fila][columna] = simbolo;
        guardarJugada(fila, columna, simbolo);
    }

    //Verifica si un jugador ha ganado
    int hayGanador(char simbolo)
    {
        for(int i = 0; i < 3; ++i)
        {
            if(tablero[i][0] == simbolo && tablero[i][1] == simbolo && tablero[i][2] == simbolo) 
            {
                return 1;  //Revisa filas
            }
        }

        for(int i = 0; i < 3; ++i)
        {
            if(tablero[0][i] == simbolo && tablero[1][i] == simbolo && tablero[2][i] == simbolo) 
            {
                return 1;  //Revisa columnas
            }
        }
        // Revisa diagonales
        if(tablero[0][0] == simbolo && tablero[1][1] == simbolo && tablero[2][2] == simbolo)
        {
            return 1;
        }

        if(tablero[0][2] == simbolo && tablero[1][1] == simbolo && tablero[2][0] == simbolo)
        {
            return 1;
        }

        return 0;
    }

    //Guarda cada jugada en una lista enlazada
    void guardarJugada(int fila, int columna, char jugador)
    {
        Jugada* nueva = new Jugada(fila, columna, jugador, historial);
        historial = nueva;
    }

    //Guarda el resultado de la partida en un archivo de texto
    void guardarResultado(string ganador)
    {
        ofstream archivo("resultados.txt", ios::app);
        if(archivo.is_open())
        {
            //Obtener la fecha y hora actual
            time_t ahora = time(0);
            struct tm* tm_info = localtime(&ahora);
            char fecha_hora[80];

            //Formatear fecha y hora
            strftime(fecha_hora, sizeof(fecha_hora), "%d/%b/%Y - %H:%M:%S", tm_info);

            //Escribir en el archivo
            archivo<<"GANADOR: "<<ganador<<endl;
            archivo<<"FECHA Y HORA: "<<fecha_hora<<endl; //Guardar fecha y hora
            archivo<<"-------------------------------------"<<endl; //Separador para claridad
            archivo.close();
        }
    }

    // Ver coordenadas por cuadro del tablero
    void verCoordenadasPorCuadro()
    {
        limpiarPantalla();
        cout<<"\t*************************************"<<endl;
        cout<<"\t****** COORDENADAS DEL TABLERO ******"<<endl;
        cout<<"\t*************************************\n"<<endl;
        cout<<"\nCoordenadas por cuadro del tablero:\n";
        cout<<"  A1 | A2 | A3\n";
        cout<<"  B1 | B2 | B3\n";
        cout<<"  C1 | C2 | C3\n";
    }

    // Ver historial de ganadores
    void verHistorial()
    {
        limpiarPantalla();
        cout<<"\t********************************************"<<endl;
        cout<<"\t********HISTORIAL (resultados.txt)**********"<<endl;
        cout<<"\t*******************************************\n"<<endl;
        ifstream archivo("resultados.txt");
        string linea;
        if(archivo.is_open())
        {
            while(getline(archivo, linea))
            {
                cout<<linea << endl;
            }
            archivo.close();
        } else {
            cout<<"No se ha encontrado el archivo de historial.\n";
        }
    }

    // Mostrar información del equipo
    void verEquipo()
    {
        limpiarPantalla();
        cout<<"\t********************************************"<<endl;
        cout<<"\t**********INFORMACION DEL EQUIPO************"<<endl;
        cout<<"\t********************************************\n"<<endl;

        cout<<"-Michell Alexis Policarpio Moran - zS21002379"<<endl;
        cout<<"-Samuel Obed Garcia Velandia - zS21002413"<<endl;
        cout<<"-Luis Fernando Bravo Ibanez - zS21002428"<<endl;

        cout<<"\nParadigmas de Programacion II - Ingenieria Informatica"<<endl;
        cout<<"Facultad de Ingenieria Electrica y Electronica - Universidad Veracruzana"<<endl;
    }
};

//Clase Juego que hereda de la clase Tablero (Herencia simple)
class Juego : public Tablero{
private:
    Jugador jugador1;   //Jugador 1
    Jugador jugador2;   //Jugador 2
    int turno;          //Contador de turnos

public:
    //Constructor del juego que inicializa a los jugadores
    Juego(string nombre1, string nombre2) 
        : jugador1(nombre1, 'X'), jugador2(nombre2, 'O'), turno(0) {}

    //Lógica principal de una partida
    void jugarPartida()
    {
        string coordenada;  // Variable para almacenar la coordenada alfanumérica
        int fila, columna;
        int fin = 0;
        
        // Resetear el tablero al inicio de cada partida
        resetear();   
        turno = 0;   

        while(!fin)
        {
            limpiarPantalla();
            imprimir();
            
            // Turno de jugador 1
            if(turno % 2 == 0)
            {
                cout <<endl<< jugador1.nombre << " (X), ingrese coordenada (Ej. B1): ";
                cin>>coordenada;

                // Conversión de entrada alfanumérica a índices del tablero
                columna = coordenada[0] - 'A';  // 'A' es la columna 0, 'B' es 1, 'C' es 2
                fila = coordenada[1] - '1';     // '1' es la fila 0, '2' es 1, '3' es 2

                // Validar si la coordenada está dentro del rango
                while(fila < 0 || fila > 2 || columna < 0 || columna > 2 || estaOcupada(fila, columna)) 
                {
                    cout<<"\nCoordenada invalida o ocupada. Intenta de nuevo.\n";
                    cout<<jugador1.nombre << " (X), ingrese coordenada (Ej. B1): ";
                    cin>>coordenada;
                    
                    // Conversión de entrada alfanumérica a índices del tablero
                    columna = coordenada[0] - 'A';
                    fila = coordenada[1] - '1';
                }

                colocarSimbolo(fila, columna, jugador1.simbolo);
                if(hayGanador(jugador1.simbolo))
                {
                    limpiarPantalla();
                    imprimir();
                    cout<<endl<<jugador1.nombre<<" gana! :D"<<endl;
                    guardarResultado(jugador1.nombre);
                    fin = 1;
                }
            } 
            else
            {
                // Turno de jugador 2
                cout<<endl << jugador2.nombre << " (O), ingrese coordenada (Ej. C2): ";
                cin>>coordenada;

                // Conversión de entrada alfanumérica a índices del tablero
                columna = coordenada[0] - 'A';
                fila = coordenada[1] - '1';

                // Validar si la coordenada está dentro del rango
                while(fila < 0 || fila > 2 || columna < 0 || columna > 2 || estaOcupada(fila, columna)) 
                {
                    cout<<"\nCoordenada invalida. Intenta de nuevo.\n";
                    cout<<jugador2.nombre << " (O), ingrese coordenada (Ej. C2): ";
                    cin>>coordenada;

                    // Conversión de entrada alfanumérica a índices del tablero
                    columna = coordenada[0] - 'A';
                    fila = coordenada[1] - '1';
                }

                colocarSimbolo(fila, columna, jugador2.simbolo);
                if(hayGanador(jugador2.simbolo))
                {
                    limpiarPantalla();
                    imprimir();
                    cout<<endl<<jugador2.nombre<<" gana! :D"<<endl;
                    guardarResultado(jugador2.nombre);
                    fin = 1;
                }
            }

            // Verificar si el tablero está lleno (empate)
            if(++turno == 9 && !fin) 
            {
                limpiarPantalla();
                imprimir();
                cout<<"\nEs un empate!" << endl;
                fin = 1;
            }
        }
    }

    // Modificar nombres de jugadores
    void modificarNombres()
    {
        cout<<"\nIngrese el nuevo nombre del Jugador 1: ";
        cin>>jugador1.nombre;
        cout<<"Ingrese el nuevo nombre del Jugador 2: ";
        cin>>jugador2.nombre;
    }

    // No necesitamos redefinir estas funciones ya que las heredamos de Tablero
    void verHistorial()
    {
        Tablero::verHistorial();
    }

    void verEquipo()
    {
        Tablero::verEquipo();
    }

    void verCoordenadasPorCuadro() 
    {
        Tablero::verCoordenadasPorCuadro();
    }
};

// Menú principal
void menuPrincipal(Juego& juego)
{
    int opcion;
    do {
        limpiarPantalla();
        cout<<"\t************************************"<<endl;
        cout<<"\t**********JUEGO DEL GATO************"<<endl;
        cout<<"\t************************************\n"<<endl;
        cout<<"1.- Iniciar juego"<<endl;
        cout<<"2.- Modificar nombres de jugadores"<<endl;
        cout<<"3.- Ver historial de ganadores"<<endl;
        cout<<"4.- Creditos de los creadores"<<endl;
        cout<<"5.- Ayuda"<<endl;
        cout<<"6.- Salir"<<endl;
        cout<<"Selecciona una opcion: ";
        cin>>opcion;

        switch (opcion){
            case 1:
                juego.jugarPartida();
                break;
            case 2:
                juego.modificarNombres();
                break;
            case 3:
                juego.verHistorial();
                break;
            case 4:
                juego.verEquipo();
                break;
            case 5:
                juego.verCoordenadasPorCuadro(); 
                break;
            case 6:
                cout<<"\nSaliendo del programa..."<<endl;
                break;
            default:
                cout<<"Opcion no valida, intenta de nuevo."<<endl;
        }

        if(opcion != 6)
        {
            char seguir;
            cout<<"\n Volver al menu principal? (s/n): ";
            cin>>seguir;
            if(seguir == 'n') opcion = 6;
        }
    } while(opcion != 6);
}

int main()
{
    limpiarPantalla();
    cout<<"\t************************************"<<endl;
    cout<<"\t**********JUEGO DEL GATO************"<<endl;
    cout<<"\t************************************\n"<<endl;
    cout<<"#NOTA: El primer usuario ingresado es el que empieza el juego\n"<<endl;
    string nombre1, nombre2;
    cout<<"Jugador 1, ingresa tu nombre: ";
    cin>>nombre1;
    cout<<"Jugador 2, ingresa tu nombre: ";
    cin>>nombre2;

    limpiarPantalla();
    Juego juego(nombre1, nombre2);

    menuPrincipal(juego);

    return 0;
}

void limpiarPantalla() {
    // Limpia la pantalla según el sistema operativo
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}