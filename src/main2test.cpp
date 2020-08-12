#include "iostream" 
#include "solver.h"

int main() {
    Solver s1(4, 4); 
    while(1) {
        int T; 
        std::cin >> T; 
        std::vector<std::string> nextmoves(T); 
        for (int i = 0; i < T; ++i) {
            std::cin >> nextmoves[i]; 
        }
        std::cout << std::endl; 
        std::cout << s1.move(nextmoves) << std::endl; 

    }
    return 0; 
}