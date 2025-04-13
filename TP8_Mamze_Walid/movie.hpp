#include <iostream>
#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int watched;

public:
    Movie(std::string n, std::string r, int w);

    std::string get_name() const;
    std::string get_rating() const;
    int get_watched() const;
    void set_name(std::string n);
    void set_rating(std::string r);
    void set_watched(int w);

    void increment_watched();
    void display() const;
};
