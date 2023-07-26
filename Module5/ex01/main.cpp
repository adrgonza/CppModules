#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat mateo("mateo", 200);
    std::cout << mateo << std::endl;

    Bureaucrat low("low", 1);
    std::cout << low;
    low.incrementGrade();
    std::cout << low << std::endl;

    Bureaucrat high("high", 150);
    std::cout << high << std::endl;
    high.decrementGrade();
    std::cout << high << std::endl;
    Bureaucrat a("other", 1150);
    std::cout << a;

    return 0;
}
