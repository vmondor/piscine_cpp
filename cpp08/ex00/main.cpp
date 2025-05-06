#include "easyfind.hpp"


// int main() {
//     // Test avec std::vector
//     std::vector<int> vec;
//     vec.push_back(10);
//     vec.push_back(20);
//     vec.push_back(30);
//     vec.push_back(40);
//     vec.push_back(50);

//     try {
//         std::vector<int>::iterator it = easyfind(vec, 30);
//         std::cout << "Element found: " << *it << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }

//     // Test avec std::list
//     std::list<int> lst;
//     lst.push_back(100);
//     lst.push_back(200);
//     lst.push_back(300);
//     lst.push_back(400);
//     lst.push_back(500);

//     try {
//         std::list<int>::iterator it = easyfind(lst, 600);  // Cet élément n'existe pas
//         std::cout << "Element found: " << *it << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }

//     return 0;
// }

#include <map>

int main()
{
    std::cout << "\tLIST" << std::endl;
    std::list<int>    lst1;

    lst1.push_back(12);
    lst1.push_back(58);
    lst1.push_back(456);
    lst1.push_back(782);
    lst1.push_back(1);
    lst1.push_back(5);
    lst1.push_back(8);
    lst1.push_back(10);

    int    test1 = 5;
    int    test2 = 555;
    try
    {
        std::cout << "try to find 5 : ";
        easyfind(lst1, test1);
        std::cout << "try to find 555 : ";
        easyfind(lst1, test2);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << "\tVECTOR" << std::endl;
    std::vector<int>    vec1(15, 100);

    vec1.push_back(47);
    vec1.push_back(7);
    vec1.push_back(4);
    vec1.push_back(8);
    vec1.push_back(2);
    vec1.push_back(5);

    int    test3 = 100;
    int    test4 = 95;
    try
    {
        std::cout << "try to find 100 : ";
        easyfind(vec1, test3);
        std::cout << "try to find 95 : ";
        easyfind(vec1, test4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}