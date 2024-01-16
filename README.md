# PyBindTest

Build library:

gcc -shared -o liblibrary.so -fPIC library.c

&nbsp;

Verify with library_test:

gcc library_test.c -L. -llibrary -o library_test

./library_test

&nbsp;

Build PyBind wrapper:

python setup.py build_ext --inplace

Then 

python -> import add_library -> undefined symbol error