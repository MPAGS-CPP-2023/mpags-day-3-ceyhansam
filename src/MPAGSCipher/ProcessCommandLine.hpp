#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

#include "CipherMode.hpp"

struct ProgramSettings {
    bool helpRequested;
    bool versionRequested;
    std::string inputFile;
    std::string outputFile;
    std::string cipherKey;
    CipherMode encrypt;
};

bool processCommandLine(const std::vector<std::string>& cmdLineArgs, struct ProgramSettings& programSettings);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP