#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(in, line)) {
        lines.push_back(line);
    }

    int maxIndex = 0;
    for (int i = 1; i < lines.size(); i++) {
        if (lines[i].length() > lines[maxIndex].length()) {
            maxIndex = i;
        }
    }

    lines[maxIndex] = "";

    for (const auto& l : lines) {
        out << l << std::endl;
    }

    in.close();
    out.close();

    return 0;
}