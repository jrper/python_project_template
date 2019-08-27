#ifndef _PICKEROBJECT_H
#define _PICKEROBJECT_H 1

#include <Python.h>

typedef struct {
    
    PyObject_HEAD
    char data_name[255];
} exampleExample;

PyObject* exampleExample_NEW();
int exampleExample_Check(PyObject*);
PyTypeObject* exampleExample_Type();

#endif /* _PICKEROBJECT_H */