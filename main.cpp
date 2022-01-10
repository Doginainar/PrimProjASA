#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

string mode;
string input1;
string input2;

unordered_map<int, int> map;

unsigned long size = 0, size2 = 0;

void getIntsProb(string str, int flag, string mode)
{
    stringstream ss;

    ss << str;

    string temp;

    int number, i = 0;

    if (mode == "1")
    {
        while (!ss.eof())
        {

            ss >> temp;
            if (stringstream(temp) >> number)
            {
                size++;
            }
            temp = "";
        }
        return;
    }

    while (!ss.eof())
    {

        ss >> temp;
        if (flag == 1)
        {
            if (stringstream(temp) >> number)
            {
                if (mode == "2")
                {
                    map.insert(make_pair(number, i));
                    i++;
                    size++;
                }
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

void get_numbers(int array_list[], string str){
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
        temp = "";
    }
}

void get_numbers2(int array_list[], string str)
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
            if (map.find(number) != map.end())
            {
                array_list[i] = number;
                i++;
            }
        }
        temp = "";
    }
}

void prob1()
{
    int *size_seq = new int[size], *number_seq = new int[size], *array_list = new int[size];
    get_numbers(array_list, input1);
    int max_size = 1, number_of_subsequences = 0;
    int number_seq_i, size_seq_i, array_list_i;
    size_seq[0] = 1;
    number_seq[0] = 1;

    for (unsigned long i = 1; i < size; i++)
    {
        number_seq_i = 1;
        size_seq_i = 1;
        array_list_i = array_list[i];

        for (unsigned long j = 0; j < i; j++)
        {
            if (array_list[j] < array_list_i)
            {
                if (size_seq[j] + 1 > size_seq_i)
                {
                    size_seq_i = size_seq[j] + 1;
                    number_seq_i = number_seq[j];
                }

                else if (size_seq[j] + 1 == size_seq_i)
                {
                    number_seq_i += number_seq[j];
                }
            }
        }
        if (size_seq_i > max_size)
        {
            max_size = size_seq_i;
        }
        size_seq[i] = size_seq_i;
        number_seq[i] = number_seq_i;
    }

    for (unsigned long i=0; i!=size; i++){
        if (size_seq[i]==max_size)
            number_of_subsequences+=number_seq[i];
    }

    cout << max_size << ' ' << number_of_subsequences << endl;
}

void prob2()
{
    int *array_list = new int[size];
    get_numbers2(array_list, input1);

    int *array_list2 = new int[size2];
    get_numbers2(array_list2, input2);

    unsigned long index_longest[size2];

    unsigned long lcis = 0, length = 0, j = 0, index_longest_j = 0, array_list_i = 0, array_list2_j = 0;

    for (unsigned long j=0; j!=size2; j++){
        index_longest[j]=0;
    }

    for (unsigned long i = 0; i < size; i++, lcis = 0)
    {
        array_list_i = array_list[i];

        for (j = 0; j < size2; j++)
        {
            array_list2_j = array_list2[j];
            index_longest_j = index_longest[j];

            if (array_list_i == array_list2_j)
                if (lcis + 1 > index_longest_j)
                {
                    index_longest[j] = lcis + 1;
                    index_longest_j = lcis + 1;
                }

            if (array_list_i > array_list2_j)
                if (index_longest_j > lcis)
                    lcis = index_longest_j;

            if (index_longest_j > length)
                length = index_longest_j;
        }
    }

    cout << length << endl;
}

int main()
{
    parse();
    if (mode == "1")
    {
        prob1();
    }
    if (mode == "2")
    {
        prob2();
    }
}
