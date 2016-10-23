#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

bool IsValid(std::string&, const char& c);
void TypeOfStrand(char&);
void TemplateDNA_BuildStrand(const std::string&, std::string&, std::string&, std::string&, std::string&);
void CodingDNA_BuildStrand(const std::string&, std::string&, std::string&, std::string&, std::string&);
void mRNA_BuildStrand(const std::string&, std::string&, std::string&, std::string&, std::string&);
void tRNA_BuildStrand(const std::string&, std::string&, std::string&, std::string&, std::string&);


int main() {
    std::string templateDNA = "";
    std::string codingDNA = "";
    std::string mRNA = "";
    std::string tRNA = "";
    std::string s = "";
    char strandType = '\0';
    
    
    TypeOfStrand(strandType);

    std::cout << "Enter a DNA strand: " << std::flush;
    getline(std::cin,s);
    while (!IsValid(s,strandType)) {
        std::cout << "Invalid, enter another strand: " << std::flush;
        std::cin >> s;
    }
    if (strandType == 't') {
        TemplateDNA_BuildStrand(s,templateDNA,codingDNA,mRNA,tRNA);
    }
    else if (strandType == 'c') {
        CodingDNA_BuildStrand(s,templateDNA,codingDNA,mRNA,tRNA);
    }
    else if (strandType == 'm') {
        mRNA_BuildStrand(s,templateDNA,codingDNA,mRNA,tRNA);
    }
    else if (strandType == 'r') {
        tRNA_BuildStrand(s,templateDNA,codingDNA,mRNA,tRNA);
    }
    else {
        throw std::invalid_argument("Invalid strand type.");
    }
    
    std::cout << "Template DNA: " << templateDNA << std::endl;
    std::cout << "Coding DNA: " << codingDNA << std::endl;
    std::cout << "Messenger RNA: " << mRNA << std::endl;
    std::cout << "Transfer RNA: " << tRNA << std::endl;
    return 0;
}

void TypeOfStrand(char& type) {
    std::cout << "What type of strand is the nucleic acid?" << std::endl;
    std::cout << "Press t for template DNA, 'c' for coding DNA, 'm' for mRNA, 'r' for tRNA." << std::endl;
    
    type = std::cin.get();
    std::cin.ignore(256,'\n');
    type = tolower(type);
    while (type != 't' && type != 'c' && type != 'm' && type != 'r') {
        std::cout << "Invalid, enter another character." << std::endl;
        std::cout << "Press t for template DNA, 'c' for coding DNA, 'm' for mRNA, 'r' for tRNA." << std::endl;
        type = std::cin.get();
        std::cin.ignore(256, '\n');
        type = tolower(type);
    }
}

bool IsValid(std::string& s, const char& c) {
    if (c == 't' || c == 'c') { //DNA
        for (unsigned int i = 0; i < s.size(); ++i) {
            s.at(i) = toupper(s.at(i));
            if (s.at(i) != 'A' && s.at(i) != 'T' && s.at(i) != 'G' && s.at(i) != 'C') {
                return false;
            }
        }
    }
    else if (c == 'm' || c == 'r') { //RNA
        for (unsigned int i = 0; i < s.size(); ++i) {
            s.at(i) = toupper(s.at(i));
            if (s.at(i) != 'A' && s.at(i) != 'U' && s.at(i) != 'G' && s.at(i) != 'C') {
                return false;
            }
        }
    }
    else {
        throw std::invalid_argument("Invalid strand type.");
    }
    return true;
}

void TemplateDNA_BuildStrand(const std::string& s, std::string& tDNA, std::string& cDNA, std::string& mRNA, std::string& tRNA) {
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'A') {
            tDNA += 'A';
            cDNA += 'T';
            mRNA += 'U';
            tRNA += 'A';
        }
        else if (s.at(i) == 'T') {
            tDNA += 'T';
            cDNA += 'A';
            mRNA += 'A';
            tRNA += 'U';
        }
        else if (s.at(i) == 'G') {
            tDNA += 'G';
            cDNA += 'C';
            mRNA += 'C';
            tRNA += 'G';
        }
        else if (s.at(i) == 'C') {
            tDNA += 'C';
            cDNA += 'G';
            mRNA += 'G';
            tRNA += 'C';
        }
    }
}

void CodingDNA_BuildStrand(const std::string& s, std::string& tDNA, std::string& cDNA, std::string& mRNA, std::string& tRNA) {
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'A') {
            tDNA += 'T';
            cDNA += 'A';
            mRNA += 'A';
            tRNA += 'U';
        }
        else if (s.at(i) == 'T') {
            tDNA += 'A';
            cDNA += 'T';
            mRNA += 'U';
            tRNA += 'A';
        }
        else if (s.at(i) == 'G') {
            tDNA += 'C';
            cDNA += 'G';
            mRNA += 'G';
            tRNA += 'C';
        }
        else if (s.at(i) == 'C') {
            tDNA += 'G';
            cDNA += 'C';
            mRNA += 'C';
            tRNA += 'G';
        }
    }
}

void mRNA_BuildStrand(const std::string& s, std::string& tDNA, std::string& cDNA, std::string& mRNA, std::string& tRNA) {
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'A') {
            tDNA += 'T';
            cDNA += 'A';
            mRNA += 'A';
            tRNA += 'U';
        }
        else if (s.at(i) == 'U') {
            tDNA += 'A';
            cDNA += 'T';
            mRNA += 'U';
            tRNA += 'A';
        }
        else if (s.at(i) == 'G') {
            tDNA += 'C';
            cDNA += 'G';
            mRNA += 'G';
            tRNA += 'C';
        }
        else if (s.at(i) == 'C') {
            tDNA += 'G';
            cDNA += 'C';
            mRNA += 'C';
            tRNA += 'G';
        }
    }
}

void tRNA_BuildStrand(const std::string& s, std::string& tDNA, std::string& cDNA, std::string& mRNA, std::string& tRNA) {
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'A') {
            tDNA += 'A';
            cDNA += 'T';
            mRNA += 'U';
            tRNA += 'A';
        }
        else if (s.at(i) == 'U') {
            tDNA += 'T';
            cDNA += 'A';
            mRNA += 'A';
            tRNA += 'U';
        }
        else if (s.at(i) == 'G') {
            tDNA += 'G';
            cDNA += 'C';
            mRNA += 'C';
            tRNA += 'G';
        }
        else if (s.at(i) == 'C') {
            tDNA += 'C';
            cDNA += 'G';
            mRNA += 'G';
            tRNA += 'C';
        }
    }
}