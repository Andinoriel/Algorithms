// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Composite.hpp"

#pragma region Leaf
void Composite::Leaf::Execute(void)
{
	std::cout << "\nLeaf: executing...";
}
#pragma endregion

#pragma region Composite
void Composite::Composite::AddChild(IComponent* component)
{
	this->children.emplace_back(component);
}
void Composite::Composite::RemoveChild(IComponent const* component)
{
	std::vector<IComponent*>::iterator del_pos = std::find_if(this->children.begin(), this->children.end(), [](IComponent* component) {
		return true; // implement your copy constructor for the required classes
	});
	if (del_pos not_eq this->children.end())
		this->children.erase(del_pos);
}
std::vector<Composite::IComponent*> Composite::Composite::GetChildren() const
{
	return this->children;
}
void Composite::Composite::Execute()
{
	std::for_each(this->children.begin(), this->children.end(), [](IComponent* component) {
		component->Execute();
	});
}

#pragma endregion

#pragma region TEST
void Composite::TEST::DO_TEST(void)
{
	Composite cmp;
	cmp.AddChild(new Leaf()); // 1
	cmp.AddChild(new Leaf()); // 2

	Composite cmp_ch1, cmp_ch2;
	cmp_ch1.AddChild(new Leaf()); //-V525 //3
	cmp_ch1.AddChild(new Leaf()); //-V525 //4 
	cmp_ch2.AddChild(new Leaf()); //-V525 //5

	cmp.AddChild(&cmp_ch1);
	cmp.AddChild(&cmp_ch2);

	cmp.Execute();
}
#pragma endregion