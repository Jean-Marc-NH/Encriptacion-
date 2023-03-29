#include <iostream>
#include "encriptacion.hpp"

using namespace std;

int main()
{
	int opt{ -1 };
	interfaz a;

	opt = a.menu_principal();

	if (opt == 1)
	{
		a.encripta();
	}
	else if (opt == 2)
	{
		a.desencripta();
	}
	else
	{
		cout << opt;
		cout << "\n\n\t\tGRACIAS POR USAR EL PROGRAMA\n\n\n";
	}

}