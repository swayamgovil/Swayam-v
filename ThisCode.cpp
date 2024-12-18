#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

void read_file(vector<vector<string>> &data, string line, vector<string>& users, vector<string>& movies){   
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
    set<string> user; 
    set<string> movie;

    for(int i=1;i<data.size();i++){
        user.insert(data[i][0]);
        movie.insert(data[i][1]);
    }    

    for (const auto& elem : user) {
        users.push_back(elem);
    } 
    for (const auto& elem : movie) {
        movies.push_back(elem);
    } 
}


void similarities(vector<vector<string>> data, map<string, float>&avg_rating, vector<string> users){    

    float count=0,sum=0;    

    for(int i=0;i<users.size();i++){   

        string temp=users[i]; 

        for(int j=1;j<data.size();j++){
            if(data[j][1]==temp){
                sum+=stof(data[j][2]); 

                if(stof(data[j][2])>0){   
                    count++;
                }   
            }
        }   
        avg_rating[temp]=sum/count;
    }    
    return ;   

}

void recommend(vector<vector<string>> data, map <string, float>&ratings, vector<string> movies){   
    //Calculate average recommendation of every movie

    for(int i=0;i<movies.size();i++){    
        float sum=0,count=0;

        string temp=movies[i];

        for(int j=1;j<data.size();j++){
            if(data[i][1]==temp){
                sum+=stof(data[i][2]);

                if(stof(data[i][2])>0){
                    count++;
                }
            }
        }
        ratings[temp]=sum/count;
    }
    

}

int main() {   

    string line;
    vector<vector<string>> data;
    map<string, float> avg_rating;
    map <string ,float> ratings;
    vector<string> users; 
    vector<string> movies;
    
    //Read data from csv file
    read_file(data, line, users, movies);

       
    //Calculate similarities between users
    similarities(data, avg_rating, users);

    //Recoomend Movies
    recommend(data, ratings, movies); 

    bool found=true;

    for(int i=0;i<users.size();i++){
        for(int j=i+1;j<users.size();j++){
            if(avg_rating[users[i]]==avg_rating[users[j]] || avg_rating[users[i]]==avg_rating[users[j]]+1 || avg_rating[users[i]]+1==avg_rating[users[j]]){

                cout<<"User "<<users[i]<<" and user "<<users[j]<<" have similarities in movie rating\n \n";
                found=false;
            }
        }
    }
    if(found){
        cout<<"No two users have given similar ratings to movies, hence no two users have similarities"<<endl;
    }

      
   cout<<"\nRecommended Movies:"<<endl; 
   vector<string> keys;
   //Copy movie names based on recommendation to vector ans
   
   for (const auto& pair : ratings) {
        keys.push_back(pair.first);
    }

    //Display recommended movie names

    for(int i=keys.size()-1;i>=0;i--){
        cout<<keys[i]<<endl;
    }
    
    return 0;
}
