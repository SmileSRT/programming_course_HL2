#include <iostream>
#include <fstream>
#include <string> 

int main(){
    std::string fileName;
    std::cout << "Please enter a file name\n";
    std::cin >> fileName;

    std::ifstream inputFile(fileName);
    std::ofstream outputFile(fileName.substr(0, fileName.length() - 4) + ".gift");

    std::string line;
    bool isTheBracketOpen = false;

    while (std::getline(inputFile, line)){
        for (char currentSymbol : line){
            if (!isTheBracketOpen){
                switch (currentSymbol){
                    case '?':
                        outputFile << "? {";
                        isTheBracketOpen = true;
                        break;

                    default:
                        outputFile << currentSymbol;
                        break;
                }
            }
            else{
                switch (currentSymbol){
                    case '+':
                        outputFile << "=";
                        break;
                    case '-':
                        outputFile << "~";
                        break;
                    
                    default:
                        outputFile << currentSymbol;
                        break;
                }
            }
        }
        
        if (isTheBracketOpen && line.empty()){
            outputFile << "}\n";
            isTheBracketOpen = false;
        }

        outputFile << '\n';
    }
    outputFile << "}";

    return 0;
}