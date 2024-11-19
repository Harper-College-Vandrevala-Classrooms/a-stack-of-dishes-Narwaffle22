#include <iostream>

using namespace std;

class Dish {
private:
    string description;

public:
    Dish() {}
    Dish(string description) {
        this->description = description;
    }

    string get_description() {
        return this->description;
    }
};

class DishStack {
public:
	DishStack();
	void push(Dish);
    Dish pop();
    Dish peek();
    int size();
private:
    const int MAX_SIZE = 10;
    Dish dishArray[10];
    int latest = -1;
    bool isFull();
};
DishStack::DishStack() {
}
void DishStack::push(Dish dish) {
    if (!isFull()) {
        dishArray[latest + 1] = dish;
        latest++;
    }
}
Dish DishStack::pop() {
    Dish currDish;
    Dish blankDish;
    if (latest != -1) {
        currDish = dishArray[latest];
        dishArray[latest] = blankDish;
        latest--;
    }
    return currDish;
}
Dish DishStack::peek() {
    if (latest != -1) {
        return dishArray[latest];
    }
}
int DishStack::size() {
    if (isFull()) {
        return 10;
    }
    else {
        return latest + 1;
    }
}
bool DishStack::isFull() {
    return latest == 10;
}

int main() {
    DishStack stack;
    Dish one_dish = Dish("A dish with one fish pattern on it");
    Dish two_dish = Dish("A dish with two fish patterns on it");
    Dish red_dish = Dish("A dish with a red fish pattern on it");
    Dish blue_dish = Dish("A dish with a blue fish pattern on it");

    // The variable stack_size should equal zero.
    int stack_size = stack.size();
    cout << stack_size << endl;

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    // The variable size_after_pushes should equal four.
    int size_after_pushes = stack.size();
    cout << size_after_pushes << endl;

    // The variable peeked_dish should have a description of "A dish with a blue fish pattern on it"
    Dish peeked_dish = stack.peek();
    cout << peeked_dish.get_description() << endl;

    // The variable popped_dish should have a description of "A dish with a blue fish pattern on it"
    Dish popped_dish = stack.pop();
    cout << popped_dish.get_description() << endl;

    // The variable another_popped_dish should have a description of "A dish with a red fish pattern on it"
    Dish another_popped_dish = stack.pop();
    cout << another_popped_dish.get_description() << endl;

    // The variable final_size should equal two.
    int final_size = stack.size();
    cout << final_size << endl;

}