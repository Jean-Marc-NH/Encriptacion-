#include <string>
#include <iostream>
#include <fstream>


class modular
{

public:

    int op1;
    int op2;
    int mod;

    modular(int, int, int);

    int suma();

    int resta();

    int multiplicacion();

    int inversa();

    ~modular();

};


class interfaz
{

public:

    int opt;

    interfaz();

    int menu_principal();

    void encripta();
    void desencripta();

};

class encriptacion
{
public:

    int op1;
    int mod;
    std::string url;

    encriptacion(std::string, int, int);

    int encriptar();

};

class desencriptacion
{
public:

    int op1;
    int mod;
    std::string url;

    desencriptacion(std::string, int, int);

    int desencriptar();

};