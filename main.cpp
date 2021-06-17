#include <iostream>
#include <string_view>

int too_complex( std::string_view sv, int other_val , int unused ) {
    enum class Modes { A, B, C };
    Modes mode = Modes::A;
    Modes prevMode = Modes::A;
    if( other_val == 7 )
        return -1;

    for( auto c : sv ) {
        switch( c ) {
            case 'a':
                if( other_val == 1 ) {
                    std::cout << "1\n";
                    if( mode == Modes::A ) {
                        for( int i=0; i<3; ++i ) {
                            if( prevMode == Modes::B )
                                std::cout << "B->A\n";
                        }
                    }
                }
                else {
                    prevMode = mode;
                    mode = Modes::B;
                }
            case 'H':
                std::cout << "H\n";
                if( other_val == 1 ) {
                    std::cout << "1\n";
                }
        }
    }
    return 0;
}

struct managed_object {
    managed_object() {
        std::cout << "ctor\n";
    }
    ~managed_object() {
        std::cout << "dtor\n";
    }
    void* operator new( size_t size ) {
        if( size > 1 ) {
            throw std::domain_error("too big");
        }
        std::cout << "allocated\n";
        return malloc(size);
    }
    void operator delete( void* addr ) {
        std::cout << "deleted\n";
        free(addr);
    }
};

char const* who() {
    std::string me = "Me";
    return me.c_str();
}

int main() {
    too_complex(who(), 42, 7);

    managed_object* obj = new managed_object();
    if( obj )
        delete obj;
}
