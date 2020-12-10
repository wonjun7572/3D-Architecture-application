#include <iostream>
#include <vector>
#include <string>

class Component
{
public:
	virtual ~Component() {};
};

class Composite : public Component
{
public:
	Composite()
	{
		table_ = new std::vector<Component*>();
	}
	
	~Composite()
	{
		for (
			std::vector<Component*>::const_iterator it = table_->begin();
			it != table_->end();
			++it
			)
		{
			delete (*it);
		}

		table_->clear();

		delete table_;
	}

	void add(Component* obj)
	{
		table_->push_back(obj);
	}
private:
	std::vector<Component*>* table_;
};

int main()
{
	Composite* container1 = new Composite();
	Composite* container2 = new Composite();

	container1->add(container2);

	delete container1;
	delete container2;

	return 0;
}