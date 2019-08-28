#include <Python.h>

#define NO_IMPORT_ARRAY
#define PY_ARRAY_UNIQUE_SYMBOL PickerObject_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"

#include <stdio.h>

#include "example.h"


static PyObject* exampleExample_new(PyTypeObject* type, PyObject *args, PyObject *kw)
{
    exampleExample *self = (exampleExample *) type->tp_alloc(type, 0);
    return (PyObject *) self;

}

static PyObject* get_name(PyObject* pyself, void *closure) {
    exampleExample *self = (exampleExample *)pyself;
    if (self->data_name) {
      return PyUnicode_FromString(self->data_name);
    } else {
      Py_RETURN_NONE;
    }
}

static int set_name(PyObject* pyself, PyObject* o, void *closure) {
    exampleExample *self = (exampleExample *)pyself;
    strncpy(self->data_name, PyBytes_AsString(PyUnicode_AsASCIIString(o)), 255);
    return 0;
} 

static int exampleExample_init(PyObject *pyself, PyObject *args, PyObject *kw)
{ 
    if (!pyself) return -1;
    exampleExample* self = (exampleExample*)pyself;

    if(PyObject_Length(args)) {
        PyObject* name;
        PyArg_ParseTuple(args, "O", &name);
        set_name(pyself, name, NULL);
    } else {
        strcpy(self->data_name, "stranger");
    }
    return 0;
}

PyObject* exampleExampleHello(PyObject *pyself, PyObject *args, PyObject *kw)
{ 
    exampleExample* self = (exampleExample*)pyself;
    if(PyObject_Length(args)) {
        PyObject* s;
        PyArg_ParseTuple(args, "O", &s);
        printf("Hello %s!\n", PyBytes_AsString(PyUnicode_AsASCIIString(s)));
        fflush(stdout);
    } else {
        printf("Hello %s!\n", self->data_name);
        fflush(stdout);
    }

     Py_RETURN_NONE;
}

static void exampleExample_dealloc(PyObject *self)
{
    /*
        code to deallocate memory, e.g.
        exampleExample *p = (exampleExample *)self;
        free(p->data)
    */
    Py_TYPE(self)->tp_free(self);
}

PyObject* exampleExample_call(PyObject *self, PyObject *args, PyObject *kw)
{
    Py_RETURN_NONE;
}

static PyObject* exampleExample_repr(PyObject* self) {
    exampleExample *p = (exampleExample *)self;
    char buf[500];
    sprintf(buf, "%s(\"%s\") ", Py_TYPE(self)->tp_name, p->data_name) ;
    return PyUnicode_FromString(buf);
}

static PyMethodDef exampleExample_methods[] = {
    { (char*)"hello", (PyCFunction) exampleExampleHello, METH_VARARGS|METH_KEYWORDS, (char*) "Say hello."},
    {NULL}
};

static PyGetSetDef exampleExample_getset[] = {
    { (char*)"name", get_name, set_name, (char*)"Get/set data name.", NULL},
    { NULL}
};

static PyTypeObject exampleExampleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "_example.Example",            /*tp_name*/
    sizeof(exampleExample),       /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    exampleExample_dealloc,       /*tp_dealloc*/
    0,                         /*tp_print PSEUDODEPRECATED*/
    0,                         /*tp_getattr DEPRECATED*/
    0,                         /*tp_setattr DEPRECATED*/
    0,                         /*tp_compare*/
    exampleExample_repr,          /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    exampleExample_call,          /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "Example object.", /* tp_doc */
    0,  /* tp_traverse */
    0,  /* tp_clear */
    0,  /* tp_richcompare */
    0,  /* tp_weaklistoffset */
    0,  /* tp_iter: __iter__() method */
    0,  /* tp_iternext: next() method */
    exampleExample_methods,                    /* tp_methods */
    0,                    /* tp_members */
    exampleExample_getset, /* tp_getset */
    0, /* tp_base */
    0, /* tp_dict */
    0, /* tp_descr_get */
    0, /* tp_descr_set */
    0, /* tp_dictoffset */
    exampleExample_init, /* tp_init */
    0, /* tp_alloc */
    exampleExample_new, /* tp_new */
    0, /* tp_free Low-level free-memory routine */
    0 /* tp_is_gc For PyObject_IS_GC */
};

PyObject* exampleExample_NEW(void){
    exampleExample* object = PyObject_NEW(exampleExample, &exampleExampleType);
    return (PyObject*) object;
}

int exampleExample_Check(PyObject* ob)
{
    return PyObject_IsInstance(ob, (PyObject*) &exampleExampleType);
}
  
PyTypeObject* exampleExample_Type(void) {
    return &exampleExampleType;
}