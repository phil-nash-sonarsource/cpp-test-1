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

int main() {
    too_complex("Hello, World!", 42, 7);
}
