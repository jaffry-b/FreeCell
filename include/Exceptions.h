#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class invalid_move : public std::exception {
    const char * what () const throw () {
        return "invalid move";
    }
};

class empty_outside_bounds: public std::exception {
    const char * what () const throw () {
        return "empty and outside bounds";
    }
};
class invalid_card: public std::exception {
    const char * what () const throw () {
        return "invalid card";
    }
};
class empty_cells: public std::exception {
    const char * what () const throw () {
        return "cell is empty";
    }
};


class outside_bounds : public std::exception {
    const char * what () const throw () {
        return "outside bounds";
    }
};

#endif