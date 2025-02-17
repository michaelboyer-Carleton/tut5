#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"

class TAArray {

    public:

        TAArray();
        ~TAArray();
        
        bool add(TextArea* ta);
        bool add(TextArea* ta, int index);

        TextArea* remove(int index);
        TextArea* remove(const string& id);

        TextArea* get(const string&) const;
        TextArea* get(int index) const;

        int getSize() const;

    private:

        TextArea** array;
        int size;

};

#endif