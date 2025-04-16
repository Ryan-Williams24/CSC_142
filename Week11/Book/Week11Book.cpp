#include <iostream>
#include <chrono>
#include <string>
#include <utility>

struct TimerClass {
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    TimePoint* timestamp;
    const char* name;
    bool moved_from;

    TimerClass(const char* timer_name = "Unnamed Timer")
        : timestamp(new TimePoint(Clock::now())), name(timer_name), moved_from(false) {}

    ~TimerClass() {
        if (!moved_from) {
            TimePoint end_time = Clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - *timestamp).count();
            std::cout << "Timer [" << name << "] elapsed time: " << duration << " ms\n";
        }
        delete timestamp;
    }

    TimerClass(const TimerClass& other)
        : timestamp(new TimePoint(*other.timestamp)), name(other.name), moved_from(false) {}

    TimerClass& operator=(const TimerClass& other) {
        if (this != &other) {
            delete timestamp;
            timestamp = new TimePoint(*other.timestamp);
            name = other.name;
            moved_from = false;
        }
        return *this;
    }

    TimerClass(TimerClass&& other) noexcept
        : timestamp(other.timestamp), name(other.name), moved_from(false) {
        other.timestamp = nullptr;
        other.moved_from = true;
    }

    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this != &other) {
            delete timestamp;
            timestamp = other.timestamp;
            name = other.name;
            moved_from = false;

            other.timestamp = nullptr;
            other.moved_from = true;
        }
        return *this;
    }
};

void performComputation(TimerClass timer) {
    volatile double result = 0.0;
    for (int i = 0; i < 1'000'000; ++i) {
        result += std::sin(i) * std::cos(i);
    }
}

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    TimerClass timer("Computation Timer");
    performComputation(std::move(timer));

    TimerClass timer2("Copy Test Timer");
    TimerClass timer3 = timer2;
    TimerClass timer4 = std::move(timer2);

    return 0;
}