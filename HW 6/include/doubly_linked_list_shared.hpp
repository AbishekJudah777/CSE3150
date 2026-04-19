#pragma once
#include <iostream>
#include <memory>

class DoublyLinkedListShared 
{
	private:
		struct Node 
		{
			int value;
			std::shared_ptr<Node> next;
			std::shared_ptr<Node> prev;
			Node(int value) : value(value), next(nullptr), prev(nullptr) {}
		
			~Node()
			{
				std::cout <<"Destroying node " << value << "\n";
			}
		};

		std::shared_ptr<Node> head_;
		std::shared_ptr<Node> tail_;
	public:
		DoublyLinkedListShared() = default;
		~DoublyLinkedListShared() = default;

		DoublyLinkedListShared(const DoublyLinkedListShared&) = delete;
		DoublyLinkedListShared& operator=(const DoublyLinkedListShared&) = delete;
	
		void push_back(int value)
		{
			auto newNode = std::make_shared<Node>(value);
			if(!head_)
				head_ = tail_ = newNode;
			else
			{
				newNode->prev = tail_;
				tail_->next = newNode;
				tail_ = newNode;
			}
		}

		void print_forward(std::ostream& os) const
		{
			Node* current = head_.get();
			while(current)
			{
				os << current->value << (current->next ? "<->" : "");
				current = current->next.get();
			}
			os << std::endl;
		}
};
