#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> list;
vector<int> list2;
vector<int> lis;
vector<int> lis2;
vector<int> number_lis;
vector<int> number_lis2;


int new_max;
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
               lis.push_back(1);
               number_lis.push_back(1);
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

    /*file.open("testfile");
    getline(file,mode);
    getline(file,input1);
    getIntsProb(input1,1);
    if(mode == "2"){
        getline(file, input2);
        getIntsProb(input2,2);
    }


    file.close();*/
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
                    if (lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        number_lis[i] = number_lis[j];
                    }

                    else if (lis[j] + 1 == lis[i]){
                        number_lis[i] += number_lis[j];
                    }

                }
            }
        }
        new_max = lis[index_max(lis)];
        int count = 0;
        for(unsigned long  i = 0; i < size; i++){
            if(lis[i] == new_max){
                count += number_lis[i];
            }
        }
        cout << new_max << ' ' << count << endl;
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


