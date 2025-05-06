#include "Span.hpp"


// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }

// int main ()
// {
//     Span sp = Span(5);
//     try
//     {
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(50);
//         sp.addNumber(9);
//         sp.addNumber(11);
//         // sp.addNumber(11);

//     }
//     catch (std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << sp.shortestSpan() << std::endl;
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     try
//     {
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     catch (std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
// }

int main() {
    Span sp(10);

    sp.addNumber(5);
    sp.addNumber(3);

    int arr[] = {7, 1, 9, 4, 6};  // Tableau d'entiers
    std::vector<int> moreNumbers(arr, arr + sizeof(arr) / sizeof(int));
    sp.addNumbers(moreNumbers.begin(), moreNumbers.end());

    try {
        std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest : " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

