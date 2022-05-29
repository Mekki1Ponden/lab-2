#include "List.h"

List::List(int value, ...) {
    if (value < 1)
        throw new std::exception("Error: The first parameter when calling this constructor must be positive!");
    this->head_ = this->tail_ = nullptr;
    va_list vl;
    va_start(vl, value);
    for (auto i = 0; i < value; i++)
        pushBack(va_arg(vl, int));
    va_end(vl);
}
List::List(const List& that) {
    this->head_ = this->tail_ = nullptr;
    if (that.isEmpty()) return;
    Item* temp = that.head_;
    do {
        this->pushBack(temp->data);
        temp = temp->next;
    }
    while (temp != that.head_);
}

void List::random(int size, int min, int max) {
    if (size < 1)
        throw new std::exception("Error: The size parameter when calling the random() method must be positive!");
    clear();
    srand(time(NULL));
    size = rand() % (size + 1);
    for (auto i = 0; i < size; i++)
        pushBack(rand() % (max - min + 1) + min);
}
int  List::size() const {
    if (isEmpty()) return 0;
    Item* temp = head_;
    int size = 0;
    do size++, temp = temp->next;
    while (temp != head_);
    return size;
}
bool List::isEmpty() const {
	return !((bool)head_);
}
void List::pushFront(int value) {
    try {
        Item* temp = new Item;
        temp->data = value, temp->next = nullptr;
        if (!head_) {
            head_ = temp, tail_ = temp;
            head_->next = temp, tail_->next = temp;
        }
        else {
            temp->next = head_, head_ = temp;
            tail_->next = temp;
        }
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
void List::pushBack(int value) {
    try {
        Item* temp = new Item;
        temp->data = value, temp->next = nullptr;
        if (!head_) {
            head_ = temp, tail_ = temp;
            head_->next = temp, tail_->next = temp;
        }
        else {
            tail_->next = temp, tail_ = temp;
            temp->next = head_;
        }
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
int  List::popFront() {
    if (isEmpty()) throw new std::exception("Error: The list is empty!");
    Item* temp = head_;
    int data = temp->data;
    if (head_ == tail_) {
        delete temp;
        head_ = nullptr, tail_ = nullptr;
        return data;
    }
    head_ = temp->next, tail_->next = head_;
    delete temp;
    return data;
}
int  List::popBack() {
    if (isEmpty()) throw new std::exception("Error: The list is empty!");
    Item* temp = tail_;
    int data = temp->data;
    temp = head_;
    if (head_ == tail_) {
        delete temp;
        head_ = nullptr, tail_ = nullptr;
        return data;
    }
    while (temp->next != tail_)
        temp = temp->next;
    tail_ = temp, temp = temp->next;
    delete temp;
    tail_->next = head_;
    return data;
}
int  List::front() const {
    if (isEmpty()) throw new std::exception("Error: The list is empty!");
    return head_->data;
}
int  List::back() const {
    if (isEmpty()) throw new std::exception("Error: The list is empty!");
    return tail_->data;
}
int* List::getArray() const {
    int* array = nullptr;
    if (isEmpty()) return array;
    try {
        array = new int[size()];
        Item* temp = head_;
        auto counter = 0;
        do array[counter++] = temp->data, temp = temp->next;
        while (temp != head_);
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return array;
}
void List::clear() {
    while (head_ != tail_) {
        Item* temp = head_;
        head_ = temp->next;
        delete temp;
    }
    if (head_ != nullptr) {
        Item* temp = head_;
        delete temp;
        head_ = nullptr, tail_ = nullptr;
    }
}

std::istream& operator>> (std::istream& in, List& list) {
    std::string where;
    while (where.empty()) {
        system("cls");
        std::cout << "Куда хотите добавить эелемент\n";
        std::cout << " 1 – в начало списка\n";
        std::cout << " 2 – в конец списка\n";
        std::cout << "\n > ";

        std::cin >> where;
        if (where[0] == '1') {
            system("cls");
            std::cout << "Введите значение для добавления в начало списка: ";
            int value;
            in >> value;
            list.pushFront(value);
            system("cls");
        }
        else if (where[0] == '2') {
            system("cls");
            std::cout << "Введите значение для добавления в конец списка: ";
            int value;
            std::cin >> value;
            list.pushBack(value);
            system("cls");
        }
        else {
            std::cout << "\n Что-то не то . . .\n Попробуйте еще раз\n ";
            system("pause");
            where.clear();
        }
    }
    return in;
}
std::ostream& operator<< (std::ostream& out, const List& list) {
    int* array = list.getArray();
    if (!array) {
        out << "Список пуст";
        return out;
    }
    int size = list.size();
    for (int i = 0; i < size; i++)
        out << array[i] << " ";
    return out;
}

List& List::operator++() {
    std::cout << "Введите значение для добавления в начало списка: ";
    int in;
    std::cin >> in;
    pushFront(in);
    return *this;
}
List& List::operator--() {
    popFront();
    return *this;
}
List& List::operator++(int) {
    std::cout << "Введите значение для добавления в конец списка: ";
    int in;
    std::cin >> in;
    pushBack(in);
    return *this;
}
List& List::operator--(int) {
    popBack();
    return *this;
}

List List::operator()(int begin, int end) {
    List list;
    if (isEmpty())
        throw new std::exception("Error: The list is empty!");
    if (begin < 0 || end < 0 || begin > end)
        throw new std::exception("Error: Both parameters must be positive when calling operator() overload!");
    if (begin > this->size() - 1)
        return list;
    Item* ptr = this->head_;
    for (auto counter = 0; counter <= end; counter++) {
        if (counter >= begin && counter < this->size()) list.pushBack(ptr->data);
        ptr = ptr->next;
    }
    return list;
}
int List::operator[](int index) {
    if (isEmpty())
        throw new std::exception("Error: The list is empty!");
    if (index < 0)
        throw new std::exception("Error: The index parameter must not be negative!");
    if (index > this->size() - 1)
        throw new std::exception("Error: The index parameter is larger than the list size!");
    Item* ptr = this->head_;
    for (auto counter = 0; counter < index; counter++)
        ptr = ptr->next;
    return ptr->data;
}

List& List::operator= (const List& that) {
    if (this == &that) return *this;
    this->clear();
    if (that.isEmpty()) {
        this->head_ = this->tail_ = nullptr;
        return *this;
    }
    Item* temp = that.head_;
    do this->pushBack(temp->data), temp = temp->next;
    while (temp != that.head_);
    return *this;
}
List operator+ (const List& l1, const List& l2) {
    List list;
    if (l1.isEmpty() || l2.isEmpty()) return list;
    Item* ptr1 = l1.head_, * ptr2 = l2.head_;
    Item* start = l1.size() > l2.size() ? l2.head_ : l1.head_;
    do {
        list.pushBack(ptr1->data + ptr2->data);
        ptr1 = ptr1->next, ptr2 = ptr2->next;
    } while (ptr1 != start && ptr2 != start);
    return list;
}
List operator- (const List& l1, const List& l2) {
    List list;
    if (l1.isEmpty() || l2.isEmpty()) return list;
    Item* ptr1 = l1.head_, * ptr2 = l2.head_;
    Item* start = l1.size() > l2.size() ? l2.head_ : l1.head_;
    do {
        list.pushBack(ptr1->data - ptr2->data);
        ptr1 = ptr1->next, ptr2 = ptr2->next;
    } while (ptr1 != start && ptr2 != start);
    return list;
}
List operator* (const List& l1, const List& l2) {
    List list;
    if (l1.isEmpty() || l2.isEmpty()) return list;
    Item* ptr1 = l1.head_, * ptr2 = l2.head_;
    Item* start = l1.size() > l2.size() ? l2.head_ : l1.head_;
    do {
        list.pushBack(ptr1->data * ptr2->data);
        ptr1 = ptr1->next, ptr2 = ptr2->next;
    } while (ptr1 != start && ptr2 != start);
    return list;
}
List operator/ (const List& l1, const List& l2) {
    List list;
    if (l1.isEmpty() || l2.isEmpty()) return list;
    Item* ptr1 = l1.head_, * ptr2 = l2.head_;
    Item* start = l1.size() > l2.size() ? l2.head_ : l1.head_;
    do {
        list.pushBack(ptr1->data / ptr2->data);
        ptr1 = ptr1->next, ptr2 = ptr2->next;
    } while (ptr1 != start && ptr2 != start);
    return list;
}