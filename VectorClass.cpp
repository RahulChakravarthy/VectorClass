//Rahul Chakravarthy
//Creating a vector class
#include <iostream>


using namespace std;

class Vector{

	private:
		int data;
		unsigned int size;
		bool capped;
		Vector* next;
		Vector* head;

	public:
		//Constructors
		Vector();
		Vector(int size);
		//~Vector();

		//Methods
		int GetSize() const;
		int GetArraySize() const;
		void Append(int value);
		void Append(int index, int data);
		void Remove(int index);
		void RemoveValue(int value);
		int GetPos(int value);
		void PrintVector();
		void PrintVector(Vector* &value);
		void massAdd(int* inputArray);
		void Cap();
		void Remove(int value, int value1);

};

class Algebra {

protected: 
	Vector vector;

public: 

	Algebra(Vector &input);
	Algebra();
	void Flex();
};

//Constructors
Vector::Vector(){

	(*this).data = 0;
	(*this).size = 0;
	(*this).next = 0;
	(*this).head = 0;
	(*this).capped = false;
}

Vector::Vector(int size){
	for (int i = 0; i < size; i++){
		(*this).data = 0;
	}

	(*this).size = size;
	(*this).head = 0;
	(*this).capped = false;
}
/*
Vector::~Vector(){

	for (int i = 0; i < (*this).GetSize(); i++) {
		(*this).Remove(i);
	} 

	(*this).size = 0;
	(*this).next = 0;
	delete (*this).head;

}
*/

void Vector::Remove(int value, int value1){

	Vector* Traverse = (*this).head;

	for (int i = 0; i < value-1; i++){
		Traverse = Traverse->next;
	}

	Traverse->next = Traverse->next->next;
}

void Vector::Remove(int value){
	
	Vector* Traverse = (*this).head;


	if ((*this).GetSize() == 1){
		Traverse = 0;
		(*this).size--;
	}

	for (int i = 0; i < (*this).size; i++){
		if (Traverse->next->data = value){
			Traverse->next = Traverse->next->next;
			(*this).size -= 1;
			return;
		}

		Traverse = Traverse->next;
	}


	return;
}

int Vector::GetSize() const{

	return (*this).size;
}

int Vector::GetArraySize() const{
	return 4;
}

void Vector::Append(int index, int data){

	Vector* temp = new Vector;
	temp->data = data;
	temp->next = 0;

	Vector* Traverse = (*this).head;

	for (int i = 0; i < index-2; i++){
		Traverse = Traverse->next;
	}

	temp->next = Traverse->next;
	Traverse->next = temp;

}

//Create a linked list
void Vector::Append(int value){
	//Always add to the beginning

	Vector* temp = new Vector;
	temp->data = value;
	temp->next = 0;
	//First element being added
	if ((*this).head == 0){
		(*this).data = temp->data;
		(*this).head = temp;
		(*this).next = temp->next;
		(*this).size++;
	}
	//Not the first element
	else {
		temp->next = (*this).head;
		(*this).head = temp;
		(*this).size++;
	}
}


void Vector::PrintVector(){

	if ((*this).size == 0){
		cout << "There are no elements in this Vector" << endl;
		return;
	}

	Vector* Traverse = (*this).head;
	cout << "SIZE: " << (*this).size << endl;
	while (Traverse != 0){
		cout << Traverse->data << endl;
		Traverse = Traverse->next;
	}

}

void Vector::PrintVector(Vector* &value){ //For arrays

	for (int i = 0; i < value->GetArraySize(); i++){
		value[i].PrintVector(); //Prints the vector in that element of the array
	}
}

void Vector::Cap(){
	(*this).capped = true;
}

int Vector::GetPos(int value){

	Vector* Traverse = (*this).head;
	int pos = 0;
	while (Traverse->next != NULL){
		pos++;
		if (Traverse->data == value){
			return pos;

		}
		Traverse = Traverse->next;
	}

	return 0;
}




Algebra::Algebra(Vector &input){
	(*this).vector = input;
}

Algebra::Algebra(){

}

int main (){

	
		Vector my_Vector;

		Algebra course(my_Vector);

		course.vector.Append(5);

}
