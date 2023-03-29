#include "encriptacion.hpp"

modular::modular(int _op1 = 1, int _mod = 1, int _op2 = 1)
{
    op1 = _op1;
    op2 = _op2;
    mod = _mod;

    op1 %= mod;
    op2 %= mod;

}

int modular::suma()
{
    return (op1 + op2) % mod;

}

int modular::resta()
{

    return (op1 - op2 + mod) % mod;

}

int modular::multiplicacion()
{
    return (op1 * op2) % mod;
}

int modular::inversa()
{

    int a{ 0 };
    int b{ 1 };
    int q{ -1 };
    int c{ -1 };
    int r{ -1 };
    int x{ mod };



    while (r != 1)
    {



        q = x / op1;
        c = a - q * b;

        while (c < 0)
        {
            c = mod + c;

        }

        //cout << "a = " << a << endl;
        //cout << "b = " << b << endl;
        //cout << "c = " << c << endl;
        //cout << "q = " << q << endl;

        a = b;
        b = c;

        r = x % op1;

        //cout << "r = " << r << endl << endl;

        x = op1;
        op1 = r;

    }

    return c;

}

modular::~modular() {
    op1 = 0;
    op2 = 0;
    mod = 0;
}

//interfaz

interfaz::interfaz()
{
    opt = -1;

}

int interfaz::menu_principal()
{
    while (opt != 1 && opt != 2 && opt != 3)
    {

        std::cout << "\n\n\t---------MENU PRINCIPAL---------\n\n";
        std::cout << "\t\t[1] Encripta\n";
        std::cout << "\t\t[2] Desencripta\n";
        std::cout << "\t\t[3] salir\n\n";

        std::cout << "\t>>>";
        std::cin >> opt;

        if (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Solo valores numericos" << "\n";
            std::system("cls");
        }
        else
        {
            switch (opt)
            {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            default:
                std::system("cls");
                break;
            }
        }        
    }
}

void interfaz::encripta()
{

    std::system("cls");

    std::string url{ "Mensaje.txt" };
    int cl{ -1 };

    while (true)
    {
        std::cout << "\n\n\t\tIngrese la clave con la que desea encriptar: ";
        std::cin >> cl;

        if (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "\n\t\tSolo valores numericos" << "\n";
            std::system("cls");
        }
        else
        {
            break;
        }
    }
    
    std::system("cls");

    encriptacion a(url, cl, 256);

    if (a.encriptar() == 1) {
        std::cout << "\n\n\t------------Encripta------------\n\n" << std::endl;
        std::cout << "\t\tENCRIPTADO CON EXITO" << std::endl;
        std::cout << "\t\tTU CLAVE PRIVADA ES: " << cl << std::endl;
    }
}

void interfaz::desencripta()
{

    std::system("cls");

    std::string url{ "encriptado.txt" };
    int cl{ -1 };

    while (true)
    {
        std::cout << "\n\n\t\tIngrese la clave con la que desea desncriptar: ";
        std::cin >> cl;

        if (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "\n\t\tSolo valores numericos" << "\n";
            std::system("cls");
        }
        else
        {
            break;
        }
    }

    std::system("cls");

    desencriptacion a(url, cl, 256);

    if (a.desencriptar() == 1) {
        std::cout << "\n\n\t----------Desencripta-----------\n\n" << std::endl;
        std::cout << "\t\tDESENCRIPTADO CON EXITO" << std::endl;
    }

}


//encripta

encriptacion::encriptacion(std::string _url, int _op, int _mod)
{
    url = _url;

    op1 = _op;

    mod = _mod;

}

int encriptacion::encriptar()
{

    std::string newLinea{""};
    std::string linea{ "" };
    std::string linea2{ "" };

    std::ifstream texto(url.c_str());

    while (getline(texto, linea))
    {
        std::cout << "p: " << linea2 << std::endl;
        linea2 += linea;
    }
    
    std::cout << linea << std::endl;


    for (int i{ 0 }; i < linea2.size(); i++)
    {
        modular x(op1, mod, int(linea2[i]));
        newLinea += char(x.multiplicacion());
    }

    std::cout << newLinea << std::endl;

    std::ofstream encriptado;

    encriptado.open("encriptado.txt");
    
    encriptado << newLinea;

    encriptado.close();


    return 1;

}


//desencriptar

desencriptacion::desencriptacion(std::string _url, int _op, int _mod) 
{
    modular x(_op, _mod);
    op1 = x.inversa();
    mod = _mod;
    url = _url;
}

int desencriptacion::desencriptar()
{
    std::string newLinea{ "" };
    std::string linea{ "" };
    std::string linea2{ "" };


    std::ifstream texto(url.c_str());

    while (getline(texto, linea))
    {
        std::cout << linea << std::endl;
        linea2 += linea;
    }

    std::cout << linea2 << std::endl;

    for (int i{ 0 }; i < linea2.size(); i++)
    {
        modular x(op1, mod, int(linea2[i]));
        newLinea += char(x.multiplicacion());
    }

    std::ofstream desencriptado;

    desencriptado.open("desencriptado.txt");

    desencriptado << newLinea;

    desencriptado.close();


    return 1;
}