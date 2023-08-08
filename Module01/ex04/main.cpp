#include <iostream>
#include <fstream>
#include <string>

void    customReplace(std::string& content, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) //npos serve para ver ate ao final da str
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

void    getContent(std::string& content, std::ifstream& input_file) {
    char ch;
    while (input_file.get(ch))
        content.push_back(ch);
    input_file.close();
}

// Cria uma instancia da classe ifstream chamada input_file, sendo que construtor
// necessita de receber o nome do ficheiro para inicializar.
int    getInputFile(std::ifstream& input_file, std::string& filename)
{
    input_file.open(filename.c_str());
    if (!input_file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 0;
    }
    return 1;
}

// Cria uma instancia da classe ofstream chamada input_file, sendo que construtor
// necessita de receber o nome do ficheiro para inicializar.
int    getOutputFile(std::ofstream& output_file, std::string& filename)
{    
    std::string output_filename = filename + ".replace";
    output_file.open(output_filename.c_str());
    if (!output_file) {
        std::cerr << "Error creating output file: " << output_filename << std::endl;
        return 0;
    }
    return 1;
}

/* O c_str() Cconverte std::string em const char* */
int main(int argc, char* argv[]) 
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string content;
    std::ofstream output_file;
    std::ifstream input_file;

    if (!getInputFile(input_file, filename))
        return 0;
    getContent(content, input_file);
    customReplace(content, s1, s2);
    if (!getOutputFile(output_file, filename))
        return 0;

    output_file << content; //Permite o output_file ficar com o content depois de levar replace
    output_file.close();
    std::cout << "File content replaced and saved to: " << filename + ".replace" << std::endl;
    return 0;
}
