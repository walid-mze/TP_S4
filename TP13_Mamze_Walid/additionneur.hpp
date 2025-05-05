#ifndef ADDITIONNEUR_HPP
#define ADDITIONNEUR_HPP

class Additionneur {
private:
    int valeur;
public:
    Additionneur(int v);
    void operator()(int x) const;
};

#endif
