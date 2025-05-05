#ifndef LIVRE_HPP
#define LIVRE_HPP

#include <string>
#include <iostream>

class Livre {
public:
    std::string titre;
    int pages;

    Livre(std::string t, int p);
    friend std::ostream& operator<<(std::ostream& os, const Livre& l);
};

#endif
