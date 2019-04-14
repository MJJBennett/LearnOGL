#include <iostream>

template<typename T>
void print(T t)
{
    std::cout << t << '\n';
}

template<typename T, typename ...Ts>
void print(T t, Ts... ts)
{
    std::cout << t << ' ';
    print(ts...);
}

namespace logl {

class error
{
public:
    error(const std::string& str) : str_("Error (" + str + "): ") {}
    error() : str_("Error: ") {}

    friend std::ostream& operator<<(std::ostream& os, error& e)
    {
        os << e.str_; 
        return os;
    }
private:
    std::string str_;
};

}
