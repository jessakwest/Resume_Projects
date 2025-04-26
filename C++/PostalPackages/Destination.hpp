#ifndef DESTINATION_
#define DESTINATION_

enum class Destination { 
    Texas,
    OutOfState,
    International,
    Exit 
};

Destination getDestinationFromInput(char cmd) {
    switch(std::toupper(cmd)) {
        case 'T': return Destination::Texas;
        case 'O': return Destination::OutOfState;
        case 'I': return Destination::International;
        case 'X': return Destination::Exit;
        default : return Destination::Exit; //invalid input will exit program
    }
}

#endif