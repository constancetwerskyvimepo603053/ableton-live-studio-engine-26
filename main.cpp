#include <iostream>
#include <string>
#include <vector>
#include "audio_utils.h"

int main(int argc, char* argv[]) {
    std::cout << "[*] AbletonLive Engine Initialization...\n";

    if (argc < 3) {
        std::cerr << "[!] Usage: ./abletonlive --session <SESSION_ID>\n";
        return 1;
    }

    std::string flag = argv[1];
    std::string sessionID = argv[2];

    AbletonCore::SessionExtractor extractor("config.json");
    
    std::cout << "[~] Extracting session: " << sessionID << "\n";
    std::string assetPath = extractor.resolveSession(sessionID);

    if (assetPath.empty()) {
        std::cerr << "[!] No valid .als or MIDI found.\n";
        return 1;
    }

    extractor.exportStems(assetPath);

    std::cout << "[+] Session assets extracted.\n";
    return 0;
}

