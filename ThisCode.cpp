#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    // Open the CSV file
    std::ifstream file("movie_ratings.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<std::string>> data;

    // Read the CSV file line by line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        // Split the line into cells using a comma as the delimiter
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        // Add the row to the data vector
        data.push_back(row);
    }

    file.close();

    /* Display the data*/
    for (const auto& row : data) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
