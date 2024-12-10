#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void read_file(vector<vector<string>> &data, string line){   
    // Open the CSV file

    ifstream file("movie_ratings.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }
    // Read the CSV file line by line

     while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<string> row;

        // Split the line into cells using a comma as the delimiter
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        // Add the row to the data vector
        data.push_back(row);
    }

    file.close();

}

int main() {   

    string line;
    vector<vector<string>> data;

    read_file(data, line);

   for(int i=0;i<data.size();i++){
    for(int j=0;j<data[i].size();j++){
        cout<<data[i][j]<<" ";
    }
    cout<<endl;
   }
    

    return 0;
}
