#pragma once

#include<iostream>
#include<memory>

class LinkedListUnique
{
	private:
		struct Node 
		{
			int value;
			std::unique_ptr<Node> next;
			
			Node(int value) : value(value) , next(nullptr) {}
		};		
		
		std::unique_ptr<Node> head_;
		Node* tail_;

	public:
		LinkedListUnique() : head_(nullptr), tail_(nullptr) {}
		~LinkedListUnique() = default;
		
		LinkedListUnique(const LinkedListUnique&) = delete;
		LinkedListUnique& operator=(const LinkedListUnique&) = delete;
		
		void push_back(int value)
		{
			auto newNode = std::make_unique<Node>(value);
			Node* rawPtr = newNode.get();
	
			if(!head_)
				head_ = std::move(newNode);
			else
			{
				tail_->next = std::move(newNode);
			}
			tail_ = rawPtr;
		}
	
		void print(std::ostream& os) const
		{
			Node* current = head_.get();
			while(current)
			{
				os << current->value;
				if(current->next)
				{
					os << "->";
				}
				current = current->next.get();
			}
			os << std::endl;
		}
			
};
