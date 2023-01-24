#include <iostream>
#include <fstream>
#include <string>
char mode;
class section {
        public:
            void login(const char loginMode)
    {
        switch(loginMode) {
            case '1':
                {
                    std::ofstream nameDB("names.txt", std::ios_base::app);
                    std::ofstream passDB("pass.txt", std::ios_base::app);
                    
                    std::cout << "Register" << std::endl;

                    std::cout << "Enter a username: " << std::endl;
                    std::cin >> username;	
                    std::cout << "Enter a password: " << std::endl;
                    std::cin >> password;	

                    nameDB << username << std::endl;
                    passDB << password << std::endl;
                }
                break;
                
            case '2':
                {
                    std::ifstream nameDB("names.txt");
                    std::ifstream passDB("pass.txt");
                    
                    
                    bool usernameCorrect, passwordCorrect;

                    std::cout << "Login" << std::endl;

                    std::cout << "Enter your username: " << std::endl;
                    std::cin >> uiUsername;
                    std::cout << "Enter your password: " << std::endl;
                    std::cin >> uiPassword;

                    while(std::getline(nameDB, fUsername))
                    {
                        if(uiUsername == fUsername) 
                        {
                            usernameCorrect = true;	
                            break;
                        } else
                        {
                            usernameCorrect = false;	
                        }
                    }

                    while(std::getline(passDB, fPassword))
                    {
                        if(uiPassword == fPassword)
                        {
                            passwordCorrect = true;	
                            break;
                        }
                        else {
                            passwordCorrect = false;	
                        }
                    }

                    if(usernameCorrect && passwordCorrect)
                    {
                        std::cout << "Hello, " << uiUsername << "!" << std::endl;	
                    } else 
                    {
                        std::cout << "I couldn't find that account." << std::endl;
                    }
                }
                break;
        }
        
    }
        private:
            std::string username;
            std::string password;
            std::string uiUsername;
            std::string uiPassword;
            std::string fUsername;
            std::string fPassword;
};

int main(){

    section sector;
    std::cout << "Welcome to \"Ozone Server!\"" << std::endl;
    std::cout << std::endl;
    std::cout << "1: Register" << std::endl;
    std::cout << "2: Login" << std::endl;
    std::cin >> mode;
    sector.login(mode);


    

}

