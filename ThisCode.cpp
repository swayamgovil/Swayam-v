#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

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

void recommend(vector<vector<string>> data, map <string, float>&ans){   
    //Calculate average recommendation of every movie

    for(int i=1;i<=3;i++){    
        float sum=0,count=0;

        for(int j=i;j<data.size();j+=3){

            sum+=std::stof(data[j][2]);   
            if(std::stof(data[j][2])>0){
                count++;
            }   
        }    
        ans[data[i][1]]=sum/count;

    }
    

}

int main() {   

    string line;
    vector<vector<string>> data;
    map <string ,float> ans;

    read_file(data, line);

    recommend(data, ans); 


   /*for(int i=0;i<data.size();i++){
    for(int j=0;j<data[i].size();j++){
        cout<<data[i][j]<<" ";
    }
    cout<<endl;
   }*/

      
   cout<<"Recommended Movies:"<<endl; 
   vector<string> keys;
   //Copy movie names based on recommendation to vector ans
   
   for (const auto& pair : ans) {
        keys.push_back(pair.first);
    }

    //Display recommended movie names

    for(int i=keys.size()-1;i>=0;i--){
        cout<<keys[i]<<endl;
    }
    

    return 0;
}
