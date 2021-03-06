#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>

std::mutex mOrder;
std::mutex mDeliv;


std::string meal(int& order) {
  switch (order) {
    case 0:
      return "(pizza)";
    case 1:
      return "(soup)";
    case 2:
      return "(steak)";
    case 3:
      return "(salad)";
    case 4:
      return "(sushi)";
    default:
      return "error";
  }
}

void online(std::queue<int>* queueOrder) {
  for (int i = 1; i < 11; i++) {
    std::srand((unsigned int)std::time(nullptr));
    int r = std::rand() % 5;
    std::cout << "Order #" << i << ": ARRIVE " << meal(r) << std::endl;
    mOrder.lock();
    queueOrder->push(r);
    mOrder.unlock();
    r = std::rand() % 5 + 6;
    std::this_thread::sleep_for(std::chrono::seconds(r));
  }
}

void cooking(std::queue<int>* queueOrder, std::queue<int>* queueDeliv) {
  for (int i = 1; i < 11; i++) {
    while (queueOrder->empty()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::srand((unsigned int)std::time(nullptr));
    int r = std::rand() % 5 + 11;
    std::cout << "Order #" << i << ": COOKING " << meal(queueOrder->front()) << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(r));
    std::cout << "Order #" << i << ": AWAITING DELIVERY " << meal(queueOrder->front()) << std::endl;
    
    mDeliv.lock();
    queueDeliv->push(queueOrder->front());
    mDeliv.unlock();
    mOrder.lock();
    queueOrder->pop();
    mOrder.unlock();
  }
}

void delivery(std::queue<int>* queueDeliv) {
  for (int i = 1; i < 11; i++) {
    while (queueDeliv->empty()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::srand((unsigned int)std::time(nullptr));
    std::this_thread::sleep_for(std::chrono::seconds(30));
    std::cout << "Order #" << i << ": DELIVERY " << meal(queueDeliv->front()) << std::endl;
    mDeliv.lock();
    queueDeliv->pop();
    mDeliv.unlock();
  }
  std::cout << std::endl << "10 orders delivered !!!" << std::endl;
}

int main() {
  std::queue<int> queueOrder = {};
  std::queue<int> queueDeliv = {};

  std::thread inOrder(online, &queueOrder);
  std::thread useOrder(cooking, &queueOrder, &queueDeliv);
  std::thread outOrder(delivery, &queueDeliv);

  inOrder.join();
  useOrder.join();
  outOrder.join();
}