#include <iostream>
#include <fstream>
#include "Queue.h"

Queue stringSearch(Queue in, const std::string& str)
{
    Queue out;
    while (!in.isEmpty())
    {
        std::string e = in.dequeue();
        if (e == str)
        {
            out.enqueue(e);
        }
    }
    return out;
}

int main()
{
    std::ifstream input ("input.txt");
    std::ofstream output ("output.txt");
    Queue inp;
    std::string tmp;
    std::string find;
    input >> find;
    while (!input.eof())
    {
        input >> tmp;
        inp.enqueue(tmp);
    }
    Queue result = stringSearch(inp, find);
    while (!result.isEmpty())
    {
        output << result.dequeue() << std::endl;
    }
    input.close();
    output.close();
    return 0;
}
