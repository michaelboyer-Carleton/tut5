#include "TAArray.h"

#include<iostream>

TAArray::TAArray() {
    
    this->array = new TextArea*[MAX_COMPONENTS];
    this->size = 0;

}

TAArray::~TAArray() {

    for (int i = 0; i < this->size; ++i) {
        if (this->array[i] == nullptr) { continue; }
        delete this->array[i];
    }

    delete [] this->array;

}

bool TAArray::add(TextArea* ta) {

    if (this->size >= MAX_COMPONENTS) { return false; }

    this->array[this->size++] = ta;
    return true;
}

bool TAArray::add(TextArea* ta, int index) {

    if (index >= MAX_COMPONENTS) { return false; }
    
    this->array[index] = ta;

    ++this->size;
    
    if (index >= this->size) {
        cout << "index is larger than size, adjusting to " << index+1 << endl;
        this->size = index + 1;
    }

    return true;
}

TextArea* TAArray::remove(const string& id) {

    TextArea* found = nullptr;

    for (int i = 0; i < this->size; ++i) {
        if (this->array[i] && this->array[i]->getId() == id) {

            found = this->array[i];

            for (int j = i; j < this->size - 1; ++j) {

                this->array[j] = this->array[j + 1];

            }

            --this->size;
            this->array[this->size] = nullptr;

            break;

        }
    }

    return found;
}

TextArea* TAArray::remove(int index) {

    TextArea* found = this->array[index];

    for (int i = index; i < this->size - 1; ++i) {

        this->array[i] = this->array[i + 1];
        
    }
    --this->size;
    this->array[this->size] = nullptr;

    return found;

}

TextArea* TAArray::get(const string& id) const {

    TextArea* found = nullptr;

    for (int i = 0; i < this->size; ++i) {
        if (this->array[i] && this->array[i]->getId() == id) {
            found = this->array[i];
            break;
        }
    }

    return found;
}

TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= this->size) { return nullptr; }
    return this->array[index];
}

int TAArray::getSize() const {
    return this->size;
}