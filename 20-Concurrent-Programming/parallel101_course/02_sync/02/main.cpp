#include <iostream>
#include <string>
#include <thread>
#include <future>

int download(std::string file) {
    for (int i = 0; i < 10; i++) {
        std::cout << "Downloading " << file
                  << " (" << i * 10 << "%)..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    std::cout << "Download complete: " << file << std::endl;
    return 404;
}

void interact() {
    std::string name;
    std::cin >> name;
    std::cout << "Hi, " << name << std::endl;
}

int main(int argc, char const *argv[])
{
    std::future<int> fret = std::async([&] {
        return download("hello.zip"); 
    });
    interact();
    fret.wait();
    std::cout << "Wait return!" << std::endl;
    int ret = fret.get();
    std::cout << "Download result: " << ret << std::endl;
    
    return 0;
}
