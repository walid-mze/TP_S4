#include "movies.hpp"

int main() {
    Movies collection;

    collection.add_movie("Big", "PG-13", 2);
    collection.add_movie("Inception", "PG-13", 5);
    collection.add_movie("The Matrix", "R", 7);

    collection.display();

    collection.increment_watched("Inception");
    collection.display();

    return 0;
}
