#include "Movies.hpp"

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const auto& movie : movies) {
        if (movie.get_name() == name) {
            return false; 
        }
    }
    movies.emplace_back(name, rating, watched);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (auto& movie : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (movies.empty()) {
        std::cout << "No movies in the collection." << std::endl;
    } else {
        std::cout << "====================" << std::endl;
        for (const auto& movie : movies) {
            movie.display();
        }
        std::cout << "====================" << std::endl;
    }
}
é