#include "CeaserCipher.hpp"
#include "RunCaesarCipher.hpp"
#include "ProcessCommandLine.hpp"

#include <iostream>
#include <string>

CeaserCipher::CeaserCipher(const size_t empkey) : key_{empkey}
{
}

CeaserCipher::CeaserCipher(const std::string& empKey) : key_{0}
{
    if (!empKey.empty()) {
        // Before doing the conversion we should check that the string contains a
        // valid positive integer.
        // Here we do that by looping through each character and checking that it
        // is a digit. What is rather hard to check is whether the number is too
        // large to be represented by an unsigned long, so we've omitted that for
        // the time being.
        // (Since the conversion function std::stoul will throw an exception if the
        // string does not represent a valid unsigned long, we could check for and
        // handled that instead but we only cover exceptions very briefly on the
        // final day of this course - they are a very complex area of C++ that
        // could take an entire course on their own!)
        for (const auto& elem : empKey) {
            if (!std::isdigit(elem)) {
                std::cerr
                    << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                    << "        the supplied key (" << empKey
                    << ") could not be successfully converted" << std::endl;
                return;
            }
        }
    }
        key_ = std::stoul(empKey);
}

std::string CeaserCipher::applyCipher(const std::string& inputText, const CipherMode encrypt) const
{
    // Create the output string
    std::string outputText;

    // Make sure that the key is in the range 0 - 25
    const std::size_t truncatedKey{key_ % alphabetSize_};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for (size_t i{0}; i < alphabetSize_; ++i) {
            if (origChar == alphabet_[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                switch(encrypt) {
                    case CipherMode::Encrypt:
                        processedChar = alphabet_[(i + truncatedKey) % alphabetSize_];
                        break;

                    case CipherMode::Decrypt:
                        processedChar = alphabet_[(i + alphabetSize_ - truncatedKey) % alphabetSize_];
                        break;
                }
                break;
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;
}


