//
// File: main.cpp
// Description: Movie display show times
// Created: Sun. Feb 26, 2023
// Author: Noah Sanderson
// mail: Noahs6423@student.vvc.edu
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

vector<string> process_line(string line){
  vector <string> elements;
  unsigned int pos1 = line.find(",");
  string time = line.substr(0, pos1);
  
  unsigned int pos2 = line.find(",", pos1+1);
  string title = line.substr(pos1+1, pos2-pos1-1);
  
  string rating = line.substr(pos2+1);
  
  elements.push_back(time);
  elements.push_back(title);
  elements.push_back(rating);
  return elements;
  }

void process_movies(const std::vector<string> &movies){
  vector<string> m_v = process_line(movies.at(0));
  string current_title = m_v.at(1);
  string show_time = m_v.at(0);
  string rating = m_v.at(2);
  unsigned int index = 0;
  string previous_title = "";
  string show_times = show_time;
  
  while(index < movies.size()){
    m_v = process_line(movies.at(index));
    current_title = m_v.at(1);
    show_time = m_v.at(0);
    rating = m_v.at(2);
    string previous_title = "";
    while(index < movies.size()) {
        m_v = process_line(movies.at(index));
        current_title = m_v.at(1);
        show_time = m_v.at(0);
        rating = m_v.at(2);
        if(previous_title == current_title) {
            cout << " "<< show_time;
        }
        else {
            if(previous_title != "") {
                cout << endl;
            }
            cout << left << setw(44); 
            cout << current_title.substr(0, 44) << " | ";
            cout << right << setw(5) << rating << " | ";
            cout << show_time;
            previous_title = current_title;
        }
    index++;
    }
  cout << endl;
  }
}


int main() {
  string line;
  string file_name;
  
  cin >> file_name;
  ifstream file = ifstream(file_name);
  vector<string> movies;
  while(!file.eof()){
    getline(file, line);
    if(line.length()){
      movies.push_back(line);
    }
  }
  process_movies(movies);
  return 0;
}