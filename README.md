# PyBindTest

Build library:

gcc -shared -o liblibrary.so -fPIC library.c

Verify with library_test:

&nbsp;

gcc library_test.c -L. -llibrary -o library_test

./library_test

&nbsp;

Build PyBind wrapper:

python setup.py build_ext --inplace
