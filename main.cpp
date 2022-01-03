#include <iostream>
#include <sstream>
#include <unordered_map>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;

string mode;
string input1;
string input2;

unordered_map<int,int> map;

unsigned long size=0, size2=0;

void getIntsProb(string str, int flag, string mode)
{
    stringstream ss;

    ss << str;

    string temp;
    int number;
    int i=0;
    while (!ss.eof())
    {

        ss >> temp;
        if (flag == 1)
        {
            if (stringstream(temp) >> number)
            {
                if (mode=="2"){
                    map.insert(make_pair(number, i));
                    i++;
                }
                size++;
            }
        }

        else
        {
            if (stringstream(temp) >> number)
            {
                if (map.find(number) != map.end())
                    size2++;
            }
        }

        temp = "";
    }
}

void parse()
{
    getline(cin, mode);
    getline(cin, input1);
    getIntsProb(input1, 1, mode);
    if (mode == "2")
    {
        getline(cin, input2);
        getIntsProb(input2, 2, mode);
    }
}

void get_numbers1(int array_list[], string str)
{
    stringstream ss;

    ss << str;

    string temp;
    int number;
    int i = 0;
    while (!ss.eof())
    {

        ss >> temp;
        if (stringstream(temp) >> number)
        {
            array_list[i] = number;
            i++;
        }
        temp="";
    }
}

void get_numbers2(int array_list2[], string str)
{
    stringstream ss;

    ss << str;

    string temp;
    int number;
    int i = 0;
    while (!ss.eof())
    {

        ss >> temp;
        if (stringstream(temp) >> number)
        {
            if (map.find(number) != map.end()){
                array_list2[i] = number;
                i++;
            }
        }
        temp="";
    }
}

void initialize_arrays(int size_seq[], int number_seq[])
{
    for (unsigned long i = 0; i != size; i++)
    {
        size_seq[i] = 1;
        number_seq[i] = 1;
    }
}

void prob1()
{
    int max_size = 1;
    int number_of_subsequences = 1;
    int *size_seq = new int[size];
    int *number_seq = new int[size];
    int *array_list = new int[size];
    int number_seq_i, number_seq_j, size_seq_i, size_seq_j;
    get_numbers1(array_list, input1);
    initialize_arrays(size_seq, number_seq);
    for (unsigned long i = 1; i < size; i++)
    {
        number_seq_i=number_seq[i];
        size_seq_i=size_seq[i];
        for (unsigned long j = 0; j < i; j++)
        {
            number_seq_j=number_seq[j];
            size_seq_j=size_seq[j];
            if (array_list[j] < array_list[i])
            {

                if (size_seq_j + 1 > size_seq_i)
                {
                    size_seq_i = size_seq_j + 1;
                    number_seq_i = number_seq_j;
                }

                else if (size_seq_j + 1 == size_seq_i)
                {
                    number_seq_i += number_seq_j;
                }

            }
        }
        if (size_seq_i > max_size)
        {
            max_size = size_seq_i;
            number_of_subsequences = 0;
        }

        if (size_seq_i == max_size)
            number_of_subsequences += number_seq_i;

        size_seq[i]=size_seq_i;
        number_seq[i]=number_seq_i;
    }

    cout << max_size << ' ' << number_of_subsequences << endl;
}

void prob2()
{
    int *array_list = new int[size];
    get_numbers1(array_list, input1);

    int *array_list2 = new int[size2];
    get_numbers2(array_list2, input2);

    unsigned long index_longest[size2];
    vector<unsigned long> lcis;
    unsigned long length=0;
    unsigned long j=0, k=0;
    
    while (j<size2){
        index_longest[j]=0;
        j++;
    }

    while (k<size){
        lcis.push_back(0);
        k++;
    }

    for (unsigned long i=0; i<size; i++)
    {
  
        for (j=0; j<size2; j++)
        {
            
            if (array_list[i] == array_list2[j])
                if (lcis[i] + 1 > index_longest[j])
                    index_longest[j] = lcis[i] + 1;
  
            if (array_list[i] > array_list2[j])
                if (index_longest[j] > lcis[i])
                    lcis[i] = index_longest[j];

            if (index_longest[j] > length)
                length = index_longest[j];
            
        }
    }
  
    cout << length << endl;
  
}

int main()
{
    
    /*
    clock_t start, end;

    start = clock();
    */

    parse();
    if (mode == "1")
    {
        prob1();
    }
    if (mode == "2")
    {
        prob2();
    }

    /*
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    */
    
}
