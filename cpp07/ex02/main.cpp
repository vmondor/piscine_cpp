#include <iostream>
#include <math.h>
#include "Array.hpp"


int main()
{
    try
    {
        // Constructeur sans paramètre
        Array<int> emptyArray;
        std::cout << "Taille du tableau vide : " << emptyArray.size() << std::endl;
        std::cout << "_______________________" << std::endl << std::endl;

        // Constructeur avec un paramètre
        Array<int> intArray(5);
        std::cout << "Taille du tableau intArray : " << intArray.size() << std::endl;
        std::cout << "_______________________" << std::endl << std::endl;

        // Accès aux éléments et modification via []
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            intArray[i] = i * 2;
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }
        std::cout << "_______________________" << std::endl << std::endl;

        // Constructeur par copie
        Array<int> copyArray(intArray);
        std::cout << "Taille du tableau copyArray : " << copyArray.size() << std::endl;
        std::cout << "_______________________" << std::endl << std::endl;

        // Modification de copyArray pour vérifier que cela n'affecte pas intArray
        copyArray[0] = 42;
        std::cout << "copyArray[0] = " << copyArray[0] << std::endl;
        std::cout << "intArray[0] (après modification de copyArray) = " << intArray[0] << std::endl;
        std::cout << "_______________________" << std::endl << std::endl;

        // Test de l'exception pour un accès hors limites
        std::cout << "Accès à un index hors limite : ";
        std::cout << intArray[10] << std::endl;
        std::cout << "_______________________" << std::endl << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception --> " << e.what() << std::endl;
    }

    return 0;
}
