#pragma once
#include <iostream>
#include <memory>

class DoublyLinkedListWeak {
	private:
		struct Node {
			int value;
			std::shared_ptr<Node> next;
			std::weak_ptr<Node> prev;

			Node(int value) : value(value), next(nullptr), prev() {}
			
			~Node() {
				std::cout << "Destroying node " << value << "\n";
				}
			};

		std::shared_ptr<Node> head_;
		std::shared_ptr<Node> tail_;

		public:
		DoublyLinkedListWeak() = default;
		~DoublyLinkedListWeak() = default;

		DoublyLinkedListWeak(const DoublyLinkedListWeak&) = delete;
		DoublyLinkedListWeak& operator=(const DoublyLinkedListWeak&) = delete;

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
				os << current->value << (current->next ? "<->" : "" );
				current = current->next.get();
			}
			os << std::endl;
		}
	
		void print_backward(std::ostream& os) const
		{
			std::shared_ptr<Node> current = tail_;
			while(current)
			{
				os << current->value;
				std::shared_ptr<Node> previous = current->prev.lock();
				if(previous)
				{
					os << "<->" ;
				}
				current = previous;
			}
			os << std::endl;
		}
};





