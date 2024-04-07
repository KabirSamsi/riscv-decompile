#include <map>

using namespace std;

struct Register {
    int value;
};

class RegisterFile {
    private:
        map<int, Register> data;

    //Constructor to initialize 32-bit register file
    RegisterFile() {
        map<int, Register> data;

        for (int i = 0; i < 32; i++) {
            data.insert(pair<int, Register>(i, Register{value: 0}));
        }
    }

    /*
    Looks up value in register file
    @param registerIndex stores the position of the register to lookup
    @returns data stored at register index
    */
    int lookup(int registerIndex) {
        return data.at(registerIndex).value;
    }
};
