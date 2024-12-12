# Swayam-v
 A C++ implementation of a simple movie recommendation system based on user ratings. This function utilizes collaborative filtering techniques to recommend movies to users based on the preferences of other users.

 Features: 
 
 1. Shows similarities (if any) between any two users based upon their ratings given to movies.
 2. Generates a list of recommended movies based upon ratings given to movies.
 3. Uses collaborative filtering method to recommend movies.
 4. Can be easily integrated into larger projects.

Requirements: 
1. C++ Programming language
2. VS Code

Files: 
1. ThisCode.cpp file containnig the C++ Code.
2. movie_ratings.csv file containing data related to movie ratings.

Libraries Used:  
1. fstream & sstream libraries to extract data from csv file.
2. vector, map,set & string to store various types of data.

Input Format:
1. A matrix containing data extracted from csv file.

Functions: 
1. read_file function to extract data from csv file and store it in vector data.
2. similarities function to calculate similarities between every two users (if any).
3. recommend function to calculate average rating given to a movie and recommend movies based upon their average ratings.

Output:
1. Users having similarities (if any).
2. Recommended movies. 
   

      
