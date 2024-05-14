#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>

// const int len = 4;
using namespace std;

long long int hashing(string str)
{

    long long int hashVal[26]{0};

    int x = 26;

    for (int i = 0; i < 26; i++)
    {
        hashVal[i] = i * (pow(4, i));
    }

    long long int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if ((int)str[i] < 90)
            str[i] = int(str[i]) + 32;
    }

    for (int i = 0; i < str.length(); i++)
        sum += hashVal[int(str[i]) - 97];

    return sum;
}

string unnecessary(string str)
{
    string ss = "";
    int c = 0;
    bool flag = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (flag && str[i] == '}')
            break;
        if (str[i] == ']')
            break;
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
            ss += str[i];
        if (str[i] == '}')
            flag = true;
    }
    return ss;
}

struct Node
{
    string data;
    Node *next;
};

class LL
{
private:
    Node *head;

public:
    LL()
    {
        head = NULL;
    }
    int length = 0;

    void dataInsert(string data)
    {
        length++;
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    long long int dataSearch(int index)
    {
        int i = 0;
        Node *current = head;
        while (current != NULL && i < index)
        {
            current = current->next;
            i++;
        }
        if (current == NULL)
        {
            return -1;
        }
        else
        {
            return hashing(current->data);
        }
    }
    string getValueAt(int index)
    {
        Node *curr = head;
        int i = 0;
        while (curr != nullptr && i < index)
        {
            curr = curr->next;
            i++;
        }
        if (curr == nullptr)
        {
            // index out of range
            return "";
        }
        return curr->data;
    }

    void dataRemove(int index)
    {
        if (head == NULL)
        {
            return;
        }
        length--;
        Node *current = head;
        if (index == 0)
        {
            head = current->next;
            delete current;
            return;
        }
        for (int i = 0; current != NULL && i < index - 1; i++)
        {
            current = current->next;
        }
        if (current == NULL || current->next == NULL)
        {
            return;
        }

        Node *next = current->next->next;
        // cout << current->next->data << endl;
        delete current->next;
        current->next = next;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "empty." << endl;
        }
        else
        {
            Node *current = head;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

bool ingredientsCheck(LL ingredients, LL *dish, string **groups, int l)
{
    const int len = l;
    // bool flag[len]{ 0 };
    bool *flag = new bool[len]{0};
    long long int *x = new long long int[len]{0};
    long long int y = 0;
    bool finalFlag = false;

    int length = ingredients.length;
    int a = 0;

    for (int k = 0; k < len; k++)
    {
        for (int i = 0; i < ingredients.length; i++)
        {
            flag[k] = false;

            for (int j = 0; j < dish[k].length; j++)
                x[k] += hashing(groups[k][j]);

            for (int j = 0; j < dish[k].length; j++)
                y += ingredients.dataSearch(i + j);
            // cout << x[k] << "\t" << y << "\t" << i << endl;
            if (x[k] != y)
            {
                flag[k] = true;
                x[k] = 0;
                y = 0;
            }

            if (!flag[k])
            {
                for (int j = 0; j < dish[k].length; j++)
                {
                    ingredients.dataRemove(i);
                    a++;
                }
                // break;
            }
        }
    }
    // ingredients.print();
    //  cout << z;
    // for (int i = 0; i < len; i++)
    //   cout << dish[i].length << endl;
    cout << a << endl;
    int dishes = 0;
    for (int i = 0; i < len; i++)
        dishes += dish[i].length;
    if (a == dishes)
        return true;
    else
    {
        return false;
    }
}

int main()
{

    ifstream input_file("p1_input.txt");

    if (!input_file.is_open())
    {
        std::cerr << "Failed to open file!" << endl;
        return 1;
    }
    int rows = 0, col = 0, cases = 0;

    string line;
    string word;
    bool flag = false;
    while (getline(input_file, line))
    {

        for (int i = 0; line[i] != '\0' && !flag; i++)
        {
            if (line[i] == ' ')
            {
                // cout << word << endl;
                word = "";
            }
            word += line[i];
            if (line[i] == '}')
            {
                rows += 1;
                // cout << word << endl;
            }
            if (word.find("',") != string::npos)
            {
                col++;
            }
            if (word.find("case") != string::npos)
            {
                flag = true;
            }
        }
        if (line.find("case") != string::npos)
            cases++;
    }
    col += rows;

    input_file.close();
    rows--;
    // cout << cases << endl;

    LL *dish = new LL[rows];
    LL *dummy = new LL[rows];
    LL *test = new LL[cases];

    ifstream file("p1_input.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open file!" << endl;
        return 1;
    }
    flag = false;
    bool eflag = false;
    int j = 0;
    bool rflag = false;
    bool flag2 = false;
    bool sflag = false;
    string sword;
    string tword;

    int l = -1;
    int xy = 0;
    while (getline(file, line))
    {
        for (int i = 0; line[i] != '\0' && !flag && j < rows; i++)
        {
            if (sword.find("},") != string::npos)
            {
                rflag = true;
            }
            if (line[i] == ' ')
            {
                // cout << sword << endl;
                if (eflag)
                {
                    string x = unnecessary(sword);
                    if (x != "")
                    {
                        dish[j].dataInsert(x);
                        dummy[j].dataInsert(x);
                    }
                }
                sword = "";
            }
            sword += line[i];
            if (line[i] == '=')
                eflag = true;

            if (sword.find("case") != string::npos)
            {
                flag = true;
            }
            if (rflag)
            {
                j++;
                rflag = false;
            }
        }

        for (int i = 0; i < line.length() && l < cases; i++)
        {

            if (flag2)
            {
                if (line[i] == '[')
                    sflag = true;
                if (line[i] == ']')
                {
                    sflag = false;
                    xy = 1;
                }
            }

            if (tword.find("case") != string::npos)
            {
                flag2 = true;
                l++;
            }
            if (line[i] == ' ' || (line.length() - i) == 1)
            {
                // cout << tword << endl;
                if (sflag + xy)
                {
                    xy = 0;
                    string x = unnecessary(tword);
                    if (x != "")
                        test[l].dataInsert(x);
                    // cout << unnecessary(tword) << endl;;
                }
                tword = "";
            }
            tword += line[i];
        }
    }

    file.close();

    for (int i = 0; i < rows; i++)
    {
        // dish[i].print();
    }
    for (int i = 0; i < cases; i++)
    {
        // test[i].print();
    }
    int max = 0;
    for (int i = 0; i < rows; i++)
    {
        if (dish[i].length > max)
            max = dish[i].length;
    }

    // cout << dish[0].length;
    string **array = new string *[rows];
    for (int i = 0; i < rows; i++)
        array[i] = new string[max];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < max; j++)
        {
            array[i][j] = dummy[i].getValueAt(j);
        }
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < max; j++)
        {
            // cout << array[i][j] << '\t';
        }
        cout << endl;
    }
    for (int i = 0; i < cases; i++)
    {
        cout << "TEST CASE " << i << ": " << ingredientsCheck(test[i], dish, array, rows) << endl;
    }
    // cout << ingredientsCheck(test[4], dish, array, 2);

    delete[] dish;
    delete[] dummy;
    delete[] test;
}