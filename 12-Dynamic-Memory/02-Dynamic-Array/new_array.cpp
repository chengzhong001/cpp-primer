#include <iostream>

void test1()
{
    int *pia = new int[10];
    typedef int arrT[42];
    int *p = new arrT;
    std::cout << sizeof(p) << std::endl;
    std::cout << pia[8] << std::endl;

    delete[] pia;
    delete[] p;
}

void test2()
{
    int *pia = new int[10];    //10个未初始化的int
    int *pia2 = new int[10](); //10个值初始化为0的int

    std::string *psa = new std::string[10];    //10个空string
    std::string *psa2 = new std::string[10](); //10个空string

    int *pia3 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::string *psa3 = new std::string[10]{"a", "b", "the", std::string(3, 'x')};
    std::cout << psa3[3] << std::endl;

    delete[] pia;
    delete[] pia2;
    delete[] psa;
    delete[] psa2;
    delete[] pia3;
    delete[] psa3;
}

void test3()
{
    std::unique_ptr<int[]> up(new int[10]);
    for (int i = 0; i < 10; i++)
    {
        up[i] = i;
    }
    std::cout << up[6] << std::endl;
    up.release();
}
void test4()
{
    std::shared_ptr<int> sp(new int[10], [](int *p)
                            { delete[] p; });
    for (size_t i = 0; i < 10; i++)
    {
        *(sp.get() + i) = i;
    }

    sp.reset();
}

int main(int argc, char const *argv[])
{
    /* code */
    // test1();
    test4();
    return 0;
}
