#include <iostream>
#include "linked_list_raw.hpp"
#include "linked_list_unique.hpp"
#include "doubly_linked_list_shared.hpp"
#include "doubly_linked_list_weak.hpp"


int main()
{
	std::cout << "--- Phase 1: Raw Pointers ---\n";
	{
		LinkedListRaw list;
		list.push_back(10);
		list.push_back(20);
		list.push_back(30);
		list.print(std::cout);
	}
	
	std::cout << "\n--- Phase 2: Unique Pointers ---\n";
	{	
		LinkedListUnique list;
		list.push_back(10);
		list.push_back(20);
		list.push_back(30);
		list.print(std::cout);
	}
	
	std::cout << "\n--- Phase 3: Shared Pointers (The Leak) ---\n";
	{
		DoublyLinkedListShared list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.print_forward(std::cout);
	}

	std::cout << "\n--- Phase 4: Weak Pointers (The Fix) ---\n";
	{
		DoublyLinkedListWeak list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.print_forward(std::cout);
		std::cout << "\n";
		list.print_backward(std::cout);
		std::cout << "\n";
	}

	return 0;
}
