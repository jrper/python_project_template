#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "example.h"

static PyObject *
long_add(PyObject *self, PyObject *args)
{
    long l1, l2;

    if (!PyArg_ParseTuple(args, "ll", &l1, &l2))
        return NULL;
    return PyLong_FromLong(l1+l2);
}

static PyMethodDef exampleMethods[] = {
    {"long_add",  long_add, METH_VARARGS,
     "long_add(a, b)\n--\n\n Add two long integers."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef examplemodule = {
    PyModuleDef_HEAD_INIT,
    "_example",   /* name of module */
    "C based example extension", /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    exampleMethods
};

PyMODINIT_FUNC
PyInit__example(void)
{
    PyObject *m;

    m = PyModule_Create(&examplemodule);
    if (m == NULL)
        return NULL;

    if (PyType_Ready(exampleExample_Type()) < 0)  return NULL;

    Py_INCREF(exampleExample_Type());
    PyModule_AddObject(m,"Example", (PyObject*)exampleExample_Type());

    return m;
}