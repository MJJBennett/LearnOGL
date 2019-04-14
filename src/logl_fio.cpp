#include "logl_fio.h"
#include "logl_print.h"

std::string readFile(std::string path) {
    std::ifstream fs;
    fs.open(path, std::ifstream::in);
    
    if (!fs.good()) {
        print(logl::error(), "Could not read from file " + path + "");
        return "";
    }

    std::string line;
    std::stringstream ss;
    while (!fs.eof()) {
        std::getline(fs, line);
        ss << line << "\n";
    }

    fs.close();

    return ss.str();
}
