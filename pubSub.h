Server:
- Create socket
- bind 
- listen 
- accept
- send/recev

Client:
- socket
- connect
- send/recev


struct Tick {
	string id;
	//... Data
};


PubSubServer.cpp
#include <thread>
#include <unordered_map>
#include <mutex>
#include <conditional_variable>

class Semaphore {
	std::mutex mutex_;
	std::condition_variable condition_;
	unsigned long count_;

	public:
		void notify() {
			std::lock_guard<decltype(mutex_)> lock(mutex_);
			++count_;
			condition_.notify_one();
		}

		void wait() {
			std::unique_lock<decltype(mutex_)> lock(mutex_);
			while(!count_) { // Handle spurious wake-ups.
				condition_.wait(lock);
			}
			--count;
		}

		bool try_wait() {
			std::lock_guard<decltype(mutex_)> lock(mutex_);
			if (count_) {
				--count_;
				return true;
			}
			return false;
		}
};


class PubSubSever {
	unordered_map<string, vector<socketAddress>> subscriptions;
	std::thread subThread; // Subscription thread
	std::thread pubThread; // Publish thread
	std::thread tickThread; // StockTick thread
	std::queue<struct Tick> cirBuffer;
	

	static PubSubSever *_instance;
	
	public:
	PubSubSever() {
		// create semaphore size of data avaliable
		// Create threads or async
	}

	~PubSubSever() {
		// join threads and finish
	}
	
	static PubSubSever* instance() {
		if (!_instance) {
			_instance = new PubSubSever;
		}
		return _instance;
	}
};

// Allocate and initialize GlobalClass's static instance member
PubSubSever * PubSubSever::_instance = nullptr;

int main() {
	PubSubSever::instance()->func();
}