
#include "Student.h"
#include "ListOfLists.h"
#include <fstream>
#include <string>
#include <stdlib.h>



void readFromFile(ListOfLists<string>& materias)
{

	ifstream file;

	string nombres;
	string titulo;
	string filename = "estudiantes.txt";

	file.open("estudiantes.txt");
	if(!file)
        cout<<"no abre ";
    else
		while (!file.eof())
		{
			file >> titulo;

			do
			{
				file >> nombres;
				materias.insertFirst(titulo,nombres);
			}while(nombres!="#");
		}
	file.close();

	//materias.mostrar();
}

int menuDePruebas()
{
    string materia;
    string estudiante;
    ListOfLists<string> lista;
    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1--Insertar---" << endl;
        cout << "2--Mostrar--" << endl;
        cout << "3--Eliminar--" << endl;
        cout << "4--Buscar--" << endl;
        cout << "5--contar alumnos de materia--" << endl;
        cout << "6. leerDeArchivo" << endl;
        cout << "7--Salir--" << endl;
        cin >> opcion;
        system("cls");

        if (opcion == 1)
        {
            cout << "Materia: "; cin >> materia;
            cout << "Estudiante: "; cin >> estudiante;
            lista.insertFirst(materia, estudiante);
        }
        if (opcion == 2)
        {
            lista.mostrar();
        }
        if (opcion == 3)
        {
           cout << "Materia: "; cin >> materia;
            cout << "Estudiante a eliminar: "; cin >> estudiante;
             lista.buscar(materia)->DeleteElem(estudiante);
            cout << "eliminado: " << endl;
        }
        if (opcion == 4)
        {
            cout << "Materia: "; cin >> materia;
            cout << "Estudiante a Buscar: "; cin >> estudiante;
            string msg = lista.buscar(materia)->SearchNoRec(estudiante);
            cout << "el estudiante buscado es: " << msg << endl;
        }
                if (opcion == 5)
        {
            cout << "Materia: "; cin >> materia;
            int total = lista.buscar(materia)->countElements();
            cout << "total de estudiantes en : "<<materia<<" : "<<total<< endl;
        }
                    if (opcion == 6)
        {
            readFromFile(lista);
        }

    } while (opcion != 7);
    return 0;
}



int main() {
    menuDePruebas();
    //SOLO FUNCIONA CON STRINGS

    /*
    ListOfLists<Student> list;

    Student materia1(1,"CALCULO");
    Student materia2(2,"ALGEBRA");
    Student materia3(3,"GEOLOGIA");
    Student estudiante1(1, "pepe");
    Student estudiante2(2, "andres");
    Student estudiante3(3, "manolo");
    Student estudiante4(4, "antonio");
    Student estudiante5(5, "jose");
    Student estudiante6(6, "jessica");
    Student estudiante7(7, "andrea");

    list.insertFirst(materia1, estudiante1);
    list.insertFirst(materia2, estudiante2);
    list.insertFirst(materia3, estudiante3);

    list.mostrar();
    */

    //readFromFile();


}

