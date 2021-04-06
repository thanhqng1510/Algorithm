/*
	Implement a stack using only queue operations.
 */


// ---------------------------------------


#include <iostream>
#include <queue>
#include <functional>
using namespace std;


// Method 1: using 2 queues (costly push operation, since coslty pop operation is not viable for top operation)
template<typename T>
class Stack_1 {
public:
	void push(const T& val) {
		while (!m_primary.empty()) {
			m_temp.push(m_primary.front());
			m_primary.pop();
		}
		
		m_primary.push(val);
		
		while (!m_temp.empty()) {
			m_primary.push(m_temp.front());
			m_temp.pop();
		}
	}
		
	void pop() {
		m_primary.pop();
	}
	
	T& top() {
		return m_primary.front();
	}
	
	const T& top() const {
		return m_primary.front();
	}
	
	unsigned int size() const {
		return m_primary.size();
	}
	
	bool empty() const {
		return m_primary.empty();
	}
	
	void consume(const std::function<void(T&)>& f) {
		while (!empty()) {
			f(top());
			pop();
		}
	}
private:
	queue<T> m_primary, m_temp;
};


// Method 2: using 1 queue (reverse order using recursion)
template<typename T>
class Stack_2 {
public:
	void push(const T& val) {
		if (!pushing) m_reverse();
		m_queue.push(val);
	}
		
	void pop() {
		if (pushing) m_reverse();
		m_queue.pop();
	}
	
	T& top() {
		if (pushing) m_reverse();
		return m_queue.front();
	}
	
	const T& top() const {
		if (pushing) m_reverse();
		return m_queue.front();
	}
	
	unsigned int size() const {
		return m_queue.size();
	}
	
	bool empty() const {
		return m_queue.empty();
	}
	
	void consume(const std::function<void(T&)>& f) {
		while (!empty()) {
			f(top());
			pop();
		}
	}
private:
	queue<T> m_queue;
	bool pushing = true;
private:
	void m_reverse() {
		m_reverseRecur();
		pushing ^= true;
	}
	
	void m_reverseRecur() {
		if (empty()) return;
		
		T val = m_queue.front();
		m_queue.pop();
		
		m_reverseRecur();
		
		m_queue.push(val);
	}
};


// Method 3: using 1 queue (rotation with costly push operation)
template<typename T>
class Stack_3 {
public:
	void push(const T& val) {
		m_queue.push(val);
		for (int i = 0; i < size() - 1; ++i) {
			m_queue.push(m_queue.front());
			m_queue.pop();
		}
	}
		
	void pop() {
		m_queue.pop();
	}
	
	T& top() {
		return m_queue.front();
	}
	
	const T& top() const {
		return m_queue.front();
	}
	
	unsigned int size() const {
		return m_queue.size();
	}
	
	bool empty() const {
		return m_queue.empty();
	}
	
	void consume(const std::function<void(T&)>& f) {
		while (!empty()) {
			f(top());
			pop();
		}
	}
private:
	queue<T> m_queue;
};


int main() {
	Stack_1<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.consume([](int& val) -> void {
		cout << val << " ";
	});
	cout << "\n";
	
	Stack_2<int> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	s2.push(5);
	s2.consume([](int& val) -> void {
		cout << val << " ";
	});
	cout << "\n";
	
	Stack_3<int> s3;
	s3.push(1);
	s3.push(2);
	s3.push(3);
	s3.push(4);
	s3.push(5);
	s3.consume([](int& val) -> void {
		cout << val << " ";
	});
	cout << "\n";
}