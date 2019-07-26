// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Observer.hpp"

void Observer::Publisher::Subscribe(ISubscriber* subscriber)
{
	this->subscribers.emplace_back(subscriber);
}
void Observer::Publisher::Unsubscribe(ISubscriber* subscriber)
{
	std::vector<ISubscriber*>::iterator del_pos = std::find_if(this->subscribers.begin(), this->subscribers.end(), [](ISubscriber* subscriber) {
		return true; // implement your copy constructor for the required classes
	});
	if (del_pos not_eq this->subscribers.end())
		this->subscribers.erase(del_pos);
}
void Observer::Publisher::Notify(void) const
{
	std::for_each(this->subscribers.begin(), this->subscribers.end(), [](ISubscriber* subscriber) {
		subscriber->Update();
	});
}
void Observer::Publisher::SomeBusinessLogic(void)
{
	this->SomeMainState = 42;
	this->Notify();
}

void Observer::ConcreteSubscriber::Update(void)
{
	std::cout << "\nNotify from Publisher! SomeMainState now is 42";
}

void Observer::TEST::DO_TEST(void)
{
	Publisher pb; 
	ConcreteSubscriber csb;

	pb.Subscribe(&csb);

	pb.SomeBusinessLogic();
};