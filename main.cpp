#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> list;
vector<int> list2;
vector<int> size_seq;
vector<int> lis2;
vector<int> number_seq;
vector<int> number_lis2;


int max_size;
string mode;
string input1;
string input2;

void getIntsProb(string str, int flag)
{
    stringstream ss;

    ss << str;

    string temp;
    int number;
    while (!ss.eof()) {

        ss >> temp;
       if(flag == 1) {
           if (stringstream(temp) >> number){
               list.push_back(number);
               size_seq.push_back(1);
               number_seq.push_back(1);
           }
       }

       else{
           if (stringstream(temp) >> number){
               list2.push_back(number);
               lis2.push_back(1);
               number_lis2.push_back(1);
           }

       }



        temp = "";
    }
}




void parse(){
    ifstream file;
    getline(cin,mode);
    getline(cin,input1);
    getIntsProb(input1,1);
    if(mode == "2"){
        getline(cin, input2);
        getIntsProb(input2,2);
    }
}

unsigned long  index_max(vector<int> v) {
    unsigned long size = v.size();
    int max;
    unsigned long max_index = 0;
    for (unsigned long i = 0; i < size; i++) {
        if (i == 0) {
            max = v[0];
            max_index = 0;
        }
        if (v[i] > max) {
            max = v[i];
            max_index = i;
        }


    }
    return max_index;
}




int main() {
    parse();
    if(mode == "1"){
        unsigned long size = list.size();
        for (unsigned long i = 1; i < size; i++) {
            for (unsigned long j = 0; j < i; j++) {
                if (list[j] < list[i]) {
                    
                    if (size_seq[j] + 1 > size_seq[i]) {
                        size_seq[i] = size_seq[j] + 1;
                        number_seq[i] = number_seq[j];
                    }

                    else if (size_seq[j] + 1 == size_seq[i]){
                        number_seq[i] += number_seq[j];
                    }
                }
            }
        }
        max_size = size_seq[index_max(size_seq)];
        int n_sized_subsequences = 0;
        for(unsigned long  i = 0; i < size; i++){
            if(size_seq[i] == max_size ){
                n_sized_subsequences += number_seq[i];
            }
        }
        cout << max_size << ' ' << n_sized_subsequences << endl;
    }
    if(mode == "2"){
        unsigned long size1 = list.size();
        unsigned long size2 = list2.size();
        cout << "Lista1: " << endl;
        for(unsigned long i = 0; i < size1; i++){
            cout << list[i] << ' ';
        }

        cout << endl << "Lista2: " << endl;

        for(unsigned long i=0; i<size2; i++){
            cout<< list2[i] << ' ';
        }
        cout << endl;
    }

}


