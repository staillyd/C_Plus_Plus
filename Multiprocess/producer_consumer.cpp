#include <unistd.h>

#include <condition_variable>  // std::condition_variable
#include <iostream>            // std::cout
#include <mutex>               // std::mutex, std::unique_lock
#include <thread>              // std::thread, std::this_thread::yield

std::mutex mtx;
std::condition_variable cv;

int cargo = 0;
bool shipment_available() { return cargo != 0; }

// 消费者线程.
void consume(int n) {
  for (int i = 0; i < n; ++i) {
    std::unique_lock<std::mutex> lck(mtx);  //进程互斥但不堵塞
    cv.wait(lck, shipment_available);  //当条件不满足时堵塞，直到被notify
    std::cout << cargo << '\n';
    cargo = 0;
  }
}

int main() {
  std::thread consumer_thread(consume, 10);  // 消费者线程. 立即start,不像python
  // sleep(2);

  // 主线程为生产者线程, 生产 10 个物品.
  for (int i = 0; i < 10; ++i) {
    while (shipment_available())  //不满足条件再往下执行
      i = i;
    //   std::this_thread::yield();//只是用于让出CPU
    // sleep(2);

    std::unique_lock<std::mutex> lck(mtx);  //进程互斥但不堵塞
    cargo = i + 1;
    cv.notify_one();
  }

  consumer_thread.join();  //进程同步,等待consumer_thread进程结束才往下执行

  return 0;
}