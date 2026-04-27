#include <iostream>
#include <string>
#include <regex>
#include <ctime>

bool isTyposquat(std::string url) {
    // Check for common tricks: 0=O, l=I, rn=m
    std::regex sus(R"(paypa[l1]|app1e|gmai[l1]|faceb00k|micr0soft)");
    return std::regex_search(url, sus);
}

bool hasHTTPS(std::string url) {
    return url.find("https://") == 0;
}

bool hasIPAddress(std::string url) {
    std::regex ip(R"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})");
    return std::regex_search(url, ip);
}

int main(int argc, char* argv[]) {
    if(argc!= 2) {
        std::cout << "Usage:./phishcheck <url>\n";
        return 1;
    }

    std::string url = argv[1];
    int risk = 0;

    std::cout << "Analyzing: " << url << "\n\n";

    if(!hasHTTPS(url)) {
        std::cout << "[+20] No HTTPS - not encrypted\n";
        risk += 20;
    }

    if(isTyposquat(url)) {
        std::cout << "[+40] TYPO: Common brand impersonation\n";
        risk += 40;
    }

    if(hasIPAddress(url)) {
        std::cout << "[+30] IP: Uses raw IP instead of domain\n";
        risk += 30;
    }

    if(url.length() > 75) {
        std::cout << "[+10] LONG: URLs >75 chars are sus\n";
        risk += 10;
    }

    std::cout << "\n=== RESULT ===\n";
    std::cout << "Risk Score: " << risk << "/100\n";

    if(risk > 50) std::cout << "VERDICT: DANGER - Likely phishing\n";
    else if(risk > 20) std::cout << "VERDICT: SUS - Be careful\n";
    else std::cout << "VERDICT: SAFE - Looks legit\n";
}
