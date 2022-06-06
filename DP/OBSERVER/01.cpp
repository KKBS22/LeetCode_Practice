#include<iostream>
#include<memory>
#include<list>
#include<string>

/**
 * I want listen to the subject event
 *
 * */
class IObserver {
	public:
		virtual void update(std::string message) = 0;

}

/**
 * I will let u know when the event happens,u keep registered to me 
 * */
class Subject {
	private:
		std::list<std::shared_ptr<IObserver>> observer_list;
		void notify_all() {
			for (auto it = observer_list.begin(); it != observer_list.end(); it++) {
				(*it)->update("LOW POWER");
			}
		}
	public:
		void reg_listener(std::shared_ptr<IObserver> observer) {
			observer_list.puch_back(observer);
		}

		void un_reg_listener(std::shared_ptr<IObserver> observer) {
			obeserver_list.remove(observer);
		}
}

/**
 * Listener
 * */
class Display : public IObserver {
}

/**
 * Listener
 * */
class Audio : public IObserver {
}


/**
 * Client code
 * */
int main() {
}
