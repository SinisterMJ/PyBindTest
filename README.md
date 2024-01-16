# PyBindTest

Build library:
gcc -shared -o libhello.so -fPIC hello.c

Verify with library_test:
gcc library_test.c -L. -llibrary -o library_test & ./library_test

Build PyBind wrapper:
python setup.py build_ext --inplace
