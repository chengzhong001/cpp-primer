cmake_minimum_required(VERSION 3.8)
project(cpp-concurrency)

# set(CMAKE_CXX_COMPILER "AppleClang")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)


add_executable(01_hello_thread               01_hello_thread.cpp)
add_executable(02_lambda_thread              02_lambda_thread.cpp)
add_executable(03_thread_argument            03_thread_argument.cpp)
add_executable(04_thread_self_manage         04_thread_self_manage.cpp)
add_executable(05_call_once                  05_call_once.cpp)
add_executable(06_naive_multithread          06_naive_multithread.cpp)
add_executable(07_mutex_lock                 07_mutex_lock.cpp)
add_executable(08_improved_mutex_lock        08_improved_mutex_lock.cpp)
# add_executable(deadlock_bank_transfer     09_deadlock_bank_transfer.cpp)
# add_executable(improved_bank_transfer     10_improved_bank_transfer.cpp)
# add_executable(bank_transfer_wait_notify  11_bank_transfer_wait_notify.cpp)
# add_executable(async_task                 12_async_task.cpp)
# add_executable(packaged_task              13_packaged_task.cpp)
# add_executable(promise_future             14_promise_future.cpp)