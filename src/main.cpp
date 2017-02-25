

#include "lib/sound.h"
#include "lib/tests.h"
#include "lib/exception.h"
#include <string>
int main2(int argc, char* argv[])
{

    if(argc < 2)
    {
        throw JP::EXCEPTION("not enough command line args.");
    }

    std::string mode = argv[1];

    
    if(mode == "--test")
    {
        tests::run();
    }
    else if(mode == "--keyboard")
    {
        SOUND s;
        //s.sound();
        //s.youtube();
        s.keyboard();
    }
    else
    {
        throw JP::EXCEPTION("Invalid run mode given");
    }
    

    return 0;
    
}

int main(int argc, char *argv[])
{
    try
    {
        main2(argc, argv);
        std::cout << "   DONE \n\n";
    }
    catch(JP::EXCEPTION& e)
    {
        std::cerr << "FATAL JP ERROR" << std::endl;
        std::cerr << "MSG: " << e.what() << std::endl;
        std::cerr << std::endl;
    }
    catch (std::exception e) 
    {   
        std::cerr << "FATAL STD ERROR" << std::endl;
        std::cerr << e.what() << std::endl;
        std::cerr << std::endl;
    }
    
    return 0;

}