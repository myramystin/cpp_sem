#include <iostream>
#include <unistd.h>   // fork(), getpid(), getppid()
#include <sys/wait.h> // wait()
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic> 

void demo_processes() {
    std::cout << "parent PID: " << getpid() << "\n";

    pid_t pid = fork(); // <-- здесь процесс "раздваивается"
    int shared_var = 100;

    if (pid < 0) {
        std::cerr << "fork() не удался" << "\n";
        return;
    } else if (pid == 0) {
        // Мы находимся в ДОЧЕРНЕМ процессе
        // fork() вернул 0 дочернему
        std::cout << "Я ДОЧЕРНИЙ процесс" << "\n";
        std::cout << "Мой PID: " << getpid() << "\n";
        std::cout << "PID моего родителя: " << getppid() << "\n";

        shared_var = 999;

        std::cout << "shared var " << shared_var << "\n";
    }
    else {
        // Мы находимся в РОДИТЕЛЬСКОМ процессе
        // fork() вернул PID дочернего процесса
        std::cout << "Я РОДИТЕЛЬСКИЙ процесс!" << "\n";
        std::cout << "PID дочернего: " << pid << "\n";

        wait(nullptr); // Ждём завершения дочернего
        std::cout << "Дочерний завершился." << "\n";

        std::cout << "shared var " << shared_var << "\n";
    }
}

void base_threads() {
    auto x = [](int x) {
        std::cout << "hello from thread " << x << "\n";
    };

    std::cout << "Главный поток начал работу" << std::endl;

    // Создаём потоки и передаём им функцию + аргументы
    std::thread t1(x, 1);
    std::thread t2(x, 2);
    std::thread t3(x, 3);

    // join() — ждём завершения потока
    // ВАЖНО: join() ОБЯЗАТЕЛЕН! Иначе программа упадёт.
    t1.join();
    t2.join();
    t3.join();

    std::cout << "Все потоки завершились" << std::endl;
}

void data_race() {

    int counter = 0; // ОБЩАЯ переменная для всех потоков

    auto increment = [&]() {
        for (int i = 0; i < 100000; i++) {
            ++counter;
        }
    };

    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    // Ожидаем: 200000
    std::cout << "Итого: " << counter << std::endl;

}

void mutexes() {
    int counter = 0; // ОБЩАЯ переменная для всех потоков
    std::mutex mtx;

    auto increment = [&]() {
        for (int i = 0; i < 100000; i++) {
            mtx.lock();
            counter++;
            mtx.unlock();
        }
    };

    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    // Ожидаем: 200000
    std::cout << "Итого: " << counter << std::endl;
}

void lock_guards() {
    int counter = 0; // ОБЩАЯ переменная для всех потоков
    std::mutex mtx;

    auto increment = [&]() {
        for (int i = 0; i < 100000; i++) {
            std::lock_guard<std::mutex> guard(mtx);
            counter++;
        }
    };

    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    // Ожидаем: 200000
    std::cout << "Итого: " << counter << std::endl;
}

void atomics() {
    std::atomic<int> atomic_counter(0);

    auto increment = [&]() {
        for (int i = 0; i < 100000; i++) {
            atomic_counter++;
        }
    };

    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    // Ожидаем: 200000
    std::cout << "Итого: " << atomic_counter << std::endl;


    auto x = atomic_counter.fetch_sub(1, std::memory_order_release);

    std::cout << "x " << x << " " << atomic_counter << "\n";

}

void demo_threads() {
    // base_threads();

    // Порядок вывода непредсказуем! Это нормально — ОС сама решает, когда какой поток запустить.
    // data_race();
    
    // mutexes();
    // lock_guards();
    atomics();
}

int main() {
    // demo_processes();
    demo_threads();

    // volatile 



    return 0;
}
