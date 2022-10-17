#include <Python.h>
#include <iostream>
#include <iomanip>
#define NOMINMAX
#include <Windows.h>
#undef NOMINMAX
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

void CallProcedure(string pName)
{
  char *procname = new char[pName.length() + 1];
  std::strcpy(procname, pName.c_str());

  Py_Initialize();
  PyObject *my_module = PyImport_ImportModule("PythonCode");
  PyErr_Print();
  PyObject *my_function = PyObject_GetAttrString(my_module, procname);
  PyObject *my_result = PyObject_CallObject(my_function, NULL);
  Py_Finalize();

  delete[] procname;
}

int callIntFunc(string proc, string param)
{
  char *procname = new char[proc.length() + 1];
  std::strcpy(procname, proc.c_str());

  char *paramval = new char[param.length() + 1];
  std::strcpy(paramval, param.c_str());

  PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
  Py_Initialize();
  pName = PyUnicode_FromString((char *)"PythonCode");
  pModule = PyImport_Import(pName);

  pDict = PyModule_GetDict(pModule);

  pFunc = PyDict_GetItemString(pDict, procname);
  if (PyCallable_Check(pFunc))
  {
    pValue = Py_BuildValue("(z)", paramval);
    PyErr_Print();
    presult = PyObject_CallObject(pFunc, pValue);
    PyErr_Print();
  }
  else
  {
    PyErr_Print();
  }
  // printf("Result is %d\n", _PyLong_AsInt(presult));
  Py_DECREF(pValue);
  Py_DECREF(pModule);
  Py_DECREF(pName);
  Py_Finalize();

  delete[] procname;
  delete[] paramval;

  return _PyLong_AsInt(presult);
}

int callIntFunc(string proc, int param)
{
  char *procname = new char[proc.length() + 1];
  std::strcpy(procname, proc.c_str());

  PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;

  Py_Initialize();

  pName = PyUnicode_FromString((char *)"PythonCode");

  pModule = PyImport_Import(pName);

  pDict = PyModule_GetDict(pModule);

  pFunc = PyDict_GetItemString(pDict, procname);
  if (PyCallable_Check(pFunc))
  {
    pValue = Py_BuildValue("(i)", param);
    PyErr_Print();
    presult = PyObject_CallObject(pFunc, pValue);
    PyErr_Print();
  }
  else
  {
    PyErr_Print();
  }
  // printf("Result is %d\n", _PyLong_AsInt(presult));
  Py_DECREF(pValue);

  Py_DECREF(pModule);
  Py_DECREF(pName);

  Py_Finalize();

  delete[] procname;

  return _PyLong_AsInt(presult);
}

void DrawMenu()
{

  int menuLoop = 0;
  int wordCount = 0;
  int itemQuantity = 0;
  string searchTerm;
  string itemName;
  string greenColor = "\033[32;1m";
  string defaultColor = "\033[0m";
  ifstream fileInput;

  while (menuLoop != 4)
  {

    std::cout << "[1] Calculate the number of times each item appears" << std::endl;
    std::cout << "[2] Calculate the frequency of a specific item" << std::endl;
    std::cout << "[3] Create a histogram based on the number of appearances of each item" << std::endl;
    std::cout << "[4] Quit" << std::endl;

    std::cin >> menuLoop;

    while (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please input a valid selection: ";
      std::cin >> menuLoop;
    }
    switch (menuLoop)
    {
    case 1:
      system("CLS");
      CallProcedure("CountAll");
      std::cout << std::endl;
      break;

    case 2:

      system("CLS");
      std::cout << "What item would you like to search for?" << std::endl;
      std::cin >> searchTerm;

      wordCount = callIntFunc("CountInstances", searchTerm);

      std::cout << std::endl
                << searchTerm << " : " << wordCount << std::endl
                << std::endl;

      break;

    case 3:
      system("CLS");
      CallProcedure("CollectData");

      fileInput.open("frequency.dat");

      fileInput >> itemName;
      fileInput >> itemQuantity;

      while (!fileInput.fail())
      {

        std::cout << defaultColor;

        std::cout << std::setw(14) << std::left << itemName << std::setw(6);

        std::cout << greenColor;

        for (int i = 0; i < itemQuantity; i++)
        {

          std::cout << std::right << "*";
        }

        std::cout << std::endl;
        fileInput >> itemName;
        fileInput >> itemQuantity;
      }
      fileInput.close();
      std::cout << defaultColor << endl;
      break;

    case 4:
      return;

    default:
      std::cout << "Please input a valid selection.";
      std::cout << std::endl;
      break;
    }
  }
}

void main()
{
  DrawMenu();
}