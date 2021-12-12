#include <iostream>
#include <string.h>
#include <string>

extern char** environ;
//int main(int argc, char **argv, char **envp)
int main(int argc, char** argv) {
    char** s = environ;

    // some env test variables...
    char* ipAddress = nullptr;
    char* port = nullptr;
    int isOk = -1;
    std::string myString;

    // get variables values..
    for (; *s; s++)
    {
        const auto result = strchr(*s, '=') + 1;
        if (strstr(*s, "IpAddress") != nullptr)
        {
            ipAddress = result;
        }
        else if (strstr(*s, "Port") != nullptr)
        {
            port = result;
        }
        else if (strstr(*s, "IsOk") != nullptr)
        {
            isOk = std::stoi(result);
        }
        else if (strstr(*s, "MyString") != nullptr)
        {
            myString = result;
        }

    }

    // check if everything is fine
    if (ipAddress == nullptr || port == nullptr || isOk == -1 || myString.empty())
    {
        throw std::invalid_argument("Error!!");
    }

    // output variable values
    std::cerr << "IpAddress: " << ipAddress << "\n";
    std::cerr << "Port: " << port << "\n";
    std::cerr << "IsOk: " << isOk << "\n";
    std::cerr << "MyString: " << myString << "\n";

    std::cerr << "============== TYPES ====================" << std::endl;
    std::cerr << "IpAddress: " << typeid(ipAddress).name() << std::endl;
    std::cerr << "Port: " << typeid(port).name() << std::endl;
    std::cerr << "IsOk: " << typeid(isOk).name() << std::endl;
    std::cerr << "MyString: " << typeid(myString).name() << std::endl << std::endl;

    std::cerr << "============== Check Values ====================" << std::endl;
    if (strcmp(ipAddress, "0.0.0.0") == 0)
    {
        std::cerr << "IpAddress\t\t= ok" << "\n";

    }
    if (strcmp(port, "8888") == 0)
    {
        std::cerr << "Port\t\t=  ok" << "\n";
    }
    if (isOk == 1)
    {
        std::cerr << "IsOk\t\t\t= ok" << "\n";
    }
    if (myString == "my-string")
    {
        std::cerr << "MyString\t\t= ok" << "\n";
    }

    return 0;

}


