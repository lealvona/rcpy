/* Contributed by BrendanSimon */

#include <Python.h>

#include <rc/dsm.h>

static char module_docstring[] =
  "This module provides an interface for the DSM2/DSMX Receiver (2.4GHz Radio Control).";

static PyObject *dsmError;

// dsm functions
static PyObject *dsm_get_ch_raw(PyObject *self, PyObject *args);
static PyObject *dsm_get_ch_normalized(PyObject *self, PyObject *args);
static PyObject *dsm_get_channels(PyObject *self, PyObject *args);
//static PyObject *dsm_get_battery_voltage(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
  {"get_ch_raw",
   (PyCFunction)dsm_get_ch_raw,
   METH_VARARGS,
   "get dsm ch raw value"}
  ,
  {"get_ch_normalized",
   (PyCFunction)dsm_get_ch_normalized,
   METH_VARARGS,
   "get dsm ch normalized value"}
  ,
  {"get_channels",
   (PyCFunction)dsm_get_channels,
   METH_VARARGS,
   "get num dsm channels"}
  ,
//  {"get_battery_voltage",
//   (PyCFunction)dsm_get_battery_voltage,
//   METH_VARARGS,
//   "get battery voltage"}
//  ,
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT,
  "_dsm",   /* name of module */
  module_docstring, /* module documentation, may be NULL */
  -1,       /* size of per-interpreter state of the module,
	       or -1 if the module keeps state in global variables. */
   module_methods
};

/* python functions */

PyMODINIT_FUNC PyInit__dsm(void)
{
  PyObject *m;

  /* create module */
  m = PyModule_Create(&module);
  if (m == NULL)
    return NULL;

  /* create exception */
  dsmError = PyErr_NewException("dsm.error", NULL, NULL);
  Py_INCREF(dsmError);
  PyModule_AddObject(m, "error", dsmError);

  /* initialize cape */
  if(rc_dsm_init() != 0){
      return NULL;
  }

  return m;
}

static
PyObject *dsm_get_ch_raw(PyObject *self, PyObject *args)
{
  /* parse arguments */
  unsigned channel;
  if (!PyArg_ParseTuple(args, "I", &channel)) {
    PyErr_SetString(dsmError, "Invalid arguments");
    return NULL;
  }

  /* get dsm value */
  int value;
  if ((value = rc_dsm_ch_raw((int)channel)) < 0) {
    PyErr_SetString(dsmError, "Failed to get dsm raw value");
    return NULL;
  }

  /* Build the output tuple */
  PyObject *ret = Py_BuildValue("i", value);

  return ret;
}

static
PyObject *dsm_get_ch_normalized(PyObject *self, PyObject *args)
{
  /* parse arguments */
  unsigned channel;
  if (!PyArg_ParseTuple(args, "I", &channel)) {
    PyErr_SetString(dsmError, "Invalid arguments");
    return NULL;
  }

  /* get dsm voltage */
  float normal_val;
  if ((normal_val = rc_dsm_ch_normalized((int)channel)) < 0) {
    PyErr_SetString(dsmError, "Failed to get normalized dsm value");
    return NULL;
  }

  /* Build the output tuple */
  PyObject *ret = Py_BuildValue("f", normal_val);

  return ret;
}

static
PyObject *dsm_get_channels(PyObject *self, PyObject *args)
{
  /* parse arguments */

  /* get num channels*/
  int channels;
  if ((voltage = rc_dsm_channelsk()) < 0) {
    PyErr_SetString(dsmError, "Failed to get DC jack voltage");
    return NULL;
  }

  /* Build the output tuple */
  PyObject *ret = Py_BuildValue("i", channels);

  return ret;
}

//static
//PyObject *dsm_get_battery_voltage(PyObject *self,
//			PyObject *args)
//{
//  /* parse arguments */
//
//  /* get dc jack voltage */
//  float voltage;
//  if ((voltage = rc_dsm_batt()) < 0) {
//    PyErr_SetString(dsmError, "Failed to get battery voltage");
//    return NULL;
//  }
//
//  /* Build the output tuple */
//  PyObject *ret = Py_BuildValue("f", voltage);
//
//  return ret;
//}

