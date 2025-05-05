#include "livre.hpp"

Livre::Livre(std::string t, int p) : titre(t), pages(p) {}

std::ostream& operator<<(std::ostream& os, const Livre& l) {
    os << l.titre << " - " << l.pages << " pages";
    return os;
}
