#include <string>
#include <vector>
#include <regex>
#include <iostream>

void split1(const std::string &str, std::vector<std::string> &tokens, const char delim)
{
    tokens.clear();
    int p = -1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == delim)
        {
            tokens.emplace_back(str.substr(p + 1, i - p - 1)); //(p,i)
            p = i;
        }
    }
    tokens.emplace_back(str.substr(p + 1));
}

void split2(const std::string &str, std::vector<std::string> &tokens, const std::string delim)
{
    tokens.clear();
    int p = -1;
    for (int i = 0; i < str.size(); i++)
    {
        if (delim.find(str[i]) != std::string::npos)
        {
            tokens.emplace_back(str.substr(p + 1, i - p - 1)); //(p,i)
            p = i;
        }
    }
    tokens.emplace_back(str.substr(p + 1));
}

void split3(const std::string &str, std::vector<std::string> &tokens, const char delim)
{
    int pos = -1;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == delim)
        {
            if (pos > 0 && str[i - 1] == delim)
            {
                pos = i;
                continue;
            }
            tokens.emplace_back(str.substr(pos + 1, i - pos - 1));
            pos = i;
        }
    }
    tokens.emplace_back(str.substr(pos + 1));
}

void split4(const std::string &str, std::vector<std::string> &tokens, const std::string delim)
{
    // 正则表达式分割
    std::regex pattern(delim);
    tokens.clear();
    std::vector<std::string> v(std::sregex_token_iterator(str.begin(), str.end(), pattern, -1), std::sregex_token_iterator());
    tokens.assign(v.begin(), v.end());
}

std::vector<std::string> split(const std::string &str, const std::string &delim)
{
    std::vector<std::string> res;
    size_t pos = 0;
    while (true)
    {
        size_t new_pos = str.find_first_of(delim, pos);
        if(new_pos == str.npos){
            res.push_back(str.substr(pos, new_pos));
            break;
        }
        res.push_back(str.substr(pos, new_pos-pos));
        pos = new_pos + 1;
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> v = {"hello", "world"};
    v.insert(v.begin() + 1, "xx");

    std::string str("hello,,,,,world,0");
    std::string str2("hello   world,0");
    std::vector<std::string> v1;

    split4(str, v1, ",+");

    for (auto word : v1)
    {
        std::cout << word << "\n";
    }

    std::cout << str.substr() << "\n";

    std::string str3 = "hello world, kangkang\n nice";
    auto v3 = split(str3, std::string("\n ,"));
    for(auto i: v3){
        std::cout << i << " ";
    }

    return 0;
}
