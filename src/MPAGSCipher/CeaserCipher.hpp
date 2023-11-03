#ifndef MPAGSCIPHER_CEASERCIPHER_HPP
#define MPAGSCIPHER_CEASERCIPHER_HPP

#include <string>
#include <iostream>
#include <vector>

#include "CipherMode.hpp"

class CeaserCipher {
    public:
        explicit CeaserCipher(const std::size_t key);

        explicit CeaserCipher(const std::string& key);

        std::string applyCipher(const std::string& inputText, const CipherMode encrypt) const;

        //std::string cipherText_ {""};

    private:

        std::size_t key_ {0};

        const std::vector<char> alphabet_ = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        const std::size_t alphabetSize_{alphabet_.size()};
    

        //Can add alphabet and alphabet size here too

};

#endif 