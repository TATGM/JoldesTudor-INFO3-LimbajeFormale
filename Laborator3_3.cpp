//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

string read_file()
{
    try
    {
        string file_link;
        cout << "Introduce the link to the text file: "; cin >> file_link;
        
        ifstream file(file_link);
        string content;
        
        if(file.is_open())
        {
            //std::istreambuf_iterator is a single-pass input iterator that reads successive characters from the std::basic_streambuf object for which it was constructed.
            content = string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();
        }
        else
        {
            cout << "File not found!\n";
            return "";
        }
        
        return content;
    }
    catch(const exception& exception)
    {
        cerr << "Exception caught: " << exception.what() << "\n";
        return "";
    }
}

bool check(const string& content)
{
    if(content.empty())
    {
        return false; //the content is empty and, by default, not valid
    }

    //regular expressions for the invoice details.
    regex regex_client("Client:\\s([^\\n]+)");
    regex regex_product("Product:\\s([a-zA-Z]+),\\sPret:\\s([\\d.]+),\\sTVA:\\s([\\d]+%),\\sCantitate:\\s(\\d+)");

    bool errors = false;

    //Client section
    //smatch is an instantiation of the match_results class template for matches on string objects.
    smatch match_client;
    //regex_search determines if there is a match between the regular expression content and some subsequence in the target character sequence.
    if(!regex_search(content, match_client, regex_client))
    {
        cout << "Error! The client section doesn't respect the format.\n";
        errors = true;
    }

    //Products section
    //sregex_iterator describes a specialization of template class regex_iterator for iterators of type string::const_iterator.
    sregex_iterator it(content.begin(), content.end(), regex_product);
    sregex_iterator end;
    for(; it != end; ++it)
    {
        int quantity = stoi(it->str(4));
        if(quantity < 0)
        {
            cout << "Error! This number '" << it->str(1) << "' is negative.\n";
            errors = true;
        }

        string product = it->str(1);
        //regex_match determines if the regular expression product matches the entire target character sequence, which may be specified as string, a C-string, or an iterator pair.
        if(!regex_match(product, regex("^[a-zA-Z]+$")))
        {
            cout << "Error! This product '" << product << "' doesn't respect the format.\n";
            errors = true;
        }
    }

    return !errors;
}

int main()
{
    string invoice = read_file();
    
    if(check(invoice))
    {
        cout << "The file respects the format.\nThe invoice:\n" << invoice << "\n";
    }
    else
    {
        cout << "The file doesn't respect the format.\nThe invoice:\n" << invoice << "\n";
    }

    return 0;
}
