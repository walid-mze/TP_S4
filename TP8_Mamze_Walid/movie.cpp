#include "Movie.hpp"

Movie::Movie(std::string n, std::string r, int w) : name(n), rating(r), watched(w) {}

std::string Movie::get_name() const { return name; }
std::string Movie::get_rating() const { return rating; }
int Movie::get_watched() const { return watched; }

void Movie::set_name(std::string n) { name = n; }
void Movie::set_rating(std::string r) { rating = r; }
void Movie::set_watched(int w) { watched = w; }

void Movie::increment_watched() { watched++; }

void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}
